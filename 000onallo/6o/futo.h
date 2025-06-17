#ifndef FUTO_H
#define FUTO_H

#include "figura.h"

class Futo : public Figura
{
public:
    Futo(string p): Figura(p) {}
    bool lephet(const string &pos) const override;
    char jeloles() const override;
};

#endif // FUTO_H
