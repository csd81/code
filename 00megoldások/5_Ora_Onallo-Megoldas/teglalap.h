#ifndef TEGLALAP_H
#define TEGLALAP_H

#include "halmaz.h"

// --- SPECIFIKÁCIÓ: TEGLALAP ---
// 20. konstruktor: xmin,xmax,ymin,ymax → "RECTANGLE"
// 21. terulet() — téglalap területe
// 22. tartalmaz(Pont) — pont belül van-e (kerületen is igen)

class Teglalap : public Halmaz
{
public:
    Teglalap(double xmin, double xmax,
             double ymin, double ymax);

    double terulet () const;
    bool tartalmaz (const Pont& pont) const;
};

#endif // TEGLALAP_H
