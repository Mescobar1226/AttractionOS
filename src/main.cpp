#include "../include/AttractionController.h"
#include <iostream>
#include <limits>

static const char* status(bool value, const char* yes, const char* no) { return value ? yes : no; }

void showPanel(const AttractionController& c) {
    std::cout << "\n========================================\n"
              << "       ATTRACTIONOS CONTROL SIMULATOR\n"
              << "========================================\n"
              << "System State:       " << c.stateName() << '\n'
              << "Platform Gates:     " << status(c.gatesClosed(), "CLOSED", "OPEN") << '\n'
              << "Restraints:         " << status(c.restraintsLocked(), "LOCKED", "UNLOCKED") << '\n'
              << "Track:              " << status(c.isTrackClear(), "CLEAR", "OCCUPIED") << '\n'
              << "Emergency Stop:     " << status(c.emergencyStopActive(), "ACTIVE", "NORMAL") << '\n'
              << "Dispatch:           " << status(c.canDispatch(), "ENABLED", "DISABLED") << "\n\n"
              << "1. Power On\n2. Begin Loading\n3. Toggle Platform Gates\n4. Toggle Restraints\n"
              << "5. Toggle Track Clear\n6. Toggle Emergency Stop\n7. Attempt Dispatch\n"
              << "8. Advance Ride Cycle\n9. View Event Log\n10. Reset System\n0. Exit\n"
              << "----------------------------------------\nSelect: ";
}

int main() {
    AttractionController controller;
    int choice = -1;
    while (choice != 0) {
        showPanel(controller);
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a menu number.\n";
            continue;
        }
        switch (choice) {
            case 1: controller.powerOn(); break;
            case 2: controller.beginLoading(); break;
            case 3: controller.toggleGates(); break;
            case 4: controller.toggleRestraints(); break;
            case 5: controller.toggleTrackClear(); break;
            case 6: controller.toggleEmergencyStop(); break;
            case 7:
                if (controller.dispatch()) std::cout << "Dispatch accepted.\n";
                else std::cout << "Dispatch denied: " << controller.dispatchDenialReason() << '\n';
                break;
            case 8: controller.advanceCycle(); break;
            case 9:
                std::cout << "\n--- EVENT LOG ---\n";
                for (const auto& entry : controller.getLog()) std::cout << entry << '\n';
                break;
            case 10: controller.reset(); break;
            case 0: std::cout << "AttractionOS shutting down.\n"; break;
            default: std::cout << "Unknown selection.\n";
        }
    }
    return 0;
}
