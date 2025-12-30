#include "DevicesFacade.hpp"
#include "DevicesGroups.hpp"
#include "LightAutomation.hpp"

#include <memory>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main() {
	std::cout << "=== Smart Home Automation Demo ===" << std::endl;

	// Create facade (creates its own hub / groups)
	DevicesFacade facade;

	// Create Rooms and Floor
	auto livingRoom = std::make_shared<RoomDevices>("LivingRoom");
	auto bedroom = std::make_shared<RoomDevices>("Bedroom");
	auto firstFloor = std::make_shared<FloorDevices>("FirstFloor");

	// Register rooms/floors with facade
	facade.addRoom(livingRoom);
	facade.addRoom(bedroom);
	facade.addFloor(firstFloor);
	firstFloor->addDevice(livingRoom);
	firstFloor->addDevice(bedroom);

	std::cout << "\n-- Creating devices --" << std::endl;
	// Create Lights and attach them to rooms
	auto livingLight1 = facade.getLight(Brand::Samsung, LightType::Led, livingRoom);
	auto livingLight2 = facade.getLight(Brand::Xiaomi, LightType::Led, livingRoom);
	auto bedroomLight = facade.getLight(Brand::Samsung, LightType::Halogen, bedroom);

	livingLight1->setBrightness(80);
	livingLight2->setBrightness(70);
	bedroomLight->setBrightness(60);

	// Create Thermostat for living room
	auto livingThermo = facade.getThermostat(Brand::Samsung, ThermostatType::TypeA, livingRoom);
	livingThermo->setTemperature(21);
	livingThermo->setMode("Heating");

	// Create Security Camera and Door Lock and Motion Sensor
	auto livingCam = facade.getCamera(Brand::Samsung, CameraType::Wireless, livingRoom);
	auto frontDoor = facade.getDoorLock(livingRoom);
	auto hallwaySensor = facade.getMotionSensor(livingRoom);

	// Subscribe relationships: motion sensor -> lights, door lock -> camera
	hallwaySensor->subscribe(livingLight1);
	hallwaySensor->subscribe(livingLight2);
	frontDoor->subscribe(livingCam);

	std::cout << "\n-- Demonstrate manual operations --" << std::endl;
	livingLight1->turnOn();
	std::this_thread::sleep_for(300ms);
	livingLight2->dim(40);
	std::this_thread::sleep_for(300ms);
	bedroomLight->turnOff();

	std::cout << "\n-- Demonstrate motion sensor (trigger & alert) --" << std::endl;
	hallwaySensor->trigger();
	hallwaySensor->sendAlert();
	// In this demo the sensor does not automatically toggle lights, so simulate automation:
	std::cout << "Automation: turning ON lights in LivingRoom due to motion..." << std::endl;
	livingRoom->switchLights(true);

	std::cout << "\n-- Demonstrate security: door lock notify cameras --" << std::endl;
	frontDoor->lock();
	frontDoor->notify();
	std::this_thread::sleep_for(300ms);
	std::cout << "Simulating unexpected unlock while armed..." << std::endl;
	frontDoor->unlock();
	frontDoor->notify();

	std::cout << "\n-- Demonstrate automation modes (EnergySaving vs Comfort) --" << std::endl;
	auto energyMode = std::make_shared<EnergySavingMode>();
	auto comfortMode = std::make_shared<ComfortMode>();

	std::cout << "Applying EnergySavingMode to livingLight1" << std::endl;
	bool shouldOn = energyMode->decide();
	livingLight1->update(shouldOn);

	std::cout << "Applying ComfortMode to livingLight2" << std::endl;
	shouldOn = comfortMode->decide();
	livingLight2->update(shouldOn);

	std::cout << "\n-- Demonstrate group operations --" << std::endl;
	std::cout << "Turning off all lights on first floor..." << std::endl;
	firstFloor->switchLights(false);

	std::cout << "\nDemo finished. Listing devices registered in hub (IDs may be empty):" << std::endl;
	// The DevicesFacade contains its own hub; to list devices we would need access to it.
	// For now, create a local hub to illustrate listing (many devices already registered by facade internally).
	// NOTE: DevicesHub::getInstance() isn't used by the facade in this implementation.

	std::cout << "Goodbye." << std::endl;
	return 0;
}