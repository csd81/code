#include "szamok.h"

namespace Tarolo {

Szamok::Szamok(unsigned int db, double def):
	darab(db)
{
	tomb=new double[db];
	for (unsigned int i=0; i<db; i++) tomb[i]=def;
}

Szamok::~Szamok()
{
	delete [] tomb;
}

unsigned int Szamok::darabLeker() const
{
	return darab;
}

void Szamok::ertekBeallit(unsigned int index, double ertek)
{
	if (index<darab)
		tomb[index]=ertek;
}

double Szamok::ertekLeker(unsigned int index) const
{
	if (index<darab)
		return tomb[index];
	else
		return -1e8;
}

} // namespace Tarolo
