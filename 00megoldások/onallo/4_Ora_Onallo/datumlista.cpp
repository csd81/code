#include "datumlista.h"

namespace Naptar {

// Spec: Statikus adattag kezdő értéke legyen 6.
unsigned int DatumLista::maxDarab = 6;

DatumLista::DatumLista(unsigned int darab, const string &megj):
    darab(darab),
    megjegyzes(megj)
{
    datumok = new Datum[darab];
}

DatumLista::~DatumLista()
{
    delete[] datumok; // Spec: Memória felszabadítása
}

DatumLista::DatumLista(const DatumLista &dl):
    darab(dl.darab),
    megjegyzes(dl.megjegyzes)
{
    datumok = new Datum[darab];
    for (unsigned int i = 0; i < darab; i++)
        datumok[i] = dl.datumok[i];
}

string DatumLista::getMegjegyzes() const { return megjegyzes; }
void DatumLista::setMegjegyzes(const string &megj) { megjegyzes = megj; }

const Datum &DatumLista::getDatum(unsigned int index) const { return datumok[index]; }

// Spec: Beállításnál indexet ellenőrizni kell!
void DatumLista::setDatum(unsigned int index, const Datum &d)
{
    if (index < darab)
        datumok[index] = d;
}

unsigned int DatumLista::getDarab() const { return darab; }

void DatumLista::hozzaad(const Datum &d)
{
    // Spec: Ha elértük maxDarab-ot, nem bővíthetjük tovább!
    if (darab >= maxDarab) return;

    Datum *uj = new Datum[darab + 1];
    for (unsigned int i = 0; i < darab; i++)
        uj[i] = datumok[i];
    uj[darab] = d;
    delete[] datumok;
    darab++;
    datumok = uj;
}

const Datum &DatumLista::legkorabbi() const
{
    unsigned int min_idx = 0;
    for (unsigned int i = 1; i < darab; i++)
    {
        if (datumok[min_idx].getEv() > datumok[i].getEv() ||
            (datumok[min_idx].getEv() == datumok[i].getEv() && datumok[min_idx].getHonap() > datumok[i].getHonap()) ||
            (datumok[min_idx].getEv() == datumok[i].getEv() && datumok[min_idx].getHonap() == datumok[i].getHonap() && datumok[min_idx].getNap() > datumok[i].getNap()))
            min_idx = i;
    }
    return datumok[min_idx];
}

unsigned int DatumLista::getMaxDarab() { return maxDarab; }
void DatumLista::setMaxDarab(unsigned int newMaxDarab) { maxDarab = newMaxDarab; }

} // namespace Naptar
