#include "MenuUI.h"

// Display main menu with all available operations
// Shows 12 different options for system control
void MenuUI::DisplayMainMenu() {
    cout << "\n";
    cout << "-|----------------------------------------------------------------------------------------------------|-\n";
    cout << "-|                                SMART CAMPUS SYSTEM MAIN MENU                                       |-\n";
    cout << "-|----------------------------------------------------------------------------------------------------|-\n";
    cout << "-|  1. Add New Device                                                                                 |-\n";
    cout << "-|  2. View All Devices                                                                               |-\n";
    cout << "-|  3. Activate All Devices                                                                           |-\n";
    cout << "-|  4. Deactivate All Devices                                                                         |-\n";
    cout << "-|  5. Interact With All Devices                                                                      |-\n";
    cout << "-|  6. Control Each Device                                                                            |-\n";
    cout << "-|  7. Interact With Single Device                                                                    |-\n";
    cout << "-|  8. Edit Device                                                                                    |-\n";
    cout << "-|  9. Delete Device                                                                                  |-\n";
    cout << "-| 10. View Connected Devices                                                                         |-\n";
    cout << "-| 11. Change Device Connection Status                                                                |-\n";
    cout << "-| 12. Exit                                                                                           |-\n";
    cout << "-|----------------------------------------------------------------------------------------------------|-\n";
    cout << "Select an option (1-12): ";
}

// Display menu for selecting device type when adding new device
// Shows 5 device types available in the system
void MenuUI::DisplayAddDeviceMenu() {
    cout << "\n-|-----------------------------|-\n";
    cout << "-|      Add New Device         |-\n";
    cout << "-|-----------------------------|-\n";
    cout << "-| 1. Security Camera          |-\n";
    cout << "-| 2. Air Conditioner          |-\n";
    cout << "-| 3. Projector                |-\n";
    cout << "-| 4. Room Lighting            |-\n";
    cout << "-| 5. Door Lock                |-\n";
    cout << "-|-----------------------------|-\n";
    cout << "Select device type (1-5): ";
}

// Display device control options
// Shows options to activate, deactivate, or edit a device
void MenuUI::DisplayDeviceControlMenu() {
    cout << "\n-|--- Control Options ---|-\n";
    cout << "-|  1. Activate            |-\n";
    cout << "-|  2. Deactivate          |-\n";
    cout << "-|  3. Edit Quality/Setting|-\n";
    cout << "-|Select option (1-3):     |-\n";
}

// Display projector-specific menu
// Shows options for configuring projector settings
void MenuUI::DisplayProjectorMenu() {
    cout << "\n-|--- Projector Configuration ---|-\n";
    cout << "-|1. Set Input Source             |-\n";
    cout << "-|2. Set Brightness Level         |-\n";
    cout << "-|3. View Current Settings        |-\n";
    cout << "-|Enter your choice:              |-\n";
}

// Display door lock-specific menu
// Shows options for controlling door lock
void MenuUI::DisplayDoorLockMenu() {
    cout << "\n-|--- Door Lock Control ---|-\n";
    cout << "-|1. View Status             |-\n";
    cout << "-|2. Lock Door               |-\n";
    cout << "-|3. Unlock Door             |-\n";
    cout << "-|Enter your choice:         |-\n";
}

// Display device table header with column titles
// Shows column headers for device listing table
void MenuUI::DisplayDeviceTableHeader() {
    cout << "\n-|-----|------------------------|----------------------|----------------------|-------------------------|-------------|-\n";
    cout << "  -| ID  | Name                     | Manufacturer         | Status               | Quality/Setting         | Conn.       |-\n";
    cout << "  -|-----|--------------------------|----------------------|----------------------|-------------------------|-------------|-\n";
}

// Display device table footer
// Shows closing line for device listing table
void MenuUI::DisplayDeviceTableFooter() {
    cout << "-|-----|--------------------------|----------------------|----------------------|--------------------------|-------------|-\n";
}

// Display success message with [+] prefix
// Used to confirm successful operations
// Parameters:
//   - message: the success message to display
void MenuUI::ShowSuccessMessage(const string& message) {
    cout << "[+] " << message << "\n";
}

// Display error message with [!] prefix
// Used to show error conditions
// Parameters:
//   - message: the error message to display
void MenuUI::ShowErrorMessage(const string& message) {
    cout << "[!] ERROR: " << message << "\n";
}

// Display info message with [*] prefix
// Used for general information display
// Parameters:
//   - message: the info message to display
void MenuUI::ShowInfoMessage(const string& message) {
    cout << "[*] " << message << "\n";
}

// Display separator line
// Used for visual organization between sections
void MenuUI::DisplaySeparator() {
    cout << "\n";
}

// Display welcome message at startup
// Shows welcome banner when system starts
void MenuUI::DisplayWelcome() {
    cout << "\n";
    cout << "-|-|----------------------------------|-|-\n";
    cout << "-|-|  WELCOME TO SMART CAMPUS SYSTEM  |-|-\n";
    cout << "-|-|                                  |-|-\n";
    cout << "-|-|   A proof-of-concept for smart   |-|-\n";
    cout << "-|-|        device management         |-|-\n";
    cout << "-|-|                                  |-|-\n";
    cout << "-|-|----------------------------------|-|-\n";
}

// Display goodbye message at exit
// Shows goodbye banner when user exits system
void MenuUI::DisplayGoodbye() {
    cout << "\n";
    cout << "-|-|-----------------------------------------|-|-\n";
    cout << "-|-|  Thank you for using the Smart Campus   |-|-\n";
    cout << "-|-|  System!                                |-|-\n";
    cout << "-|-|                                         |-|-\n";
    cout << "-|-|  Goodbye!                               |-|-\n";
    cout << "-|-|-----------------------------------------|-|-\n";
}