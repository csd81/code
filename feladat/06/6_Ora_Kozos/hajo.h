#ifndef HAJO_H
#define HAJO_H

#include "jarmu.h"

class Hajo : public Jarmu
{
   unsigned int teherbiras;
public:
    Hajo(unsigned int tomeg, unsigned int sebesseg, unsigned int teherbiras);
    void kiir() const;
};

#endif // HAJO_H
