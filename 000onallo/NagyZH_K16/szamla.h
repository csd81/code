#ifndef SZAMLA_H
#define SZAMLA_H
#include <iostream>
#include "tranzakcio.h"
using namespace std;

class Szamla
{
protected:
    string tipus;
    string szamlaszam;
    int egyenleg;
public:
    Szamla(const string &szamlaszam, int egyenleg);
    virtual ~Szamla();
    virtual bool vegrehajt(Tranzakcio& )  = 0;
    virtual void kiir() const;
    string getTipus() const;
    string getSzamlaszam() const;
};

#endif // SZAMLA_H
