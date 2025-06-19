#include "mappa.h"

Mappa::Mappa(): darab(0), fajlok(nullptr)
{

}

Mappa::~Mappa()
{
    for (int i = 0; i < darab; ++i)
        delete fajlok[i];
    delete[] fajlok;
}

int Mappa::getDarab() const
{
    return darab;
}

void operator<<(Mappa& m, const Fajl* f)
{
    Fajl** uj = new Fajl*[m.darab + 1];
    for (int i = 0; i < m.darab; ++i)
        uj[i] = m.fajlok[i];
    uj[m.darab] = const_cast<Fajl*>(f); // Ha tényleg const-ot kapsz, máshogy kell megoldani
    delete[] m.fajlok;
    m.fajlok = uj;
    m.darab++;


}

void Mappa::tartalom()
{
    for (int i = 0; i < darab; ++i) {
        fajlok[i]->adatok();
    }
}

bool Mappa::operator[](string fajlnev)
{
    for (int i = 0; i < darab; ++i) {
        if (fajlok[i]->getNev() == fajlnev)
            return true;
    }
    return false;
}

bool operator>(const Mappa& m1, const Mappa& m2){
        int osszeg1 = 0, osszeg2 = 0;
    for (int i = 0; i < m1.darab; ++i)
        osszeg1 += m1.fajlok[i]->getMeret();
    for (int i = 0; i < m2.darab; ++i)
        osszeg2 += m2.fajlok[i]->getMeret();
    return osszeg1 > osszeg2;
}
