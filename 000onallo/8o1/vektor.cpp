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
