#include <iostream>
#include "DeviceManager.h"
using namespace std;

// Entry point - creates device manager and starts system
int main() {
    DeviceManager manager;
    manager.DisplayMainMenu();
    return 0;
}