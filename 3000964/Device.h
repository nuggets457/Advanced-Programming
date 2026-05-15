#ifndef DEVICE_H
#define DEVICE_H
#include <string>
using namespace std;

// Base class for all smart devices in the Smart Campus System
// Provides common interface and functionality for all device types
// Uses virtual methods to enable polymorphic behavior
class Device {
protected:
    // Protected members - accessible by derived classes
    int deviceID;             // Unique identifier for the device
    string deviceName;        // Device name/label
    string manufacturer;      // Manufacturer information
    bool status;              // Active/Inactive state
    bool connectionStatus;    // Connected/Disconnected state

public:
    // Constructor - Initialize device with basic information
    Device(int id, const string& name, const string& mfg);

    // Virtual destructor - ensures proper cleanup of derived classes
    virtual ~Device() = default;

    // Virtual methods - each device implements these according to its type
    virtual void Activate();                                    // Turn device on
    virtual void Deactivate();                                  // Turn device off
    virtual void InteractionEvent() = 0;                        // Handle user interaction
    virtual void ViewInfo() const = 0;                          // Display device information
    virtual string GetQualityOrSetting() const { return "-"; }  // Return device-specific info
    virtual void EditSettings() = 0;                            // Edit device configuration

    // Connection management methods
    virtual bool CheckConnection() const;                       // Check if device is connected
    virtual void SetConnectionStatus(bool connected);           // Update connection status

    // Getter methods - retrieve device properties
    int GetDeviceID() const { return deviceID; }
    string GetDeviceName() const { return deviceName; }
    string GetManufacturer() const { return manufacturer; }
    bool GetStatus() const { return status; }
    bool GetConnectionStatus() const { return connectionStatus; }

    // Setter methods - modify device properties
    void SetDeviceName(const string& name) { deviceName = name; }
    void SetManufacturer(const string& mfg) { manufacturer = mfg; }
};

#endif