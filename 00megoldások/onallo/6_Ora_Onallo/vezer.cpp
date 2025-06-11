#include "vezer.h"

/*
Feladat:
Vezer osztály:
- Származik a Figura osztályból
- Konstruktor: beállítja a kezdő pozíciót
*/
Vezer::Vezer(const string &pos):
    Figura(pos)
{
}

/*
Feladat:
A Vezer osztály lephet függvénye:
- A vezér tud bástya- és futó-módon is lépni
- Nem maradhat helyben
*/
bool Vezer::lephet(const string &pos) const
{
    if (pos.length()<2) return false;

    int oszlopelteres=pos[0]-pozicio[0], sorelteres=pos[1]-pozicio[1];
    int oszlop_abszolut=(oszlopelteres<0 ? -oszlopelteres : oszlopelteres);
    int sor_abszolut=(sorelteres<0 ? -sorelteres : sorelteres);

    if (oszlop_abszolut==0 && sor_abszolut==0) return false;

    else if (oszlop_abszolut==sor_abszolut) return true;

    else if ((pos[0]==pozicio[0]) ^ (pos[1]==pozicio[1])) return true;

    else return false;
}

/*
Feladat:
jeloles függvény:
- A vezér figurához tartozó karakter: 'V'
*/
char Vezer::jeloles() const
{
    return 'V';
}
