#include "figura.h"

/*
Feladat:
A Figura osztály egy sakkfigura adatait tárolja:
- az oszlop és a sor (egy darab szöveg, pl. "A5" vagy "G2").
A pozíciót a konstruktorban várja.
*/
Figura::Figura(const string &pos):
    pozicio(pos)
{
}

/*
Feladat:
Statikus ervenyes függvény, amely ellenőrzi, hogy a megadott pozíció érvényes-e.
A pozíció érvényes, ha két karakterből áll:
- első karakter nagybetű (A-H)
- második karakter számjegy (1-8)
*/
bool Figura::ervenyes(const string &pos)
{
    if (pos.length()!=2) return false;
    return (pos[0]>='A' && pos[0]<='H' && pos[1]>='1' && pos[1]<='8');
}

/*
Feladat:
A figura aktuális pozícióját adja vissza.
*/
const string &Figura::getPozicio() const
{
    return pozicio;
}

/*
Feladat:
Destruktor. Mivel nincs külön lefoglalt memória, üres.
*/
Figura::~Figura()
{
}

/*
Feladat:
odalep függvény:
Ha a pozíció érvényes és a figura léphet oda, akkor átállítja a figura pozícióját ide.
Visszatérési érték: true, ha sikerült a lépés; különben false.
*/
bool Figura::odalep(const string &pos)
{
    if (ervenyes(pos) && lephet(pos))
    {
        pozicio=pos;
        return true;
    }
    else return false;
}
