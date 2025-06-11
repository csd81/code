#include "huszar.h"

/*
Feladat:
Huszar osztály:
- Származik a Figura osztályból
- Konstruktor: beállítja a kezdő pozíciót
*/
Huszar::Huszar(const string &pos):
    Figura(pos)
{
}

/*
Feladat:
A Huszar osztály lephet függvénye:
- A huszár "L" alakban léphet: 2 mezőt az egyik irányba, 1 mezőt a másikba
- Nem maradhat helyben
*/
bool Huszar::lephet(const string &pos) const
{
    if (pos.length()<2) return false;

    int oszlopelteres=pos[0]-pozicio[0], sorelteres=pos[1]-pozicio[1];
    int oszlop_abszolut=(oszlopelteres<0 ? -oszlopelteres : oszlopelteres);
    int sor_abszolut=(sorelteres<0 ? -sorelteres : sorelteres);

    return ((oszlop_abszolut==1 && sor_abszolut==2) || (oszlop_abszolut==2 && sor_abszolut==1));
}

/*
Feladat:
jeloles függvény:
- A huszár figurához tartozó karakter: 'H'
*/
char Huszar::jeloles() const
{
    return 'H';
}
