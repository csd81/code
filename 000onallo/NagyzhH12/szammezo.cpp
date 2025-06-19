#include "szammezo.h"

unsigned int SzamMezo::maxertek = 100;

unsigned int SzamMezo::getErtek() const
{
    return ertek;
}

void SzamMezo::setErtek(unsigned int newErtek)
{
    if (getSzerkesztheto() ==true)
        ertek = newErtek;
}

bool SzamMezo::megfelelo() const
{
    return ( ertek <=SzamMezo::maxertek);
}

SzamMezo &SzamMezo::operator=(int szam)
{
    this->ertek = szam;
    return *this;
}



void SzamMezo::setMaxertek(int newMaxertek)
{
    maxertek = newMaxertek;
}

int SzamMezo::getMaxertek()
{
    return maxertek;
}



SzamMezo::SzamMezo(const string &megnevezes, bool szerkesztheto) : BeviteliMezo(megnevezes, szerkesztheto),
    ertek(0)
{}
