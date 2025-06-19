#ifndef SZURKE_H
#define SZURKE_H
#include "szin.h"

class Szurke : public Szin
{   double vilagossag;
public:
    Szurke(double vilagossag);

    unsigned char R() const;
    unsigned char G() const;
    unsigned char B() const;
};

#endif // SZURKE_H
