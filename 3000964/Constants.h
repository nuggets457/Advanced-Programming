#ifndef CONSTANTS_H
#define CONSTANTS_H

// ============================================================================
// TEMPERATURE SETTINGS
// ============================================================================
namespace Temperature {
    const int MIN_TEMP = -50;
    const int MAX_TEMP = 50;
}

// ============================================================================
// BRIGHTNESS SETTINGS
// ============================================================================
namespace Brightness {
    const int MIN_BRIGHTNESS = 0;
    const int MAX_BRIGHTNESS = 100;
}

// ============================================================================
// MENU OPTIONS
// ============================================================================
namespace Menu {
    // Main menu options
    const int ADD_DEVICE = 1;
    const int VIEW_DEVICES = 2;
    const int ACTIVATE_ALL = 3;
    const int DEACTIVATE_ALL = 4;
    const int INTERACT_ALL = 5;
    const int CONTROL_DEVICE = 6;
    const int INTERACT_DEVICE = 7;
    const int EDIT_DEVICE = 8;
    const int DELETE_DEVICE = 9;
    const int VIEW_CONNECTED = 10;
    const int CHANGE_CONNECTION = 11;
    const int EXIT = 12;
    const int MIN_OPTION = 1;
    const int MAX_OPTION = 12;

    // Device types
    const int CAMERA = 1;
    const int AC = 2;
    const int PROJECTOR = 3;
    const int LIGHTS = 4;
    const int LOCK = 5;
    const int MIN_TYPE = 1;
    const int MAX_TYPE = 5;

    // Control options
    const int ACTIVATE = 1;
    const int DEACTIVATE = 2;
    const int EDIT = 3;

    // Door lock states
    const int LOCKED = 1;
    const int UNLOCKED = 0;

    // Connection states
    const int CONNECTED = 1;
    const int DISCONNECTED = 0;

    // Camera resolution options
    const int RESOLUTION_720P = 1;
    const int RESOLUTION_1080P = 2;
    const int RESOLUTION_2K = 3;
    const int RESOLUTION_4K = 4;
    const int MIN_RESOLUTION = 1;
    const int MAX_RESOLUTION = 4;

    // Projector menu options
    const int PROJECTOR_SET_INPUT = 1;
    const int PROJECTOR_SET_BRIGHTNESS = 2;
    const int PROJECTOR_VIEW_SETTINGS = 3;

    // Door lock menu options
    const int LOCK_VIEW_STATUS = 1;
    const int LOCK_LOCK_DOOR = 2;
    const int LOCK_UNLOCK_DOOR = 3;
}

// ============================================================================
// INPUT/BUFFER LIMITS
// ============================================================================
namespace Limits {
    const int INPUT_BUFFER_SIZE = 256;
    const int MIN_DEVICE_ID = 1;
    const int MAX_STRING_LENGTH = 100;
}

#endif