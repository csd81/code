#include "kebab.h"



Kebab::Kebab(const string &name, const string &sauce, bool hasOnion, bool hasTomato, bool hasFeta) : Food(name, "kebab"),
    sauce(sauce),
    hasOnion(hasOnion),
    hasTomato(hasTomato),
    hasFeta(hasFeta)
{
}



void Kebab::print() const
{
    cout << this->getName() << " "
    << sauce << " "
    << hasOnion << " "
    << hasTomato << " "
    << hasFeta << " ; "
         << price() << " Ft" << endl;
}

int Kebab::price() const
{
    int ar=1800;
    if (hasOnion) ar+=150;
    if (hasTomato) ar+=150;
    if (hasFeta) ar+=250;
    return ar;
}


