#ifndef SOLDIER_H
#define SOLDIER_H

#include "character.h"

class Soldier : public Character
{
    int power;
    int armor;
public:
    Soldier(const string &id, int maxhp, int power, int armor);
    void print() const override;
    int getarmor() const override;
    int action(Character& target) const override;
};

#endif // SOLDIER_H
