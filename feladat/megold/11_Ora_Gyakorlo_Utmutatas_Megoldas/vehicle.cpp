#include "vehicle.h"

Vehicle::Vehicle(const string &id,
                 int mass,
                 int speed):
    id(id),
    mass(mass),
    speed(speed)
{
}

int Vehicle::getMass() const
{
    return mass;
}

string Vehicle::getId() const
{
    return id;
}
