#include "probalkozas.h"

void Probalkozas::setNev(const std::string &newNev)
{
    nev = newNev;
}

void Probalkozas::setTavolsag(double newTavolsag)
{
    tavolsag = newTavolsag;
}

void Probalkozas::setErvenyes(bool newErvenyes)
{
    ervenyes = newErvenyes;
}

Probalkozas::Probalkozas(const std::string& nev, double tavolsag, bool ervenyes):
    nev(nev),
    tavolsag(tavolsag),
    ervenyes(ervenyes)
{
}

Probalkozas::Probalkozas()
{
    nev = "ismeretlen";
    tavolsag = 0;
    ervenyes = false;

}

const std::string &Probalkozas::getNev() const
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
