#ifndef SZAMLISTA_H
#define SZAMLISTA_H

#include "adatmegjelenito.h"

class SzamLista : public AdatMegjelenito
{   int also, felso;
    static int lepeskoz;

public:

    SzamLista(const string &szin, bool lathato,
    int also, int felso);


    int getAlso() const;
    int getFelso() const;

    // AdatMegjelenito interface
public:
    void megjelenit() const override;
    int operator*();
    static int getLepeskoz();
    static void setLepeskoz(int newLepeskoz);
};

#endif // SZAMLISTA_H
