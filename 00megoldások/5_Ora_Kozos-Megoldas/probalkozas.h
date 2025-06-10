#ifndef PROBALKOZAS_H
#define PROBALKOZAS_H

#include <string>
using namespace std;

// Spec 1. Legyen a Probalkozas osztályban paraméter nélküli konstruktor.
// A név "ismeretlen", távolság 0, érvényesség false.

class Probalkozas
{
    string nev;
    double tavolsag;
    bool ervenyes;
public:
    Probalkozas(); // Spec 1.
    Probalkozas(const string& nev, double tavolsag, bool ervenyes);

    // Spec: getterek
    const string& getNev() const;
    double getTavolsag() const;
    bool getErvenyes() const;
};

#endif // PROBALKOZAS_H
