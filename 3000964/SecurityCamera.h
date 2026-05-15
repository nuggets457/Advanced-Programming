#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H
#include "Device.h"
using namespace std;

// Security Camera device class
// Inherits from Device base class
// Manages camera resolution and power source settings
class SecurityCamera : public Device {
private:
    string cameraQuality;     // Resolution: 720p, 1080p, 2K, 4K
    string powerSource;       // Power source: mains, battery, battery+solar

public:
    // Constructor - Initialize security camera with quality and power settings
    // Parameters:
    //   - id: unique device identifier
    //   - name: device name
    //   - mfg: manufacturer name
    //   - quality: camera resolution (720p, 1080p, 2K, 4K)
    //   - power: power source type (mains, battery, battery+solar)
    SecurityCamera(int id, const string& name, const string& mfg,
        const string& quality, const string& power);

    // Virtual method overrides
    void InteractionEvent() override;           // View camera feed
    void ViewInfo() const override;             // Display camera information
    void EditSettings() override;               // Change camera resolution
    string GetQualityOrSetting() const override;  // Return quality and power as string

    // Getters - retrieve camera properties
    string GetCameraQuality() const { return cameraQuality; }
    string GetPowerSource() const { return powerSource; }

    // Setters - modify camera properties
    void SetCameraQuality(const string& quality) { cameraQuality = quality; }
};

#endif