// Sokszog gyerekosztály
// 23. Legyen egy Sokszog osztály a Halmaz osztályból származtatva, ami tetszőleges számú csúcsból álló sokszöglapot fog reprezentálni. Ne legyen saját adattagja. Legyen egy konstruktora, aminek ezúttal egy paramétere van: várja a megnevezést (string), ezt továbbítja az ősosztálynak. A ponthalmaz kezdetben üres.

// 24. *Legyen egy kerulet függvény a Sokszog osztályban, ami visszaadja a sokszög kerületét. A számítás módja ugyanaz, mint az Utvonal osztály hossz függvénye esetén, csak az első és utolsó pont távolságát is az összeghez kell adni.

// 25. *Legyen egy bennfoglalo függvény a Sokszog osztályban, ami nem vár paramétert, és egy minimális területű Teglalap objektumot ad vissza, ami tartalmazza a Sokszog-et.


#include "sokszog.h"
#include "teglalap.h"
#include <algorithm>

Sokszog::Sokszog(std::string megnevezes) : Halmaz(megnevezes)

{}

double Sokszog::kerulet() const
{
    const auto& pontok = getPontok();
    size_t n = pontok.size();
    if (n < 2)
        return 0.0;

    double osszeg = 0.0;

    for (size_t i = 0; i < n - 1; ++i) {
        osszeg += Pont::tavolsag(pontok[i], pontok[i+1]);
    }

    osszeg += Pont::tavolsag(pontok[n-1], pontok[0]);
    return osszeg;

}

Teglalap Sokszog::bennfoglalo() const
{
    const auto& pontok = getPontok();
    if (pontok.empty()) {
        // Üres sokszög esetén például egy nulla méretű téglalapot adunk vissza
        return Teglalap(0, 0, 0, 0);
    }

    double xmin = pontok[0].getX();
    double xmax = pontok[0].getX();
    double ymin = pontok[0].getY();
    double ymax = pontok[0].getY();

    for (const auto& p : pontok) {
        if (p.getX() < xmin) xmin = p.getX();
        if (p.getX() > xmax) xmax = p.getX();

        if (p.getY() < ymin) ymin = p.getY();
        if (p.getY() > ymax) ymax = p.getY();
    }


    return Teglalap(xmin, xmax, ymin, ymax);

}
