#pragma once
#include <string>
#include <vector>

class AttractionController {
public:
    enum class State { OFF, STARTUP, IDLE, LOADING, READY, DISPATCHING, RUNNING, UNLOADING, FAULT };

    AttractionController();
    void powerOn();
    void beginLoading();
    void toggleGates();
    void toggleRestraints();
    void toggleTrackClear();
    void toggleEmergencyStop();
    bool canDispatch() const;
    bool dispatch();
    void advanceCycle();
    void reset();

    State getState() const;
    std::string stateName() const;
    bool gatesClosed() const;
    bool restraintsLocked() const;
    bool isTrackClear() const;
    bool emergencyStopActive() const;
    std::string dispatchDenialReason() const;
    const std::vector<std::string>& getLog() const;

private:
    State state_;
    bool gatesClosed_;
    bool restraintsLocked_;
    bool trackClear_;
    bool emergencyStop_;
    std::vector<std::string> log_;
    void log(const std::string& message);
    void evaluateReady();
    void enterFault(const std::string& reason);
};
