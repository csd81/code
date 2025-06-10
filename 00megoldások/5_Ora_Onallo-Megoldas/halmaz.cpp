#include "halmaz.h"
#include <fstream>
using namespace std;

// --- SPECIFIKÁCIÓ PDF 6. ---
// konstruktor: csak megnevezés
Halmaz::Halmaz(const string &megnevezes): megnevezes(megnevezes) {}

// --- SPECIFIKÁCIÓ PDF 7. ---
// konstruktor: megnevezés + elemszám
Halmaz::Halmaz(const string &megnevezes, size_t meret): megnevezes(megnevezes), pontok(meret) {}

// --- SPECIFIKÁCIÓ PDF 8. ---
// hozzaad(Pont)
void Halmaz::hozzaad(const Pont &ujpont) {
    pontok.push_back(ujpont);
}

// --- SPECIFIKÁCIÓ PDF 9. ---
// hozzaad(x, y): függvénytúlterhelés
void Halmaz::hozzaad(double x, double y) {
    hozzaad(Pont(x,y));
}

// --- SPECIFIKÁCIÓ PDF 10. ---
// kiir(): megnevezés, elemszám, pontok listázása
void Halmaz::kiir() const {
    cout << megnevezes << " [" << pontok.size() << "]:";
    for (size_t i=0;i<pontok.size();i++)
        pontok[i].kiir();
    cout << endl;
}

// --- SPECIFIKÁCIÓ PDF 11. ---
// beolvas(fajl): fájlból pontok beolvasása
void Halmaz::beolvas(const string &fajl) {
    pontok.clear(); // előző pontok törlése
    ifstream in(fajl);
    if (!in.is_open()) {
        cout << "Hiba! Nem sikerult megnyitni a fajlt: " << fajl << endl;
        return;
    }

    size_t N;
    in >> N;
    for (size_t i=0;i<N;i++) {
        double x, y;
        in >> x >> y;
        hozzaad(x,y);
    }
}

// --- SPECIFIKÁCIÓ PDF 12. ---
// fajlbair(fajl): fájlba pontok mentése, beolvasható formátumban
void Halmaz::fajlbair(const string &fajl) const {
    ofstream out(fajl);
    out << pontok.size() << endl;
    for (size_t i=0;i<pontok.size();i++)
        out << pontok[i].getX() << ' ' << pontok[i].getY() << endl;
}
