#include "vektor.h"

/*
Feladat:
A Vektor osztály konstruktorában a vektor méretét (darab) állítjuk be,
és lefoglaljuk a szükséges memóriát a lebegőpontos számokat tároló tömb számára.
*/
Vektor::Vektor(unsigned int db):
    darab(db)
{
    elemek = new double[darab];
}

/*
Feladat:
Másoló konstruktor, amely másik vektor adataiból hozza létre az új példányt.
*/
Vektor::Vektor(const Vektor &masik):
    darab(masik.darab)
{
    elemek = new double[darab];
    for (unsigned int i = 0; i < darab; i++)
        elemek[i] = masik.elemek[i];
}

/*
Feladat:
A destruktor feladata a lefoglalt memória felszabadítása.
*/
Vektor::~Vektor()
{
    delete[] elemek;
}

/*
Segédfüggvények a vektor adataihoz való hozzáféréshez.
*/
unsigned int Vektor::getDarab() const
{
    return darab;
}

double Vektor::getElem(unsigned int index) const
{
    return elemek[index];
}

void Vektor::setElem(unsigned int index, double elem)
{
    elemek[index] = elem;
}

/*
(a) + operátor: két vektor összeadása, új vektorral tér vissza.
*/
Vektor Vektor::operator +(const Vektor &masik) const
{
    if (darab == masik.darab)
    {
        Vektor eredmeny(darab);
        for (unsigned int i = 0; i < darab; i++)
            eredmeny.elemek[i] = elemek[i] + masik.elemek[i];
        return eredmeny;
    }
    else
    {
        return *this;
    }
}

/*
(b) += operátor: hozzáadás másik vektorhoz, magát a módosított vektort adja vissza.
*/
Vektor &Vektor::operator +=(const Vektor &masik)
{
    if (darab == masik.darab)
    {
        for (unsigned int i = 0; i < darab; i++)
            elemek[i] += masik.elemek[i];
    }
    return *this;
}

/*
(c) + operátor: szám és vektor összeadása, ha a szám van bal oldalon.
*/
Vektor operator +(double ertek, const Vektor &v)
{
    Vektor eredmeny(v.darab);
    for (unsigned int i = 0; i < v.darab; i++)
        eredmeny.elemek[i] = ertek + v.elemek[i];
    return eredmeny;
}

/*
= operátor: másik vektor értékeinek másolása.
*/
Vektor &Vektor::operator =(const Vektor &masik)
{
    if (this != &masik)
    {
        delete[] elemek;
        darab = masik.darab;
        elemek = new double[darab];
        for (unsigned int i = 0; i < darab; i++)
            elemek[i] = masik.elemek[i];
    }
    return *this;
}

/*
Prefix -- operátor: a vektor minden elemét csökkenti eggyel.
*/
Vektor &Vektor::operator--()
{
    for (unsigned int i = 0; i < darab; i++)
        elemek[i] -= 1;
    return *this;
}

/*
Postfix -- operátor: a vektor minden elemét csökkenti eggyel.
*/
Vektor Vektor::operator--(int)
{
    Vektor eredeti(*this);
    for (unsigned int i = 0; i < darab; i++)
        elemek[i] -= 1;
    return eredeti;
}

/*
<< operátor: a vektor elemeit kiírja a megkapott kimeneti folyamra.
*/
ostream &operator <<(ostream &os, const Vektor &v)
{
    os << "(";
    for (unsigned int i = 0; i < v.darab; i++)
    {
        if (i > 0) os << " , ";
        os << v.elemek[i];
    }
    os << ")";
    return os;
}

/*
- operátor: két vektor kivonása.
*/
Vektor Vektor::operator -(const Vektor &masik) const
{
    if (darab == masik.darab)
    {
        Vektor eredmeny(darab);
        for (unsigned int i = 0; i < darab; i++)
            eredmeny.elemek[i] = elemek[i] - masik.elemek[i];
        return eredmeny;
    }
    else
    {
        return *this;
    }
}

/*
-= operátor: két vektor kivonása, magát a módosított vektort adja vissza.
*/
Vektor &Vektor::operator -=(const Vektor &masik)
{
    if (darab == masik.darab)
    {
        for (unsigned int i = 0; i < darab; i++)
            elemek[i] -= masik.elemek[i];
    }
    return *this;
}

/*
- operátor: szám és vektor kivonása (szám bal oldalon).
*/
Vektor operator -(double ertek, const Vektor &v)
{
    Vektor eredmeny(v.darab);
    for (unsigned int i = 0; i < v.darab; i++)
        eredmeny.elemek[i] = ertek - v.elemek[i];
    return eredmeny;
}

/*
* operátor: két vektor elemenkénti szorzása.
*/
Vektor Vektor::operator *(const Vektor &masik) const
{
    if (darab == masik.darab)
    {
        Vektor eredmeny(darab);
        for (unsigned int i = 0; i < darab; i++)
            eredmeny.elemek[i] = elemek[i] * masik.elemek[i];
        return eredmeny;
    }
    else
    {
        return *this;
    }
}

/*
*= operátor: két vektor elemenkénti szorzása, módosítja a bal oldali vektort.
*/
Vektor &Vektor::operator *=(const Vektor &masik)
{
    if (darab == masik.darab)
    {
        for (unsigned int i = 0; i < darab; i++)
            elemek[i] *= masik.elemek[i];
    }
    return *this;
}

