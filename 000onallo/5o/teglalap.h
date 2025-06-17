#ifndef TEGLALAP_H
#define TEGLALAP_H

#include "halmaz.h"

class Teglalap : public Halmaz
{
public:
    Teglalap(const double xmin, const double xmax, const double ymin, const double ymax);
    double terulet() const;
    bool tartalmaz(const Pont& p) const;
};

#endif // TEGLALAP_H
