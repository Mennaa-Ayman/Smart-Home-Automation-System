# Software Design Patterns

##  Smart Home Automation System 📱
This project involves designing and implementing a modular Smart Home Automation System in C++. The system will simulate managing various smart devices found in a modern home environment, such 
as lights, thermostats, and security cameras. It demonstrates architecture-focused software design using multiple **Creational, Structural, and Behavioral Design Patterns.**

## Features: 
**1. Device Creation and Management**
- The system supports dynamic creation of different device types and families, allowing multiple brands or variants of the same device type without major changes to the core system.
- A centralized controller (hub) manages all devices, providing a unified interface for system operations.

**2. Device Organization**
- Devices can be grouped logically based on location (e.g., rooms, floors, zones) or function (e.g., lighting, security).
- Operations can be applied to individual devices or entire groups through the same interface, simplifying control.
- The system can integrate devices with different interfaces, including external or legacy devices, seamlessly.
- A simplified interface allows users or external systems to interact with the entire smart home without needing to understand internal complexities.

**3. Interaction and Automation**
- Devices can communicate state changes or updates to other components automatically.
- User or automated requests are represented as objects that can be queued, executed, or undone, supporting flexible command management.
- The system supports multiple automation modes (e.g., Energy Saving, Comfort) that can be switched at runtime based on user preferences or environmental conditions.
- Internal states of devices are handled effectively, allowing smooth transitions in response to commands or external triggers.
## Structure: 
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
## Build Instructions: 
```
make build
make run
```

