#ifndef REPULO_H
#define REPULO_H

#include "jarmu.h"

class Repulo : public Jarmu
{
    unsigned int utasletszam;
public:
    Repulo(unsigned int tomeg, unsigned int sebesseg, unsigned int utasletszam);
    void kiir() const;
};

#endif // REPULO_H
