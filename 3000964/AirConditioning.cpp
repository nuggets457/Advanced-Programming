#include "AirConditioning.h"
#include "Constants.h"
#include <iostream>
using namespace std;

AirConditioning::AirConditioning(int id, const string& name, const string& mfg, int tempTarget)
    : Device(id, name, mfg), targetTemperature(tempTarget) {
    // Initialize parent class and set target temperature
}

string AirConditioning::GetQualityOrSetting() const {
    return "Temp: " + to_string(targetTemperature) + " C";
}

void AirConditioning::InteractionEvent() {
    if (!status) {
        cout << MSG_ACTIVATE_FIRST << "\n";
        return;
    }

    int userInput;
    cout << "\n--- Air Conditioner Control ---\n";
    cout << "Current target temperature: " << targetTemperature << " C\n";
    cout << "Enter new target temperature: ";
    cin >> userInput;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(Limits::INPUT_BUFFER_SIZE, '\n');
        cout << MSG_INVALID_INPUT << "\n";
        return;
    }

    if (userInput < Temperature::MIN_TEMP || userInput > Temperature::MAX_TEMP) {
        cout << MSG_INVALID_TEMP << "\n";
        return;
    }

    targetTemperature = userInput;
    cout << "Target temperature set to " << targetTemperature << " C\n";
}

void AirConditioning::EditSettings() {
    cout << "\n--- Edit Air Conditioner ---\n";
    cout << "Current temperature: " << targetTemperature << " C\n";
    int temp;
    cout << "Enter new target temperature (in Celsius): ";
    cin >> temp;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(Limits::INPUT_BUFFER_SIZE, '\n');
        cout << "[!] " << MSG_INVALID_INPUT << "\n";
        return;
    }

    if (temp < Temperature::MIN_TEMP || temp > Temperature::MAX_TEMP) {
        cout << "[!] " << MSG_INVALID_TEMP << "\n";
        return;
    }

    targetTemperature = temp;
    cout << "[+] Target temperature updated to: " << targetTemperature << " C\n";
}

void AirConditioning::ViewInfo() const {
    cout << "\n--- Air Conditioning Information ---\n";
    cout << "ID: " << deviceID << "\nName: " << deviceName << "\n";
    cout << "Manufacturer: " << manufacturer << "\n";
    cout << "Status: " << (status ? "Active" : "Inactive") << "\n";
    cout << "Connected: " << (connectionStatus ? "Yes" : "No") << "\n";
    cout << "Target Temperature: " << targetTemperature << " C\n";
}