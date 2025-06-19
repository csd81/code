#include "szurke.h"

Szurke::Szurke(double vilagossag):
    vilagossag(vilagossag)
     {}

unsigned char Szurke::R() const
{
    return static_cast<unsigned char>(255*vilagossag);
}

unsigned char Szurke::G() const
{
    return static_cast<unsigned char>(255*vilagossag);
}

unsigned char Szurke::B() const
{
    return static_cast<unsigned char>(255*vilagossag);
}
