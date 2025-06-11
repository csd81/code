#ifndef BASTYA_H
#define BASTYA_H

#include "figura.h"

/*
Feladat:
Származtass a Figura osztályból Bastya osztályt.
- A bástya vízszintesen vagy függőlegesen bármennyit léphet.
- Nem maradhat helyben.

Feladat:
Fejtsd ki a lephet függvényt.

Feladat:
Fejtsd ki a jeloles függvényt: 'B'
*/

class Bastya : public Figura
{
public:
    // Konstruktor: beállítja a kezdőpozíciót.
    Bastya(const string &pos);

    // Megmondja, hogy a bástya léphet-e a megadott pozícióra.
    bool lephet(const string &pos) const;

    // A bástya jelölése: 'B'.
    char jeloles() const;
};

#endif // BASTYA_H
