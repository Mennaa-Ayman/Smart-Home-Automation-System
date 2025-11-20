/* ======================================================================================
1. Abstract Factory Design Pattern: 
To ensure that the system can support multiple brands or variants of the same device types 
without major changes to the core system like {Light, Thermostat, SecurityCamera}

2. Factory Method Design Pattern:
To allow the system to create specific types of devices like {DoorLock and MotionSensor}
========================================================================================= */

#ifndef DEVICESFACTORY_HPP
#define DEVICESFACTORY_HPP

#include <memory>
#include "Devices.hpp"

// ---------------- Abstract Factory Class ---------------- //
class DeviceFactory {
public:
    virtual std::shared_ptr <Light> getLedLight() = 0;
    virtual std::shared_ptr <Light> getHalogenLight() = 0;

    virtual std::shared_ptr <SmartThermostat> getThermostatA() = 0;
    virtual std::shared_ptr <SmartThermostat> getThermostatB() = 0;

    virtual std::shared_ptr <SecurityCamera> getWirelessCamera() = 0;
    virtual std::shared_ptr <SecurityCamera> getWiredCamera() = 0;
    
    virtual ~DeviceFactory() {}
};

// ----------------- Concrete Factory for Samsung ------------------- //
class SamsungFactory : public DeviceFactory {
public:
    std::shared_ptr <Light> getLedLight() override;
    std::shared_ptr <Light> getHalogenLight() override;

    std::shared_ptr <SmartThermostat> getThermostatA() override;
    std::shared_ptr <SmartThermostat> getThermostatB() override;

    std::shared_ptr <SecurityCamera> getWirelessCamera() override;
    std::shared_ptr <SecurityCamera> getWiredCamera() override;
};

// ----------------- Concrete Factory for Xiaomi ------------------- //
class XiaomiFactory : public DeviceFactory {
public:
    std::shared_ptr <Light> getLedLight() override;
    std::shared_ptr <Light> getHalogenLight() override;

    std::shared_ptr <SmartThermostat> getThermostatA() override;
    std::shared_ptr <SmartThermostat> getThermostatB() override;

    std::shared_ptr <SecurityCamera> getWirelessCamera() override;
    std::shared_ptr <SecurityCamera> getWiredCamera() override;

};

// ------------------- Factory Method for Motion Sensor ------------------- //
class MotionSensorFactory {
public:
    virtual std::shared_ptr<MotionSensor> createSensor() = 0;
};

class MotionSensorFactory1 : public MotionSensorFactory{
public:
    std::shared_ptr<MotionSensor> createSensor() override;
};

class MotionSensorFactory2 : public MotionSensorFactory{
public:
    std::shared_ptr<MotionSensor> createSensor() override;
};

// ------------------- Factory Method for Door Lock ------------------- //
class DoorLockFactory {
public:
    virtual std::shared_ptr<DoorLock> createLock() = 0;
};

class DoorLockFactory1 : public DoorLockFactory{
public:
    std::shared_ptr<DoorLock> createLock() override;
};

#endif