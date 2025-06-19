#include "vehicle.h"

Vehicle::Vehicle(std::string id, int tomeg, int sebesseg)
    : id(id), tomeg(tomeg), sebesseg(sebesseg)
{}



std::string Vehicle::getId() const{
    return id;
}

int Vehicle::getMass() const{
    return tomeg;
}

int Vehicle::getSpeed() const {
    return sebesseg;
}

