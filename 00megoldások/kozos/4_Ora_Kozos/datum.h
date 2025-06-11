#ifndef DATUM_H
#define DATUM_H

// Spec: A megoldás során a main függvény és Datum osztály adott.
// Célszerű a Datum osztályt kiegészíteni egy metódussal, ami összehasonlít kettő dátumot.

class Datum
{
    unsigned int ev, honap, nap;
public:
    Datum(unsigned int _ev, unsigned int _honap, unsigned int _nap);
    unsigned int getEv() const;
    void setEv(unsigned int value);
    unsigned int getHonap() const;
    void setHonap(unsigned int value);
    unsigned int getNap() const;
    void setNap(unsigned int value);

    // Spec: Célszerű a Datum osztályt kiegészíteni egy metódussal, ami összehasonlít kettő dátumot.
    bool kisebbMint(const Datum &masik) const;
};

#endif // DATUM_H
