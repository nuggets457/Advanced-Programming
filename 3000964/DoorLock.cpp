#include "DoorLock.h"
#include "Constants.h"
#include <iostream>
using namespace std;

DoorLock::DoorLock(int id, const string& name, const string& mfg, bool isLocked)
    : Device(id, name, mfg), locked(isLocked), lastOpenedBy("System") {
    // Initialize parent class and set lock-specific properties
}

string DoorLock::GetQualityOrSetting() const {
    return locked ? "State: LOCKED" : "State: UNLOCKED";
}

void DoorLock::SetLocked(bool lockState, const string& username) {
    locked = lockState;
    lastOpenedBy = username;
}

void DoorLock::InteractionEvent() {
    if (!status) {
        cout << MSG_ACTIVATE_FIRST << "\n";
        return;
    }

    int choice;
    cout << "\n--- Door Lock Control ---\n";
    cout << "1. View Status\n2. Lock Door\n3. Unlock Door\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(Limits::INPUT_BUFFER_SIZE, '\n');
        cout << MSG_INVALID_INPUT << "\n";
        return;
    }

    if (choice == Menu::LOCK_VIEW_STATUS) {
        cout << "Door is currently " << (locked ? "LOCKED" : "UNLOCKED") << "\n";
        cout << "Last opened by: " << lastOpenedBy << "\n";
    }
    else if (choice == Menu::LOCK_LOCK_DOOR) {
        string username;
        cout << "Enter username: ";
        cin >> username;
        SetLocked(true, username);
        cout << "Door locked by " << username << "\n";
    }
    else if (choice == Menu::LOCK_UNLOCK_DOOR) {
        string username;
        cout << "Enter username: ";
        cin >> username;
        SetLocked(false, username);
        cout << "Door unlocked by " << username << "\n";
    }
    else {
        cout << MSG_INVALID_OPTION << "\n";
    }
}

void DoorLock::EditSettings() {
    cout << "\n--- Edit Door Lock ---\n";
    cout << "Current state: " << (locked ? "LOCKED" : "UNLOCKED") << "\n";
    int lockState;
    cout << "Enter new state: 1 for Locked, 0 for Unlocked: ";
    cin >> lockState;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(Limits::INPUT_BUFFER_SIZE, '\n');
        cout << "[!] " << MSG_INVALID_INPUT << "\n";
        return;
    }

    if (lockState != Menu::UNLOCKED && lockState != Menu::LOCKED) {
        cout << "[!] Invalid lock state.\n";
        return;
    }

    string username;
    cout << "Enter username: ";
    cin.ignore();
    getline(cin, username);

    if (username.empty()) {
        cout << "[!] Username cannot be empty.\n";
        return;
    }

    SetLocked(lockState == Menu::LOCKED, username);
    cout << "[+] Lock state updated to: " << (lockState == Menu::LOCKED ? "Locked" : "Unlocked") << "\n";
}

void DoorLock::ViewInfo() const {
    cout << "\n--- Door Lock Information ---\n";
    cout << "ID: " << deviceID << "\nName: " << deviceName << "\n";
    cout << "Manufacturer: " << manufacturer << "\n";
    cout << "Status: " << (status ? "Active" : "Inactive") << "\n";
    cout << "Connected: " << (connectionStatus ? "Yes" : "No") << "\n";
    cout << "Lock State: " << (locked ? "LOCKED" : "UNLOCKED") << "\n";
    cout << "Last Opened By: " << lastOpenedBy << "\n";
}