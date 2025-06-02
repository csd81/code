// Haromszog gyerekosztály

// 17. Legyen egy Haromszog osztály a Halmaz osztályból származtatva. Ne legyen saját adattagja. Legyen egy konstruktora, ami három Pont paramétert vár, ezek a háromszög csúcsai. A ponthalmaz ebből a három Pont-ból álljon. Az ősosztálynak átadott megnevezés a "TRIANGLE" legyen.

// 18. *Legyen a Haromszog osztályban egy getA, getB és getC függvény, amik visszaadják a háromszög csúcsait. A csúcsokat az ősosztályban tárolt háromelemű vector<Pont> tárolóból kell kinyerni.

// 19. *Legyen egy alak függvény a Haromszog osztályban, ami egy string-et ad vissza. Ez a "hegyesszogu", "derekszogu" és "tompaszogu" valamelyike lehet az alábbiak szerint. Tegyük fel, hogy a háromszög oldalai 𝑣, 𝑤 és 𝑧, amik közül 𝑧 a leghosszabb. Számítsuk ki a 𝐷 = 𝑧 2 − (𝑣 2 + 𝑤 2 ) kifejezést.

// • Ha 𝐷 < −10−8 , akkor háromszög hegyesszögű.
// • Ha −10−8 ≤ 𝐷 ≤ 10−8 , akkor a háromszög derékszögű.
// • Ha 10−8 < 𝐷, akkor a háromszög tompaszögű.

// Itt is használható a Pont osztály statikus tavolsag függvénye.



#ifndef HAROMSZOG_H
#define HAROMSZOG_H

#include "halmaz.h"

class Haromszog : public Halmaz
{
public:
    Haromszog(const Pont& a, const Pont& b, const Pont& c);
    const Pont& getA() const;
    const Pont& getB() const;
    const Pont& getC() const;
    std::string alak() const;
};

#endif // HAROMSZOG_H


// Haromszog gyerekosztály
//17. Legyen egy Haromszog osztály a Halmaz osztályból származtatva. Ne legyen saját adattagja. Legyen egy konstruktora, ami három Pont paramétert vár, ezek a háromszög csúcsai. A ponthalmaz ebből a három Pont-ból álljon. Az ősosztálynak átadott megnevezés a "TRIANGLE" legyen.

//  18. *Legyen a Haromszog osztályban egy getA, getB és getC függvény, amik visszaadják a háromszög csúcsait. A csúcsokat az ősosztályban tárolt háromelemű vector<Pont> tárolóból kell kinyerni.

// 19. *Legyen egy alak függvény a Haromszog osztályban, ami egy string-et ad vissza. Ez a "hegyesszogu", "derekszogu" és "tompaszogu" valamelyike lehet az alábbiak szerint. Tegyük fel, hogy a háromszög oldalai 𝑣, 𝑤 és 𝑧, amik közül 𝑧 a leghosszabb. Számítsuk ki a 𝐷 = 𝑧 2 − (𝑣 2 + 𝑤 2 ) kifejezést.

// • Ha 𝐷 < −10−8 , akkor háromszög hegyesszögű.
// • Ha −10−8 ≤ 𝐷 ≤ 10−8 , akkor a háromszög derékszögű.
// • Ha 10−8 < 𝐷, akkor a háromszög tompaszögű.

// Itt is használható a Pont osztály statikus tavolsag függvénye.
