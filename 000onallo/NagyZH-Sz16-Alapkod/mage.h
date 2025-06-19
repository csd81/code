#ifndef MAGE_H
#define MAGE_H

#include "character.h"

class Mage : public Character
{
    double magic;

public:
    Mage(const string &id, int price, double magic);


    // Character interface
public:
    void print() const override;


    // Character interface
public:
    int attack(Dragon &d) const override;
};

#endif // MAGE_H
