#ifndef VERSENY_H
#define VERSENY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// using namespace std;

#include "probalkozas.h"

class Verseny
{

    std::string    megnevezes;
    std::vector<Probalkozas> probvec;
public:
    Verseny(const std::string& versenyfile);
    void kiir() const;
    std::ostream& kiir(std::ostream& os) const;
    void kiir(const std::string& outfile) const;

    void uj(std::string nev, double tavolsag, bool ervenyes);
    std::vector<double> ervenyesDobasok() const;


    void nevSzerint(const std::string& nev, std::vector<Probalkozas>& pv) const;



};

#endif // VERSENY_H



