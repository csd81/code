#include "datum.h"

Datum::Datum(unsigned int _ev, unsigned int _honap, unsigned int _nap):
	ev(_ev),
	honap(_honap),
	nap(_nap)
{
}


Datum::Datum(const Datum& other)
    : ev(other.ev), honap(other.honap), nap(other.nap)
{}


unsigned int Datum::getEv() const
{
	return ev;
}

void Datum::setEv(unsigned int value)
{
	ev = value;
}

unsigned int Datum::getHonap() const
{
	return honap;
}

void Datum::setHonap(unsigned int value)
{
	honap = value;
}

unsigned int Datum::getNap() const
{
	return nap;
}

void Datum::setNap(unsigned int value)
{
	nap = value;
}

bool Datum::regebbiMint(Datum &d)
{
    return (this->ev < d.ev || this->honap < d.honap ||  this->nap < d.nap);
}
