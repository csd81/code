// Halmaz – általános tároló osztály

// 6. Legyen egy Halmaz osztály, aminek két adattagja van: egy megnevezés (string), és egy pontokat tároló vector<Pont>. A konstruktor csak egy paramétert, a megnevezést kapja meg, a tároló kezdetben legyen üres.

// 7. Legyen olyan konstruktor is a Halmaz osztályban, ami két paramétert kap: a megnevezésen kívül egy elemszámot is, és a ponthalmaznak kezdetben ennyi eleme legyen. Az elemeket nem kell beállítani, az alapértelmezett origó (0,0) fog érvényesülni. (Megoldható az előző feladattal együtt, egyetlen konstruktorral.)

// 8. Legyen a Halmaz osztályban egy hozzaad függvény, ami egyetlen paraméterben egy Pont-ot kap és a vektor végére beszúrja azt.

// 9. Terheld túl a hozzaad függvényt: legyen olyan változata is, ami két double értéket kap paraméterben, az új Pont x és y koordinátáját.

// 10. Legyen a Halmaz osztályban egy kiir függvény, ami egyetlen sorban kiírja a halmaz megnevezését, a tárolt pontok számát, majd az egyes pontokat, sortöréssel a legvégén (a formátumhoz lásd a példakimenetet).

// 11. *Legyen a Halmaz osztályban egy beolvas függvény, ami paraméterben egy fájl elérési útját kapja meg (string), és onnan olvassa be a pontokat. A függvény először törölje a meglévő pontokat. A fájlban először a pontok száma szerepel, majd a pontok egyenként, mindegyiknek az x és y koordinátája, kizárólag whitespace-szel elválasztva. Fontos: A teszteléshez a mellékelt halmaz3.txt fájlt a projekt build könyvtárába kell másolni.

// 12. *Legyen a Halmaz osztályban egy fajlbair függvény, ami paraméterben egy fájl elérési útját kapja meg. Mentse el a pontokat a megadott fájlba (felülírva annak korábbi tartalmát) olyan formátumban, hogy ugyanaz a fájl a beolvas függvénnyel beolvasható legyen.



#include "halmaz.h"

const std::vector<Pont>& Halmaz::getPontok() const
{
    return pv;
}



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
        if (i != pv.size() - 1) {
        os << ", ";
        }
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
    fajl >> pontSzam;
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

// Halmaz – általános tároló osztály

// 6. Legyen egy Halmaz osztály, aminek két adattagja van: egy megnevezés (string), és egy pontokat tároló vector<Pont>. A konstruktor csak egy paramétert, a megnevezést kapja meg, a tároló kezdetben legyen üres.

// 7. Legyen olyan konstruktor is a Halmaz osztályban, ami két paramétert kap: a megnevezésen kívül egy elemszámot is, és a ponthalmaznak kezdetben ennyi eleme legyen. Az elemeket nem kell beállítani, az alapértelmezett origó (0,0) fog érvényesülni. (Megoldható az előző feladattal együtt, egyetlen konstruktorral.)

// 8. Legyen a Halmaz osztályban egy hozzaad függvény, ami egyetlen paraméterben egy Pont-ot kap és a vektor végére beszúrja azt.

// 9. Terheld túl a hozzaad függvényt: legyen olyan változata is, ami két double értéket kap paraméterben, az új Pont x és y koordinátáját.

// 10. Legyen a Halmaz osztályban egy kiir függvény, ami egyetlen sorban kiírja a halmaz megnevezését, a tárolt pontok számát, majd az egyes pontokat, sortöréssel a legvégén (a formátumhoz lásd a példakimenetet).

// 11. *Legyen a Halmaz osztályban egy beolvas függvény, ami paraméterben egy fájl elérési útját kapja meg (string), és onnan olvassa be a pontokat. A függvény először törölje a meglévő pontokat. A fájlban először a pontok száma szerepel, majd a pontok egyenként, mindegyiknek az x és y koordinátája, kizárólag whitespace-szel elválasztva. Fontos: A teszteléshez a mellékelt halmaz3.txt fájlt a projekt build könyvtárába kell másolni.

// 12. *Legyen a Halmaz osztályban egy fajlbair függvény, ami paraméterben egy fájl elérési útját kapja meg. Mentse el a pontokat a megadott fájlba (felülírva annak korábbi tartalmát) olyan formátumban, hogy ugyanaz a fájl a beolvas függvénnyel beolvasható legyen.

