#include "DevicesFacade.hpp"

DevicesFacade::DevicesFacade() {
    myHub = DevicesHub::getInstance();
    lightGroup = std::make_shared<LightingGroup>();
    secGroup = std::make_shared<SecurityGroup>();
    // Controller = std::make_shared<DeviceController>();
}

std::shared_ptr<Light> DevicesFacade::getLight(Brand brand, LightType type,std::shared_ptr<RoomDevices> roomGroup) {
    std::shared_ptr<Light> light;

    if (type == LightType::Led) {
        if (brand == Brand::Samsung) {
            light = std::make_shared<SamsungLedLight>();
        } else if (brand == Brand::Xiaomi) {
            light = std::make_shared<XiaomiLedLight>();
        }
    } else if (type == LightType::Halogen) {
            light = std::make_shared<HalogenLight>();
        }
    myHub->registerDevice(light);
    lightGroup->addDevice(light);
    HouseDevices.push_back(light);
    if(roomGroup){
        roomGroup->addDevice(light);
    }
    return light;
}

std::shared_ptr<SmartThermostat> DevicesFacade::getThermostat(Brand brand, ThermostatType type,std::shared_ptr<RoomDevices> roomGroup) {
    std::shared_ptr<SmartThermostat> thermostat;

    if (brand == Brand::Samsung) {
        if (type == ThermostatType::TypeA) {
            thermostat = std::make_shared<SamsungSmartThermostatA>();
        } else if (type == ThermostatType::TypeB) {
            thermostat = std::make_shared<SamsungSmartThermostatB>();
        }
    } else if (brand == Brand::Xiaomi) {
        if (type == ThermostatType::TypeA) {
            thermostat = std::make_shared<XiaomiSmartThermostatA>();
        } else if (type == ThermostatType::TypeB) {
            thermostat = std::make_shared<XiaomiSmartThermostatB>();
        }
    }
    myHub->registerDevice(thermostat);
    HouseDevices.push_back(thermostat);
    if(roomGroup){
        roomGroup->addDevice(thermostat);
    }
    return thermostat;
}

std::shared_ptr<SecurityCamera> DevicesFacade::getCamera(Brand brand, CameraType type,std::shared_ptr<RoomDevices> roomGroup) {
    std::shared_ptr<SecurityCamera> camera;

    if (brand == Brand::Samsung) {
        if (type == CameraType::Wireless) {
            camera = std::make_shared<SamsungWirelessCamera>();
        } else if (type == CameraType::Wired) {
            camera = std::make_shared<SamsungWiredCamera>();
        }
    } else if (brand == Brand::Xiaomi) {
        if (type == CameraType::Wireless) {
            camera = std::make_shared<XiaomiWirelessCamera>();
        } else if (type == CameraType::Wired) {
            camera = std::make_shared<XiaomiWiredCamera>();
        }
    }
    myHub->registerDevice(camera);
    secGroup->addDevice(camera);
    HouseDevices.push_back(camera);
    if(roomGroup){
        roomGroup->addDevice(camera);
    }
    return camera;
}

std::shared_ptr<MotionSensor> DevicesFacade::getMotionSensor(std::shared_ptr<RoomDevices> roomGroup) {
    auto sensor = std::make_shared<MotionSensor>();
    myHub->registerDevice(sensor);
    secGroup->addDevice(sensor);
    HouseDevices.push_back(sensor);
    if(roomGroup){
        roomGroup->addDevice(sensor);
    }
    return sensor;
}

std::shared_ptr<DoorLock> DevicesFacade::getDoorLock(std::shared_ptr<RoomDevices> roomGroup) {
    auto doorLock =  std::make_shared<DoorLock>();
    myHub->registerDevice(doorLock);
    secGroup->addDevice(doorLock);
    HouseDevices.push_back(doorLock);
    if(roomGroup){
        roomGroup->addDevice(doorLock);
    }
    return doorLock;
}

void DevicesFacade::addRoom(std::shared_ptr<RoomDevices> room) {
    Rooms.push_back(room);
}
void DevicesFacade::addFloor(std::shared_ptr<FloorDevices> floor) {
    Floors.push_back(floor);
}
