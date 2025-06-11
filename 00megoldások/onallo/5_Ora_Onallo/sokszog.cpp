#include "sokszog.h"

// --- SPECIFIKÁCIÓ PDF 23. ---
// konstruktor: név paraméter → üres Sokszog
Sokszog::Sokszog(const string &megnevezes): Halmaz(megnevezes) {}

// --- SPECIFIKÁCIÓ PDF 24. ---
// kerulet(): pontok közti távolságok összege + első-utolsó
double Sokszog::kerulet() const {
    if (pontok.size() < 2)
        return 0;

    double sum = Pont::tavolsag(pontok.front(), pontok.back());
    for (size_t i=1;i<pontok.size();i++)
        sum += Pont::tavolsag(pontok[i-1], pontok[i]);
    return sum;
}

// --- SPECIFIKÁCIÓ PDF 25. ---
// bennfoglalo(): minimális Teglalap, ami tartalmazza a Sokszöget
Teglalap Sokszog::bennfoglalo() const {
    double xmin = pontok[0].getX();
    double xmax = xmin;
    double ymin = pontok[0].getY();
    double ymax = ymin;

    for (size_t i=1;i<pontok.size();i++) {
        if (xmin > pontok[i].getX()) xmin = pontok[i].getX();
        if (xmax < pontok[i].getX()) xmax = pontok[i].getX();
        if (ymin > pontok[i].getY()) ymin = pontok[i].getY();
        if (ymax < pontok[i].getY()) ymax = pontok[i].getY();
    }

    return Teglalap(xmin, xmax, ymin, ymax);
}
