# CampusGuard: Emergency Response Coordination
COS 214 Practical 5 (2026)

## Team Members
* Enock Nyamweya
* Kyle Pillay
* Terrence Hluyo

## 1. Overview
CampusGuard is an emergency-response coordination platform written in C++11. It integrates six Gang of Four (GoF) design patterns to coordinate campus security, medical personnel, facilities, and access control:
* **Command Pattern**: Encapsulates operator actions (dispatch, lockdown, evacuation) and undo history.
* **Mediator Pattern**: Central dispatch coordination across decoupled response units (Security, Medical, Facilities, Fire).
* **Adapter Pattern**: Translates calls between the modern door interface and legacy turnstile hardware.
* **Facade Pattern**: High-level entry point coordinating multi-step emergency workflows across subsystems.
* **State Pattern**: Enforces the incident lifecycle (Reported -> Dispatched -> Contained -> Resolved) and validates transitions.
* **Strategy Pattern**: Provides swappable response algorithms (Evacuation vs. Lockdown tactics).

## 2. Project Layout
* src/ - All C++ source (.cpp) and header (.h) files
* docs/ - Visual Paradigm (.vpp) file, exported UML diagrams (.png), and report assets
* Makefile - Local C++11 build configuration
* Dockerfile & docker-compose.yml - Containerized build and run environment

## 3. Build and Run

### 3.1 Docker (Required for Demonstration)

**1. Compile and Run Normally:**
```bash
docker compose up --build
```
*(To stop and clean up containers: `docker compose down`)*

**2. Check for Memory Leaks (Valgrind):**
```bash
docker compose run --rm campusguard valgrind --leak-check=full ./campusguard
```

**3. Debugging (GDB):**
```bash
docker compose run --rm campusguard gdb ./campusguard
```
*(GDB Quick Guide: Type `break main` to set a breakpoint, `run` to start the program, `next` to step line-by-line, and `step` to go inside a function).*

**4. Open an Interactive Shell:**
```bash
docker compose run --rm campusguard bash
```

### 3.2 Local
```bash
make
./campusguard
```

Memory check:
```bash
make valgrind
```

Clean:
```bash
make clean
```
