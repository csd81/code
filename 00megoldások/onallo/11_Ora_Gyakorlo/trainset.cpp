#include "trainset.h"

#include <iostream>
using namespace std;

#include "engine.h"

// Készíts egy TrainSet osztályt, amely egy szerelvényt reprezentál. 
// A szerelvény járművekből áll, ezeket egy vektorban tároljuk (vector<Vehicle*>). 
// Az osztálynak legyen egy konstruktora, amely a járművek vektorát várja paraméterben 
// és ezek lesznek a szerelvény járművei.

TrainSet::TrainSet(const vector<Vehicle*> &vehiclesToUse):
    cars(vehiclesToUse) // copy ctor
{
}

// Legyen egy getEngine metódus a TrainSet osztályban, amely visszatér 
// a szerelvényben lévő mozdonnyal (Engine*). 
// Ha nincs, vagy egynél több mozdony van, akkor nullptr legyen az érték.

Engine *TrainSet::getEngine() const
{
    Engine* engine = nullptr;
    for (size_t i=0;i<cars.size();i++)
    {
        if (cars[i]->getType() == "ENGINE")
        {
            if (engine)
                return nullptr; // masodik mozdony
            engine = (Engine*)cars[i];
        }
    }
    return engine; // lehet nullptr, ha nincs mozdony
}

// Legyen egy engineCanTow metódust TrainSet osztályban, ami azzal tér vissza, 
// hogy a szerelvény mozdonya el tudja-e vontatni a vagonokat a tömegük alapján. 
// Feltehetjük, hogy egy mozdony van. 
// A mozdony saját tömegét nem kell beleszámolni.

bool TrainSet::engineCanTow() const
{
    int massToTow = 0;
    for (size_t i=0;i<cars.size();i++)
        if (cars[i]->getType() != "ENGINE")
            massToTow += cars[i]->getMass();

    // feltetelezzuk, hogy getEngine() nem nullptr
    return massToTow <= getEngine()->getTowableMass();
}

// Legyen egy isValid metódus a TrainSet osztályban, ami visszaadja, hogy a szerelvény érvényes-e. 
// Ez akkor teljesül, ha pontosan egy mozdony van, legalább egy vagon, és a mozdony el tudja vontatni a vagonokat.

bool TrainSet::isValid() const
{
    if (!getEngine())
        return false; // nem pontosan 1 db mozdony van
    if (cars.size() < 2)
        return false; // nincs legalább egy vagon
    if (!engineCanTow())
        return false; // a mozdony nem bírja el a vagonokat
    return true;
}

// Ajánlott csinálni egy printAll metódust, ami kiírja a járműveket abban a szerelvényben.

void TrainSet::printAll() const
{
    cout << "Szerelveny:" << endl;
    for (size_t i=0;i<cars.size();i++)
        cars[i]->print();
}
