#include "rendezveny.h"

Rendezveny::Rendezveny() :
    Szamsor(7)
{
}

Rendezveny::Rendezveny(const Rendezveny &r)
    : 	darab(r.darab)
{
    tomb=new int[darab];
    for (unsigned int i=0; i<darab; i++)
        tomb[i]=sz.tomb[i];
}




// Ezen felül tároljon egy
// Szemely mutatót, ami a rendezvény kiemelt vendégének nevét tárolja (feltéve ha van, ezért
// mutató). A kiemelt vendéget lehessen beállítani és lekérdezni.

// Készíts a Rendezveny osztályba egy kiir függvényt, amely kiírja az összes adatot.

// Készíts másoló konstruktort a Rendezveny osztályhoz.

// Készíts a Rendezveny-be egy legjobbNap függvényt, amely kiírja, hogy a rendezvény hanyadik
// napján volt a legnagyobb a létszám.

