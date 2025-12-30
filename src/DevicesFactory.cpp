#include "DevicesFactory.hpp"

// ------------------- XiaomiFactory Methods Implementation ------------------- //

std::shared_ptr <Light> XiaomiFactory::getHalogenLight() {
    return std::make_shared<HalogenLight>();
}
std::shared_ptr <Light> XiaomiFactory::getLedLight() {
    return  std::make_shared<XiaomiLedLight>();
}
std::shared_ptr <SmartThermostat> XiaomiFactory::getThermostatA() {
    return std::make_shared<XiaomiSmartThermostatA>();
}
std::shared_ptr <SmartThermostat> XiaomiFactory::getThermostatB() {
    return std::make_shared<XiaomiSmartThermostatB>();
}
std::shared_ptr <SecurityCamera> XiaomiFactory::getWirelessCamera() {
    return std::make_shared<XiaomiWirelessCamera>();
}
std::shared_ptr <SecurityCamera> XiaomiFactory::getWiredCamera() {
    return std::make_shared<XiaomiWiredCamera>();
}


// ------------------- SamsungFactory Methods Implementation ------------------- //

std::shared_ptr <Light> SamsungFactory::getHalogenLight() {
    return std::make_shared<HalogenLight>();
}
std::shared_ptr <Light> SamsungFactory::getLedLight() {
    return  std::make_shared<SamsungLedLight>();
}
std::shared_ptr <SmartThermostat> SamsungFactory::getThermostatA() {
    return std::make_shared<SamsungSmartThermostatA>();
}
std::shared_ptr <SmartThermostat> SamsungFactory::getThermostatB() {
    return std::make_shared<SamsungSmartThermostatB>();
}
std::shared_ptr <SecurityCamera> SamsungFactory::getWirelessCamera() {
    return std::make_shared<SamsungWirelessCamera>();
}
std::shared_ptr <SecurityCamera> SamsungFactory::getWiredCamera() {
    return std::make_shared<SamsungWiredCamera>();
}

// ------------------- MotionSensorFactory1 and 2 Methods Implementation ------------------- //
std::shared_ptr<MotionSensor> MotionSensorFactory1::createSensor() {
    return std::make_shared<MotionSensor>();
}   

std::shared_ptr<MotionSensor> MotionSensorFactory2::createSensor() {
    return std::make_shared<MotionSensor>();
} 

// ------------------- DoorLockFactory Methods Implementation ------------------- //
std::shared_ptr<DoorLock> DoorLockFactory1::createLock() {
    return std::make_shared<DoorLock>();
}
