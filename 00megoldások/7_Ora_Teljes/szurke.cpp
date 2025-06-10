#include "szurke.h"

Szurke::Szurke(double vilagos):
	vilagos(vilagos)
{
}

unsigned char Szurke::R() const
{
	return vilagos*255;
}

unsigned char Szurke::G() const
{
	return vilagos*255;
}

unsigned char Szurke::B() const
{
	return vilagos*255;
}
