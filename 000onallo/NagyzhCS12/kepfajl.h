#ifndef KEPFAJL_H
#define KEPFAJL_H

#include "fajl.h"
#include <iostream>
using namespace std;

class KepFajl : public Fajl
{

int szelesseg;
int magassag;
public:
KepFajl(const std::string &nev, int meret, int fontossag, int szelesseg, int magassag);

    int getSzelesseg() const;
    int getMagassag() const;
    void adatok() const;
    int operator*() const;
};

#endif // KEPFAJL_H
