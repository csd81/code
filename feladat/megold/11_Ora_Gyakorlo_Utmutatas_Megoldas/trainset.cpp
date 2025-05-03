#include "trainset.h"

#include <iostream>
using namespace std;

#include "engine.h"

TrainSet::TrainSet(const vector<Vehicle*> &vehiclesToUse):
    cars(vehiclesToUse) // copy ctor
{
}

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

bool TrainSet::engineCanTow() const
{
    int massToTow = 0;
    for (size_t i=0;i<cars.size();i++)
        if (cars[i]->getType() != "ENGINE")
            massToTow += cars[i]->getMass();

    // feltetelezzuk, hogy getEngine() nem nullptr
    return massToTow <= getEngine()->getTowableMass();
}

bool TrainSet::isValid() const
{
    if (!getEngine())
        return false; // nem pontosan 1 db mozdony van
    if (cars.size() < 2)
        return false; // nincs legalabb egy vagon
    if (!engineCanTow())
        return false; // a mozdony nem birja el a vagonokat
    return true;
}

void TrainSet::printAll() const
{
    cout << "Szerelveny:" << endl;
    for (size_t i=0;i<cars.size();i++)
        cars[i]->print();
}
