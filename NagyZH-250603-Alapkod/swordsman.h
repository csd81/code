#ifndef SWORDSMAN_H
#define SWORDSMAN_H

#include "character.h"

class Swordsman : public Character
{
    int strength;
public:
    Swordsman(const string &id, int price, int strength);

    void print() const;
    int attackPower() const;
};

#endif // SWORDSMAN_H
