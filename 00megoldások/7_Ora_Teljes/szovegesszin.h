#ifndef SZOVEGESSZIN_H
#define SZOVEGESSZIN_H

#include "rgbszin.h"

// --- SPECIFIKÁCIÓ ---
// SzovegesSzin osztály az RGBSzin osztályból származik
// Egy szöveget is tárol, ami a szín elnevezése
//
// Konstruktor:
// - szöveget vár
//   - ha ismert színnév: beállítja a megfelelő r,g,b komponenseket
//   - ha hexa formában kapja ('#' karakterrel kezdődik), abból állítja be a komponenseket
//   - ha nem ismert -> fekete lesz
//
// printCode(): a szöveget adja vissza (nem hexadecimális kódot)

class SzovegesSzin : public RGBSzin
{
    string szoveg; // szín szöveges megnevezése

public:
    SzovegesSzin(const string &sz);

    virtual string printCode() const;
};

#endif // SZOVEGESSZIN_H
