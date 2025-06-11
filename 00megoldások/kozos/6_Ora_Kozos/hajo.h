#ifndef HAJO_H
#define HAJO_H

#include "jarmu.h"

// Származtass a Jarmu osztályból két másik osztályt:
// A Hajo osztály pedig tároljon még egy teherbírás értéket.
// Mindkét osztály a konstruktorban várja az új értékeket is.

class Hajo : public Jarmu
{
    unsigned int teherbiras; // plusz adattag: teherbírás
public:
    Hajo(unsigned int t, unsigned int s, unsigned int teher); // konstruktor plusz értékkel
    void kiir() const; // override: Jarmu::kiir()
};

#endif // HAJO_H
