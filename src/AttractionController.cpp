#include "../include/AttractionController.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

AttractionController::AttractionController()
    : state_(State::OFF), gatesClosed_(false), restraintsLocked_(false), trackClear_(true), emergencyStop_(false) {
    log("Controller initialized: system OFF");
}

void AttractionController::log(const std::string& message) {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm{};
#ifdef _WIN32
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif
    std::ostringstream out;
    out << std::put_time(&tm, "%H:%M:%S") << "  " << message;
    log_.push_back(out.str());
}

void AttractionController::powerOn() {
    if (state_ != State::OFF) return;
    state_ = State::STARTUP;
    log("Power on; startup checks initiated");
    if (emergencyStop_) { enterFault("Emergency stop active during startup"); return; }
    state_ = State::IDLE;
    log("Startup checks passed; system IDLE");
}

void AttractionController::beginLoading() {
    if (state_ == State::IDLE) {
        state_ = State::LOADING;
        gatesClosed_ = false;
        restraintsLocked_ = false;
        log("Vehicle entered loading state");
    }
}

void AttractionController::toggleGates() {
    if (state_ != State::LOADING && state_ != State::READY) return;
    gatesClosed_ = !gatesClosed_;
    log(std::string("Platform gates ") + (gatesClosed_ ? "CLOSED" : "OPENED"));
    evaluateReady();
}

void AttractionController::toggleRestraints() {
    if (state_ != State::LOADING && state_ != State::READY) return;
    restraintsLocked_ = !restraintsLocked_;
    log(std::string("Restraints ") + (restraintsLocked_ ? "LOCKED" : "UNLOCKED"));
    evaluateReady();
}

void AttractionController::toggleTrackClear() {
    trackClear_ = !trackClear_;
    log(std::string("Track status changed to ") + (trackClear_ ? "CLEAR" : "OCCUPIED"));
    if (!trackClear_ && (state_ == State::DISPATCHING || state_ == State::RUNNING)) enterFault("Track became occupied during active cycle");
    else evaluateReady();
}

void AttractionController::toggleEmergencyStop() {
    emergencyStop_ = !emergencyStop_;
    log(std::string("Emergency stop ") + (emergencyStop_ ? "ACTIVATED" : "RELEASED"));
    if (emergencyStop_) enterFault("Emergency stop activated");
}

void AttractionController::evaluateReady() {
    if ((state_ == State::LOADING || state_ == State::READY) && canDispatch()) {
        if (state_ != State::READY) log("All dispatch interlocks satisfied; dispatch ENABLED");
        state_ = State::READY;
    } else if (state_ == State::READY) {
        state_ = State::LOADING;
        log("Dispatch interlock no longer satisfied; dispatch DISABLED");
    }
}

bool AttractionController::canDispatch() const {
    return (state_ == State::LOADING || state_ == State::READY) && gatesClosed_ && restraintsLocked_ && trackClear_ && !emergencyStop_;
}

std::string AttractionController::dispatchDenialReason() const {
    if (state_ == State::FAULT) return "System is in FAULT state.";
    if (state_ != State::LOADING && state_ != State::READY) return "Vehicle is not in a dispatchable state.";
    if (!gatesClosed_) return "Platform gates are open.";
    if (!restraintsLocked_) return "Restraints are not locked.";
    if (!trackClear_) return "Track is not clear.";
    if (emergencyStop_) return "Emergency stop is active.";
    return "No interlock prevents dispatch.";
}

bool AttractionController::dispatch() {
    if (!canDispatch()) {
        log("Dispatch DENIED: " + dispatchDenialReason());
        return false;
    }
    state_ = State::DISPATCHING;
    log("Dispatch accepted; vehicle DISPATCHING");
    return true;
}

void AttractionController::advanceCycle() {
    if (state_ == State::DISPATCHING) { state_ = State::RUNNING; log("Vehicle entered RUNNING state"); }
    else if (state_ == State::RUNNING) { state_ = State::UNLOADING; log("Vehicle entered UNLOADING state"); }
    else if (state_ == State::UNLOADING) {
        state_ = State::IDLE;
        gatesClosed_ = false;
        restraintsLocked_ = false;
        log("Cycle complete; system returned to IDLE");
    }
}

void AttractionController::enterFault(const std::string& reason) {
    state_ = State::FAULT;
    log("FAULT: " + reason);
}

void AttractionController::reset() {
    if (emergencyStop_) { log("Reset DENIED: emergency stop remains active"); return; }
    state_ = State::IDLE;
    gatesClosed_ = false;
    restraintsLocked_ = false;
    trackClear_ = true;
    log("Operator reset completed; system IDLE");
}

AttractionController::State AttractionController::getState() const { return state_; }
bool AttractionController::gatesClosed() const { return gatesClosed_; }
bool AttractionController::restraintsLocked() const { return restraintsLocked_; }
bool AttractionController::isTrackClear() const { return trackClear_; }
bool AttractionController::emergencyStopActive() const { return emergencyStop_; }
const std::vector<std::string>& AttractionController::getLog() const { return log_; }

std::string AttractionController::stateName() const {
    switch (state_) {
        case State::OFF: return "OFF"; case State::STARTUP: return "STARTUP"; case State::IDLE: return "IDLE";
        case State::LOADING: return "LOADING"; case State::READY: return "READY"; case State::DISPATCHING: return "DISPATCHING";
        case State::RUNNING: return "RUNNING"; case State::UNLOADING: return "UNLOADING"; case State::FAULT: return "FAULT";
    }
    return "UNKNOWN";
}
