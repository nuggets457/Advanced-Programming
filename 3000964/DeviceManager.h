#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <algorithm>
#include <string>
#include "Device.h"
#include "SecurityCamera.h"
#include "AirConditioning.h"
#include "Projector.h"
#include "RoomLighting.h"
#include "DoorLock.h"
#include "MenuUI.h"
#include "Constants.h"

using namespace std;

// MANAGER CLASS - Handles all device operations and system control
// Design Pattern: Manager Pattern + Polymorphism Pattern
// - Manages collection of Device pointers
// - Calls virtual methods without knowing actual device types
// - No dynamic_cast needed - pure polymorphic behavior
// - Uses MenuUI for all user interface displays
// - Uses raw pointers with manual memory management
class DeviceManager {
private:
    // Collection of devices - vector of raw Device pointers
    // We manually manage cleanup in destructor
    vector<Device*> devices;

    // ========== HELPER FUNCTIONS ==========

    // Clear input buffer after invalid input
    void ClearInputBuffer();

    // Validate integer input is within range
    bool ValidateIntInput(int& value, int minVal, int maxVal, const string& errorMsg);

    // Validate string input is not empty
    bool ValidateStringInput(const string& value, const string& fieldName);

    // ========== CORE OPERATIONS ==========

    // Add device to the system
    void AddDevice(Device* device);

    // Create and add new device (FACTORY PATTERN)
    void AddNewDevice();

    // View all devices in table format
    void ViewAllDevices() const;

    // Activate all devices in system
    void ActivateAllDevices();

    // Deactivate all devices in system
    void DeactivateAllDevices();

    // Interact with all active devices
    void InteractWithAllDevices();

    // Control specific device (activate/deactivate/edit)
    void ControlEachDevice();

    // Interact with single device
    void ControlSingleDevice(const string& action);

    // Edit device settings
    void EditDevice();

    // Delete device from system
    void DeleteDevice();

    // View connected vs disconnected devices
    void ViewConnectedDevices() const;

    // Change device connection status
    void ChangeDeviceConnectionStatus();

public:
    // Constructor - initialize empty device collection
    DeviceManager();

    // Destructor - clean up all allocated devices manually
    ~DeviceManager();

    // Main menu - entry point for entire system
    void DisplayMainMenu();
};

#endif