#include "teglalap.h"

Teglalap::Teglalap(double xmin, double xmax, double ymin, double ymax)
    : Halmaz("RECTANGLE", 0)
{
    hozzaad(Pont(xmin, ymin));
    hozzaad(Pont(xmin, ymax));
    hozzaad(Pont(xmax, ymin));
    hozzaad(Pont(xmax, ymax));
}

double Teglalap::terulet() const
{
    const auto& pontok = getPontok();

    double szelesseg = Pont::tavolsag(pontok[0], pontok[3]);
;
    double magassag = Pont::tavolsag(pontok[0], pontok[1]);
;

    return szelesseg * magassag;

}

bool Teglalap::tartalmaz(Pont p) const
{
    const auto& pontok = getPontok();
    double xmin = pontok[0].getX();
    double xmax = pontok[2].getX();
    double ymin = pontok[0].getY();
    double ymax = pontok[1].getY();

    return (p.getX() >= xmin && p.getX() <= xmax) &&
           (p.getY() >= ymin && p.getY() <= ymax);
}


// Teglalap gyerekosztály

// 20. Legyen egy Teglalap osztály a Halmaz osztályból származtatva, ami egy tengelypárhuzamos téglalapot fog reprezentálni. Ne legyen saját adattagja. Legyen egy konstruktora, ami paraméterben a téglalapot meghatározó négy double értéket vár: 𝑥𝑚𝑖𝑛 , 𝑥𝑚𝑎𝑥 , 𝑦𝑚𝑖𝑛 , 𝑦𝑚𝑎𝑥 . Feltételezhetjük, hogy 𝑥𝑚𝑖𝑛 < 𝑥𝑚𝑎𝑥 és 𝑦𝑚𝑖𝑛 < 𝑦𝑚𝑎𝑥 , ezt nem kell külön ellenőrizni. Az ősosztálynak átadott megnevezés legyen "RECTANGLE", és a ponthalmaz a fenti határok által meghatározott téglalap négy csúcsából álljon (tetszőleges sorrendben), vagyis: (𝑥𝑚𝑖𝑛 , 𝑦𝑚𝑖𝑛 ), (𝑥𝑚𝑖𝑛 , 𝑦𝑚𝑎𝑥 ), (𝑥𝑚𝑎𝑥 , 𝑦𝑚𝑎𝑥 ), (𝑥𝑚𝑎𝑥 , 𝑦𝑚𝑖𝑛 ).

// 21. *Legyen a Teglalap osztályban egy terulet függvény, ami visszaadja a téglalap területét (double).

// 22. *Legyen a Teglalap osztályban egy tartalmaz függvény, ami paraméterben egy Pont-ot kap, és visszaad egy bool értéket aszerint, hogy a Pont a téglalapon belül van-e. A téglalap kerületén lévő pontok belsőnek számítanak.
