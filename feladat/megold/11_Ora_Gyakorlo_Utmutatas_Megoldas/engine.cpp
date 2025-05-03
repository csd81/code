#include "engine.h"

#include <iostream>
using namespace std;

Engine::Engine(const string &id,
               int mass,
               int speed,
               int towableMass):
    Vehicle(id,mass,speed),
    towableMass(towableMass)
{
}

int Engine::getTowableMass() const
{
    return towableMass;
}

void Engine::print() const
{
    cout << getType() << " " << id << ": ";
    cout << mass << " t, ";
    cout << "max " << speed << " km/h, ";
    cout << "towing capacity: " << towableMass << " t";
    cout << endl;
}

string Engine::getType() const
{
    return "ENGINE";
}
