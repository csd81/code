#ifndef TRAINSET_H
#define TRAINSET_H
#include "vehicle.h"
#include "engine.h"
#include <vector>

class TrainSet
{
    std::vector<Vehicle*> v_set;
public:
    TrainSet(const std::vector<Vehicle *> &set);
    Engine* getEngine() const;
    bool engineCanTow() const;
    bool isValid() const;
    void printAll() const;
};

#endif // TRAINSET_H
