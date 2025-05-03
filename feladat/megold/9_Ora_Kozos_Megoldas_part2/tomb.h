#ifndef TOMB_H
#define TOMB_H

#include "tombalap.h"

template <class Tipus, int Meret>
class Tomb : public TombAlap<Tipus>
{
	Tipus tomb[Meret];
public:
	int meret() const override;
	void beallit(int index, const Tipus &adat) override;
	Tipus leker(int index) const override;
	Tipus &elem(int index) override;
	const Tipus &elem(int index) const override;
};

template<class Tipus, int Meret>
int Tomb<Tipus,Meret>::meret() const
{
	return Meret;
}

template<class Tipus, int Meret>
void Tomb<Tipus,Meret>::beallit(int index, const Tipus &adat)
{
	if (index>=0 && index<Meret)
		tomb[index]=adat;
}

template<class Tipus, int Meret>
Tipus Tomb<Tipus,Meret>::leker(int index) const
{
	return tomb[index];
}

template<class Tipus, int Meret>
Tipus &Tomb<Tipus,Meret>::elem(int index)
{
	return tomb[index];
}

template<class Tipus, int Meret>
const Tipus &Tomb<Tipus,Meret>::elem(int index) const
{
	return tomb[index];
}

#endif // TOMB_H
