# 🎢 AttractionOS

> C++ theme park attraction control system simulator.

AttractionOS is a software engineering portfolio project that simulates the control logic behind a fictional theme park attraction.

Instead of simply demonstrating basic C++ programming, AttractionOS explores how software can respond to changing system conditions, enforce operating requirements, detect faults, and control transitions between different attraction states.

The project uses a **finite-state machine, simulated safety inputs, dispatch interlocks, fault handling, event logging, and software testing** to demonstrate concepts used in real-time and control-oriented software development.

> **Note:** AttractionOS is an educational software simulation. It is not designed, tested, certified, or intended to control real attractions, machinery, or other safety-critical systems.

---

## 🚀 Vision

Modern theme park attractions rely on software, hardware, sensors, control systems, operators, and mechanical components working together.

Even a seemingly simple action such as dispatching a ride vehicle requires the system to evaluate multiple conditions.

Questions the software may need to answer include:

* Are the platform gates closed?
* Are the restraints locked?
* Is the track clear?
* Is the attraction in the correct operating state?
* Has an emergency stop been activated?
* What should happen if a required condition changes?
* How should the system respond to a fault?

AttractionOS explores these ideas through a simulated attraction control environment where system conditions determine whether an operation is allowed to continue.

---

## ✨ Current Features

* C++ attraction control simulator
* Finite-state machine architecture
* Simulated platform gate monitoring
* Simulated restraint monitoring
* Simulated track-clear detection
* Emergency stop simulation
* Dispatch interlock logic
* Automatic fault detection
* Operator reset and recovery
* Timestamped event logging
* Console-based operator interface
* Automated controller tests
* Software requirements documentation
* Architecture documentation
* Software test plan

---

## 🎛 Attraction States

AttractionOS models attraction operation using a finite-state machine.

The current system includes the following states:

```text
OFF
 ↓
STARTUP
 ↓
IDLE
 ↓
LOADING
 ↓
READY
 ↓
DISPATCHING
 ↓
RUNNING
 ↓
UNLOADING
 ↓
IDLE
```

Abnormal conditions can interrupt normal operation and place the attraction into a fault state:

```text
NORMAL OPERATION
       │
       │
Emergency Stop / Fault
       ↓
     FAULT
       │
  Operator Reset
       ↓
      IDLE
```

Using defined states helps prevent the attraction from performing actions that should not be possible during its current operating condition.

---

## 🔒 Dispatch Interlocks

One of the main features of AttractionOS is its simulated dispatch interlock system.

Before a vehicle can dispatch, the controller verifies that required conditions have been satisfied.

```text
Platform Gates CLOSED
        +
Restraints LOCKED
        +
Track CLEAR
        +
Emergency Stop NORMAL
        ↓
DISPATCH ENABLED
```

If one or more conditions are not satisfied, the dispatch request is denied and the operator receives information explaining why.

This allows the project to demonstrate how software requirements can be translated into control logic.

---

## ⚠️ Fault Handling

AttractionOS also simulates abnormal operating conditions.

The controller can detect conditions such as:

* Emergency stop activation
* Unsafe dispatch conditions
* Invalid operating states
* System conditions that prevent continued operation

When a fault occurs, the attraction transitions into a **FAULT** state.

The system must meet the appropriate reset conditions before normal simulated operation can resume.

This creates a simple environment for exploring concepts such as fault detection, state transitions, operator feedback, and recovery logic.

---

## 🧠 What This Project Demonstrates

AttractionOS was designed to explore several areas of software engineering beyond basic application development:

* Object-oriented C++
* Finite-state machines
* Control logic
* Software interlocks
* Requirements-based development
* Fault handling
* Event logging
* Software testing
* System architecture
* Technical documentation
* Separation of interface and control logic

The project also demonstrates how a software system can evaluate multiple inputs before allowing a requested action to occur.

---

## 🛠 Tech Stack

### Programming

* C++
* C++ Standard Library

### Development

* Visual Studio
* CMake

### Testing

* C++ automated controller tests
* Scenario-based testing
* Requirements verification

### Documentation

* Markdown
* System requirements
* Architecture documentation
* Test planning
* GitHub

---

## 📂 Project Structure

