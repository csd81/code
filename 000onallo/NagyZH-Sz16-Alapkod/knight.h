#ifndef KNIGHT_H
#define KNIGHT_H

#include "character.h"

class Knight : public Character
{   unsigned int strength;
public:
    Knight(const string &id, int price, unsigned int strength);


    // Character interface
public:
    void print() const override;


    // Character interface
public:
    int attack(Dragon &d) const override;
};

#endif // KNIGHT_H
