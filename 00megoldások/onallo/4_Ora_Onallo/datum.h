#ifndef DATUM_H
#define DATUM_H

namespace Naptar { // Spec: A meglévő Datum osztály és a készítendő DatumLista osztály legyenek a Naptar névtérben.

class Datum
{
    unsigned int ev, honap, nap;
public:
    // Spec: A Datum osztály kiegészítendő, hogy legyen alapértelmezett konstruktor (ez megtörtént)
    Datum(unsigned int _ev, unsigned int _honap, unsigned int _nap);
    Datum(); // Spec: alapértelmezett konstruktor

    // Spec: beállító és lekérő függvények a dátum elemeihez
    unsigned int getEv() const;
    void setEv(unsigned int value);
    unsigned int getHonap() const;
    void setHonap(unsigned int value);
    unsigned int getNap() const;
    void setNap(unsigned int value);
};

} // namespace Naptar

#endif // DATUM_H
