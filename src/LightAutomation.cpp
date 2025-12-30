#include "LightAutomation.hpp"
#include "Devices.hpp"

#include <memory>

bool EnergySavingMode::decide() {
    // Example: in energy saving mode we prefer to keep lights off unless
    // some external condition (motion, low ambient light) is met. The
    // real sensor checks are left to the automation engine; for the demo
    // return false to indicate "don't force ON".
    return false;
}

bool ComfortMode::decide() {
    // Comfort mode favors being ON; demo returns true.
    return true;
}


void LightOnState::handleOnPress(std::shared_ptr<Device> /*device*/) {
    // Already on, do nothing
}

void LightOnState::handleOffPress(std::shared_ptr<Device> device) {
    device->turnOff();
    device->setState(std::make_shared<LightOffState>());
}

void LightOnState::handleDimCommand(std::shared_ptr<Device> dev) {
    auto device = std::dynamic_pointer_cast<Light>(dev);
    if (device) {
        device->setBrightness(50);
        device->setState(std::make_shared<LightDimmedState>());
    }
}

// ---------------- LightDimmedState ----------------
void LightDimmedState::handleOnPress(std::shared_ptr<Device> dev) {
    auto device = std::dynamic_pointer_cast<Light>(dev);
    if (device) {
        device->setBrightness(100);
        device->turnOn();
        device->setState(std::make_shared<LightOnState>());
    }
}

void LightDimmedState::handleOffPress(std::shared_ptr<Device> dev) {
    auto device = std::dynamic_pointer_cast<Light>(dev);
    if (device) {
        device->turnOff();
        device->setState(std::make_shared<LightOffState>());
    }
}

void LightDimmedState::handleDimCommand(std::shared_ptr<Device> dev) {
    auto device = std::dynamic_pointer_cast<Light>(dev);
    if (device) {
        // further dim
        int level = 30;
        device->setBrightness(level);
    }
}

// ---------------- LightOffState ----------------
void LightOffState::handleOnPress(std::shared_ptr<Device> dev) {
    auto device = std::dynamic_pointer_cast<Light>(dev);
    if (device) {
        device->turnOn();
        device->setState(std::make_shared<LightOnState>());
    }
}

void LightOffState::handleOffPress(std::shared_ptr<Device> /*device*/) {
    // already off
}

void LightOffState::handleDimCommand(std::shared_ptr<Device> dev) {
    auto device = std::dynamic_pointer_cast<Light>(dev);
    if (device) {
        device->setBrightness(30);
        device->setState(std::make_shared<LightDimmedState>());
    }
}