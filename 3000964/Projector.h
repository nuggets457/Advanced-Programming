#ifndef PROJECTOR_H
#define PROJECTOR_H
#include "Device.h"
using namespace std;

// Projector device - input source and brightness
class Projector : public Device {
private:
    string inputSource;    // VGA, HDMI, wireless
    int brightnessLevel;   // 0-100%

public:
    Projector(int id, const string& name, const string& mfg,
        const string& input, int brightness);

    void InteractionEvent() override;
    void ViewInfo() const override;
    void EditSettings() override;
    string GetQualityOrSetting() const override;

    string GetInputSource() const { return inputSource; }
    int GetBrightnessLevel() const { return brightnessLevel; }
    void SetInputSource(const string& input) { inputSource = input; }
    void SetBrightnessLevel(int brightness);
};

#endif