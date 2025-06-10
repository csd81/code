#ifndef RGBSZIN_H
#define RGBSZIN_H

#include "szin.h"

// --- SPECIFIKÁCIÓ ---
// RGBSzin osztály a Szin osztályból származik
// Tárolja a három (r,g,b) komponens értékét unsigned char típusként
//
// Kötelező konstruktorok:
// - paraméteres konstruktor: (r,g,b) értékeket vár
// - paraméter nélküli konstruktor: fekete színt állít be (0,0,0)
//
// Implementálandó metódusok:
// - R(), G(), B() függvények: tárolt komponensek visszaadása
// - RGBSzin(const Szin &sz): másik tetszőleges Szin típusból konstruktor (komponensek átvétele)

class RGBSzin : public Szin
{
protected:
    unsigned char r, g, b; // r, g, b komponensek

public:
    // paraméteres konstruktor
    RGBSzin(unsigned char r, unsigned char g, unsigned char b);

    // paraméter nélküli konstruktor (fekete szín)
    RGBSzin();

    // konstruktor másik Szin típusból
    RGBSzin(const Szin &sz);

    // komponens lekérő függvények
    virtual unsigned char R() const;
    virtual unsigned char G() const;
    virtual unsigned char B() const;
};

#endif // RGBSZIN_H
