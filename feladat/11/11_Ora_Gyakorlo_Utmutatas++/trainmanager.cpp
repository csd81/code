#include "trainmanager.h"
#include <iostream>

TrainManager::TrainManager(std::vector<Vehicle*> v, std::vector<TrainSet*> t) :
vehicles(v), trainsets(t) {}

void TrainManager::addVehicle(Vehicle* v){
    vehicles.push_back(v);
}

void TrainManager::removeVehicle(Vehicle* v){
    for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
        if (*it == v) {
            vehicles.erase(it);
            break;
        }
    }
}

void TrainManager::printAll(){
    std::cout << "--- Nyilvantartott jarmuvek:\n";
    for (Vehicle* v : vehicles){
        v->print();
    }
}

bool TrainManager::coupleSet(std::vector<Vehicle*> vset){
    TrainSet* newSet = new TrainSet(vset);
    if (newSet->isValid()) {
        trainsets.push_back(newSet);
        return true;
    } else {
        delete newSet;
        return false;
    }
}

void TrainManager::decoupleSet(TrainSet* tset){
    for (auto it = trainsets.begin(); it != trainsets.end(); ++it){
        if (*it == tset) {
            trainsets.erase(it);
            delete tset;
            break;
        }
    }
}

TrainSet* TrainManager::searchSet(std::string engineId){
    for (TrainSet* t : trainsets){
        Engine* e = t->getEngine();
        if (e && e->getId() == engineId) {
            return t;
        }

    }
    return nullptr;

}

void TrainManager::printSets(){
    std::cout << "--- Nyilvantartott szerelvenyek:\n";
    for (TrainSet* t : trainsets){
         std::cout << "Szerelveny:\n";
        t->printAll();
    }
}




const std::vector<Vehicle*>& TrainManager::getVehicles() const {
        return vehicles;
}

























