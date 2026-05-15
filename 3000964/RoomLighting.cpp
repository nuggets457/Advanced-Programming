#include "RoomLighting.h"
#include "Constants.h"
#include <iostream>

using namespace std;

RoomLighting::RoomLighting(int id, const string& name, const string& mfg, int brightness)
    : Device(id, name, mfg), brightnessLevel(brightness) {
    // Initialize parent class and set brightness level
}

string RoomLighting::GetQualityOrSetting() const {
    return "Brightness: " + to_string(brightnessLevel) + "%";
}

void RoomLighting::SetBrightnessLevel(int brightness) {
    if (brightness < Brightness::MIN_BRIGHTNESS || brightness > Brightness::MAX_BRIGHTNESS) {
        cout << "Error: Brightness must be between " << Brightness::MIN_BRIGHTNESS
            << " and " << Brightness::MAX_BRIGHTNESS << ".\n";
        return;
    }
    brightnessLevel = brightness;
}

void RoomLighting::InteractionEvent() {
    if (!status) {
        cout << MSG_ACTIVATE_FIRST << "\n";
        return;
    }

    cout << "\n--- Room Lighting Control ---\n";
    cout << "Current brightness level: " << brightnessLevel << "%\n";
    cout << "Enter new brightness level (" << Brightness::MIN_BRIGHTNESS << "-"
        << Brightness::MAX_BRIGHTNESS << "): ";

    int brightness;
    cin >> brightness;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(Limits::INPUT_BUFFER_SIZE, '\n');
        cout << MSG_INVALID_INPUT << "\n";
        return;
    }

    SetBrightnessLevel(brightness);
    if (brightness >= Brightness::MIN_BRIGHTNESS && brightness <= Brightness::MAX_BRIGHTNESS) {
        cout << "Brightness set to " << brightnessLevel << "%\n";
    }
}

void RoomLighting::EditSettings() {
    cout << "\n--- Edit Room Lighting ---\n";
    cout << "Current brightness: " << brightnessLevel << "%\n";

    int brightness;
    cout << "Enter new brightness level (" << Brightness::MIN_BRIGHTNESS << "-"
        << Brightness::MAX_BRIGHTNESS << "): ";
    cin >> brightness;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(Limits::INPUT_BUFFER_SIZE, '\n');
        cout << "[!] " << MSG_INVALID_INPUT << "\n";
        return;
    }

    if (brightness < Brightness::MIN_BRIGHTNESS || brightness > Brightness::MAX_BRIGHTNESS) {
        cout << "[!] " << MSG_INVALID_BRIGHT << "\n";
        return;
    }

    brightnessLevel = brightness;
    cout << "[+] Brightness updated to: " << brightnessLevel << "%\n";
}

void RoomLighting::ViewInfo() const {
    cout << "\n--- Room Lighting Information ---\n";
    cout << "ID: " << deviceID << "\nName: " << deviceName << "\n";
    cout << "Manufacturer: " << manufacturer << "\n";
    cout << "Status: " << (status ? "Active" : "Inactive") << "\n";
    cout << "Connected: " << (connectionStatus ? "Yes" : "No") << "\n";
    cout << "Brightness Level: " << brightnessLevel << "%\n";
}