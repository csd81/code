#include "vektor.h"

Vektor::Vektor(unsigned int db):
	darab(db)
{
	elemek=new double[darab];
}

Vektor::Vektor(const Vektor &masik):
	darab(masik.darab)
{
	elemek=new double[darab];
	for (unsigned int i=0; i<darab; i++)
		elemek[i]=masik.elemek[i];
}

Vektor::~Vektor()
{
	delete [] elemek;
}

Vektor &Vektor::operator=(const Vektor &masik)
{
    if (this == &masik)
        return *this;

    if (this->darab != masik.darab)
    {
        delete [] this->elemek;
        this->elemek = new double[masik.darab];
        this->darab = masik.darab;
    }
    for (unsigned i=0; i<darab; i++)
    {
        this->elemek[i] = masik.elemek[i];
    }
    return *this;
}

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
	elemek[index]=elem;
}

Vektor Vektor::operator+(const Vektor &masik) const
{
    // Vektor eredmeny(this->darab);
    // for (unsigned i=0; i<this->darab; i++)
    // {
    //     eredmeny.elemek[i] = this->elemek[i] + masik.elemek[i];
    // }
    // return eredmeny;
    Vektor eredmeny(*this);
    return eredmeny += masik;
}

Vektor &Vektor::operator--()
{
    for (unsigned i=0; i<darab; i++)
        --elemek[i];
    return *this;
}

double &Vektor::operator[](unsigned int index)
{
    return elemek[index];
}

const double &Vektor::operator[](unsigned int index) const
{
    return elemek[index];
}

Vektor Vektor::operator--(int)
{
    Vektor masolat(*this);
    for (unsigned i=0; i<darab; i++)
        --elemek[i];
    return masolat;
}

Vektor &Vektor::operator +=(const Vektor &masik)
{
    for (unsigned i=0; i<darab; i++)
    {
        elemek[i] += masik.elemek[i];
    }
    return *this;
}

// Vektor operator+(const Vektor &v1, const Vektor &v2)
// {
//     Vektor eredmeny(v1.getDarab());
//     for (unsigned i=0; i<v1.getDarab(); i++)
//     {
//         double ertek = v1.getElem(i) + v2.getElem(i);
//         eredmeny.setElem(i, ertek);
//     }
//     return eredmeny;
// }

Vektor operator+(double ertek, const Vektor &v)
{
    Vektor eredmeny(v.darab);
    for (unsigned i=0; i<v.darab; i++)
    {
        eredmeny.elemek[i] = ertek + v.elemek[i];
    }
    return eredmeny;
}

ostream &operator<<(ostream &os, const Vektor &v)
{
    os << "(";
    for (unsigned int i=0; i<v.getDarab(); i++)
    {
        if (i>0) os << " , ";
        os << v.getElem(i);
    }
    os << ")";

    return os;
}



