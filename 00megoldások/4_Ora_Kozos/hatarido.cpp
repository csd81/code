#include "hatarido.h"
#include <iostream>

// Spec: Legyen a Hatarido osztályban egy statikus adattag is, ami az aktuális dátumot tárolja.
// Az értéke kezdetben legyen a mai nap.
Datum Hatarido::aktualisDatum(2023,2,27);

Hatarido::Hatarido(const string &n):
    nev(n)
{
}

Hatarido::~Hatarido()
{
    // Spec: Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.
    if (alphaDatum) delete alphaDatum;
    if (betaDatum) delete betaDatum;
    if (vegsoDatum) delete vegsoDatum;
}

Hatarido::Hatarido(const Hatarido &h):
    nev(h.nev)
{
    // Spec: Másoló konstruktor
    if (h.alphaDatum) alphaDatum = new Datum(*h.alphaDatum);
    else alphaDatum = nullptr;

    if (h.betaDatum) betaDatum = new Datum(*h.betaDatum);
    else betaDatum = nullptr;

    if (h.vegsoDatum) vegsoDatum = new Datum(*h.vegsoDatum);
    else vegsoDatum = nullptr;
}

string Hatarido::getNev() const
{
    return nev;
}

void Hatarido::setNev(const string &_nev)
{
    nev = _nev;
}

const Datum *Hatarido::getAlphaDatum() const
{
    return alphaDatum;
}

void Hatarido::setAlphaDatum(const Datum &_alpha)
{
    if (alphaDatum == nullptr) alphaDatum = new Datum(_alpha);
    else *alphaDatum = _alpha;
}

const Datum *Hatarido::getBetaDatum() const
{
    return betaDatum;
}

void Hatarido::setBetaDatum(const Datum &_beta)
{
    if (betaDatum == nullptr) betaDatum = new Datum(_beta);
    else *betaDatum = _beta;
}

const Datum *Hatarido::getVegsoDatum() const
{
    return vegsoDatum;
}

void Hatarido::setVegsoDatum(const Datum &_vegso)
{
    if (vegsoDatum == nullptr) vegsoDatum = new Datum(_vegso);
    else *vegsoDatum = _vegso;
}

// Spec: A bejegyzett határidőket lehessen törölni is egy hataridoTorol metódus segítségével.
void Hatarido::hataridoTorol(const string &melyik)
{
    if (melyik == "alpha" && alphaDatum)
    {
        delete alphaDatum;
        alphaDatum = nullptr;
    }
    else if (melyik == "beta" && betaDatum)
    {
        delete betaDatum;
        betaDatum = nullptr;
    }
    else if (melyik == "vegso" && vegsoDatum)
    {
        delete vegsoDatum;
        vegsoDatum = nullptr;
    }
}

const Datum &Hatarido::getAktualisDatum()
{
    return aktualisDatum;
}

void Hatarido::setAktualisDatum(const Datum &newAktualisDatum)
{
    aktualisDatum = newAktualisDatum;
}

// Spec: A Hatarido osztályban legyen egy lejart metódus,
// amely a kimenetre kiírja az összes olyan határidőt, ami lejárt.
void Hatarido::lejart() const
{
    if (alphaDatum && alphaDatum->kisebbMint(aktualisDatum))
        std::cout << "Az alpha hatarido lejart" << std::endl;

    if (betaDatum && betaDatum->kisebbMint(aktualisDatum))
        std::cout << "A beta hatarido lejart" << std::endl;

    if (vegsoDatum && vegsoDatum->kisebbMint(aktualisDatum))
        std::cout << "A vegso hatarido lejart" << std::endl;
}
