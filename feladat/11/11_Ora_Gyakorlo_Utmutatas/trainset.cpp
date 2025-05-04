#include "trainset.h"
#include <vector>
#include <iostream>


TrainSet::TrainSet(std::vector<Vehicle*> v) :     vehicles(v) {}

Engine* TrainSet::getEngine(){
    Engine* found = nullptr;
    for (Vehicle* v : vehicles) {
        if (v->getType() == "ENGINE") {
            if (found != nullptr) {
                return nullptr;
            }
            found = dynamic_cast<Engine*>(v);
        }
    }

    return found;
}

bool TrainSet::engineCanTow(){
    Engine* engine = getEngine();
    if (!engine) return false;

    int totalMass = 0;
    for (Vehicle* v : vehicles) {
        if (v->getType() != "ENGINE") {
            totalMass += v->getMass();
        }
    }

    return totalMass <= engine->getTowingCapacity();
}

bool TrainSet::isValid(){
    int engineCount = 0;
    int carCount = 0;
    for (Vehicle* v : vehicles) {
        if (v->getType() != "ENGINE") {
            carCount++;
        }
        else {
            engineCount++;
        }
    }

    return (engineCount == 1 &&   carCount >= 1 &&  TrainSet::engineCanTow());
}

void TrainSet::printAll() {
    for (Vehicle* v : vehicles) {
        v->print();
    }
}
