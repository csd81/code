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
    Probalkozas ();
    const string& getNev () const;
    double getTavolsag () const;
    bool getErvenyes () const;
    void setNev(const string &newNev);
    void setTavolsag(double newTavolsag);
    void setErvenyes(bool newErvenyes);
};

#endif // PROBALKOZAS_H
