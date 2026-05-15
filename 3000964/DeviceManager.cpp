#include "DeviceManager.h"

DeviceManager::DeviceManager() {
    // Vector initialized empty by default
}

DeviceManager::~DeviceManager() {
    // Delete all devices and free memory
    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        if (devices[i] != NULL) {
            delete devices[i];
            devices[i] = NULL;
        }
    }
    devices.clear();
}

void DeviceManager::ClearInputBuffer() {
    cin.clear();
    cin.ignore(Limits::INPUT_BUFFER_SIZE, '\n');
}

bool DeviceManager::ValidateIntInput(int& value, int minVal, int maxVal, const string& errorMsg) {
    if (cin.fail()) {
        ClearInputBuffer();
        MenuUI::ShowErrorMessage("Invalid input type.");
        return false;
    }
    if (value < minVal || value > maxVal) {
        MenuUI::ShowErrorMessage(errorMsg);
        return false;
    }
    return true;
}

bool DeviceManager::ValidateStringInput(const string& value, const string& fieldName) {
    if (value.empty()) {
        MenuUI::ShowErrorMessage(fieldName + " cannot be empty.");
        return false;
    }
    return true;
}

void DeviceManager::AddDevice(Device* device) {
    if (device != NULL) {
        devices.push_back(device);
    }
}

void DeviceManager::ViewAllDevices() const {
    if (devices.empty()) {
        MenuUI::ShowInfoMessage("No devices in the system.");
        return;
    }

    MenuUI::DisplayDeviceTableHeader();

    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        Device* device = devices[i];
        string statusStr = device->GetStatus() ? "Active" : "Inactive";
        string qualityStr = device->GetQualityOrSetting();
        string connStr = device->GetConnectionStatus() ? "Connected" : "Disconnected";

        cout << "| "
            << setw(3) << setfill('0') << device->GetDeviceID() << " | "
            << setw(26) << left << setfill(' ') << device->GetDeviceName() << "| "
            << setw(20) << left << device->GetManufacturer() << "| "
            << setw(20) << left << statusStr << "| "
            << setw(25) << left << qualityStr << "| "
            << setw(10) << left << connStr << " |\n";
    }

    MenuUI::DisplayDeviceTableFooter();
}

void DeviceManager::DisplayMainMenu() {
    int choice;
    bool running = true;

    MenuUI::DisplayWelcome();

    while (running) {
        MenuUI::DisplayMainMenu();

        int choice_input;
        if (!(cin >> choice_input)) {
            ClearInputBuffer();
            MenuUI::ShowErrorMessage("Invalid input.");
            continue;
        }

        if (choice_input < Menu::MIN_OPTION || choice_input > Menu::MAX_OPTION) {
            MenuUI::ShowErrorMessage("Invalid option.");
            continue;
        }

        choice = choice_input;

        switch (choice) {
        case Menu::ADD_DEVICE:
            AddNewDevice();
            break;
        case Menu::VIEW_DEVICES:
            ViewAllDevices();
            break;
        case Menu::ACTIVATE_ALL:
            ActivateAllDevices();
            break;
        case Menu::DEACTIVATE_ALL:
            DeactivateAllDevices();
            break;
        case Menu::INTERACT_ALL:
            InteractWithAllDevices();
            break;
        case Menu::CONTROL_DEVICE:
            ControlEachDevice();
            break;
        case Menu::INTERACT_DEVICE:
            ControlSingleDevice("interact");
            break;
        case Menu::EDIT_DEVICE:
            EditDevice();
            break;
        case Menu::DELETE_DEVICE:
            DeleteDevice();
            break;
        case Menu::VIEW_CONNECTED:
            ViewConnectedDevices();
            break;
        case Menu::CHANGE_CONNECTION:
            ChangeDeviceConnectionStatus();
            break;
        case Menu::EXIT:
            running = false;
            MenuUI::DisplayGoodbye();
            break;
        }
    }
}

