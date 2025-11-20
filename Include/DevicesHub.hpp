/* =====================================================================================
Singleton Design Pattern:
To ensure that there is a single, centralized hub managing all devices.
======================================================================================== */

#ifndef DEVICESHUB_HPP
#define DEVICESHUB_HPP

#include <memory>
#include <vector>
#include <iostream>
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
    std::vector<std::shared_ptr<Device>> devices;
    static std::shared_ptr<DevicesHub> instance;
    DevicesHub() {}

public:
    static std::shared_ptr<DevicesHub> getInstance();
    
    void registerDevice(std::shared_ptr<Device> device);
    void listDevices();
    
};

#endif