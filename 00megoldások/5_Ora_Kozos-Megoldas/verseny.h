#ifndef VERSENY_H
#define VERSENY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "probalkozas.h"

// Spec 3. Verseny osztály legyen a következő két adattaggal:
// megnevezés (string) és vector<Probalkozas>

class Verseny
{
    string megnevezes;
    vector<Probalkozas> probalkozasok;
public:
    // Spec 4. konstruktor fájlbeolvasással
    Verseny(const string& inputfajl);

    // Spec 5–7. kiir() 3 változat
    void kiir(ostream& os = std::cout) const;
    void kiir(const string& outputfajl) const;

    // Spec 8. uj() függvény
    void uj(const string& nev, double tav, bool erv);

    // Spec 9. ervenyesDobasok() függvény
    vector<double> ervenyesDobasok() const;

    // Spec 11. nevSzerint() függvény
    void nevSzerint(const string& nev, vector<Probalkozas>& cel) const;
};

#endif // VERSENY_H
