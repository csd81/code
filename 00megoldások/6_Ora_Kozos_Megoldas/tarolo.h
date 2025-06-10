#ifndef TAROLO_H
#define TAROLO_H

#include "jarmu.h"

// Adott még egy Tarolo osztály, amely legfeljebb 5 járművet tárol, mutatókkal.

#define TAROLO_KAPACITAS 5

class Tarolo
{
    Jarmu *tomb[TAROLO_KAPACITAS]; // Tároló tömb, max. 5 jármű mutatója
public:
    Tarolo(); // Konstruktor
    ~Tarolo(); // Destruktor - Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.
    void beallit(unsigned int index, Jarmu *j); // Jármű beállítása egy adott indexre
    void megjelenit() const; // Tárolt járművek megjelenítése
    Tarolo(const Tarolo &t); // Másoló konstruktor - Készíts másoló konstruktort a Tarolo osztályba.
};

#endif // TAROLO_H
