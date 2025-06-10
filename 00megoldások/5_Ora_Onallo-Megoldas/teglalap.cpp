#include "teglalap.h"

// --- SPECIFIKÁCIÓ PDF 20. ---
// konstruktor: "RECTANGLE", 4 csúcs
Teglalap::Teglalap(double xmin, double xmax, double ymin, double ymax): Halmaz("RECTANGLE") {
    hozzaad(xmin, ymin);
    hozzaad(xmin, ymax);
    hozzaad(xmax, ymax);
    hozzaad(xmax, ymin);
}

// --- SPECIFIKÁCIÓ PDF 21. ---
// terulet(): téglalap területe
double Teglalap::terulet() const {
    return ( pontok[2].getX() - pontok[0].getX() ) * ( pontok[1].getY() - pontok[0].getY() );
}

// --- SPECIFIKÁCIÓ PDF 22. ---
// tartalmaz(Pont): pont belül van-e
bool Teglalap::tartalmaz(const Pont &pont) const {
    if (pontok[0].getX() > pont.getX()) return false;
    if (pontok[2].getX() < pont.getX()) return false;
    if (pontok[0].getY() > pont.getY()) return false;
    if (pontok[1].getY() < pont.getY()) return false;
    return true;
}
