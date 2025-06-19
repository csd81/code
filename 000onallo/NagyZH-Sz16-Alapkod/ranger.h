#ifndef RANGER_H
#define RANGER_H

#include "character.h"

class Ranger : public Character
{
    int agility;
public:
    Ranger(const string &id, int price, int agility);


    // Character interface
public:
    void print() const override;


    // Character interface
public:
    int attack(Dragon &d) const override;
};

#endif // RANGER_H
