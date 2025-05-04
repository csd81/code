#include <iostream>
#include <memory>
#include <vector>
#include "engine.h"
#include "freightcar.h"
#include "passengercar.h"
#include "trainmanager.h"

using namespace std;

void showMenu() {
    cout << "\n=== Railway Manager ===\n"
         << "1) List all vehicles\n"
         << "2) Add Engine\n"
         << "3) Add FreightCar\n"
         << "4) Add PassengerCar\n"
         << "5) Build a TrainSet\n"
         << "6) List all TrainSets\n"
         << "7) Exit\n"
         << "Select: ";
}

int main() {
    TrainManager manager;

    while (true) {
        showMenu();
        int choice; 
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1'000, '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            manager.printAll();
            break;
        }
        case 2: {
            string id; int mass, speed, tow;
            cout << "Engine ID: ";        cin >> id;
            cout << "Mass (t): ";         cin >> mass;
            cout << "Max speed (km/h): "; cin >> speed;
            cout << "Towing cap (t): ";   cin >> tow;
            manager.addVehicle(new Engine(id, mass, speed, tow));
            break;
        }
        case 3: {
            string id; int mass, speed, cap;
            cout << "Freight ID: ";       cin >> id;
            cout << "Mass (t): ";         cin >> mass;
            cout << "Max speed (km/h): "; cin >> speed;
            cout << "Carry cap (t): ";    cin >> cap;
            manager.addVehicle(new FreightCar(id, mass, speed, cap));
            break;
        }
        case 4: {
            string id; int mass, speed, pax;
            cout << "Passenger ID: ";     cin >> id;
            cout << "Mass (t): ";         cin >> mass;
            cout << "Max speed (km/h): "; cin >> speed;
            cout << "Seats: ";            cin >> pax;
            manager.addVehicle(new PassengerCar(id, mass, speed, pax));
            break;
        }
        case 5: {
            cout << "Enter vehicle IDs to couple (space-separated), end with 0:\n";
            vector<Vehicle*> vec;
            while (true) {
                string vid; cin >> vid;
                if (vid == "0") break;
                // lookup by ID
                bool found = false;
                // naive linear search:
                for (auto v : manager.getVehicles()) {
                    if (v->getId() == vid) {
                        vec.push_back(v);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "  >> No such vehicle: " << vid << "\n";
            }
            bool ok = manager.coupleSet(vec);
            cout << (ok ? "TrainSet created ✔\n" : "Failed to create (invalid)\n");
            break;
        }
        case 6: {
            manager.printSets();
            break;
        }
        case 7:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid option\n";
        }
    }
}
