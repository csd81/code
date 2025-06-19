#ifndef FOLYOSZAMLA_H
#define FOLYOSZAMLA_H

#include "szamla.h"

class FolyoSzamla : public Szamla
{   string nev;
public:
    FolyoSzamla(const string &szamlaszam, int egyenleg, const string &nev);




    bool vegrehajt(Tranzakcio &)  override;
    void kiir() const override;

};

#endif // FOLYOSZAMLA_H
