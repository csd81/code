#ifndef TRAINMANAGER_H
#define TRAINMANAGER_H
#include "vehicle.h"
#include "trainset.h"
#include <vector>

class TrainManager
{
    std::vector<Vehicle*> v_vehicles;

    std::vector<TrainSet*> v_sets;
public:
    TrainManager();
    void addVehicle(Vehicle* p_v);
    void printAll();

    bool coupleSet(const std::vector<Vehicle*>& v_vehicle) ;

    void printSets();
    TrainSet* searchSet(std::string s_engineId);
    void decoupleSet(TrainSet* p_ts);
    void removeVehicle(Vehicle* p_v);
};

#endif // TRAINMANAGER_H
