#include "DevicesHub.hpp"

void DevicesHub::registerDevice(std::shared_ptr<Device> device) {
    devices.push_back(device);
}

void DevicesHub::listDevices() {
    std::cout << "Registered Devices in Hub:" << std::endl;
    for (const auto& device : devices) {
        std::cout << "- " << device->getId() << std::endl;
    }
}
