#ifndef HELYSZIN_H
#define HELYSZIN_H

#include "esemeny.h"
#include <vector>

class Helyszin
{
    string nev, cim;
    vector<Esemeny> esemenyek;
public:
    void betolt(const string &fajlnev);
    void kiir() const;
    void esemenyHosszKiir(const string &fajlnev) const;
};

#endif // HELYSZIN_H
