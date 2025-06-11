#ifndef KIRALY_H
#define KIRALY_H

#include "figura.h"

/*
Feladat:
Származtass a Figura osztályból Kiraly osztályt.

Feladat:
A király 1 mezőt léphet bármilyen irányban (összesen 8 lehetőség).
- Nem maradhat helyben.

Feladat:
Fejtsd ki a lephet függvényt.

Feladat:
Fejtsd ki a jeloles függvényt: 'K'
*/

class Kiraly : public Figura
{
public:
    // Konstruktor: beállítja a kezdőpozíciót.
    Kiraly(const string &pos);

    // Megmondja, hogy a király léphet-e a megadott pozícióra.
    bool lephet(const string &pos) const;

    // A király jelölése: 'K'.
    char jeloles() const;
};

#endif // KIRALY_H
