#include "halmaz.h"

Halmaz::Halmaz(const std::string& nev)
    : megnevezes(nev), pv()
{}

Halmaz::Halmaz(const string &nev, size_t elemszam)
    : megnevezes(nev), pv(elemszam, Pont(0.0, 0.0))
{}

void Halmaz::hozzaad(const Pont &p)
{
    pv.push_back(p);

}

void Halmaz::hozzaad(double x, double y)
{
    pv.emplace_back(x, y);

}

void Halmaz::kiir(ostream &os) const
{
    os << megnevezes << " (" << pv.size() << "): ";
    for (size_t i = 0; i < pv.size(); i++){
        pv[i].kiir(os);
        if (i != pv.size() -1) {}
        os << ", ";
    }
    os << std::endl;
}

void Halmaz::beolvas(const string &fajlnev)
{
    std::ifstream fajl(fajlnev);
    if (!fajl.is_open()) {
        throw std::runtime_error("...");
    }

    pv.clear();
    size_t pontSzam = 0;
    fajl >> pontszam;
    for (size_t i = 0; i < pontSzam; ++i) {
        double x, y;
        fajl >> x >> y;
        if (fajl.fail()) {
            throw std::runtime_error("Hibás");
        }
        pv.emplace_back(x,y);
    }
}

void Halmaz::fajlbair(const string &fajlnev) const
{
    std::ofstream fajl(fajlnev, std::ios::trunc); // Felülírja a fájlt
    if (!fajl.is_open()) {
        throw std::runtime_error("Nem sikerült megnyitni a fájlt írásra: " + fajlnev);
    }

    // Először a pontok számát írjuk ki
    fajl << pv.size() << "\n";

    // Majd az egyes pontokat (x és y koordináták whitespace-szel elválasztva)
    for (const auto& p : pv) {
        fajl << p.getX() << " " << p.getY() << "\n";
    }
}
