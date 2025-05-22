#ifndef KNIGHT_H
#define KNIGHT_H

#include "warrior.h"

class Knight : public Warrior
{
    int strength;
public:
    Knight(const std::string &id, int price, int strength);

    void print() const override;
    void attack(Dragon& dragon) const override;
};

#endif // KNIGHT_H