```text
AttractionOS/
│
├── include/
│   └── AttractionController.h
│
├── src/
│   ├── main.cpp
│   └── AttractionController.cpp
│
├── tests/
│   └── ControllerTests.cpp
│
├── docs/
│   ├── SystemRequirements.md
│   ├── Architecture.md
│   └── TestPlan.md
│
├── screenshots/
│
├── README.md
├── CMakeLists.txt
├── .gitignore
└── LICENSE
```

---

## ⚙️ Getting Started

### Clone the repository

```bash
git clone https://github.com/Mescobar1226/ShowFlow.git
cd AttractionOS
```

### Build with CMake

```bash
cmake -S . -B build
cmake --build build
```

### Run AttractionOS

```bash
./build/AttractionOS
```

On Windows, depending on the CMake generator and configuration, the executable may instead be located inside the Debug or Release directory.

---

## 🧪 Testing

AttractionOS includes automated tests for the attraction controller.

The tests verify important behaviors such as:

* Dispatch is denied when platform gates are open
* Dispatch is denied when restraints are unlocked
* Dispatch is denied when the track is not clear
* Dispatch is denied during an emergency-stop condition
* Dispatch is permitted when required simulated conditions are satisfied
* Fault conditions transition the controller into the appropriate state
* Reset behavior follows defined system requirements

Testing is included to demonstrate the relationship between **software requirements, implementation, and verification**.

---

## 📋 Engineering Documentation

Writing the code is only one part of ShowFlow.

The repository also includes documentation describing how the simulated system is designed and tested.

### System Requirements

`docs/SystemRequirements.md`

Defines expected controller behavior and operating requirements.

### Architecture

`docs/Architecture.md`

Explains the overall software structure, finite-state machine, and separation between the operator interface and attraction controller.

### Test Plan

`docs/TestPlan.md`

Documents the scenarios used to verify that the controller behaves according to its requirements.

---

## 📸 Screenshots

*Coming soon.*

Future screenshots will demonstrate:

* Operator control panel
* Successful dispatch
* Dispatch denied by an interlock
* Emergency-stop activation
* Fault recovery
* Event logging

---

## 🎯 Why I Built This

As a software engineering student, I wanted to explore software that interacts with simulated real-world systems rather than building another traditional application.

AttractionOS allows me to explore the software engineering side of that interest by practicing C++, control logic, finite-state machines, fault handling, testing, requirements development, and technical documentation.

---

## 🔮 Planned Features

* Graphical operator control panel
* Additional simulated sensors
* Multiple ride vehicles
* Vehicle position tracking
* Additional fault conditions
* Maintenance mode
* Operator access levels
* Expanded automated testing
* Configuration files
* Data logging and analysis
* Serial communication simulation
* Arduino or microcontroller integration
* Hardware-based sensor demonstration

---

## 📈 Roadmap

* [x] Build C++ project foundation
* [x] Create attraction state machine
* [x] Implement simulated safety inputs
* [x] Implement dispatch interlocks
* [x] Add emergency-stop behavior
* [x] Add fault handling
* [x] Add event logging
* [x] Create operator console
* [x] Create automated controller tests
* [x] Document system requirements
* [x] Create architecture documentation
* [x] Create software test plan
* [ ] Add screenshots
* [ ] Develop graphical operator interface
* [ ] Expand sensor simulation
* [ ] Add multiple vehicle support
* [ ] Add serial communication
* [ ] Integrate optional microcontroller hardware

---

## 🛡️ Safety Disclaimer

AttractionOS is an **educational software engineering project** created to demonstrate programming and control-system concepts in a simulated environment.

It is not a safety system and has not been designed, reviewed, validated, or certified for use with real amusement rides, industrial equipment, vehicles, machinery, or other safety-critical applications.

Real attraction control systems require specialized engineering, formal safety analysis, appropriate hardware, redundancy, applicable industry standards, independent verification, extensive testing, and regulatory compliance.

---

## 🤝 Contributing

This project is currently under active development as part of my software engineering portfolio.

Feedback, ideas, and suggestions are always welcome.

---

## 📄 License

This project is licensed under the MIT License.

---

**Created by Mei-Lynn Velazquez Escobar**

Software Engineering Student | C++ & Python Developer 
