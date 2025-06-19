#ifndef KATONA_H
#define KATONA_H
#include <iostream>
using namespace std;

#include "karakter.h"

class Katona : public Karakter
{
    int power;
    int armor;
public:
    Katona(const string &id, string &type,  int maxHP, int power, int armor);



    void print() const override;
    void action(Karakter & dest) const override;
    int getPower() const;

    int getarmor() const override;
};

#endif // KATONA_H
