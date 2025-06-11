#include "engine.h"

#include <iostream>
using namespace std;

// Engine: a mozdonyt reprezentálja, legyen egy plusz tulajdonsága, 
// amely a mozdony által elvontatható tömeget adja meg (int). 
// A típus szövege "ENGINE".

// Készíts a Vehicle osztályba egy tisztán virtuális print metódust. 
// A metódus az egyes járművek tulajdonságait írja ki a standard kimenetre. 
// Valósítsd meg a print metódust a gyerekosztályokban.

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
