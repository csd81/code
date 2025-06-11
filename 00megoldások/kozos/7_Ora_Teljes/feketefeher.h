#ifndef FEKETEFEHER_H
#define FEKETEFEHER_H

#include "szin.h"

// --- SPECIFIKÁCIÓ ---
// FeketeFeher osztály a Szin osztályból származik
// Egy logikai értéket tárol: fekete-e vagy fehér-e a szín
//
// Konstruktor: logikai értéket vár (true=fekete, false=fehér)
//
// Implementálandó metódusok:
// - R(), G(), B(): ha fekete -> 0, ha fehér -> 255

class FeketeFeher : public Szin
{
    bool fekete; // true: fekete, false: fehér

public:
    FeketeFeher(bool fekete);

    virtual unsigned char R() const;
    virtual unsigned char G() const;
    virtual unsigned char B() const;
};

#endif // FEKETEFEHER_H
