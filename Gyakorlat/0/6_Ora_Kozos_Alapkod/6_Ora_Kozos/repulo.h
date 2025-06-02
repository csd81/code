#ifndef REPULO_H
#define REPULO_H

#include "jarmu.h"

class Repulo : public Jarmu
{
    int utasok;
public:

    Repulo(int utasok, unsigned int t, unsigned int s);
    void kiir() const override;
    Jarmu* clone() const override;
};

#endif // REPULO_H
