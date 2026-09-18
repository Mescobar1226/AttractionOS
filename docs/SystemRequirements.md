# AttractionOS System Requirements

## Purpose
AttractionOS simulates high-level control behavior for a fictional theme-park attraction for software-engineering education and portfolio demonstration.

## Functional Requirements

**REQ-01 — Power State:** The controller shall initialize in OFF and permit a transition through STARTUP to IDLE.

**REQ-02 — Loading:** The controller shall permit loading to begin from IDLE.

**REQ-03 — Dispatch Interlocks:** The controller shall permit dispatch only when platform gates are closed, restraints are locked, the simulated track is clear, the emergency stop is inactive, and the controller is in LOADING or READY.

**REQ-04 — Dispatch Rejection:** The controller shall reject a dispatch request when any required interlock is unsatisfied and provide a human-readable reason.

**REQ-05 — State Sequence:** An accepted dispatch shall transition through DISPATCHING, RUNNING, UNLOADING, and back to IDLE when the simulated cycle is advanced.

**REQ-06 — Emergency Stop:** Activating the simulated emergency stop shall place the controller in FAULT.

**REQ-07 — Active-Cycle Track Fault:** If the track becomes occupied during DISPATCHING or RUNNING, the controller shall enter FAULT.

**REQ-08 — Reset:** A reset shall not clear FAULT while the simulated emergency stop remains active.

**REQ-09 — Event Logging:** The controller shall maintain a timestamped event log for significant operator actions and state changes.

## Nonfunctional Requirements

- Written in standard C++17 or newer.
- Controller logic shall be separated from the console user interface.
- Code shall use descriptive identifiers and encapsulate controller state.
- The project shall include repeatable automated tests for critical simulated behaviors.

## Safety Scope

These requirements describe a simplified educational simulation. They are not requirements for a real attraction or safety-related control system.
