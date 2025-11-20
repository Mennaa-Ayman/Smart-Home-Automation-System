#include "LightAutomation.hpp"

bool EnergySavingMode::decide() {
    // Example: auto on if energy usage is low
    return true;
}

bool ComfortMode::decide() {
    // Example: always on for comfort lighting
    return false;
}


void LightOnState::handleOnPress(std::shared_ptr<Device> device) {
    // Already on, do nothing
}

void LightOnState::handleOffPress(std::shared_ptr<Device> device) {
    device->turnOff();
    device->setState(std::make_shared<LightOffState>());
}

void LightOnState::handleDimCommand(std::shared_ptr<Device> dev) {
    auto device = dynamic_pointer_cast<Light>(dev);
    device->setBrightness(50);
    device->setState(std::make_shared<LightDimmedState>());
}