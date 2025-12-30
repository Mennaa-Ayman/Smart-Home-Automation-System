/* =====================================================================================
- Factoy Design Pattern:
To allow the system to treat individual devices and compositions of devices uniformly.

- Observer Design Pattern:
To enable devices to communicate:
    - Motion sensor notifies light → turn on
    - Door lock notifies Camerasecurity

======================================================================================== */

#ifndef DEVICES_HPP
#define DEVICES_HPP

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "LightAutomation.hpp"

// ---------------- Abstract Device Class ---------------- //
class Device{
protected:
    std::shared_ptr<State> state;
    std::string id;
public:
    void setState(std::shared_ptr<State> s) { this->state = s; }
    void setState(stateCode code) {
        // Create concrete State objects based on the enum. State is an
        // abstract base; constructing State directly is invalid.
        switch(code) {
            case stateCode::ON:
                this->state = std::make_shared<LightOnState>();
                break;
            case stateCode::OFF:
                this->state = std::make_shared<LightOffState>();
                break;
            case stateCode::DIMMED:
                this->state = std::make_shared<LightDimmedState>();
                break;
        }
    }
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Device() {}
    std::string getId() const { return id; }
};

// ---------------- Abstract Light Class ---------------- //
class Light : public Device {
protected:
    int brightnessLevel;
    std::shared_ptr<LightMode> mode;

public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void dim(int level) = 0;
    virtual ~Light() {}
    void update(bool on);
    void setBrightness(int level) { this->brightnessLevel = level; }
    void setMode(std::shared_ptr<LightMode> m) { this->mode = m; }
};

// ------------------ Concrete Light Classes < Variants > ---------------- //
class SamsungLedLight : public Light {
public:
    void turnOn() override;
    void turnOff() override;
    void dim(int level) override;
};

class XiaomiLedLight : public Light {
public:
    void turnOn() override;
    void turnOff() override;
    void dim(int level) override;
};

class HalogenLight : public Light {
public:
    void turnOn() override;
    void turnOff() override;
    void dim(int level) override;
};

// ------------------ Abstract Thermostat Class ---------------- //
class SmartThermostat : public Device{
protected:
    int temperature;
public:
    void turnOn() override;
    void turnOff() override;
    virtual void setTemperature(int temp);
    virtual void setMode(std::string mode) = 0;
    virtual ~SmartThermostat() {}
};

// ------------------ Concrete Thermostat Classes < Variants > ---------------- //
class SamsungSmartThermostatA : public SmartThermostat{
public:
    void setMode(std::string mode) override;
};

class SamsungSmartThermostatB : public SmartThermostat{
public:
    void setMode(std::string mode) override;
};

class XiaomiSmartThermostatA : public SmartThermostat{
public:
    void setMode(std::string mode) override;
};

class XiaomiSmartThermostatB : public SmartThermostat{
public:
    void setMode(std::string mode) override;
};

// ------------------ Abstract Security Camera Class ---------------- //
class SecurityCamera : public Device{
protected:
    bool isNightVisionEnabled;
public:
    virtual void switchMode()=0;
    void turnOn() override;
    void turnOff() override;

    // Base implementations are provided; not pure virtual so derived
    // concrete camera types can be instantiated without re-implementing
    // recording/nv behavior unless specialized.
    virtual void startRecording();
    virtual void stopRecording();

    void update(bool on);

    virtual void enableNightVision();
    virtual ~SecurityCamera() {}
};

// ------------------ Concrete Security Camera Classes ---------------- //
class XiaomiWirelessCamera : public SecurityCamera{
public:
    void switchMode() override;    
};

class SamsungWirelessCamera : public SecurityCamera{
public:
    void switchMode() override;
};

class SamsungWiredCamera : public SecurityCamera{
public:
    void switchMode() override;
};

class XiaomiWiredCamera : public SecurityCamera{
public:
    void switchMode() override;
};

// ------------------ Abstract Door Lock Class ---------------- //
class DoorLock : public Device{
protected:
    bool isLocked;
    std::vector<std::shared_ptr<SecurityCamera>> linkedCameras;

public:
    void lock();
    void unlock();
    void turnOn() override; 
    void turnOff() override; 
    ~DoorLock() {}
    void subscribe(std::shared_ptr<SecurityCamera> camera);
    void notify();
};


// =------------------ Abstract Motion Sensor Class ---------------- //
class MotionSensor : public Device{
protected:
    bool alertTriggered;
    std::vector<std::shared_ptr<Light>> linkedLights;

public:
    void sendAlert();
    void trigger();
    void turnOn() override;
    void turnOff() override;
    ~MotionSensor() {}
    void subscribe(std::shared_ptr<Light> light);
};

#endif