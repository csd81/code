#include "akcio.h"



string Akcio::getTipus() const
{
    return tipus;
}

int Akcio::getErtek() const
{
    return ertek;
}

int Akcio::getNehezseg() const
{
    return nehezseg;
}

double Akcio::operator*()
{
    return (double)ertek/nehezseg;
}

Akcio::Akcio(const string &tipus, int ertek, int nehezseg) : tipus(tipus),
    ertek(ertek),
    nehezseg(nehezseg)
{}
