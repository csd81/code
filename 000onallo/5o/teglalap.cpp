#include "teglalap.h"

Teglalap::Teglalap(const double xmin, const double xmax, const double ymin, const double ymax): Halmaz("RECTANGLE")
 {
    tarolo.push_back(Pont(xmin,ymin));
    tarolo.push_back(Pont(xmin,ymax));
    tarolo.push_back(Pont(xmax,ymin));
    tarolo.push_back(Pont(xmax,ymax));
 }

double Teglalap::terulet() const
{

    double dx = Pont::tavolsag(tarolo[0], tarolo[2]);
    double dy = Pont::tavolsag(tarolo[0], tarolo[1]);
    return dx * dy;

}

bool Teglalap::tartalmaz(const Pont& p) const
{
    if ((p.getX() >= tarolo[0].getX() &&  p.getX() <= tarolo[2].getX())
    && (p.getY() >= tarolo[0].getY() &&  p.getY() <= tarolo[1].getY()))
    {
        return true;
    }
    return false;
}
