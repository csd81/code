// Haromszog gyerekosztály

//17. Legyen egy Haromszog osztály a Halmaz osztályból származtatva. Ne legyen saját adattagja. Legyen egy konstruktora, ami három Pont paramétert vár, ezek a háromszög csúcsai. A ponthalmaz ebből a három Pont-ból álljon. Az ősosztálynak átadott megnevezés a "TRIANGLE" legyen.

//  18. *Legyen a Haromszog osztályban egy getA, getB és getC függvény, amik visszaadják a háromszög csúcsait. A csúcsokat az ősosztályban tárolt háromelemű vector<Pont> tárolóból kell kinyerni.

// 19. *Legyen egy alak függvény a Haromszog osztályban, ami egy string-et ad vissza. Ez a "hegyesszogu", "derekszogu" és "tompaszogu" valamelyike lehet az alábbiak szerint. Tegyük fel, hogy a háromszög oldalai 𝑣, 𝑤 és 𝑧, amik közül 𝑧 a leghosszabb. Számítsuk ki a 𝐷 = 𝑧 2 − (𝑣 2 + 𝑤 2 ) kifejezést.

// • Ha 𝐷 < −10−8 , akkor háromszög hegyesszögű.
// • Ha −10−8 ≤ 𝐷 ≤ 10−8 , akkor a háromszög derékszögű.
// • Ha 10−8 < 𝐷, akkor a háromszög tompaszögű.

// Itt is használható a Pont osztály statikus tavolsag függvénye.


#include "haromszog.h"
#include <algorithm>


Haromszog::Haromszog(const Pont &a, const Pont &b, const Pont &c) : Halmaz("TRIANGLE", 0)
{
    // pv.clear();
    hozzaad(a);
    hozzaad(b);
    hozzaad(c);

}

const Pont &Haromszog::getA() const
{
    return getPontok()[0];

}

const Pont &Haromszog::getB() const
{
    return getPontok()[1];

}

const Pont &Haromszog::getC() const
{
    return getPontok()[2];

}

string Haromszog::alak() const
{
    const auto& pontok = getPontok();
    double v = Pont::tavolsag(pontok[0], pontok[1]);
    double w = Pont::tavolsag(pontok[1], pontok[2]);
    double z = Pont::tavolsag(pontok[2], pontok[0]);

    double maxOldal = std::max({v,w,z});
    double osszeg = v*v + w*w + z*z - maxOldal * maxOldal;
    double D = maxOldal*maxOldal - osszeg;
    const double  eps = 1e-8;

    if (D < -eps)
        return   "hegyesszogu";
    else if (D <= eps)
        return   "derekszogu";
    else
        return "tompaszogu";

}


// Haromszog gyerekosztály
//17. Legyen egy Haromszog osztály a Halmaz osztályból származtatva. Ne legyen saját adattagja. Legyen egy konstruktora, ami három Pont paramétert vár, ezek a háromszög csúcsai. A ponthalmaz ebből a három Pont-ból álljon. Az ősosztálynak átadott megnevezés a "TRIANGLE" legyen.

//  18. *Legyen a Haromszog osztályban egy getA, getB és getC függvény, amik visszaadják a háromszög csúcsait. A csúcsokat az ősosztályban tárolt háromelemű vector<Pont> tárolóból kell kinyerni.

// 19. *Legyen egy alak függvény a Haromszog osztályban, ami egy string-et ad vissza. Ez a "hegyesszogu", "derekszogu" és "tompaszogu" valamelyike lehet az alábbiak szerint. Tegyük fel, hogy a háromszög oldalai 𝑣, 𝑤 és 𝑧, amik közül 𝑧 a leghosszabb. Számítsuk ki a 𝐷 = 𝑧 2 − (𝑣 2 + 𝑤 2 ) kifejezést.

// • Ha 𝐷 < −10−8 , akkor háromszög hegyesszögű.
// • Ha −10−8 ≤ 𝐷 ≤ 10−8 , akkor a háromszög derékszögű.
// • Ha 10−8 < 𝐷, akkor a háromszög tompaszögű.

// Itt is használható a Pont osztály statikus tavolsag függvénye.
