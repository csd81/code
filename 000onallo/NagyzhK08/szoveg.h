#ifndef SZOVEG_H
#define SZOVEG_H

#include "adatmegjelenito.h"
#include <iostream>
using namespace std;

class Szoveg : public AdatMegjelenito
{
    string szooveg;
    int betumeret;
public:

    Szoveg(const string &szooveg, int betumeret, const string &szin, bool lathato);

    string getSzoveg() const;
    int getBetumeret() const;


    // AdatMegjelenito interface
public:
    void megjelenit() const override;
    Szoveg& operator=(const string& st);
};

#endif // SZOVEG_H
