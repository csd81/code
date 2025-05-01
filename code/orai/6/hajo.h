#ifndef HAJO_H
#define HAJO_H

#include "jarmu.h"

class Hajo : public Jarmu
{
    unsigned teherbiras;
public:
    Hajo(unsigned int t, unsigned int s, unsigned teher);
    void kiir() const override;
    Hajo *clone() const override;
};

#endif // HAJO_H

/*
 *
 * void kiir() const        =>      0x3921abc2
 * ~Hajo()                  =>      0xaa433336
 *
 */
