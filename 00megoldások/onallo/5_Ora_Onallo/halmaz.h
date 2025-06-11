#ifndef HALMAZ_H
#define HALMAZ_H

#include <vector>
using namespace std;

#include "pont.h"

// --- SPECIFIKÁCIÓ: HALMAZ ---
// 6. adattagok: megnevezés (string), pontokat tároló vector<Pont>
//    konstruktor: csak megnevezés
// 7. konstruktor: megnevezés + elemszám → default origó pontok
// 8. hozzaad(Pont)
// 9. hozzaad(x,y) — függvény túlterhelés
// 10. kiir() — megnevezés, elemszám, pontok
// 11. beolvas(fájl)
// 12. fajlbair(fájl)

class Halmaz
{
protected:
    string megnevezes;
    vector<Pont> pontok;
public:
    Halmaz(const string& megnevezes);
    Halmaz(const string& megnevezes, size_t meret);

    void hozzaad (const Pont& ujpont);
    void hozzaad (double x, double y);

    void kiir () const;

    void beolvas (const string& fajl);
    void fajlbair (const string& fajl) const;
};

#endif // HALMAZ_H
