#ifndef HUSZAR_H
#define HUSZAR_H

#include "figura.h"

class Huszar : public Figura
{
public:
    Huszar(const string &pos);
    bool lephet(string poz) const override;
    char jeloles() const override;
};

#endif // HUSZAR_H
