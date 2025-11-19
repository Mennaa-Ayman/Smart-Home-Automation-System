/* =====================================================================================
Composite Design Pattern:
To allow the system to treat individual devices and compositions of devices uniformly.
======================================================================================== */

#ifndef DEVICES_HPP
#define DEVICES_HPP

#include <string>
#include <memory>

// ---------------- Abstract Device Class ---------------- //
class Device{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual std::string getStatus() = 0;
    virtual ~Device() {}
};

// ---------------- Abstract Light Class ---------------- //
class Light : public Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void dim(int level) = 0;
    virtual ~Light() {}
};

// ------------------ Concrete Light Classes < Variants > ---------------- //
class SamsungLedLight : public Light {
public:
    void turnOn() override {}
    void turnOff() override {}
    std::string getStatus() override { return "Samsung LED Light Status"; }
    void dim(int level) override {}
};

class XiaomiLedLight : public Light {
public:
    void turnOn() override {}
    void turnOff() override {}
    std::string getStatus() override { return "Xiaomi LED Light Status"; }
    void dim(int level) override {}
};

class HalogenLight : public Light {
public:
    void turnOn() override {}
    void turnOff() override {}
    std::string getStatus() override { return "Halogen Light Status"; }
    void dim(int level) override {}
};

// ------------------ Abstract Thermostat Class ---------------- //
class SmartThermostat : public Device{
public:
    virtual void setTemperature(int temp) = 0;
    virtual void setMode(std::string mode) = 0;
    virtual ~SmartThermostat() {}
};

// ------------------ Concrete Thermostat Classes ---------------- //

class SmartThermostatA : public SmartThermostat{
public:
    void setTemperature(int temp) override {}
    void setMode(std::string mode) override {}
};

class SmartThermostatB : public SmartThermostat{
public:
    void setTemperature(int temp) override {}
    void setMode(std::string mode) override {}
};

// ------------------ Abstract Security Camera Class ---------------- //
class SecurityCamera : public Device{
public:
    virtual void startRecording() = 0;
    virtual void stopRecording() = 0;
    virtual void enableNightVision() = 0;
    virtual ~SecurityCamera() {}
};

// ------------------ Concrete Security Camera Classes ---------------- //
class wirelessCamera : public SecurityCamera{
public:
    void startRecording() override {}
    void stopRecording() override {}
    void enableNightVision() override {}
};

class wiredCamera : public SecurityCamera{
public:
    void startRecording() override {}
    void stopRecording() override {}
    void enableNightVision() override {}
};

// ------------------ Abstract Door Lock Class ---------------- //
class DoorLock : public Device{
public:
    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual ~DoorLock() {}
};

// =------------------ Abstract Motion Sensor Class ---------------- //
class MotionSensor : public Device{
public:
    virtual void sendAlert() = 0;
    virtual void trigger() = 0;
    virtual ~MotionSensor() {}
};

#endif