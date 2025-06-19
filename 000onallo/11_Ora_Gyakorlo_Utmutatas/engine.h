#ifndef ENGINE_H
#define ENGINE_H
#include "vehicle.h"

class Engine : public Vehicle {
    int maxMass;
    std::string type;
public:
    Engine(const std::string &id, int tomeg, int sebesseg, int maxMass);

    std::string getType() const;
    void print() const;
    int getMaxMass() const;
};





#endif //ENGINE_H
