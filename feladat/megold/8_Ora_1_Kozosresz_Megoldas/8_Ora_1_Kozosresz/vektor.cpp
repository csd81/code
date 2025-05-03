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

Vektor Vektor::operator +(const Vektor &masik) const
{
	if (darab==masik.darab)
	{
		Vektor eredmeny(darab);
		for (unsigned int i=0; i<darab; i++)
			eredmeny.elemek[i]=elemek[i]+masik.elemek[i];
		return eredmeny;
	}
	else
	{
		return *this;
	}
}

Vektor &Vektor::operator +=(const Vektor &masik)
{
	if (darab==masik.darab)
	{
		for (unsigned int i=0; i<darab; i++)
			elemek[i]+=masik.elemek[i];
		return *this;
	}
	else
	{
		return *this;
	}
}

Vektor operator +(double ertek, const Vektor &v)
{
	Vektor eredmeny(v.darab);
	for (unsigned int i=0; i<v.darab; i++)
		eredmeny.elemek[i]=ertek+v.elemek[i];
	return eredmeny;
}

//Vektor operator +(double ertek, const Vektor &v)
//{
//	Vektor eredmeny(v.getDarab());
//	for (unsigned int i=0; i<v.getDarab(); i++)
//		eredmeny.setElem(i,v.getElem(i)+ertek);
//	return eredmeny;
//}

Vektor &Vektor::operator =(const Vektor &masik)
{
	if (this!=&masik)
	{
		delete [] elemek;
		darab=masik.darab;
		elemek=new double[darab];
		for (unsigned int i=0; i<darab; i++)
			elemek[i]=masik.elemek[i];
	}
	return *this;
}

Vektor &Vektor::operator--()
{
	for (unsigned int i=0; i<darab; i++)
		elemek[i]=elemek[i]-1;
	return *this;
}

Vektor Vektor::operator--(int)
{
	Vektor eredeti(*this);
	for (unsigned int i=0; i<darab; i++)
		elemek[i]=elemek[i]-1;
	return eredeti;
}

ostream &operator <<(ostream &os, const Vektor &v)
{
	os << "(";
	for (unsigned int i=0; i<v.darab; i++)
	{
		if (i>0) os << " , ";
		os << v.elemek[i];
	}
	os << ")";
	return os;
}
