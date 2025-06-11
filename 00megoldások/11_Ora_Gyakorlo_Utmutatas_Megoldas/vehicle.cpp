#include "vehicle.h"

// Készíts egy absztrakt Vehicle osztályt, amely vasúti járműveket reprezentál. 
// A járműveknek legyen egy azonosítója (string), egy tömege (int), egy sebessége (int) 
// és egy tisztán virtuális getType metódus, ami visszaadja a típusát (string). 
// Az osztálynak legyen egy konstruktora, amely a típuson kívül minden más tulajdonságot 
// megkap paraméterben és beállítja azokat. 
// Legyen virtuális destruktor. 
// Getterek is kellenek a későbbi feladatokhoz (getId, getMass).

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