void DeviceManager::AddNewDevice() {
    int type, id;
    string name, manufacturer;

    MenuUI::DisplayAddDeviceMenu();

    if (!(cin >> type) || type < Menu::MIN_TYPE || type > Menu::MAX_TYPE) {
        ClearInputBuffer();
        MenuUI::ShowErrorMessage("Invalid device type.");
        return;
    }

    cout << "Enter unique Device ID: ";
    if (!(cin >> id) || id <= Limits::MIN_DEVICE_ID) {
        ClearInputBuffer();
        MenuUI::ShowErrorMessage("Invalid ID.");
        return;
    }

    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        if (devices[i]->GetDeviceID() == id) {
            MenuUI::ShowErrorMessage("Device ID already exists.");
            return;
        }
    }

    cout << "Enter Device Name: ";
    ClearInputBuffer();
    getline(cin, name);
    if (!ValidateStringInput(name, "Device Name")) {
        return;
    }

    cout << "Enter Manufacturer: ";
    getline(cin, manufacturer);
    if (!ValidateStringInput(manufacturer, "Manufacturer")) {
        return;
    }

    if (type == Menu::CAMERA) {
        string quality, power;

        cout << "Select resolution:\n1. 720p\n2. 1080p\n3. 2K\n4. 4K\nEnter option (1-4): ";
        int q;
        if (!(cin >> q) || q < Menu::MIN_RESOLUTION || q > Menu::MAX_RESOLUTION) {
            ClearInputBuffer();
            MenuUI::ShowErrorMessage("Invalid resolution.");
            return;
        }

        switch (q) {
        case Menu::RESOLUTION_720P: quality = "720p"; break;
        case Menu::RESOLUTION_1080P: quality = "1080p"; break;
        case Menu::RESOLUTION_2K: quality = "2K"; break;
        case Menu::RESOLUTION_4K: quality = "4K"; break;
        }

        cout << "Enter power source (mains/battery/battery+solar): ";
        ClearInputBuffer();
        getline(cin, power);
        if (!ValidateStringInput(power, "Power Source")) {
            return;
        }

        SecurityCamera* camera = new SecurityCamera(id, name, manufacturer, quality, power);
        AddDevice(camera);
        MenuUI::ShowSuccessMessage("Security Camera added.");
    }
    else if (type == Menu::AC) {
        int temp;
        cout << "Enter target temperature (in Celsius): ";
        if (!(cin >> temp) || temp < Temperature::MIN_TEMP || temp > Temperature::MAX_TEMP) {
            ClearInputBuffer();
            MenuUI::ShowErrorMessage("Invalid temperature.");
            return;
        }

        AirConditioning* ac = new AirConditioning(id, name, manufacturer, temp);
        AddDevice(ac);
        MenuUI::ShowSuccessMessage("Air Conditioner added.");
    }
    else if (type == Menu::PROJECTOR) {
        string input;
        int brightness;

        cout << "Enter input source (VGA/HDMI/wireless): ";
        ClearInputBuffer();
        getline(cin, input);
        if (!ValidateStringInput(input, "Input Source")) {
            return;
        }

        cout << "Enter brightness level (0-100): ";
        if (!(cin >> brightness) || brightness < Brightness::MIN_BRIGHTNESS || brightness > Brightness::MAX_BRIGHTNESS) {
            ClearInputBuffer();
            MenuUI::ShowErrorMessage("Invalid brightness.");
            return;
        }

        Projector* projector = new Projector(id, name, manufacturer, input, brightness);
        AddDevice(projector);
        MenuUI::ShowSuccessMessage("Projector added.");
    }
    else if (type == Menu::LIGHTS) {
        int brightness;
        cout << "Enter brightness level (0-100): ";
        if (!(cin >> brightness) || brightness < Brightness::MIN_BRIGHTNESS || brightness > Brightness::MAX_BRIGHTNESS) {
            ClearInputBuffer();
            MenuUI::ShowErrorMessage("Invalid brightness.");
            return;
        }

        RoomLighting* lights = new RoomLighting(id, name, manufacturer, brightness);
        AddDevice(lights);
        MenuUI::ShowSuccessMessage("Room Lighting added.");
    }
    else if (type == Menu::LOCK) {
        int lockState;
        cout << "Initial state: 1 for Locked, 0 for Unlocked: ";
        if (!(cin >> lockState) || (lockState != Menu::UNLOCKED && lockState != Menu::LOCKED)) {
            ClearInputBuffer();
            MenuUI::ShowErrorMessage("Invalid lock state.");
            return;
        }

        string username;
        cout << "Enter username for last opened by: ";
        ClearInputBuffer();
        getline(cin, username);
        if (!ValidateStringInput(username, "Username")) {
            return;
        }

        DoorLock* doorLock = new DoorLock(id, name, manufacturer, lockState == Menu::LOCKED);
        doorLock->SetManufacturer(username);
        AddDevice(doorLock);
        MenuUI::ShowSuccessMessage("Door Lock added.");
    }
}

