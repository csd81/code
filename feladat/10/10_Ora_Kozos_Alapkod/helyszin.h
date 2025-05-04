#ifndef HELYSZIN_H
#define HELYSZIN_H
#include <vector>
#include <string>
#include "esemeny.h"

class Helyszin
{
private:
    std::string nev;
    std::string cim;
    std::vector<Esemeny> esemenyek;

public:
    Helyszin() = default;

    void betolt(const std::string& fajlnev);

    void kiir() const;
    void esemenyHosszKiir(const std::string& fajlnev) const;
};

#endif // HELYSZIN_H
