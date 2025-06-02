// Teglalap gyerekosztály

// 20. Legyen egy Teglalap osztály a Halmaz osztályból származtatva, ami egy tengelypárhuzamos téglalapot fog reprezentálni. Ne legyen saját adattagja. Legyen egy konstruktora, ami paraméterben a téglalapot meghatározó négy double értéket vár: 𝑥𝑚𝑖𝑛 , 𝑥𝑚𝑎𝑥 , 𝑦𝑚𝑖𝑛 , 𝑦𝑚𝑎𝑥 . Feltételezhetjük, hogy 𝑥𝑚𝑖𝑛 < 𝑥𝑚𝑎𝑥 és 𝑦𝑚𝑖𝑛 < 𝑦𝑚𝑎𝑥 , ezt nem kell külön ellenőrizni. Az ősosztálynak átadott megnevezés legyen "RECTANGLE", és a ponthalmaz a fenti határok által meghatározott téglalap négy csúcsából álljon (tetszőleges sorrendben), vagyis: (𝑥𝑚𝑖𝑛 , 𝑦𝑚𝑖𝑛 ), (𝑥𝑚𝑖𝑛 , 𝑦𝑚𝑎𝑥 ), (𝑥𝑚𝑎𝑥 , 𝑦𝑚𝑎𝑥 ), (𝑥𝑚𝑎𝑥 , 𝑦𝑚𝑖𝑛 ).

// 21. *Legyen a Teglalap osztályban egy terulet függvény, ami visszaadja a téglalap területét (double).

// 22. *Legyen a Teglalap osztályban egy tartalmaz függvény, ami paraméterben egy Pont-ot kap, és visszaad egy bool értéket aszerint, hogy a Pont a téglalapon belül van-e. A téglalap kerületén lévő pontok belsőnek számítanak.


#ifndef TEGLALAP_H
#define TEGLALAP_H

#include "halmaz.h"

class Teglalap : public Halmaz
{
public:
    Teglalap(double xmin, double xmax, double ymin, double ymax);
    double terulet() const;
    bool tartalmaz(Pont p) const;
};


#endif // TEGLALAP_H


// Teglalap gyerekosztály

// 20. Legyen egy Teglalap osztály a Halmaz osztályból származtatva, ami egy tengelypárhuzamos téglalapot fog reprezentálni. Ne legyen saját adattagja. Legyen egy konstruktora, ami paraméterben a téglalapot meghatározó négy double értéket vár: 𝑥𝑚𝑖𝑛 , 𝑥𝑚𝑎𝑥 , 𝑦𝑚𝑖𝑛 , 𝑦𝑚𝑎𝑥 . Feltételezhetjük, hogy 𝑥𝑚𝑖𝑛 < 𝑥𝑚𝑎𝑥 és 𝑦𝑚𝑖𝑛 < 𝑦𝑚𝑎𝑥 , ezt nem kell külön ellenőrizni. Az ősosztálynak átadott megnevezés legyen "RECTANGLE", és a ponthalmaz a fenti határok által meghatározott téglalap négy csúcsából álljon (tetszőleges sorrendben), vagyis: (𝑥𝑚𝑖𝑛 , 𝑦𝑚𝑖𝑛 ), (𝑥𝑚𝑖𝑛 , 𝑦𝑚𝑎𝑥 ), (𝑥𝑚𝑎𝑥 , 𝑦𝑚𝑎𝑥 ), (𝑥𝑚𝑎𝑥 , 𝑦𝑚𝑖𝑛 ).

// 21. *Legyen a Teglalap osztályban egy terulet függvény, ami visszaadja a téglalap területét (double).

// 22. *Legyen a Teglalap osztályban egy tartalmaz függvény, ami paraméterben egy Pont-ot kap, és visszaad egy bool értéket aszerint, hogy a Pont a téglalapon belül van-e. A téglalap kerületén lévő pontok belsőnek számítanak.
