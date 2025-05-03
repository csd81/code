#include "hajo.h"
#include <iostream>

Hajo::Hajo(unsigned int tomeg, unsigned int sebesseg, unsigned int teherbiras):

    Jarmu(tomeg, sebesseg), teherbiras(teherbiras)
{
}

void Hajo::kiir() const{
    std::cout << "\nHajo - Sebesseg: " << getSebesseg() <<
        " tomege: " << getSebesseg() <<
               " teherb: " << teherbiras;
}
