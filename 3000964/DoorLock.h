#ifndef DOORLOCK_H
#define DOORLOCK_H
#include "Device.h"
using namespace std;

// Smart Door Lock device class
// Inherits from Device base class
// Manages door lock state and security tracking
class DoorLock : public Device {
private:
    bool locked;               // Locked or unlocked state (true = locked, false = unlocked)
    string lastOpenedBy;       // Username of person who last accessed the door

public:
    // Constructor - Initialize door lock with lock state
    // Parameters:
    //   - id: unique device identifier
    //   - name: device name
    //   - mfg: manufacturer name
    //   - isLocked: initial lock state (true = locked, false = unlocked)
    DoorLock(int id, const string& name, const string& mfg, bool isLocked);

    // Virtual method overrides
    void InteractionEvent() override;           // Let user lock/unlock door
    void ViewInfo() const override;             // Show lock information
    void EditSettings() override;               // Change lock state
    string GetQualityOrSetting() const override;  // Return lock state as string

    // Getters - retrieve lock properties
    bool IsLocked() const { return locked; }
    string GetLastOpenedBy() const { return lastOpenedBy; }

    // Setter - change lock state with user tracking
    void SetLocked(bool lockState, const string& username);
};

#endif