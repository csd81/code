#ifndef VERSENY_H
#define VERSENY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "probalkozas.h"

class Verseny
{
    string megnevezes;
    vector<Probalkozas> probalkozasok;
public:
    Verseny(const string &filenev);
    void kiir() const;
    void kiir(ostream& os) const;
    void kiir(const string& filenev) const;
    void uj(const string& n,double t,bool e);
    vector<double> ervenyesDobasok() const;
    void nevSzerint(const string& nev, vector<Probalkozas>& cel) const;
    string getMegnevezes() const;
    void setMegnevezes(const string &newMegnevezes);
    vector<Probalkozas> getProbak() const;
    void setProbak(const vector<Probalkozas> &newProbak);
};

#endif // VERSENY_H








