#ifndef ENGINE_H
#define ENGINE_H

#include "vehicle.h"

class Engine : public Vehicle
{
    int towableMass;
public:
    Engine(const string& id,
           int mass,
           int speed,
           int towableMass);

    int getTowableMass() const;

    void print() const;

    string getType() const;

    // bool isEngine() const; // return true
};

#endif // ENGINE_H