void DeviceManager::ActivateAllDevices() {
    if (devices.empty()) {
        MenuUI::ShowInfoMessage("No devices to activate.");
        return;
    }

    MenuUI::ShowInfoMessage("Activating all devices...");
    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        devices[i]->Activate();
    }
    MenuUI::ShowSuccessMessage("All devices are now active.");
}

void DeviceManager::DeactivateAllDevices() {
    if (devices.empty()) {
        MenuUI::ShowInfoMessage("No devices to deactivate.");
        return;
    }

    MenuUI::ShowInfoMessage("Deactivating all devices...");
    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        devices[i]->Deactivate();
    }
    MenuUI::ShowSuccessMessage("All devices are now inactive.");
}

void DeviceManager::InteractWithAllDevices() {
    if (devices.empty()) {
        MenuUI::ShowInfoMessage("No devices to interact with.");
        return;
    }

    MenuUI::ShowInfoMessage("Interacting with all devices...");
    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        if (devices[i]->GetStatus()) {
            cout << "    [*] Interacting with " << devices[i]->GetDeviceName() << "...\n";
            devices[i]->InteractionEvent();
        }
        else {
            cout << "    [!] " << devices[i]->GetDeviceName() << " is inactive.\n";
        }
    }
    MenuUI::ShowInfoMessage("Interaction complete.");
}

void DeviceManager::ControlEachDevice() {
    if (devices.empty()) {
        MenuUI::ShowInfoMessage("No devices in the system.");
        return;
    }

    ViewAllDevices();

    int id;
    cout << "Enter Device ID to control: ";

    if (!(cin >> id) || id <= Limits::MIN_DEVICE_ID) {
        ClearInputBuffer();
        MenuUI::ShowErrorMessage("Invalid ID.");
        return;
    }

    Device* selectedDevice = NULL;
    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        if (devices[i]->GetDeviceID() == id) {
            selectedDevice = devices[i];
            break;
        }
    }

    if (selectedDevice == NULL) {
        MenuUI::ShowErrorMessage("Device ID not found.");
        return;
    }

    cout << "\n--- Device Details ---\n";
    cout << "ID: " << selectedDevice->GetDeviceID() << " | Name: " << selectedDevice->GetDeviceName() << "\n";
    cout << "Status: " << (selectedDevice->GetStatus() ? "Active" : "Inactive") << "\n";
    cout << "Quality/Setting: " << selectedDevice->GetQualityOrSetting() << "\n";

    MenuUI::DisplayDeviceControlMenu();

    int opt;
    if (!(cin >> opt) || opt < Menu::ACTIVATE || opt > Menu::EDIT) {
        ClearInputBuffer();
        MenuUI::ShowErrorMessage("Invalid option.");
        return;
    }

    if (opt == Menu::ACTIVATE) {
        selectedDevice->Activate();
    }
    else if (opt == Menu::DEACTIVATE) {
        selectedDevice->Deactivate();
    }
    else if (opt == Menu::EDIT) {
        selectedDevice->EditSettings();
    }
}

void DeviceManager::ControlSingleDevice(const string& action) {
    if (devices.empty()) {
        MenuUI::ShowInfoMessage("No devices in the system.");
        return;
    }

    int id;
    cout << "\nEnter Device ID: ";

    if (!(cin >> id) || id <= Limits::MIN_DEVICE_ID) {
        ClearInputBuffer();
        MenuUI::ShowErrorMessage("Invalid ID.");
        return;
    }

    Device* selectedDevice = NULL;
    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        if (devices[i]->GetDeviceID() == id) {
            selectedDevice = devices[i];
            break;
        }
    }

    if (selectedDevice == NULL) {
        MenuUI::ShowErrorMessage("Device ID not found.");
        return;
    }

    if (action == "interact") {
        if (!selectedDevice->GetStatus()) {
            MenuUI::ShowErrorMessage("Device is inactive.");
            return;
        }
        MenuUI::ShowInfoMessage("Interacting with: " + selectedDevice->GetDeviceName());
        selectedDevice->InteractionEvent();
    }
}

