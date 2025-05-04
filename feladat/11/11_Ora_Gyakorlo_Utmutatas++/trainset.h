#ifndef TRAINSET_H
#define TRAINSET_H
#include "vehicle.h"
#include "engine.h"
#include "freightcar.h"
#include "passengercar.h"
#include <vector>

class TrainSet
{
private:
    std::vector<Vehicle*> vehicles;

public:
    TrainSet(std::vector<Vehicle*> v);
    Engine* getEngine();
    bool engineCanTow();
    bool isValid();
    void printAll();
};

#endif // TRAINSET_H
