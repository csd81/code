#ifndef TRAINMANAGER_H
#define TRAINMANAGER_H

#include <vector>
using namespace std;

#include "vehicle.h"
#include "trainset.h"

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
