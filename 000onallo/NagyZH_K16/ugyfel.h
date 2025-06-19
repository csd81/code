#ifndef UGYFEL_H
#define UGYFEL_H

#include "szamla.h"
class Ugyfel
{
    string nev;
    int meret;
    Szamla ** szamlak;
public:
    Ugyfel(const string &nev);
    ~Ugyfel();
    void kiir() const;
    Ugyfel& operator+=(Szamla * sz);

    Szamla * alkalmaz(Tranzakcio&);
    Szamla *  operator[](int i);
};

#endif // UGYFEL_H
