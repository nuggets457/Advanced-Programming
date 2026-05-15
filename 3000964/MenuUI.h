#ifndef MENUUI_H
#define MENUUI_H

#include <string>
#include <iostream>
using namespace std;

// Menu UI class - handles all menu displays and user interface design
// Separates UI presentation from business logic
// Provides static methods for displaying various menus and messages
class MenuUI {
public:
    // ========== MAIN MENU DISPLAYS ==========

    // Display main menu with all system options
    static void DisplayMainMenu();

    // Display device type selection menu
    static void DisplayAddDeviceMenu();

    // Display device control options menu
    static void DisplayDeviceControlMenu();

    // Display projector interaction menu
    static void DisplayProjectorMenu();

    // Display door lock interaction menu
    static void DisplayDoorLockMenu();

    // ========== TABLE DISPLAY METHODS ==========

    // Display device listing header (column titles)
    static void DisplayDeviceTableHeader();

    // Display device listing footer (closing line)
    static void DisplayDeviceTableFooter();

    // ========== MESSAGE DISPLAYS ==========

    // Display success message with [+] prefix
    static void ShowSuccessMessage(const string& message);

    // Display error message with [!] prefix
    static void ShowErrorMessage(const string& message);

    // Display info message with [*] prefix
    static void ShowInfoMessage(const string& message);

    // Display separator line for visual organization
    static void DisplaySeparator();

    // Display welcome message at startup
    static void DisplayWelcome();

    // Display goodbye message at exit
    static void DisplayGoodbye();
};

#endif