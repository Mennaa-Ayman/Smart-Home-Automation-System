#include "DevicesFacade.hpp"
#include <algorithm>
#include <iostream>

DevicesFacade::DevicesFacade() {}

DevicesFacade::~DevicesFacade() {}

void DevicesFacade::addDevice(const std::string &id, std::shared_ptr<Device> device, const std::string &group){
	std::lock_guard<std::mutex> lk(mtx_);
	if(!device) return;
	devices_[id] = device;
	if(!group.empty()){
		ensureGroupExistsLocked(group);
		groups_[group].push_back(id);
	}
}

void DevicesFacade::removeDevice(const std::string &id){
	std::lock_guard<std::mutex> lk(mtx_);
	devices_.erase(id);
	for(auto &g : groups_){
		auto &vec = g.second;
		vec.erase(std::remove(vec.begin(), vec.end(), id), vec.end());
	}
}

void DevicesFacade::addDeviceToGroup(const std::string &group, const std::string &deviceId){
	std::lock_guard<std::mutex> lk(mtx_);
	if(devices_.find(deviceId) == devices_.end()) return;
	ensureGroupExistsLocked(group);
	auto &vec = groups_[group];
	if(std::find(vec.begin(), vec.end(), deviceId) == vec.end()) vec.push_back(deviceId);
}

void DevicesFacade::removeDeviceFromGroup(const std::string &group, const std::string &deviceId){
	std::lock_guard<std::mutex> lk(mtx_);
	auto it = groups_.find(group);
	if(it == groups_.end()) return;
	auto &vec = it->second;
	vec.erase(std::remove(vec.begin(), vec.end(), deviceId), vec.end());
}

std::shared_ptr<Device> DevicesFacade::findDeviceLocked(const std::string &id){
	auto it = devices_.find(id);
	if(it == devices_.end()) return nullptr;
	return it->second;
}

void DevicesFacade::turnOnDevice(const std::string &id){
	std::lock_guard<std::mutex> lk(mtx_);
	auto dev = findDeviceLocked(id);
	if(dev) dev->turnOn();
}

void DevicesFacade::turnOffDevice(const std::string &id){
	std::lock_guard<std::mutex> lk(mtx_);
	auto dev = findDeviceLocked(id);
	if(dev) dev->turnOff();
}

std::string DevicesFacade::getDeviceStatus(const std::string &id){
	std::lock_guard<std::mutex> lk(mtx_);
	auto dev = findDeviceLocked(id);
	if(dev) return dev->getStatus();
	return "(unknown device)";
}

void DevicesFacade::turnOnGroup(const std::string &group){
	std::lock_guard<std::mutex> lk(mtx_);
	auto it = groups_.find(group);
	if(it == groups_.end()) return;
	for(const auto &id : it->second){
		auto dev = findDeviceLocked(id);
		if(dev) dev->turnOn();
	}
}

void DevicesFacade::turnOffGroup(const std::string &group){
	std::lock_guard<std::mutex> lk(mtx_);
	auto it = groups_.find(group);
	if(it == groups_.end()) return;
	for(const auto &id : it->second){
		auto dev = findDeviceLocked(id);
		if(dev) dev->turnOff();
	}
}

std::vector<std::string> DevicesFacade::getGroupStatus(const std::string &group){
	std::lock_guard<std::mutex> lk(mtx_);
	std::vector<std::string> statuses;
	auto it = groups_.find(group);
	if(it == groups_.end()) return statuses;
	for(const auto &id : it->second){
		auto dev = findDeviceLocked(id);
		if(dev) statuses.push_back(dev->getStatus());
		else statuses.push_back("(unknown device)");
	}
	return statuses;
}

void DevicesFacade::enqueueCommand(FacadeCommand cmd){
	std::lock_guard<std::mutex> lk(mtx_);
	commandQueue_.push(std::move(cmd));
}

bool DevicesFacade::processNextCommand(){
	std::lock_guard<std::mutex> lk(mtx_);
	if(commandQueue_.empty()) return false;
	auto cmd = commandQueue_.front();
	commandQueue_.pop();
	if(cmd.execute) cmd.execute();
	history_.push_back(cmd);
	return true;
}

bool DevicesFacade::undoLastCommand(){
	std::lock_guard<std::mutex> lk(mtx_);
	if(history_.empty()) return false;
	auto cmd = history_.back();
	history_.pop_back();
	if(cmd.undo) cmd.undo();
	return true;
}

std::vector<std::string> DevicesFacade::listGroups(){
	std::lock_guard<std::mutex> lk(mtx_);
	std::vector<std::string> out;
	for(const auto &p : groups_) out.push_back(p.first);
	return out;
}

std::vector<std::string> DevicesFacade::listDevices(){
	std::lock_guard<std::mutex> lk(mtx_);
	std::vector<std::string> out;
	for(const auto &p : devices_) out.push_back(p.first);
	return out;
}

void DevicesFacade::ensureGroupExistsLocked(const std::string &group){
	if(groups_.find(group) == groups_.end()) groups_.emplace(group, std::vector<std::string>());
}
