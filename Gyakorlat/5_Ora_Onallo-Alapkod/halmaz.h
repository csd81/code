

//



#ifndef HALMAZ_H
#define HALMAZ_H
#include "pont.h"
#include <vector>
#include <iostream>
#include <string>

class Halmaz
{
    std::string megnevezes;
    std::vector<Pont> pv;
public:
    Halmaz(const std::string& nev);
    Halmaz(const std::string& nev, size_t elemszam = 0);
    void hozzaad(const Pont& p);
    void hozzaad(double x, double y);
    void kiir(std::ostream& os) const;
    void beolvas(const std::string& fajlnev);
    void fajlbair(const std::string& fajlnev) const;




};



#endif // HALMAZ_H




// Halmaz – általános tároló osztály

// 6. Legyen egy Halmaz osztály, aminek két adattagja van: egy megnevezés (string), és egy pontokat tároló vector<Pont>. A konstruktor csak egy paramétert, a megnevezést kapja meg, a tároló kezdetben legyen üres.

//                                                                                                                                                                                                                    7. Legyen olyan konstruktor is a Halmaz osztályban, ami két paramétert kap: a megnevezésen kívül egy elemszámot is, és a ponthalmaznak kezdetben ennyi eleme legyen. Az elemeket nem kell beállítani, az alapértelmezett origó (0,0) fog érvényesülni. (Megoldható az előző feladattal együtt, egyetlen konstruktorral.)

//                                                                                                                                                                                                                                                                                                                                                                                                                                                         8. Legyen a Halmaz osztályban egy hozzaad függvény, ami egyetlen paraméterben egy Pont-ot kap és a vektor végére beszúrja azt.

//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    9. Terheld túl a hozzaad függvényt: legyen olyan változata is, ami két double értéket kap paraméterben, az új Pont x és y koordinátáját.

//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    10. Legyen a Halmaz osztályban egy kiir függvény, ami egyetlen sorban kiírja a halmaz megnevezését, a tárolt pontok számát, majd az egyes pontokat, sortöréssel a legvégén (a formátumhoz lásd a példakimenetet).

//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            11. *Legyen a Halmaz osztályban egy beolvas függvény, ami paraméterben egy fájl elérési útját kapja meg (string), és onnan olvassa be a pontokat. A függvény először törölje a meglévő pontokat. A fájlban először a pontok száma szerepel, majd a pontok egyenként, mindegyiknek az x és y koordinátája, kizárólag whitespace-szel elválasztva. Fontos: A teszteléshez a mellékelt halmaz3.txt fájlt a projekt build könyvtárába kell másolni.

//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             12. *Legyen a Halmaz osztályban egy fajlbair függvény, ami paraméterben egy fájl elérési útját kapja meg. Mentse el a pontokat a megadott fájlba (felülírva annak korábbi tartalmát) olyan formátumban, hogy ugyanaz a fájl a beolvas függvénnyel beolvasható legyen.

