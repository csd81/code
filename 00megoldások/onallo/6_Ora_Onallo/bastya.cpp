#include "bastya.h"

/*
Feladat:
Bastya osztály:
- Származik a Figura osztályból
- Konstruktor: beállítja a kezdő pozíciót
*/
Bastya::Bastya(const string &pos):
    Figura(pos)
{
}

/*
Feladat:
A Bastya osztály lephet függvénye:
- Vízszintesen vagy függőlegesen bármennyit léphet
- Nem maradhat helyben
*/
bool Bastya::lephet(const string &pos) const
{
    if (pos.length()<2) return false;

    // XNOR: vagy sor, vagy oszlop egyezik, de nem mindkettő egyszerre
    return ((pos[0]==pozicio[0]) ^ (pos[1]==pozicio[1]));
}

/*
Feladat:
jeloles függvény:
- A bástya figurához tartozó karakter: 'B'
*/
char Bastya::jeloles() const
{
    return 'B';
}
