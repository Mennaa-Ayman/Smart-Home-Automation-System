/* =====================================================================================
Singleton Design Pattern:
To ensure that there is a single, centralized hub managing all devices.
======================================================================================== */

#ifndef DEVICESHUB_HPP
#define DEVICESHUB_HPP

#include <memory>
#include "Devices.hpp"
#include "DevicesFactory.hpp"

enum class DeviceType {
    LedLight,
    HalogenLight,
    TypeAThermostat,
    TypeBThermostat,
    WirelessCamera,
    WiredCamera,
};

class DevicesHub {
private:
    static std::shared_ptr<DevicesHub> instance;
    DevicesHub() {}

public:
    static std::shared_ptr<DevicesHub> getInstance();
    
    std::shared_ptr<DoorLock> getDoorLock();
    std::shared_ptr<MotionSensor> getMotionSensor();
    
};

#endif