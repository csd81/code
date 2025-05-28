#include "probalkozas.h"

Probalkozas::Probalkozas(const string& nev, double tavolsag, bool ervenyes):
    nev(nev),
    tavolsag(tavolsag),
    ervenyes(ervenyes)
{
}

const string &Probalkozas::getNev() const
{
    return nev;
}

double Probalkozas::getTavolsag() const
{
    return tavolsag;
}

bool Probalkozas::getErvenyes() const
{
    return ervenyes;
}
