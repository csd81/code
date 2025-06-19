#ifndef MAGUS_H
#define MAGUS_H
#include <iostream>
using namespace std;
#include "karakter.h"

class Magus : public Karakter
{
    int magic;
public:
    Magus(const string &id, string &type, int maxHP, int magic);
    void print() const override;
    void action(Karakter & dest) const override;
    int getarmor() const override;
};

#endif // MAGUS_H
