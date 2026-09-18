#include "../include/AttractionController.h"
#include <cassert>
#include <iostream>

int main() {
    AttractionController c;
    assert(c.getState() == AttractionController::State::OFF);
    c.powerOn();
    assert(c.getState() == AttractionController::State::IDLE);
    c.beginLoading();
    assert(!c.canDispatch());
    c.toggleGates();
    assert(!c.canDispatch());
    c.toggleRestraints();
    assert(c.canDispatch());
    assert(c.dispatch());
    assert(c.getState() == AttractionController::State::DISPATCHING);
    c.advanceCycle();
    assert(c.getState() == AttractionController::State::RUNNING);
    c.toggleEmergencyStop();
    assert(c.getState() == AttractionController::State::FAULT);
    c.reset();
    assert(c.getState() == AttractionController::State::FAULT); // E-stop still active
    c.toggleEmergencyStop();
    c.reset();
    assert(c.getState() == AttractionController::State::IDLE);
    std::cout << "All AttractionOS tests passed.\n";
}
