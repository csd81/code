#ifndef REPULO_H
#define REPULO_H

#include "jarmu.h"

class Repulo : public Jarmu
{
    unsigned utasletszam;
public:
    Repulo(unsigned int t, unsigned int s, unsigned letszam);
    void kiir() const override;
    Repulo *clone() const override;
};

#endif // REPULO_H
