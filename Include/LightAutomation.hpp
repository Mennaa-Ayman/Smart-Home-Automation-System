/* ====================================================================================
- Strategy Design Pattern: Automation modes for lights
- State Design Pattern:  For representing internal device states
======================================================================================= */

#ifndef LIGHT_AUTOMATION_HPP
#define LIGHT_AUTOMATION_HPP

#include <memory>

// Forward-declare Device to avoid circular includes between Devices and
// LightAutomation. Devices.hpp will include this header to obtain the
// State classes, so we only need a declaration here.
class Device;

// ------------------------------ Strategy Design Pattern ------------------------------- //
class LightMode{
public:
    virtual ~LightMode() {}
    virtual bool decide()=0; 
};

class EnergySavingMode : public LightMode{
public:
    bool decide()  override;
    
};  

class ComfortMode : public LightMode{
public:
    bool decide() override;
};

enum class stateCode {
    ON,
    OFF,
    DIMMED
};

// ---------------- State Design Pattern: For representing internal device states ---------------- //
class State {
public:
    virtual ~State() = default;
    virtual void handleOnPress(std::shared_ptr<Device> device) = 0;
    virtual void handleOffPress(std::shared_ptr<Device> device) = 0;
    virtual void handleDimCommand(std::shared_ptr<Device> device) = 0;
};

class LightOnState : public State {
public:
    void handleOnPress(std::shared_ptr<Device> device) override;
    void handleOffPress(std::shared_ptr<Device> device) override;
    void handleDimCommand(std::shared_ptr<Device> device) override;
};

class LightDimmedState : public State {
public:
    void handleOnPress(std::shared_ptr<Device> device) override;
    void handleOffPress(std::shared_ptr<Device> device) override;
    void handleDimCommand(std::shared_ptr<Device> device) override;
};

class LightOffState : public State {
public:
    void handleOnPress(std::shared_ptr<Device> device) override;
    void handleOffPress(std::shared_ptr<Device> device) override;
    void handleDimCommand(std::shared_ptr<Device> device) override;
};


#endif