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

    virtual std::shared_ptr <SmartThermostat> getThermostat() = 0;
    virtual std::shared_ptr <SmartThermostat> getThermostatB() = 0;

    virtual std::shared_ptr <SecurityCamera> getWirelessCamera() = 0;
    virtual std::shared_ptr <SecurityCamera> getWiredCamera() = 0;
    
    virtual ~DeviceFactory() {}
};

// ----------------- Concrete Factory for Samsung ------------------- //
class SamsungFactory : public DeviceFactory {
public:
    std::shared_ptr <Light> getLedLight() override {
        return std::make_shared<Light>();
    }
    std::shared_ptr <SmartThermostat> getThermostat() override {
        return std::make_shared<SmartThermostatA>();
    }
};

// ----------------- Concrete Factory for Xiaomi ------------------- //
class XiaomiFactory : public DeviceFactory {
public:
    std::shared_ptr <Light> getLedLight() override {
        return  std::make_shared<XiaomiLedLight>();
    }
    std::shared_ptr <SmartThermostat> getThermostat() override {
        return std::make_shared<SmartThermostatB>();
    }
};
// ------------------- Factory Method for Motion Sensor ------------------- //
class MotionSensorFactoryInterface {
public:
    virtual std::shared_ptr<MotionSensor> createSensor() = 0;
};

class MotionSensorFactory : public MotionSensorFactoryInterface{
public:
    std::shared_ptr<MotionSensor> createSensor() override;
};

// ------------------- Factory Method for Door Lock ------------------- //
class DoorLockFactoryInterface {
public:
    virtual std::shared_ptr<DoorLock> createDoorLock() = 0;
};

class DoorLockFactory : public DoorLockFactoryInterface{
public:
    std::shared_ptr<DoorLock> createDoorLock() override;
};

#endif