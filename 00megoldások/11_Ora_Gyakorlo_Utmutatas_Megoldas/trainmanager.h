#ifndef TRAINMANAGER_H
#define TRAINMANAGER_H

#include <vector>
using namespace std;

#include "vehicle.h"
#include "trainset.h"

// Hozz létre egy TrainManager osztályt, amely a vasúti járműveink kezelését valósítja meg. 
// Az osztály egy vektorban (vector<Vehicle*>) tárolja a járműveinket, amiket egyenként dinamikusan kell foglalnunk. 
// A tároló kezdetben üres.

// Módosítsd a TrainManager osztályt úgy, hogy szerelvényeket is tudjon tárolni tetszőleges mennyiségben (vector<TrainSet*>).

// Legyen addVehicle metódus a TrainManager osztályban, amely paraméterben egy járművet vár (Vehicle*) és hozzáadja a tárolóhoz.

// Legyen egy printAll metódus TrainManager osztályban, amely kiírja a járművek adatait. 
// Ehhez használja a járművek print metódusát.

// Legyen egy coupleSet metódus a TrainManager osztályban, ami paraméterben várja a járművek vektorát, azokból összeállít egy szerelvényt és eltárolja azt. 
// Csak érvényes szerelvényt lehet eltárolni, különben a szerelvényt azonnal törölni is kell.

// Legyen egy printSets metódus a TrainManager osztályban, amely kiírja a tárolt szerelvények adatait. 
// Ehhez a TrainSet osztályban is ajánlott csinálni egy printAll metódust.

// Legyen egy searchSet metódus a TrainManager osztályban, ami paraméterben egy mozdony azonosítóját kapja meg (string), 
// és ez alapján visszaadja a szerelvényt (TrainSet*). Ha nem találja a szerelvényt, akkor nullptr-t adjon vissza.

// Legyen egy decoupleSet metódus a TrainManager osztályban, ami egy szerelvényt vár paraméterben (TrainSet*), 
// és eltávolítja azt a szerelvények közül.

// Legyen egy removeVehicle metódus a TrainManager osztályban, ami egy járművet vár paraméterben, 
// és eltávolítja azt a tároltak közül (a szerelvényekben lévőkkel nem kell foglalkozni).

class TrainManager
{
    vector<Vehicle*> vehicles;
    vector<TrainSet*> sets;
public:
    TrainManager()=default;
    ~TrainManager();

    void addVehicle(Vehicle* vehicle);
    void printAll() const;
    bool coupleSet(const vector<Vehicle*> &vehiclesToUse);
    void printSets() const;

    TrainSet* searchSet(const string& engineId) const;
    void decoupleSet(TrainSet* set);
    void removeVehicle (Vehicle* vehicle);
};

#endif // TRAINMANAGER_H
