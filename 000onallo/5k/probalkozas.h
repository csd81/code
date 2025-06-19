#ifndef PROBALKOZAS_H
#define PROBALKOZAS_H

#include <vector>
#include <string>
// using namespace std;

class Probalkozas
{
    std::string nev;
    double tavolsag;
    bool ervenyes;
public:
    Probalkozas(const std::string& nev, double tavolsag, bool ervenyes);
    Probalkozas();
    const std::string& getNev () const;
    double getTavolsag () const;
    bool getErvenyes () const;
    void setNev(const std::string &newNev);
    void setTavolsag(double newTavolsag);
    void setErvenyes(bool newErvenyes);
};

#endif // PROBALKOZAS_H




