#ifndef FUTO_H
#define FUTO_H

#include "figura.h"

/*
Feladat:
Készítsd el a Futo osztályt (Figura leszármazottja).

Feladat:
A futó átlósan bármennyit léphet.
- Nem maradhat helyben.

Feladat:
Fejtsd ki a lephet függvényt.

Feladat:
Fejtsd ki a jeloles függvényt: 'F'
*/

class Futo : public Figura
{
public:
    // Konstruktor: beállítja a kezdőpozíciót.
    Futo(const string &pos);

    // Megmondja, hogy a futó léphet-e a megadott pozícióra.
    bool lephet(const string &pos) const;

    // A futó jelölése: 'F'.
    char jeloles() const;
};

#endif // FUTO_H
