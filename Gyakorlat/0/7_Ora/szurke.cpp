#include "szurke.h"



Szurke::Szurke(float ertek) : ertek(ertek)
{}

unsigned char Szurke::R() const
{
    return static_cast<unsigned char>(round(ertek * 255));
}

unsigned char Szurke::G() const
{
    return static_cast<unsigned char>(round(ertek * 255));
}

unsigned char Szurke::B() const
{
    return static_cast<unsigned char>(round(ertek * 255));
}
