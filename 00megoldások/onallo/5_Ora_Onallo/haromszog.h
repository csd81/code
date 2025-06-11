#ifndef HAROMSZOG_H
#define HAROMSZOG_H

#include "halmaz.h"

// --- SPECIFIKÁCIÓ: HAROMSZÖG ---
// 17. konstruktor: 3 Pont → "TRIANGLE"
// 18. getA(), getB(), getC()
// 19. alak() → "hegyesszogu", "derekszogu", "tompaszogu"

class Haromszog : public Halmaz
{
public:
    Haromszog(const Pont& A,
              const Pont& B,
              const Pont& C);

    Pont getA () const;
    Pont getB () const;
    Pont getC () const;

    string alak () const;
};

#endif // HAROMSZOG_H
