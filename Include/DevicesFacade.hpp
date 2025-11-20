/* ==========================================================================================================
Facade Design Pattern:
To provide a simplified interface to a complex subsystem involving multiple device types and their factories.
============================================================================================================= */

#ifndef DEVICESFACADE_HPP
#define DEVICESFACADE_HPP

#include <memory>
#include "Devices.hpp"
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <functional>
#include <mutex>

// Simple command representation used by the facade for queued operations
struct FacadeCommand {
	std::function<void()> execute;
	std::function<void()> undo;
	std::string description;
};

class DevicesFacade {
public:
	DevicesFacade();
	~DevicesFacade();

	// Device registration
	void addDevice(const std::string &id, std::shared_ptr<Device> device, const std::string &group = "");
	void removeDevice(const std::string &id);

	// Group management
	void addDeviceToGroup(const std::string &group, const std::string &deviceId);
	void removeDeviceFromGroup(const std::string &group, const std::string &deviceId);

	// Basic operations (device-level)
	void turnOnDevice(const std::string &id);
	void turnOffDevice(const std::string &id);
	std::string getDeviceStatus(const std::string &id);

	// Group operations
	void turnOnGroup(const std::string &group);
	void turnOffGroup(const std::string &group);
	std::vector<std::string> getGroupStatus(const std::string &group);

	// Command queue / automation support
	void enqueueCommand(FacadeCommand cmd);
	bool processNextCommand();
	bool undoLastCommand();

	// Introspection
	std::vector<std::string> listGroups();
	std::vector<std::string> listDevices();

private:
	std::unordered_map<std::string, std::shared_ptr<Device>> devices_;
	std::unordered_map<std::string, std::vector<std::string>> groups_;

	std::queue<FacadeCommand> commandQueue_;
	std::vector<FacadeCommand> history_;

	std::mutex mtx_;

	// Helpers
	std::shared_ptr<Device> findDeviceLocked(const std::string &id);
	void ensureGroupExistsLocked(const std::string &group);
};
#endif
