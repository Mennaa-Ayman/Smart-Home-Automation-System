#include "Devices.hpp"

// =============================== Light Impementation =============================== //
void Light::update(bool on){
    if(on){
        turnOn();
    } else {
        turnOff();
    }
}
// ------------ SamsungLedLight Methods Implementation ------------ //
void SamsungLedLight::turnOn() {
    std::cout<< "Samsung LED Light turned ON." << "Brightness = " << brightnessLevel<<std::endl;
}

void SamsungLedLight::turnOff() {
    std::cout<< "Samsung LED Light turned OFF." << std::endl;
}

void SamsungLedLight::dim(int level) {
    brightnessLevel = level;
    std::cout << "Samsung LED Light dimmed to level " << brightnessLevel << std::endl;
}

// ------------ XiaomiLedLight Methods Implementation ------------ //
void XiaomiLedLight::turnOn() {
    std::cout<< "Xiaomi LED Light turned ON." << "Brightness = " << brightnessLevel<<std::endl;
}
void XiaomiLedLight::turnOff(){
    std::cout<< "Xiaomi LED Light turned OFF." << std::endl;
}
void XiaomiLedLight::dim(int level){
    brightnessLevel = level;
    std::cout << "Xiaomi LED Light dimmed to level " << brightnessLevel << std::endl;
}

// ---------------- HalogenLight Methods Implementation --------------------------- //
void HalogenLight::turnOn(){
    std::cout<< "Halogen Light turned ON." << "Brightness = " << brightnessLevel<<std::endl;

}
void HalogenLight::turnOff(){
    std::cout<<"Halogen Light is turned OFF." <<std::endl;
}
void HalogenLight::dim(int level){
    brightnessLevel = level;
    std::cout<< "Halogen Light dimmed to level " << brightnessLevel <<std::endl;
}

// ================================ Thermosat Implementation =============================== //
void SmartThermostat::turnOn(){
    std::cout << "Smart Thermostat turned ON." << std::endl;
}
void SmartThermostat::turnOff(){
    std::cout << "Smart Thermostat turned OFF." << std::endl;
}
void SmartThermostat::setTemperature(int temp){
    temperature = temp;
    std::cout << "Smart Thermostat temperature set to " << temperature << " degrees." << std::endl;
}
// -------------------------- Samsung Thermosat ---------------------- //
void SamsungSmartThermostatA::setMode(std::string mode){
    std::cout << "Samsung Smart Thermostat A mode set to " << mode << "with temprature " << temperature << std::endl;
}
void SamsungSmartThermostatB::setMode(std::string mode){
    std::cout << "Samsung Smart Thermostat B mode set to " << mode << "with temprature " << temperature << std::endl;
}

// ------------------------- Xiaomi Thermosat ---------------------- //
void XiaomiSmartThermostatA::setMode(std::string mode){
    std::cout << "Xiaomi Smart Thermostat A mode set to " << mode << "with temprature " << temperature << std::endl;
}
void XiaomiSmartThermostatB::setMode(std::string mode){
    std::cout << "Xiaomi Smart Thermostat B mode set to " << mode << "with temprature " << temperature << std::endl;
}

// ================================ Security Camera Implementation =============================== //
void SecurityCamera::turnOn(){
    std::cout << "Security Camera turned ON." << std::endl;
}
void SecurityCamera::turnOff(){
    std::cout << "Security Camera turned OFF." << std::endl;
}
void SecurityCamera::startRecording(){
    std::cout << "Security Camera starts recording." << std::endl;
}
void SecurityCamera::stopRecording(){
    std::cout << "Security Camera stops recording." << std::endl;
}
void SecurityCamera::enableNightVision(){
    isNightVisionEnabled = true;
    std::cout << "Night Vision enabled." << std::endl;
}
void SecurityCamera::update(bool on){
    if(on){
        startRecording();
    } else {
        stopRecording();
    }
}

// -------------------------- Xiaomi Cameras ---------------------- //
void XiaomiWirelessCamera::switchMode(){
    std::cout << "Xiaomi Wireless Camera switched mode." << std::endl;
}
void XiaomiWiredCamera::switchMode(){
    std::cout << "Xiaomi Wired Camera switched mode." << std::endl;
}
// -------------------------- Samsung Cameras ---------------------- //
void SamsungWirelessCamera::switchMode(){
    std::cout << "Samsung Wireless Camera switched mode." << std::endl;
}
void SamsungWiredCamera::switchMode(){
    std::cout << "Samsung Wired Camera switched mode." << std::endl;
}
// ================================ Door Lock Implementation =============================== //
void DoorLock::lock(){
    isLocked = true;
    std::cout << "Door is locked." << std::endl;
}
void DoorLock::unlock(){
    isLocked = false;
    std::cout << "Door is unlocked." << std::endl;
}

void DoorLock::turnOn() {
    // Interpret "turn on" as arming the lock (no-op wrapper)
    lock();
}

void DoorLock::turnOff() {
    // Interpret "turn off" as disarming the lock
    unlock();
}

void DoorLock::subscribe(std::shared_ptr<SecurityCamera> camera){
    linkedCameras.push_back(camera);
}
void DoorLock::notify(){
    for(const auto& camera : linkedCameras){
        camera->update(isLocked);
    }
}

// ================================ Motion Sensor Implementation =============================== //
void MotionSensor::trigger(){
    alertTriggered = true;
    std::cout << "Motion detected!" << std::endl;
}
void MotionSensor::sendAlert(){
    if(alertTriggered){
        std::cout << "Alert sent from Motion Sensor!" << std::endl;
        alertTriggered = false;
    } else {
        std::cout << "No motion detected. No alert sent." << std::endl;
    }
}
void MotionSensor::subscribe(std::shared_ptr<Light> light){
    linkedLights.push_back(light);
}

void MotionSensor::turnOn() {
    // No hardware concept of "power on" in this demo
    std::cout << "MotionSensor powered ON." << std::endl;
}

void MotionSensor::turnOff() {
    std::cout << "MotionSensor powered OFF." << std::endl;
}
