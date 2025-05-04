#ifndef ENGINE_H
#define ENGINE_H
#define vehicletype "ENGINE"
#include "vehicle.h"

class Engine : public Vehicle
{
    int towingCapacity;

public:
    Engine(std::string i, int m, int s, int t);
    std::string getType() const;
    void print() const;
    int getTowingCapacity() const;
};

#endif // ENGINE_H
