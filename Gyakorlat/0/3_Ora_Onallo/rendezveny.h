#ifndef RENDEZVENY_H
#define RENDEZVENY_H

#include "szamsor.h"
#include "szemely.h"
#include <iostream>

using namespace std;

class Rendezveny : public Szamsor
{
    Szemely* kiemelt;
public:
    Rendezveny();

    Rendezveny(const Rendezveny &r);  // copy

    ~Rendezveny();

    void setKiemeltVendeg(const Szemely &sz);
    const Szemely* getKiemeltVendeg() const;
    void kiir() const;

    void legjobbNap() const;

};

#endif // RENDEZVENY_H


// Származtass egy Rendezveny osztályt a Szamsor osztályból, ami egy egy hetes rendezvény adatait tárolja.
// Ebben az ősosztály által létrehozott dinamikus tömb mindenképpen 7 méretű lesz (egy-egy szám a hét minden napjához, ami az adott napi létszám).

// Ezen felül tároljon egy Szemely mutatót, ami a rendezvény kiemelt vendégének nevét tárolja (feltéve ha van, ezért mutató).
// A kiemelt vendéget lehessen beállítani és lekérdezni.

// Készíts a Rendezveny osztályba egy kiir függvényt, amely kiírja az összes adatot.
// Készíts másoló konstruktort a Rendezveny osztályhoz.

// Készíts a Rendezveny-be egy legjobbNap függvényt, amely kiírja, hogy a rendezvény hanyadik napján volt a legnagyobb a létszám.
