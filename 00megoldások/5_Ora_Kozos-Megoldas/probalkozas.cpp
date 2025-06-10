#include "probalkozas.h"

// Spec 1. paraméter nélküli konstruktor
Probalkozas::Probalkozas():
    nev("ismeretlen"),
    tavolsag(0),
    ervenyes(false)
{
}

Probalkozas::Probalkozas(const string& nev, double tavolsag, bool ervenyes):
    nev(nev),
    tavolsag(tavolsag),
    ervenyes(ervenyes)
{
}

// Spec: getterek
const string& Probalkozas::getNev() const { return nev; }
double Probalkozas::getTavolsag() const { return tavolsag; }
bool Probalkozas::getErvenyes() const { return ervenyes; }
