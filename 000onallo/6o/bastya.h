#ifndef BASTYA_H
#define BASTYA_H

#include "figura.h"

class Bastya : public Figura
{
public:
    Bastya(string p);
    bool lephet(const string &pos) const override;
    char jeloles() const override;
};

#endif // BASTYA_H
