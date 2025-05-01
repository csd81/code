#include "hatarido.h"

Datum Hatarido::aktualisDatum(2025,2,28);

string Hatarido::getNev() const
{
    return nev;
}

void Hatarido::setNev(const string &newNev)
{
    nev = newNev;
}

Datum *Hatarido::getAlphaDatum() const
{
    return alphaDatum;
}

void Hatarido::setAlphaDatum(const Datum &d)
{
    // delete alphaDatum;
    // alphaDatum = new Datum(d);

    if (alphaDatum) *alphaDatum = d;
    else alphaDatum = new Datum(d);
}

Datum *Hatarido::getBetaDatum() const
{
    return betaDatum;
}

void Hatarido::setBetaDatum(const Datum &d)
{
    if (betaDatum) *betaDatum = d;
    else betaDatum = new Datum(d);
}

Datum *Hatarido::getVegsoDatum() const
{
    return vegsoDatum;
}

void Hatarido::setVegsoDatum(const Datum &d)
{
    if (vegsoDatum) *vegsoDatum = d;
    else vegsoDatum = new Datum(d);
}

Datum Hatarido::getAktualisDatum()
{
    return aktualisDatum;
}

void Hatarido::setAktualisDatum(const Datum &d)
{
    aktualisDatum = d;
}

Hatarido::Hatarido(const string &_nev):
    nev(_nev),
    alphaDatum(nullptr),
    betaDatum(nullptr),
    vegsoDatum(nullptr)
{
}

Hatarido::~Hatarido()
{
    delete alphaDatum;
    delete betaDatum;
    delete vegsoDatum;
}
