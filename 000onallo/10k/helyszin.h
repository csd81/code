#ifndef HELYSZIN_H
#define HELYSZIN_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "esemeny.h"

class Helyszin
{
    std::string nev;
    std::string cim;
    std::vector<Esemeny> esemenyek;
public:

    void betolt(const std::string& jsonFajl);
    void kiir();
    void esemenyHosszKiir(const std::string& kimenetiFajl);
};

#endif // HELYSZIN_H

