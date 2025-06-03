#ifndef MAGE_H
#define MAGE_H

#include "character.h"

class Mage : public Character
{
    int magic;
public:
    Mage(const string &id, int maxhp, int magic);
    void print() const override;
    int getarmor() const override;
    int action(Character& target) const override;
};

#endif // MAGE_H
