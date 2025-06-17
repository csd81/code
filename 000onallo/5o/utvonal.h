#ifndef UTVONAL_H
#define UTVONAL_H

#include "halmaz.h"

class Utvonal : public Halmaz
{
    bool irany;
public:
    Utvonal();
    void megfordit();
    void kiir() const;
    double hossz() const;
};

#endif // UTVONAL_H
