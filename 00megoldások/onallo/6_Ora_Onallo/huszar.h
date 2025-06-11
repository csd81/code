#ifndef HUSZAR_H
#define HUSZAR_H

#include "figura.h"

/*
Feladat:
Készítsd el a Huszar osztályt (Figura leszármazottja).

Feladat:
A huszár "L" alakban léphet (2+1 lépés).
- Nem maradhat helyben.

Feladat:
Fejtsd ki a lephet függvényt.

Feladat:
Fejtsd ki a jeloles függvényt: 'H'
*/

class Huszar : public Figura
{
public:
    // Konstruktor: beállítja a kezdőpozíciót.
    Huszar(const string &pos);

    // Megmondja, hogy a huszár léphet-e a megadott pozícióra.
    bool lephet(const string &pos) const;

    // A huszár jelölése: 'H'.
    char jeloles() const;
};

#endif // HUSZAR_H
