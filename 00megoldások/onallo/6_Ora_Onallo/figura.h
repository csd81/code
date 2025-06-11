#ifndef FIGURA_H
#define FIGURA_H

#include <string>

using namespace std;

/*
Feladat:
A Figura osztály egy sakkfigura adatait tárolja:
- az oszlop és a sor (egy darab szöveg, pl. "A5" vagy "G2").
A pozíciót a konstruktorban várja.

Feladat:
Készíts statikus ervenyes függvényt.
- Érvényes pozíció: két karakterből áll
  - első: nagybetű A-H
  - második: számjegy 1-8

Feladat:
A Figura osztályba készíts egy tisztán virtuális lephet függvényt,
amely megmondja, hogy a figura léphet-e a megadott pozícióra.
(Feltételezi, hogy a pozíció érvényes.)

Feladat:
Készíts odalep függvényt:
- Ha érvényes pozíció, és a figura léphet rá → állítsa be a pozíciót.
- Visszatérési érték: sikeres volt-e a lépés.

Feladat:
Készíts tisztán virtuális jeloles függvényt:
- Egy karaktert ad vissza (pl. bástya 'B', király 'K', stb.)
*/

class Figura
{
protected:
    // A figura pozíciója sakk-táblán, pl. "A5" vagy "G2".
    string pozicio;

public:
    // Konstruktor: beállítja a figura kezdőpozícióját.
    Figura(const string &pos);

    // Pozíció lekérdezése.
    const string &getPozicio() const;

    // Destruktor (virtuális a helyes öröklés biztosítására).
    virtual ~Figura();

    // Statikus függvény: ellenőrzi, hogy a megadott pozíció érvényes-e.
    static bool ervenyes(const string &pos);

    // Tisztán virtuális függvény:
    // Megmondja, hogy a figura léphet-e az adott pozícióra.
    virtual bool lephet(const string &pos) const = 0;

    // Megpróbál a megadott pozícióra lépni:
    // Ha érvényes és léphet oda → beállítja a pozíciót.
    bool odalep(const string &pos);

    // Tisztán virtuális függvény:
    // Visszaadja a figurához tartozó karakteres jelölést.
    virtual char jeloles() const = 0;
};

#endif // FIGURA_H
