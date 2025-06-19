#ifndef VALOGATOS_H
#define VALOGATOS_H

#include "karakter.h"
#include <iostream>
using namespace std;

class Valogatos : public Karakter
{
    string tipus;
public:
    Valogatos(const string &nev, int pont, const string &tipus);

    string getTipus() const;


    // Karakter interface
public:
    bool vegrehajt(Akcio &) override;
};

#endif // VALOGATOS_H
