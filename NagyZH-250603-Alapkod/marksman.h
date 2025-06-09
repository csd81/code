#ifndef MARKSMAN_H
#define MARKSMAN_H

#include "character.h"

class Marksman : public Character
{
    int agility;
    bool elite;
public:
    Marksman(const string &id, int price, int agility, bool elite);

    void print() const;
    int attackPower() const;
};

#endif // MARKSMAN_H
