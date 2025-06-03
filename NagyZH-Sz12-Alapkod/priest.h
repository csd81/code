#ifndef PRIEST_H
#define PRIEST_H

#include "character.h"

class Priest : public Character
{
    int magic;
public:
    Priest(const string &id, int maxhp, int magic);
    void print() const override;
    int getarmor() const override;
    int action(Character& target) const override;

};

#endif // PRIEST_H
