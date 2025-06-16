#include "szamsor.h"

Szamsor::Szamsor(unsigned int db):
	darab(db)
{
	tomb=new int[db];
}



Szamsor::Szamsor(const Szamsor &masik) : darab(masik.darab)
{
    tomb =new int[darab];
    for (unsigned int i =0; i< darab; i++)
        tomb[i]=masik.tomb[i];

}

Szamsor& Szamsor::operator=(const Szamsor &other)
{
    if (this == &other){
        return *this;
    } else
    delete [] tomb;
    darab = other.darab;
    tomb = new int[darab];
    for (unsigned int i = 0; i < darab; ++i)
        tomb[i]=other.tomb[i];
    return *this;
}

Szamsor::~Szamsor()
{
	delete [] tomb;
}

unsigned int Szamsor::getDarab() const
{
	return darab;
}

int Szamsor::getErtek(unsigned int index) const
{
	return tomb[index];
}

void Szamsor::setErtek(unsigned int index, int ertek)
{
	if (index<darab)
		tomb[index]=ertek;
}

double Szamsor::atlag() const
{
    double sum = 0.0;
    for (unsigned int i = 0; i<darab; i++){
        sum += tomb[i];
        }
    return sum/darab;
}
