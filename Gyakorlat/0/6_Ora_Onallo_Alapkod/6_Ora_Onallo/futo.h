#ifndef FUTO_H
#define FUTO_H

#include "figura.h"

class Futo : public Figura
{
public:
    Futo(const string &pos);
    bool lephet(string poz) const override;
    char jeloles() const override;
};

#endif // FUTO_H
