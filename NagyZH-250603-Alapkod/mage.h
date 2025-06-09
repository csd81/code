#ifndef MAGE_H
#define MAGE_H

#include "character.h"

class Mage : public Character
{
    int magic;
public:
    Mage(const string &id, int price, int magic);

    void print() const;
    int attackPower() const;
};

#endif // MAGE_H
