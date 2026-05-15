#include "Device.h"
#include "Constants.h"
#include <iostream>
using namespace std;

// Constructor - Initialize device with ID, name, and manufacturer
// By default all devices are inactive (status = false) but connected (connectionStatus = true)
// Parameters:
//   - id: unique device identifier
//   - name: device name for display
//   - mfg: manufacturer name
Device::Device(int id, const string& name, const string& mfg)
    : deviceID(id), deviceName(name), manufacturer(mfg), status(false), connectionStatus(true) {
    // All new devices start inactive but connected
}

// Turn on the device
// Displays confirmation message when device is activated
void Device::Activate() {
    status = true;  // Set status to active
    cout << "[+] " << deviceName << " activated." << endl;
}

// Turn off the device
// Displays confirmation message when device is deactivated
void Device::Deactivate() {
    status = false;  // Set status to inactive
    cout << "[-] " << deviceName << " deactivated." << endl;
}

// Check if device is connected to network
// Returns true if connected, false if disconnected
bool Device::CheckConnection() const {
    return connectionStatus;
}

// Set device connection status
// Allows simulating network connection/disconnection events
// Parameters:
//   - connected: true for connected, false for disconnected
void Device::SetConnectionStatus(bool connected) {
    connectionStatus = connected;
}