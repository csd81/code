#include "feketefeher.h"



FeketeFeher::FeketeFeher(bool fekete) : fekete(fekete)
{}

unsigned char FeketeFeher::R() const
{
    return fekete ? 0 :255;
}

unsigned char FeketeFeher::G() const
{
    return fekete ? 0 :255;
}

unsigned char FeketeFeher::B() const
{
    return fekete ? 0 :255;
}
