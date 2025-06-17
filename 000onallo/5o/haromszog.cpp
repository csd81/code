#include "haromszog.h"
#include "halmaz.h"


Haromszog::Haromszog(const Pont &p1, const Pont &p2, const Pont &p3) : Halmaz("TRIANGLE", 3)
{
    tarolo.push_back(p1);
    tarolo.push_back(p2);
    tarolo.push_back(p3);
}

Pont Haromszog::getA()  const
{
    return tarolo[0];
}

Pont Haromszog::getB()   const
{
    return tarolo[1];
}

Pont Haromszog::getC()  const
{
    return tarolo[2];
}

string Haromszog::alak() const
{
    double v, w, z;
    v = Pont::tavolsag(tarolo[0], tarolo[1]);
    w = Pont::tavolsag(tarolo[1], tarolo[2]);
    z = Pont::tavolsag(tarolo[0], tarolo[2]);
        if (z<w) swap(z,w);
        if (z<v) swap(z,w);

    double D = z*z - (v*v + w*w);
    if (D < -1e-8)  return "hegyesszogu";
    else if (D > 1e-8) return "tompaszogu";
    else  return "derekszogu";
}
