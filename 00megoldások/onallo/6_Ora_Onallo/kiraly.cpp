#include "kiraly.h"

/*
Feladat:
Kiraly osztály:
- Származik a Figura osztályból
- Konstruktor: beállítja a kezdő pozíciót
*/
Kiraly::Kiraly(const string &pos):
    Figura(pos)
{
}

/*
Feladat:
A Kiraly osztály lephet függvénye:
- A király 1 mezőt léphet bármilyen irányban (összesen 8 lehetőség)
- Nem maradhat helyben
*/
bool Kiraly::lephet(const string &pos) const
{
    if (pos.length()<2) return false;

    int oszlopelteres=pos[0]-pozicio[0], sorelteres=pos[1]-pozicio[1];

    int oszlop_abszolut=(oszlopelteres<0 ? -oszlopelteres : oszlopelteres);
    int sor_abszolut=(sorelteres<0 ? -sorelteres : sorelteres);
    int abszolut_max=(oszlop_abszolut>sor_abszolut ? oszlop_abszolut : sor_abszolut);

    return abszolut_max==1;
}

/*
Feladat:
jeloles függvény:
- A király figurához tartozó karakter: 'K'
*/
char Kiraly::jeloles() const
{
    return 'K';
}
