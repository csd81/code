#include "feketefeher.h"

FeketeFeher::FeketeFeher(bool fekete):
	fekete(fekete)
{
}

unsigned char FeketeFeher::R() const
{
	if (fekete) return 0;
	else return 255;
}

unsigned char FeketeFeher::G() const
{
	if (fekete) return 0;
	else return 255;
}

unsigned char FeketeFeher::B() const
{
	if (fekete) return 0;
	else return 255;
}
