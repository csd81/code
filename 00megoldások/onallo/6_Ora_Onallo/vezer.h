#ifndef VEZER_H
#define VEZER_H

#include "figura.h"

/*
Feladat:
Készítsd el a Vezer osztályt (Figura leszármazottja).

Feladat:
A vezér tud bástya- és futó-módon is lépni:
- vízszintesen, függőlegesen vagy átlósan bármennyit.
- Nem maradhat helyben.

Feladat:
Fejtsd ki a lephet függvényt.

Feladat:
Fejtsd ki a jeloles függvényt: 'V'
*/

class Vezer : public Figura
{
public:
    // Konstruktor: beállítja a kezdőpozíciót.
    Vezer(const string &pos);

    // Megmondja, hogy a vezér léphet-e a megadott pozícióra.
    bool lephet(const string &pos) const;

    // A vezér jelölése: 'V'.
    char jeloles() const;
};

#endif // VEZER_H
