#include "Projector.h"
#include "Constants.h"
#include <iostream>
using namespace std;

Projector::Projector(int id, const string& name, const string& mfg,
    const string& input, int brightness)
    : Device(id, name, mfg), inputSource(input), brightnessLevel(brightness) {
    // Initialize parent class and set projector-specific properties
}

string Projector::GetQualityOrSetting() const {
    return "Input: " + inputSource + " | Brightness: " + to_string(brightnessLevel) + "%";
}

void Projector::SetBrightnessLevel(int brightness) {
    if (brightness < Brightness::MIN_BRIGHTNESS || brightness > Brightness::MAX_BRIGHTNESS) {
        cout << "Error: Brightness must be between " << Brightness::MIN_BRIGHTNESS
            << " and " << Brightness::MAX_BRIGHTNESS << ".\n";
        return;
    }
    brightnessLevel = brightness;
}

void Projector::InteractionEvent() {
    if (!status) {
        cout << MSG_ACTIVATE_FIRST << "\n";
        return;
    }

    int choice;
    cout << "\n--- Projector Configuration ---\n";
    cout << "1. Set Input Source\n2. Set Brightness Level\n3. View Current Settings\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(Limits::INPUT_BUFFER_SIZE, '\n');
        cout << MSG_INVALID_INPUT << "\n";
        return;
    }

    if (choice == Menu::PROJECTOR_SET_INPUT) {
        cout << "Current input source: " << inputSource << "\n";
        cout << "Enter new input source (VGA/HDMI/wireless): ";
        cin >> inputSource;
        cout << "Input source set to " << inputSource << "\n";
    }
    else if (choice == Menu::PROJECTOR_SET_BRIGHTNESS) {
        cout << "Current brightness: " << brightnessLevel << "%\n";
        cout << "Enter new brightness level (0-100): ";
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
    else if (choice == Menu::PROJECTOR_VIEW_SETTINGS) {
        cout << "Current Input Source: " << inputSource << "\n";
        cout << "Current Brightness: " << brightnessLevel << "%\n";
    }
    else {
        cout << MSG_INVALID_OPTION << "\n";
    }
}

void Projector::EditSettings() {
    cout << "\n--- Edit Projector ---\n";
    cout << "Current settings: Input: " << inputSource << " | Brightness: " << brightnessLevel << "%\n";
    string input;
    int brightness;

    cout << "Enter new input source (VGA/HDMI/wireless): ";
    cin.ignore();
    getline(cin, input);

    if (input.empty()) {
        cout << "[!] " << MSG_INVALID_INPUT << " Input source cannot be empty.\n";
        return;
    }

    cout << "Enter new brightness level (0-100): ";
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

    inputSource = input;
    brightnessLevel = brightness;
    cout << "[+] Projector settings updated.\n";
}

void Projector::ViewInfo() const {
    cout << "\n--- Projector Information ---\n";
    cout << "ID: " << deviceID << "\nName: " << deviceName << "\n";
    cout << "Manufacturer: " << manufacturer << "\n";
    cout << "Status: " << (status ? "Active" : "Inactive") << "\n";
    cout << "Connected: " << (connectionStatus ? "Yes" : "No") << "\n";
    cout << "Input Source: " << inputSource << "\nBrightness Level: " << brightnessLevel << "%\n";
}