#ifndef SZURKE_H
#define SZURKE_H

#include "szin.h"

// --- SPECIFIKÁCIÓ ---
// Szurke osztály a Szin osztályból származik
// Egy double értéket tárol 0 és 1 között: világosság
// - 0: teljesen fekete
// - 1: teljesen fehér
// - közte arányosan változik
//
// Implementálandó metódusok:
// - R(), G(), B(): vilagos * 255

class Szurke : public Szin
{
    double vilagos; // 0..1 világosság

public:
    Szurke(double vilagos);

    virtual unsigned char R() const;
    virtual unsigned char G() const;
    virtual unsigned char B() const;
};

#endif // SZURKE_H
