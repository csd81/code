#include "datum.h"

Datum::Datum(unsigned int _ev, unsigned int _honap, unsigned int _nap):
	ev(_ev),
	honap(_honap),
	nap(_nap)
{
}

unsigned int Datum::getEv() const { return ev; }

void Datum::setEv(unsigned int value) { ev = value; }

unsigned int Datum::getHonap() const { return honap; }

void Datum::setHonap(unsigned int value) { honap = value; }

unsigned int Datum::getNap() const { return nap; }

void Datum::setNap(unsigned int value) { nap = value; }


bool Datum::kisebbMint(const Datum& masik) const {
    if (ev < masik.ev) return true;
    if (ev > masik.ev) return false;

    if (honap < masik.honap) return true;
    if (honap > masik.honap) return false;

    return nap < masik.nap;
}

void Datum::kiir(std::ostream& os) const {
    os << ev << "-"
       << (honap < 10 ? "0" : "") << honap << "-"
       << (nap < 10 ? "0" : "") << nap;
}
