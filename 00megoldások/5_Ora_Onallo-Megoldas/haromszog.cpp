#include "haromszog.h"

// --- SPECIFIKÁCIÓ PDF 17. ---
// konstruktor: 3 Pont → "TRIANGLE"
Haromszog::Haromszog(const Pont &A, const Pont &B, const Pont &C): Halmaz("TRIANGLE") {
    hozzaad(A);
    hozzaad(B);
    hozzaad(C);
}

// --- SPECIFIKÁCIÓ PDF 18. ---
// getA(), getB(), getC()
Pont Haromszog::getA() const { return pontok[0]; }
Pont Haromszog::getB() const { return pontok[1]; }
Pont Haromszog::getC() const { return pontok[2]; }

// --- SPECIFIKÁCIÓ PDF 19. ---
// alak(): háromszög típusa
string Haromszog::alak() const {
    double a = Pont::tavolsag(getB(), getC());
    double b = Pont::tavolsag(getC(), getA());
    double c = Pont::tavolsag(getA(), getB());

    if (a > c) swap(a,c);
    if (b > c) swap(b,c);

    double D = c*c - (a*a + b*b);
    if (D < -1e-8) return "hegyesszogu";
    if (D > 1e-8) return "tompaszogu";
    return "derekszogu";
}
