#include "DevicesGroups.hpp"

/* -------------------- Room Devices -------------------- */
void RoomDevices::addDevice(shared_ptr<Device> device) {
    devices.push_back(device);
}

void RoomDevices::turnOn() {
    std::cout << "Turning on all devices in room: " << roomName << std::endl;
    for (const auto& device : devices) {
        device->setState(stateCode::ON);
    }
}

void RoomDevices::turnOff() {
    std::cout << "Turning off all devices in room: " << roomName << std::endl;
    for (const auto& device : devices) {
        device->setState(stateCode::OFF);
    }
}
void RoomDevices::switchLights(bool on) {
    for (const auto& device : devices) {
        auto light = std::dynamic_pointer_cast<Light>(device);
        if (light) {
            if (on) {
                light->turnOn();
            } else {
                light->turnOff();
            }
        }
    }
}

/* -------------------- Floor Devices -------------------- */
void FloorDevices::addDevice(shared_ptr<Device> room) {
    rooms.push_back(room);
}
void FloorDevices::turnOn() {
    std::cout << "Turning on all devices on floor: " << floorName << std::endl;
    for (const auto& room : rooms) {
        room->setState(stateCode::ON);
    }
}
void FloorDevices::turnOff() {
    std::cout << "Turning off all devices on floor: " << floorName << std::endl;
    for (const auto& room : rooms) {
        room->setState(stateCode::OFF);
    }
}
void FloorDevices::switchLights(bool on) {
    for (const auto& room : rooms) {
        auto roomDevices = std::dynamic_pointer_cast<RoomDevices>(room);
        if (roomDevices) {
            roomDevices->switchLights(on);
        }
    }
}

// -------------------- Lighting Group -------------------- //
void LightingGroup::addDevice(shared_ptr<Device> light) {
    lights.push_back(light);
}
void LightingGroup::turnOn() {
    std::cout << "Turning on all lights in the lighting group." << std::endl;
    for (const auto& light : lights) {
        light->setState(stateCode::ON);
    }
}
void LightingGroup::turnOff() {
    std::cout << "Turning off all lights in the lighting group." << std::endl;
    for (const auto& light : lights) {
        light->setState(stateCode::OFF);
    }
}

// -------------------- Security Group -------------------- //
void SecurityGroup::addDevice(shared_ptr<Device> secDevice) {
    securityDevices.push_back(secDevice);
}
void SecurityGroup::turnOn() {
    std::cout << "Activating all security devices in the security group." << std::endl;
    for (const auto& secDevice : securityDevices) {
        secDevice->setState(stateCode::ON);
    }
}
void SecurityGroup::turnOff() {
    std::cout << "Deactivating all security devices in the security group." << std::endl;
    for (const auto& secDevice : securityDevices) {
        secDevice->setState(stateCode::OFF);
    }
}