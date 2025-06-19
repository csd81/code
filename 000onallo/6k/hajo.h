#ifndef HAJO_H
#define HAJO_H
#include <iostream>
#include "jarmu.h"

class Hajo : public Jarmu
{
    int teherbiras;
public:
    Hajo(int teherbiras, unsigned int t, unsigned int s);
    void kiir() const override;
    Jarmu* clone() const override;
};

#endif // HAJO_H
