# AttractionOS Test Plan

## Objective
Verify that the educational simulator follows its documented state and interlock requirements.

| Test | Procedure | Expected Result |
|---|---|---|
| T01 Startup | Power on from OFF | Controller reaches IDLE |
| T02 Empty interlocks | Begin loading and request dispatch | Dispatch denied |
| T03 Gates only | Close gates without locking restraints | Dispatch remains disabled |
| T04 All interlocks | Close gates, lock restraints, track clear, E-stop normal | READY / dispatch enabled |
| T05 Normal dispatch | Dispatch with all interlocks satisfied | State becomes DISPATCHING |
| T06 Normal cycle | Advance DISPATCHING → RUNNING → UNLOADING → IDLE | Cycle completes in order |
| T07 Emergency stop | Activate E-stop | Controller enters FAULT |
| T08 Reset blocked | Attempt reset while E-stop active | Controller remains FAULT |
| T09 Reset recovery | Release E-stop and reset | Controller returns to IDLE |
| T10 Track fault | Mark track occupied while RUNNING | Controller enters FAULT |

## Automated Tests
`tests/ControllerTests.cpp` uses C++ assertions to cover startup, interlock behavior, dispatch, state progression, emergency-stop fault behavior, blocked reset, and recovery.

## Manual Testing
Use the console menu to intentionally attempt invalid sequences and verify that the simulator refuses invalid dispatches and records meaningful log entries.
