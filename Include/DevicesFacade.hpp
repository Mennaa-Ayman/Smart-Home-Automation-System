/* ==========================================================================================================
Facade Design Pattern:
To provide a simplified interface to a complex subsystem involving multiple device types and their factories.
============================================================================================================= */

#ifndef DEVICESFACADE_HPP
#define DEVICESFACADE_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "Devices.hpp"
#include "DevicesHub.hpp"
#include "DevicesGroups.hpp"

enum class Brand {
    Samsung,
    Xiaomi
};  
enum class LightType{
    Led,
    Halogen
};
enum class ThermostatType{
    TypeA,
    TypeB
};
enum class CameraType{
    Wireless,
    Wired
};

class DevicesFacade {
private:
    std::shared_ptr<DevicesHub> myHub;
    std::vector<std::shared_ptr<Device>> HouseDevices;
    std::vector<std::shared_ptr<RoomDevices>> Rooms;
    std::vector<std::shared_ptr<FloorDevices>> Floors;
    std::shared_ptr<LightingGroup> lightGroup;
    std::shared_ptr<SecurityGroup> secGroup;
    // std::shared_ptr<DeviceController> Controller;
public:
    DevicesFacade();
    std::shared_ptr<Light> getLight(Brand brand, LightType type,std::shared_ptr<RoomDevices> roomGroup=nullptr);
    std::shared_ptr<SmartThermostat> getThermostat(Brand brand, ThermostatType type,std::shared_ptr<RoomDevices> roomGroup=nullptr);
    std::shared_ptr<SecurityCamera> getCamera(Brand brand, CameraType type,std::shared_ptr<RoomDevices> roomGroup=nullptr);
    std::shared_ptr<MotionSensor> getMotionSensor(std::shared_ptr<RoomDevices> roomGroup=nullptr);
    std::shared_ptr<DoorLock> getDoorLock(std::shared_ptr<RoomDevices> roomGroup=nullptr);
    void addRoom(std::shared_ptr<RoomDevices> room);
    void addFloor(std::shared_ptr<FloorDevices> floor);
};

#endif
