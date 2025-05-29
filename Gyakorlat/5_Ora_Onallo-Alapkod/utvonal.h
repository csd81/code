#ifndef UTVONAL_H
#define UTVONAL_H

#include "halmaz.h"

class Utvonal : public Halmaz
{
public:
    Utvonal();
};

#endif // UTVONAL_H

Utvonal gyerekosztály
13. Legyen egy Utvonal osztály a Halmaz osztályból származtatva. Legyen konstruktor, ami nem vár
paramétert, az ősosztálynak átadott megnevezés a "PATH" legyen, és kezdetben a ponthalmaz üres.
Legyen továbbá egy irányt jelölő logikai adattag, ami kezdetben true.
14. *Legyen egy megfordit függvény az Utvonal osztályban, ami az irányt jelölő logikai változót az
ellentettjére állítja.
15. *Írd felül a kiir függvényt az Utvonal osztályban úgy, hogy ha az irányt jelölő logikai változó értéke
false, akkor a pontok fordított sorrendben kerüljenek kiírásra (a tárolási sorrend nem változik).
16. *Legyen egy hossz függvény az Utvonal osztályban, ami visszaadja a reprezentált útvonal hosszát
(double). Ha kettőnél kevesebb pont van a halmazban, akkor a hossz 0, egyébként a szomszédos
pontok távolságainak az összege. Tipp: használható a Pont osztályból a statikus tavolsag függvény két
pont távolságának kiszámítására.

