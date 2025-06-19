#ifndef ADATHALMAZ_H
#define ADATHALMAZ_H

#include "adatmegjelenito.h"
class AdatHalmaz
{
    int darab;
    AdatMegjelenito* * megjelenitok;
public:
    AdatHalmaz();

    ~AdatHalmaz();

    int getMeret();

    AdatHalmaz& operator<< (AdatMegjelenito* am);

    void kiir();

    friend bool operator< (AdatHalmaz& a1, AdatHalmaz& a2);
    AdatHalmaz& operator~();
};

#endif // ADATHALMAZ_H


