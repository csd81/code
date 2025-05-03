#ifndef TRAINSET_H
#define TRAINSET_H

#include <vector>
using namespace std;

#include "vehicle.h"
#include "engine.h"

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
