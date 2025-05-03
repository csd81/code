#include "freightcar.h"

#include <iostream>
using namespace std;

FreightCar::FreightCar(const string &id,
                       int mass,
                       int speed,
                       int capacity):
    Vehicle(id, mass, speed),
    capacity(capacity)
{
}

void FreightCar::print() const
{
    cout << getType() << " " << id << ": ";
    cout << mass << " t, ";
    cout << "max " << speed << " km/h, ";
    cout << "carrying capacity: " << capacity << " t";
    cout << endl;
}

string FreightCar::getType() const
{
    return "FreightCar";
}
