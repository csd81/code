#ifndef TRAINSET_H
#define TRAINSET_H

#include <vector>
using namespace std;

#include "vehicle.h"
#include "engine.h"

// Készíts egy TrainSet osztályt, amely egy szerelvényt reprezentál. 
// A szerelvény járművekből áll, ezeket egy vektorban tároljuk (vector<Vehicle*>). 
// Az osztálynak legyen egy konstruktora, amely a járművek vektorát várja paraméterben 
// és ezek lesznek a szerelvény járművei.

// Legyen egy getEngine metódus a TrainSet osztályban, amely visszatér a szerelvényben lévő mozdonnyal (Engine*). 
// Ha nincs, vagy egynél több mozdony van, akkor nullptr legyen az érték.

// Legyen egy engineCanTow metódust TrainSet osztályban, ami azzal tér vissza, hogy a szerelvény mozdonya el tudja-e vontatni a vagonokat a tömegük alapján. 
// Feltehetjük, hogy egy mozdony van. A mozdony saját tömegét nem kell beleszámolni.

// Legyen egy isValid metódus a TrainSet osztályban, ami visszaadja, hogy a szerelvény érvényes-e. 
// Ez akkor teljesül, ha pontosan egy mozdony van, legalább egy vagon, és a mozdony el tudja vontatni a vagonokat.

// Ajánlott csinálni egy printAll metódust, ami kiírja a járműveket abban a szerelvényben.

class TrainSet
{
    vector<Vehicle*> cars; // kocsik es a mozdony
public:
    TrainSet(const vector<Vehicle*>& vehiclesToUse);
    // destruktorban nem kell felszabaditas,
    // mert nem birtokolja a jarmuveket, csak hivatkozza oket
    // a TrainManager a birtoklo osztaly

    Engine* getEngine() const;
    bool engineCanTow() const;
    bool isValid() const;
    void printAll() const;
};

#endif // TRAINSET_H
