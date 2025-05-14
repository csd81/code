#ifndef MAGE_H
#define MAGE_H

#include "warrior.h"

class Mage : public Warrior
{
    double magic;
public:
    Mage(const std::string &id, int price, double magic);

    void print() const override;
    void attack(Dragon& dragon) const override;
};

#endif // MAGE_H
