#include "datum.h"

Datum::Datum(unsigned int _ev, unsigned int _honap, unsigned int _nap):
	ev(_ev),
	honap(_honap),
	nap(_nap)
{
}

Datum::~Datum()
{

}

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

bool Datum::kisebbMint(const Datum &masik)
{
    if (this->ev < masik.getEv()) return true;
    else if (this->ev > masik.getEv()) return false;
    else if (this->honap < masik.getHonap()) return true;
    else if (this->honap > masik.getHonap()) return false;
    else if (this->nap < masik.getNap()) return true;
    else return false;
}


void Datum::kiir()
{
    std::cout <<
    this->getEv() << "." <<
    this->getHonap() << "." <<
    this->getNap() << std::endl;
}



