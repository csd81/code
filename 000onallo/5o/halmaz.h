#ifndef HALMAZ_H
#define HALMAZ_H
#include <vector>
#include <iostream>
#include "pont.h"

class Halmaz
{
protected:
    std::string megnevezes;
    vector<Pont> tarolo;
public:
    Halmaz(std::string m);
    Halmaz(std::string m, int elemszam);

    void hozzaad(Pont p);
    void hozzaad(double x, double y);
    virtual void kiir() const;
    void beolvas(const std::string& filename);
    void fajlbair(const std::string& filename) const;
};

#endif // HALMAZ_H
