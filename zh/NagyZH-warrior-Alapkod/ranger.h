#ifndef RANGER_H
#define RANGER_H

#include "warrior.h"

class Ranger : public Warrior
{
    int agility;
public:

    Ranger(const std::string &id, int price, int agility);
    void print() const override;
    void attack(Dragon& dragon) const override;
};

#endif // RANGER_H

