#include "szurke.h"

Szurke::Szurke(double vilagossag) : vilagossag(vilagossag)
{}

unsigned char Szurke::R() const
{
    return (unsigned char)(vilagossag*255);
}

unsigned char Szurke::G() const
{
    return (unsigned char)(vilagossag*255);
}

unsigned char Szurke::B() const
{
    return (unsigned char)(vilagossag*255);
}
