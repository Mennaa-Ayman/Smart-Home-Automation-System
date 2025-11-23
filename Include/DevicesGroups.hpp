/* =========================================================================================
- Composite Design Pattern - Device Groups:
To treat individual devices and groups of devices uniformly.
============================================================================================ */

#ifndef DEVICESGROUPS_HPP
#define DEVICESGROUPS_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Devices.hpp"

using namespace std;

/* -------------------- Room Devices  -------------------- */
class RoomDevices : public Device {
private:
    string roomName;
    vector<shared_ptr<Device>> devices;
public:
    explicit RoomDevices(const string& rName): roomName(rName) {}
    void addDevice(shared_ptr<Device> device);
    void turnOn() override;
    void turnOff() override;
    void switchLights(bool on);
    string getRoomName() { return roomName; }
};

/* -------------------- Floor Devices -------------------- */
class FloorDevices : public Device {
private:
    string floorName;
    vector<shared_ptr<Device>> rooms;
public:
    explicit FloorDevices(const string& fName): floorName(fName) {};
    void addDevice(shared_ptr<Device> room);
    void turnOn() override;
    void turnOff() override;
    void switchLights(bool on);
    string getFloorName(){ return floorName; }
};

/* -------------------- Lighting Group  -------------------- */
class LightingGroup : public Device {
private:
    vector<shared_ptr<Device>> lights;
public:
    void addDevice(shared_ptr<Device> light);
    void turnOn() override;
    void turnOff() override;
};

/* -------------------- Security Group  -------------------- */
class SecurityGroup : public Device {
private:
    vector<shared_ptr<Device>> securityDevices;
public:
    void addDevice(shared_ptr<Device> secDevice);
    void turnOn() override;
    void turnOff() override;
};


#endif