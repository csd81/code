#ifndef KEBAB_H
#define KEBAB_H

#include "food.h"

class Kebab : public Food
{
    string sauce; // édes, csípős, fokhagymás
    bool hasOnion;
    bool hasTomato;
    bool hasFeta;
public:
    Kebab(const string &name, const string &sauce, bool hasOnion, bool hasTomato, bool hasFeta);
    void print() const;
    int price() const;
};

#endif // KEBAB_H
