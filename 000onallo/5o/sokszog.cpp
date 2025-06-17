#include "sokszog.h"
#include "utvonal.h"
#include "teglalap.h"

Sokszog::Sokszog(string megn): Halmaz(megn) {}

double Sokszog::kerulet() const
{
    double sum = 0.0;
    if (tarolo.size() < 1) return 0.0;
    else for (size_t i = 0; i < tarolo.size(); ++i) {
        size_t kov = (i + 1) % tarolo.size();
        sum += Pont::tavolsag(tarolo[i], tarolo[kov]);
        }
    return sum;
}

Teglalap Sokszog::bennfoglalo() const
{
    double xmin=tarolo[0].getX();
    double ymin=tarolo[0].getY();
    double xmax=tarolo[0].getX();
    double ymax=tarolo[0].getY();

    for (Pont p : tarolo){
        if (p.getX() < xmin) xmin =p.getX();
        if (p.getY() < ymin) ymin =p.getY();
        if (p.getX() > xmax) xmax =p.getX();
        if (p.getY() > ymax) ymax =p.getY();
    }
    return Teglalap(xmin, xmax, ymin, ymax);
}
