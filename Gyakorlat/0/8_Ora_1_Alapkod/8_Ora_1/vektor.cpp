#include "vektor.h"


Vektor::Vektor(unsigned int meret) : meret(meret)
{
    if (meret <=0){
        throw std::invalid_argument("A vektor merete pozitiv kell legyen.");
    }
    elemek = new double[meret];
    for (unsigned int i =0; i< meret; i++){
        elemek[i] = 0.0;
    }
}

Vektor::Vektor(const Vektor &masik) : meret(masik.meret)
{
    elemek = new double[meret];
    for (unsigned int i =0; i< meret; i++){
        elemek[i] = masik.elemek[i];
    }
}

Vektor& Vektor::operator=(const Vektor& masik){
    if (this != &masik){
        delete[] elemek;
        meret = masik.meret;
        elemek = new double[meret];
        for (unsigned int i = 0; i<meret; i++){
            elemek[i] =    masik.elemek[i];
        }
    }
    return *this;
}

Vektor::~Vektor()
{
    delete[] elemek;
}

unsigned int Vektor::getDarab() const
{
    return meret;
}

double Vektor::getElem(unsigned int index) const
{
    if (index >= meret)
        throw std::out_of_range("Index kivul esik a vektor hatarain.");
    return elemek[index];

}

void Vektor::setElem(unsigned int index, double elem)
{
    if (index >= meret)
        throw std::out_of_range("Index kivul esik a vektor hatarain.");
    elemek[index]= elem;
}

Vektor Vektor::operator+(const Vektor &masik) const
{
    if (meret != masik.meret)
        throw std::invalid_argument("Kulonbozo meretu vektorokat nem lehet osszeadni.");
    Vektor result(meret);
    for (unsigned int i = 0; i < meret; i++){
        result.elemek[i] = elemek[i] + masik.elemek[i];
    }
    return result;
}

double& Vektor::operator[](unsigned int index) {
    if (index >= meret)
        throw std::out_of_range("Index kivul esik a vektor hatarain.");
    return elemek[index];
}

const double& Vektor::operator[](unsigned int index) const {
    if (index >= meret)
        throw std::out_of_range("Index kivul esik a vektor hatarain.");
    return elemek[index];
}

double Vektor::operator^(const Vektor& masik) const {
    if (meret != masik.meret)
        throw std::invalid_argument("Kulonbozo meretu vektorokat nem lehet skalarszorozni.");
    double osszeg = 0;
    for (unsigned int i = 0; i < meret; ++i)
        osszeg += elemek[i] * masik.elemek[i];
    return osszeg;
}

double Vektor::operator*() const {
    double osszeg = 0;
    for (unsigned int i = 0; i < meret; ++i)
        osszeg += elemek[i] * elemek[i];
    return sqrt(osszeg);
}

Vektor Vektor::operator~() const {
    double hossz = this->operator*();
    if (hossz == 0)
        throw std::domain_error("Nullvektort nem lehet normalizalni.");
    Vektor eredmeny(meret);
    for (unsigned int i = 0; i < meret; ++i)
        eredmeny.elemek[i] = elemek[i] / hossz;
    return eredmeny;
}

bool Vektor::operator!=(const Vektor& masik) {
    return !(*this == masik);
}

bool Vektor::operator<(const Vektor& masik) {
    if (meret != masik.meret) return false;
    for (unsigned int i = 0; i < meret; ++i) {
        if (elemek[i] >= masik.elemek[i]) return false;
    }
    return true;
}

Vektor Vektor::operator-(const Vektor &masik) const
{
    if (meret != masik.meret)
        throw std::invalid_argument("...");
    Vektor res(meret);
    for (unsigned int i =0; i < meret; i++){
        res.elemek[i] = elemek[i] - masik.elemek[i];
    }
    return res;
}



Vektor Vektor::operator/(const Vektor &masik) const
{
    if (meret != masik.meret)
        throw std::invalid_argument("...");
    Vektor res(meret);
    for (unsigned int i =0; i < meret; i++){
        if (masik.elemek[i] == 0.0)
            throw std::domain_error("Nullaval valo osztas.");
        res.elemek[i] = elemek[i] / masik.elemek[i];
    }
    return res;
}

Vektor &Vektor::operator+=(const Vektor &masik)
{
    if (meret != masik.meret)
        throw std::invalid_argument("Kulonbozo meretu vektorokat nem lehet osszeadni.");
    for (unsigned int i = 0; i < meret; ++i)
        this->elemek[i] += masik.elemek[i];
     return *this;
}

Vektor &Vektor::operator-=(const Vektor &masik)
{
    if (meret != masik.meret)
        throw std::invalid_argument("Kulonbozo meretu vektorokat nem lehet osszeadni.");
    for (unsigned int i = 0; i < meret; ++i)
        this->elemek[i] -= masik.elemek[i];
    return *this;
}

Vektor &Vektor::operator*=(const Vektor &masik)
{
    if (meret != masik.meret)
        throw std::invalid_argument("Kulonbozo meretu vektorokat nem lehet osszeadni.");
    for (unsigned int i = 0; i < meret; ++i)
        this->elemek[i] *= masik.elemek[i];
    return *this;
}

Vektor &Vektor::operator/=(const Vektor &masik)
{
    if (meret != masik.meret)
        throw std::invalid_argument("Kulonbozo meretu vektorokat nem lehet osszeadni.");
    for (unsigned int i = 0; i < meret; ++i)
        this->elemek[i] /= masik.elemek[i];
    return *this;
}


bool Vektor::operator==(const Vektor &masik)
{
    if (meret != masik.meret)
        return false;

    for (unsigned int i = 0; i < meret; ++i){
        if (this->elemek[i]!=masik.elemek[i])
            return false;
    }
    return true;
}

Vektor &Vektor::operator--()
{
    for (unsigned int i = 0; i < meret; ++i){
        --this->elemek[i];
    }
    return *this;
}


Vektor Vektor::operator--(int)
{
    Vektor regi(*this);
    --(*this);
    return regi;
}


Vektor &Vektor::operator++()
{
    for (unsigned int i = 0; i < meret; ++i)
        ++elemek[i];
    return *this;
}

Vektor Vektor::operator+(double skalar) const
{
    Vektor eredmeny(meret);
    for (unsigned int i = 0; i < meret; ++i)
        eredmeny.elemek[i] = elemek[i]+skalar;
    return eredmeny;
}

Vektor Vektor::operator-(double skalar) const
{
    Vektor eredmeny(meret);
    for (unsigned int i = 0; i < meret; ++i)
        eredmeny.elemek[i] = elemek[i]-skalar;
    return eredmeny;
}



Vektor Vektor::operator/(double skalar) const
{
    Vektor eredmeny(meret);
    for (unsigned int i = 0; i < meret; ++i)
        eredmeny.elemek[i] = elemek[i]/skalar;
    return eredmeny;
}

Vektor Vektor::operator++(int)
{
    Vektor regi(*this);
    ++(*this);
    return regi;
}