/*
* operátor: szám és vektor szorzása (szám bal oldalon).
*/
Vektor operator *(double ertek, const Vektor &v)
{
    Vektor eredmeny(v.darab);
    for (unsigned int i = 0; i < v.darab; i++)
        eredmeny.elemek[i] = ertek * v.elemek[i];
    return eredmeny;
}

/*
/ operátor: két vektor elemenkénti osztása.
*/
Vektor Vektor::operator /(const Vektor &masik) const
{
    if (darab == masik.darab)
    {
        Vektor eredmeny(darab);
        for (unsigned int i = 0; i < darab; i++)
            eredmeny.elemek[i] = elemek[i] / masik.elemek[i];
        return eredmeny;
    }
    else
    {
        return *this;
    }
}

/*
/= operátor: két vektor elemenkénti osztása, módosítja a bal oldali vektort.
*/
Vektor &Vektor::operator /=(const Vektor &masik)
{
    if (darab == masik.darab)
    {
        for (unsigned int i = 0; i < darab; i++)
            elemek[i] /= masik.elemek[i];
    }
    return *this;
}

/*
/ operátor: szám és vektor osztása (szám bal oldalon).
*/
Vektor operator /(double ertek, const Vektor &v)
{
    Vektor eredmeny(v.darab);
    for (unsigned int i = 0; i < v.darab; i++)
        eredmeny.elemek[i] = ertek / v.elemek[i];
    return eredmeny;
}

/*
+, -, *, / operátorok számmal jobb oldalon.
*/
Vektor Vektor::operator +(double ertek) const
{
    Vektor eredmeny(darab);
    for (unsigned int i = 0; i < darab; i++)
        eredmeny.elemek[i] = elemek[i] + ertek;
    return eredmeny;
}

Vektor Vektor::operator -(double ertek) const
{
    Vektor eredmeny(darab);
    for (unsigned int i = 0; i < darab; i++)
        eredmeny.elemek[i] = elemek[i] - ertek;
    return eredmeny;
}

Vektor Vektor::operator *(double ertek) const
{
    Vektor eredmeny(darab);
    for (unsigned int i = 0; i < darab; i++)
        eredmeny.elemek[i] = elemek[i] * ertek;
    return eredmeny;
}

Vektor Vektor::operator /(double ertek) const
{
    Vektor eredmeny(darab);
    for (unsigned int i = 0; i < darab; i++)
        eredmeny.elemek[i] = elemek[i] / ertek;
    return eredmeny;
}

/*
Prefix ++ operátor: minden elem növelése eggyel.
*/
Vektor &Vektor::operator++()
{
    for (unsigned int i = 0; i < darab; i++)
        elemek[i] += 1;
    return *this;
}

/*
Postfix ++ operátor: minden elem növelése eggyel.
*/
Vektor Vektor::operator++(int)
{
    Vektor eredeti(*this);
    for (unsigned int i = 0; i < darab; i++)
        elemek[i] += 1;
    return eredeti;
}

/*
[] operátor: indexeléssel hozzáférés az elemhez (referenciaként).
*/
double &Vektor::operator [](unsigned int index)
{
    return elemek[index];
}

/*
[] operátor konstans verziója.
*/
const double &Vektor::operator [](unsigned int index) const
{
    return elemek[index];
}

/*
^ operátor: két vektor skaláris szorzata.
*/
double Vektor::operator ^(const Vektor &masik) const
{
    if (darab == masik.darab)
    {
        double ertek = 0;
        for (unsigned int i = 0; i < darab; i++)
            ertek += elemek[i] * masik.elemek[i];
        return ertek;
    }
    else
    {
        return 0;
    }
}

/*
Unáris * operátor: a vektor hossza.
*/
double Vektor::operator *() const
{
    double osszeg = 0;
    for (unsigned int i = 0; i < darab; i++)
        osszeg += elemek[i] * elemek[i];
    return sqrt(osszeg);
}

/*
Unáris ~ operátor: normalizált vektor.
*/
Vektor Vektor::operator ~() const
{
    Vektor eredmeny(darab);
    double hossz = **this; // a vektor hossza
    for (unsigned int i = 0; i < darab; i++)
        eredmeny.elemek[i] = elemek[i] / hossz;
    return eredmeny;
}

/*
== operátor: két vektor elemeinek egyezősége.
*/
bool Vektor::operator ==(const Vektor &masik) const
{
    if (darab != masik.darab) return false;
    for (unsigned int i = 0; i < darab; i++)
    {
        if (elemek[i] != masik.elemek[i]) return false;
    }
    return true;
}

/*
!= operátor: két vektor elemeinek nem egyezősége.
*/
bool Vektor::operator !=(const Vektor &masik) const
{
    if (darab != masik.darab) return true;
    for (unsigned int i = 0; i < darab; i++)
    {
        if (elemek[i] != masik.elemek[i]) return true;
    }
    return false;
}

/*
< operátor: elemenkénti kisebb-nagyobb összehasonlítás.
*/
bool Vektor::operator <(const Vektor &masik) const
{
    if (darab != masik.darab) return false;
    for (unsigned int i = 0; i < darab; i++)
    {
        if (!(elemek[i] < masik.elemek[i])) return false;
    }
    return true;
}
