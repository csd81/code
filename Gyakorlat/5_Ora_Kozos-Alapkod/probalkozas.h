#ifndef PROBALKOZAS_H
#define PROBALKOZAS_H

#include <string>
using namespace std;

class Probalkozas
{
    string nev;
    double tavolsag;
    bool ervenyes;
public:
    Probalkozas (const string& nev, double tavolsag, bool ervenyes);
    const string& getNev () const;
    double getTavolsag () const;
    bool getErvenyes () const;
};

#endif // PROBALKOZAS_H
