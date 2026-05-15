#ifndef AIRCONDITIONING_H
#define AIRCONDITIONING_H
#include "Device.h"
using namespace std;

// Air Conditioner device class
// Inherits from Device base class
// Manages temperature settings and provides temperature control functionality
class AirConditioning : public Device {
private:
    int targetTemperature;     // Target temperature in Celsius

public:
    // Constructor - Initialize AC with target temperature
    // Parameters:
    //   - id: unique device identifier
    //   - name: device name
    //   - mfg: manufacturer name
    //   - tempTarget: initial target temperature in Celsius
    AirConditioning(int id, const string& name, const string& mfg, int tempTarget);

    // Virtual method overrides - implement base class pure virtual methods
    void InteractionEvent() override;           // Allow user to set temperature
    void ViewInfo() const override;             // Display AC information
    void EditSettings() override;               // Change temperature setting
    string GetQualityOrSetting() const override;  // Return temp as string for table display

    // Getter - retrieve current target temperature
    int GetTargetTemperature() const { return targetTemperature; }

    // Setter - update target temperature
    void SetTargetTemperature(int temp) { targetTemperature = temp; }
};

#endif