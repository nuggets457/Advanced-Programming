#include "SecurityCamera.h"
#include "Constants.h"
#include <iostream>
using namespace std;

SecurityCamera::SecurityCamera(int id, const string& name, const string& mfg,
    const string& quality, const string& power)
    : Device(id, name, mfg), cameraQuality(quality), powerSource(power) {
    // Initialize parent class and set camera-specific properties
}

string SecurityCamera::GetQualityOrSetting() const {
    return "Quality: " + cameraQuality + " | Power: " + powerSource;
}

void SecurityCamera::InteractionEvent() {
    if (!status) {
        cout << MSG_ACTIVATE_FIRST << "\n";
        return;
    }

    cout << "Now viewing camera: " << deviceName << "\n";
    cout << "Current Resolution: " << cameraQuality << "\n";
    cout << "Feed is streaming...\n";
}

void SecurityCamera::EditSettings() {
    cout << "\n--- Edit Security Camera ---\n";
    cout << "Current resolution: " << cameraQuality << "\n";
    cout << "Select new resolution:\n";
    cout << "1. 720p\n2. 1080p\n3. 2K\n4. 4K\n";
    int q;
    cout << "Enter option (1-4): ";
    cin >> q;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(Limits::INPUT_BUFFER_SIZE, '\n');
        cout << "[!] " << MSG_INVALID_INPUT << "\n";
        return;
    }

    if (q < Menu::MIN_RESOLUTION || q > Menu::MAX_RESOLUTION) {
        cout << "[!] Invalid resolution option.\n";
        return;
    }

    switch (q) {
    case Menu::RESOLUTION_720P:
        cameraQuality = "720p";
        break;
    case Menu::RESOLUTION_1080P:
        cameraQuality = "1080p";
        break;
    case Menu::RESOLUTION_2K:
        cameraQuality = "2K";
        break;
    case Menu::RESOLUTION_4K:
        cameraQuality = "4K";
        break;
    }

    cout << "[+] Resolution updated to: " << cameraQuality << "\n";
}

void SecurityCamera::ViewInfo() const {
    cout << "\n--- Security Camera Information ---\n";
    cout << "ID: " << deviceID << " | Name: " << deviceName << "\n";
    cout << "Manufacturer: " << manufacturer << "\n";
    cout << "Status: " << (status ? "Active" : "Inactive") << "\n";
    cout << "Connected: " << (connectionStatus ? "Yes" : "No") << "\n";
    cout << "Quality: " << cameraQuality << " | Power: " << powerSource << "\n";
}