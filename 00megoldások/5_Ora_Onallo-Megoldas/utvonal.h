#ifndef UTVONAL_H
#define UTVONAL_H

#include "halmaz.h"

// --- SPECIFIKÁCIÓ: UTVONAL ---
// 13. konstruktor: megnevezés legyen "PATH", pontok üresek, irány=true
// 14. megfordit() → irány változó ellenkezőre állítása
// 15. kiir() felülírva: ha irány == false, pontok fordított sorrendben
// 16. hossz() — szomszédos pontok távolságainak összege

class Utvonal : public Halmaz
{
    bool irany=true;
public:
    Utvonal();

    void megfordit ();
    void kiir ();
    double hossz () const;
};

#endif // UTVONAL_H
