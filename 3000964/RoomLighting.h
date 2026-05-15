#ifndef ROOMLIGHTING_H
#define ROOMLIGHTING_H
#include "Device.h"
using namespace std;

// Smart lights - controls brightness
class RoomLighting : public Device {
private:
    int brightnessLevel;  // 0-100%

public:
    RoomLighting(int id, const string& name, const string& mfg, int brightness);

    void InteractionEvent() override;
    void ViewInfo() const override;
    void EditSettings() override;
    string GetQualityOrSetting() const override;

    int GetBrightnessLevel() const { return brightnessLevel; }
    void SetBrightnessLevel(int brightness);
};

#endif