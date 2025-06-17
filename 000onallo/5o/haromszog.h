#ifndef HAROMSZOG_H
#define HAROMSZOG_H

#include "halmaz.h"

class Haromszog : public Halmaz
{
public:
    Haromszog(const Pont& p1, const Pont& p2, const Pont& p3);
    Pont getA() const;
    Pont getB() const;
    Pont getC() const;
    string alak() const;
};

#endif // HAROMSZOG_H
