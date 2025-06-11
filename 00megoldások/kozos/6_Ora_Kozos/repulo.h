#ifndef REPULO_H
#define REPULO_H

#include "jarmu.h"

// Származtass a Jarmu osztályból két másik osztályt:
// A Repulo osztály tároljon még egy utas létszámot.
// Mindkét osztály a konstruktorban várja az új értékeket is.
// A Jarmu osztályban van egy kiir függvény, amely megjeleníti az adatokat. 
// Ezt a függvényt fejtsd ki a gyerekosztályokban is.

class Repulo : public Jarmu
{
    unsigned int utasok; // plusz adattag: utas létszám
public:
    Repulo(unsigned int t, unsigned int s, unsigned int u); // konstruktor plusz értékkel
    void kiir() const; // override: Jarmu::kiir()
};

#endif // REPULO_H
