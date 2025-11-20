# Smart Home Automation System 💡
This project implements a modular Smart Home Automation System in C++. The system will simulate managing various smart devices found in a modern home environment, such 
as lights, thermostats, and security cameras. It demonstrates architecture-focused software design using multiple **Creational, Structural, and Behavioral Design Patterns.**

## 🚀 Full Features & Design Patterns: 
### 1. Device Creation and Management
- **Abstract Factory Design Pattern:**
    - To create families of related devices (Lights, Thermostats and Cameras) dynamically.
    - Also supports different brands and models with no changes to the core system.
- **Factory Design Pattern:**
    - Used with MotionSensor and DoorLock where the only variant is the type of Factory
- **Singleton Design Pattern:**
    - For the Central Smart Home Controller / Hub.
    - Ensures only one global controller manages all devices.

### 2. Device Organization
- **Composite Design Pattern:**
    - To group devices by:
        - Room `RoomDevices`
        - Floor `FloorDevices`
        - Function `(LightingGroup, SecurityGroup)`
<<<<<<< HEAD
    - Allows treating **individual devices and whole groups the same way**.
||||||| 91bad22
    - Allows treating **individual devices and whole groups the same way**.
- **Adapter Design Pattern:**
    - To support **devices with different or legacy interfaces**.
    - Example:
        - External camera API → adapt to your system’s `ISmartDevice` interface.
=======
    - Allows treating individual devices and whole groups the same way.
- **Adapter Design Pattern:**
    - To support **devices with different or legacy interfaces**.
    - Example:
        - External camera API → adapt to your system’s `ISmartDevice` interface.
>>>>>>> a73c6d8a42aef5cb3196dc707822d9277ebd1322
- **Facade Design Pattern:**
    - Provide a **simple interface to the entire home system**.
    - Hides complexity from the client.
      
### 3. Interaction and Automation
- **Observer Design Pattren:**
    - Devices communicate automatically:
        - Motion sensor notifies light → turn on
        - Thermostat notifies heater
        - Door lock notifies security system
    - Event-driven communication.
- **Command Design Pattern:**
    - very user command becomes an object:
        - Execute
        - Undo
        - Queue
    - Example:
        - `TurnOffAllLightsCommand`
        - `SetTemperatureCommand`
- **Strategy Design Pattern:**
    - For automation modes:
        - `EnergySavingMode`
        - `ComfortMode`
    - Switch automation logic at runtime.
      
- **State Design Pattern:**
    - For representing internal device states:
        - Light: OFF → ON → DIMMED
        - Thermostat: HEATING → COOLING → IDLE
    - Clean state transitions.
 
## 📁 Structure: 
```
├── MakeFile
├── build/
├── include/
│   ├── (all header files)
│   └── ...
├── src/
│   ├── main.cpp
│   ├── (all source files)
│   └── ...
└── docs/
    └── Design Patterns Documentation.pdf
```
## 🛠️ Build & Run: 
```
make build
make run
```

## Requirements
- C++ 17
- GNU Make 4.4







