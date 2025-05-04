#include "vehicle.h"



Vehicle::Vehicle(const std::string& i, int m, int s) :
    id(i),
    mass(m),
    speed(s)
{}

Vehicle::~Vehicle() {}

std::string Vehicle::getId() const {return id;}
int Vehicle::getMass() const {return mass;}
int Vehicle::getSpeed() const {return speed;}
