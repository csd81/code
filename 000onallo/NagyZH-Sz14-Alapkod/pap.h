#ifndef PAP_H
#define PAP_H
#include <iostream>
using namespace std;

#include "karakter.h"

class Pap : public Karakter
{
    int magic;
public:
    Pap(const string &id, string &type, int maxHP, int magic);
    void print() const override;
    void action(Karakter & dest) const override;
    int getarmor() const override;
};

#endif // PAP_H
