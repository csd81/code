#include "probalkozas.h"

void Probalkozas::setNev(const string &newNev)
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

Probalkozas::Probalkozas(const string& nev, double tavolsag, bool ervenyes):
    nev(nev),
    tavolsag(tavolsag),
    ervenyes(ervenyes)
{
}

Probalkozas::Probalkozas() :
    nev("ismeretlen"),
    tavolsag(0),
    ervenyes(false)
{

}

// 1. Legyen a Probalkozas osztályban paraméter nélküli konstruktor. A név , a távolság 0, az érvényesség false legyen. (Szükséges később a vector<Probalkozas> teljeskörű működéséhez.)

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
