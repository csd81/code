#ifndef TRAINMANAGER_H
#define TRAINMANAGER_H
#include <vector>
#include <string>
#include "vehicle.h"
#include "trainset.h"

class TrainManager
{

    std::vector<Vehicle*> vehicles;
    std::vector<TrainSet*> trainsets;

public:
    TrainManager(std::vector<Vehicle*> v = {}, std::vector<TrainSet*> t = {});
    void addVehicle(Vehicle* v);
    void removeVehicle(Vehicle* v);
    void printAll();

    bool coupleSet(std::vector<Vehicle*> vset);
    void decoupleSet(TrainSet* tset);
    TrainSet* searchSet(std::string engineID);
    void printSets();

 


    const std::vector<Vehicle*>& getVehicles() const;

};

#endif // TRAINMANAGER_H
