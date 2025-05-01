#ifndef FEKETEFEHER_H
#define FEKETEFEHER_H

#include "szin.h"

class FeketeFeher : public Szin
{
    bool fekete;
public:
    FeketeFeher(bool fekete);
    unsigned char R() const override;
    unsigned char G() const override;
    unsigned char B() const override;
};

#endif // FEKETEFEHER_H
//