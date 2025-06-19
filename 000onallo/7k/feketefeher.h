#ifndef FEKETEFEHER_H
#define FEKETEFEHER_H
#include "szin.h"

class FeketeFeher : public Szin
{
    bool fekete;
public:
    FeketeFeher(bool fekete);
    unsigned char R() const;
    unsigned char G() const;
    unsigned char B() const;
};

#endif // FEKETEFEHER_H

