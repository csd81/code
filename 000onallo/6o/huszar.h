#ifndef HUSZAR_H
#define HUSZAR_H

#include "figura.h"

class Huszar : public Figura
{
public:
    Huszar(string p): Figura(p) {}
    bool lephet(const string &pos) const override;
    char jeloles() const override;
};

#endif // HUSZAR_H
