#include "DevicesHub.hpp"

// Initialize static singleton instance pointer
std::shared_ptr<DevicesHub> DevicesHub::instance = nullptr;

std::shared_ptr<DevicesHub> DevicesHub::getInstance() {
    if (!instance) {
        // Use private constructor via new inside the class scope
        instance = std::shared_ptr<DevicesHub>(new DevicesHub());
    }
    return instance;
}

void DevicesHub::registerDevice(std::shared_ptr<Device> device) {
    devices.push_back(device);
}

void DevicesHub::listDevices() {
    std::cout << "Registered Devices in Hub:" << std::endl;
    for (const auto& device : devices) {
        std::cout << "- " << device->getId() << std::endl;
    }
}
