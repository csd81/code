#include "szurke.h"

Szurke::Szurke(double arnyalat) :
    arnyalat(arnyalat)
{}

unsigned char Szurke::R() const
{
    return 255*arnyalat;
}

unsigned char Szurke::G() const
{
    return 255*arnyalat;
}

unsigned char Szurke::B() const
{
    return 255*arnyalat;
}
