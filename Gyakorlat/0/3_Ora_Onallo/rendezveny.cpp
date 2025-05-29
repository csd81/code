// Származtass egy Rendezveny osztályt a Szamsor osztályból, ami egy egy hetes rendezvény adatait tárolja.
// Ebben az ősosztály által létrehozott dinamikus tömb mindenképpen 7 méretű lesz (egy-egy szám a hét minden napjához, ami az adott napi létszám).

// Ezen felül tároljon egy Szemely mutatót, ami a rendezvény kiemelt vendégének nevét tárolja (feltéve ha van, ezért mutató).
// A kiemelt vendéget lehessen beállítani és lekérdezni.

// Készíts a Rendezveny osztályba egy kiir függvényt, amely kiírja az összes adatot.+
// Készíts másoló konstruktort a Rendezveny osztályhoz.
// Készíts a Rendezveny-be egy legjobbNap függvényt, amely kiírja, hogy a rendezvény hanyadik napján volt a legnagyobb a létszám.

#include "rendezveny.h"
#include <iostream>

using namespace std;

Rendezveny::Rendezveny() : Szamsor(7), kiemelt(nullptr) {}

Rendezveny::Rendezveny(const Rendezveny &r) : Szamsor(r), kiemelt(nullptr)
{
    if (r.kiemelt)
        kiemelt = new Szemely(*r.kiemelt);
}

Rendezveny::~Rendezveny()
{
    delete kiemelt;
}

void Rendezveny::setKiemeltVendeg(const Szemely &sz)
{
    if (kiemelt)
        delete kiemelt;
    kiemelt = new Szemely(sz);
}

const Szemely* Rendezveny::getKiemeltVendeg() const
{
    return kiemelt;
}

void Rendezveny::kiir() const
{
    cout << "Letszamok: ";
    for (unsigned int i = 0; i < getDarab(); i++)
    {
        if (i > 0) cout << ", ";
        cout << getErtek(i);
    }
    cout << endl;

    if (kiemelt)
    {
        cout << "Kiemelt vendeg: ";
        kiemelt->kiir();
    }
    else
        cout << "Nincs kiemelt vendeg.\n";
}

// kiírja, hogy a rendezvény hanyadik napján volt a legnagyobb a létszám.
void Rendezveny::legjobbNap() const
{
    int max = getErtek(0);
    unsigned int index = 0;
    for (unsigned int i = 1; i < getDarab(); i++)
    {
        if (getErtek(i) > max)
        {
            max = getErtek(i);
            index = i;
        }
    }
    cout << "Legnagyobb letszam a(z) " << (index + 1) << ". napon volt: " << max << " fo.\n";
}


