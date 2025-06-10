#ifndef SZIN_H
#define SZIN_H

#include <string>

using namespace std;

// --- SPECIFIKÁCIÓ ---
// A Szin osztály egy absztrakt ősosztály
// Nem tárol adattagot (üres absztrakt osztály)
//
// 3 tisztán virtuális függvényt kell tartalmaznia:
// - R(): visszaadja a piros komponens értékét (unsigned char, 0..255)
// - G(): visszaadja a zöld komponens értékét (unsigned char, 0..255)
// - B(): visszaadja a kék komponens értékét (unsigned char, 0..255)
//
// További metódusok:
// - szamotHexava: int (0..15) -> hexa karakter
// - hexatSzamma: hexa karakter -> int (0..15)
// - printCode(): virtuális, hexadecimális színkód (#RRGGBB) formában adja vissza a színt
// - megegyezik: két szín megegyezik-e komponensenként

class Szin
{
public:
    virtual ~Szin();

    // 3 tisztán virtuális függvény a színkomponensek lekérésére
    virtual unsigned char R() const = 0;
    virtual unsigned char G() const = 0;
    virtual unsigned char B() const = 0;

    // szamotHexava: decimális szám (0..15) -> hexa karakter ('0'..'9', 'A'..'F')
    static char szamotHexava(int i);

    // hexatSzamma: hexa karakter -> decimális szám (0..15)
    static int hexatSzamma(char c);

    // printCode: szín kiírása hexadecimális formában (#RRGGBB)
    virtual string printCode() const;

    // megegyezik: két szín megegyezik-e (mindhárom komponens egyezik)
    bool megegyezik(const Szin &sz) const;
};

#endif // SZIN_H
