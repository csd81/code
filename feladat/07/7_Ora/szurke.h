#ifndef SZURKE_H
#define SZURKE_H

#include "szin.h"

class Szurke : public Szin
{
    double vilagos;

public:
    Szurke(double vilagos);
    virtual unsigned char R() const;
    virtual unsigned char G() const;
    virtual unsigned char B() const;
};

#endif // SZURKE_H
