#ifndef SZURKE_H
#define SZURKE_H

#include "szin.h"

class Szurke : public Szin
{
    float ertek;
public:
    Szurke(float ertek);
    unsigned char R() const override;
    unsigned char G() const override;
    unsigned char B() const override;
};

#endif // SZURKE_H
