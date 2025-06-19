#ifndef HITELSZAMLA_H
#define HITELSZAMLA_H

#include "szamla.h"

class HitelSzamla : public Szamla
{   int hitelkeret;
public:
    HitelSzamla(const string &szamlaszam, int egyenleg, int hitelkeret);

    bool vegrehajt(Tranzakcio &) override;
    void kiir() const override;
};

#endif // HITELSZAMLA_H