void DeviceManager::EditDevice() {
    if (devices.empty()) {
        MenuUI::ShowInfoMessage("No devices to edit.");
        return;
    }

    ViewAllDevices();

    int id;
    cout << "Enter Device ID to edit: ";

    if (!(cin >> id) || id <= Limits::MIN_DEVICE_ID) {
        ClearInputBuffer();
        MenuUI::ShowErrorMessage("Invalid ID.");
        return;
    }

    Device* selectedDevice = NULL;
    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        if (devices[i]->GetDeviceID() == id) {
            selectedDevice = devices[i];
            break;
        }
    }

    if (selectedDevice == NULL) {
        MenuUI::ShowErrorMessage("Device ID not found.");
        return;
    }

    selectedDevice->EditSettings();
}

void DeviceManager::DeleteDevice() {
    if (devices.empty()) {
        MenuUI::ShowInfoMessage("No devices to delete.");
        return;
    }

    ViewAllDevices();

    int id;
    cout << "Enter Device ID to delete: ";

    if (!(cin >> id) || id <= Limits::MIN_DEVICE_ID) {
        ClearInputBuffer();
        MenuUI::ShowErrorMessage("Invalid ID.");
        return;
    }

    bool found = false;
    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        if (devices[i]->GetDeviceID() == id) {
            delete devices[i];
            devices[i] = NULL;
            devices.erase(devices.begin() + i);
            found = true;
            break;
        }
    }

    if (!found) {
        MenuUI::ShowErrorMessage("Device ID not found.");
        return;
    }

    MenuUI::ShowSuccessMessage("Device deleted successfully.");
}

void DeviceManager::ViewConnectedDevices() const {
    if (devices.empty()) {
        MenuUI::ShowInfoMessage("No devices in the system.");
        return;
    }

    cout << "\n--- Connected Devices ---\n";
    bool hasConnected = false;

    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        if (devices[i]->CheckConnection()) {
            cout << "ID: " << devices[i]->GetDeviceID() << " | "
                << devices[i]->GetDeviceName() << " (Connected)\n";
            hasConnected = true;
        }
    }

    if (!hasConnected) {
        cout << "[!] No connected devices.\n";
    }

    cout << "\n--- Disconnected Devices ---\n";
    bool hasDisconnected = false;

    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        if (!devices[i]->CheckConnection()) {
            cout << "ID: " << devices[i]->GetDeviceID() << " | "
                << devices[i]->GetDeviceName() << " (Disconnected)\n";
            hasDisconnected = true;
        }
    }

    if (!hasDisconnected) {
        cout << "[!] No disconnected devices.\n";
    }
}

void DeviceManager::ChangeDeviceConnectionStatus() {
    if (devices.empty()) {
        MenuUI::ShowInfoMessage("No devices in the system.");
        return;
    }

    ViewConnectedDevices();

    int id;
    cout << "\nEnter Device ID to change connection status: ";

    if (!(cin >> id) || id <= Limits::MIN_DEVICE_ID) {
        ClearInputBuffer();
        MenuUI::ShowErrorMessage("Invalid ID.");
        return;
    }

    Device* selectedDevice = NULL;
    for (int i = 0; i < static_cast<int>(devices.size()); i++) {
        if (devices[i]->GetDeviceID() == id) {
            selectedDevice = devices[i];
            break;
        }
    }

    if (selectedDevice == NULL) {
        MenuUI::ShowErrorMessage("Device ID not found.");
        return;
    }

    bool current = selectedDevice->GetConnectionStatus();
    cout << "Current connection status: "
        << (current ? "Connected" : "Disconnected") << "\n";

    cout << "Enter new status (1 for Connected, 0 for Disconnected): ";
    int newStatus;

    if (!(cin >> newStatus) || (newStatus != Menu::DISCONNECTED && newStatus != Menu::CONNECTED)) {
        ClearInputBuffer();
        MenuUI::ShowErrorMessage("Invalid input.");
        return;
    }

    selectedDevice->SetConnectionStatus(newStatus == Menu::CONNECTED);
    MenuUI::ShowSuccessMessage("Connection status updated.");
}