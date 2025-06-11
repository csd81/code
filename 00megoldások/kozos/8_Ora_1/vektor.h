#ifndef VEKTOR_H
#define VEKTOR_H

#include <cmath>
#include <iostream>

using namespace std;

/*
Feladat
A megadott osztály a Vektor osztály, amely egy matematikai vektort ábrázol.
Az osztály tárolja a vektor méretét, illetve a megfelelő mennyiségű lebegőpontos számot tároló tömböt.
Ezeket a konstruktor állítja be, ami a méretet várja paraméterül.
Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.
*/

class Vektor
{
    unsigned int darab;          // A vektor mérete (elemek száma)
    double *elemek;              // Dinamikusan foglalt tömb, a vektor elemeinek tárolására

public:
    Vektor(unsigned int db);     // Konstruktor: a méretet várja paraméterül
    Vektor(const Vektor &masik); // Másoló konstruktor
    ~Vektor();                   // Destruktor: memória felszabadítása

    unsigned int getDarab() const;
    double getElem(unsigned int index) const;
    void setElem(unsigned int index, double elem);

    // (a) + operátor: két vektor összeadása, új vektorral tér vissza
    Vektor operator +(const Vektor &masik) const;

    // (b) += operátor: hozzáadás másik vektorhoz, magát a módosított vektort adja vissza
    Vektor& operator +=(const Vektor &masik);

    // (c) + operátor: szám és vektor összeadása, ha a szám van bal oldalon
    friend Vektor operator +(double ertek, const Vektor &v);

    // = operátor: másik vektor értékeinek másolása
    Vektor& operator =(const Vektor &masik);

    // prefix -- operátor: minden elem csökkentése eggyel
    Vektor& operator--();

    // postfix -- operátor: minden elem csökkentése eggyel
    Vektor operator--(int);

    // << operátor: kimeneti folyamra kiírja a vektor elemeit
    friend ostream& operator <<(ostream &os, const Vektor &v);

    // ----------------------------------------------------------
    // A többi számolós operátorok implementációja, a (c) feladathoz hasonlóan:

    // - operátor
    Vektor operator -(const Vektor &masik) const;
    Vektor& operator -=(const Vektor &masik);
    friend Vektor operator -(double ertek, const Vektor &v);

    // * operátor
    Vektor operator *(const Vektor &masik) const;
    Vektor& operator *=(const Vektor &masik);
    friend Vektor operator *(double ertek, const Vektor &v);

    // / operátor
    Vektor operator /(const Vektor &masik) const;
    Vektor& operator /=(const Vektor &masik);
    friend Vektor operator /(double ertek, const Vektor &v);

    // +, -, *, / operátorok számmal jobb oldalon
    Vektor operator +(double ertek) const;
    Vektor operator -(double ertek) const;
    Vektor operator *(double ertek) const;
    Vektor operator /(double ertek) const;

    // prefix ++ operátor
    Vektor& operator++();

    // postfix ++ operátor
    Vektor operator++(int);

    // [] operátor: index alapján visszaadja az elem referenciáját
    double& operator [](unsigned int index);

    // [] operátor konstans verziója
    const double& operator [](unsigned int index) const;

    // ^ operátor: két vektor skaláris szorzata
    double operator ^(const Vektor &masik) const;

    // unáris * operátor: a vektor hossza
    double operator *() const;

    // unáris ~ operátor: normalizált vektor visszaadása
    Vektor operator ~() const;

    // == operátor: vektorok összehasonlítása (egyezés)
    bool operator ==(const Vektor &masik) const;

    // != operátor: vektorok összehasonlítása (nem egyezés)
    bool operator !=(const Vektor &masik) const;

    // < operátor: elemenkénti kisebb-nagyobb összehasonlítás
    bool operator <(const Vektor &masik) const;
};

#endif // VEKTOR_H
