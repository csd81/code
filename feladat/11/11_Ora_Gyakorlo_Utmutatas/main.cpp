#include <iostream>
#include <vector>
using namespace std;

// #include "engine.h"
// #include "freightcar.h"
// #include "passengercar.h"
// #include "trainset.h"
// #include "trainmanager.h"

int main()
{
    cout << "main() eleje!" << endl << endl;

    // // Ez az egy db nyilvantartas lesz a programban
    // TrainManager trainManager;

    // // Engine: mozdonyok (id, mass, speed, towableMass)
    // Engine* m31 = new Engine("M31", 3, 20, 11);
    // Engine* m41 = new Engine("M41", 30, 100, 250);
    // Engine* m47 = new Engine("M47", 26, 70, 180);

    // // Mozdonyok hozzaadasa a nyilvantartashoz
    // trainManager.addVehicle(m31);
    // trainManager.addVehicle(m41);
    // trainManager.addVehicle(m47);

    // // FreightCar: teherkocsi (id, mass, speed, capacity)
    // FreightCar* eas1 = new FreightCar("Eas1", 8, 60, 10);
    // FreightCar* eas2 = new FreightCar("Eas2", 8, 60, 10);
    // FreightCar* eas3 = new FreightCar("Eas3", 8, 60, 10);
    // FreightCar* eas4 = new FreightCar("Eas4", 8, 60, 10);
    // FreightCar* ks1 = new FreightCar("Ks1", 4, 80, 12);
    // FreightCar* ks2 = new FreightCar("Ks2", 4, 80, 12);
    // FreightCar* ks3 = new FreightCar("Ks3", 4, 80, 12);
    // FreightCar* ks4 = new FreightCar("Ks4", 4, 80, 12);

    // trainManager.addVehicle(eas1);
    // trainManager.addVehicle(eas2);
    // trainManager.addVehicle(eas3);
    // trainManager.addVehicle(eas4);
    // trainManager.addVehicle(ks1);
    // trainManager.addVehicle(ks2);
    // trainManager.addVehicle(ks3);
    // trainManager.addVehicle(ks4);

    // // PassengerCar: szemelykocsi (id, mass, speed, passengerCount)
    // PassengerCar* Bhv1 = new PassengerCar("Bhv1", 13, 100, 80);
    // PassengerCar* Bhv2 = new PassengerCar("Bhv2", 13, 100, 80);
    // PassengerCar* Bhv3 = new PassengerCar("Bhv3", 13, 100, 80);
    // PassengerCar* ARp = new PassengerCar("ARp", 15, 120, 60);
    // PassengerCar* Bp1 = new PassengerCar("Bp1", 11, 120, 70);
    // PassengerCar* Bp2 = new PassengerCar("Bp2", 11, 120, 70);
    // PassengerCar* Bp3 = new PassengerCar("Bp3", 11, 120, 70);
    // PassengerCar* Bp4 = new PassengerCar("Bp4", 11, 120, 70);

    // trainManager.addVehicle(Bhv1);
    // trainManager.addVehicle(Bhv2);
    // trainManager.addVehicle(Bhv3);
    // trainManager.addVehicle(ARp);
    // trainManager.addVehicle(Bp1);
    // trainManager.addVehicle(Bp2);
    // trainManager.addVehicle(Bp3);
    // trainManager.addVehicle(Bp4);

    // trainManager.printAll();
    // cout << endl;

    // // Szerelvenyek elkeszitese...
    // // M31+Ks1+Ks2+Ks3
    // vector<Vehicle*> vec1{m31, ks1, ks2, ks3};
    // bool set1 = trainManager.coupleSet(vec1);
    // cout << "Az M31+Ks1+Ks2+Ks3 szerelveny letrehozasa: ";
    // cout << (set1 ? "sikerult." : "NEM SIKERULT!") << endl;

    // // M41+ARp+Bp1+Bp3+Bhv1+Bhv3
    // bool set2 = trainManager.coupleSet(vector<Vehicle*>
    // {
    //     m41,ARp,Bp1,Bp3,Bhv1,Bhv3
    // });
    // cout << "Az M41+ARp+Bp1+Bp3+Bhv1+Bhv3 szerelveny letrehozasa: ";
    // cout << (set2 ? "sikerult." : "NEM SIKERULT!") << endl;

    // // M47+Eas1+Eas2+Eas3+Eas4+Ks4
    // bool set3 = trainManager.coupleSet(vector<Vehicle*>
    // {
    //     m47,eas1,eas2,eas2,eas3,eas4,ks4
    // });
    // cout << "Az M47+Eas1+Eas2+Eas3+Eas4+Ks4 szerelveny letrehozasa: ";
    // cout << (set3 ? "sikerult." : "NEM SIKERULT!") << endl;

    // // Osszes jarmu kiirasa
    // trainManager.printAll();
    // cout << endl;
    // // Osszes szerelveny kiirasa
    // trainManager.printSets();
    // cout << endl;

    // // Bontsuk fel az M47+Eas1+Eas2+Eas3+Eas4+Ks4 szerelvenyt
    // TrainSet* trainSet = trainManager.searchSet("M47");
    // trainManager.decoupleSet(trainSet);

    // // Selejtezzuk le az Eas1-3 kocsikat
    // trainManager.removeVehicle(eas1);
    // trainManager.removeVehicle(eas2);
    // trainManager.removeVehicle(eas3);

    // // Kiiras meg egyszer
    // trainManager.printAll();
    // cout << endl;
    // trainManager.printSets();
    // cout << endl;

    cout << "main() vege!" << endl;
    return 0;
}
