#include "futo.h"

/*
Feladat:
Futo osztály:
- Származik a Figura osztályból
- Konstruktor: beállítja a kezdő pozíciót
*/
Futo::Futo(const string &pos):
    Figura(pos)
{
}

/*
Feladat:
A Futo osztály lephet függvénye:
- A futó átlósan bármennyit léphet
- Nem maradhat helyben
*/
bool Futo::lephet(const string &pos) const
{
    if (pos.length()<2) return false;

    int oszlopelteres=pos[0]-pozicio[0], sorelteres=pos[1]-pozicio[1];
    int oszlop_abszolut=(oszlopelteres<0 ? -oszlopelteres : oszlopelteres);
    int sor_abszolut=(sorelteres<0 ? -sorelteres : sorelteres);

    return (!(oszlop_abszolut==0 && sor_abszolut==0) && oszlop_abszolut==sor_abszolut);
}

/*
Feladat:
jeloles függvény:
- A futó figurához tartozó karakter: 'F'
*/
char Futo::jeloles() const
{
    return 'F';
}
