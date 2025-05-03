#include "repulo.h"
#include <iostream>

Repulo::Repulo(unsigned int tomeg, unsigned int sebesseg, unsigned int utasletszam) :
    Jarmu(tomeg, sebesseg), utasletszam(utasletszam)
{
}

void Repulo::kiir() const{
    std::cout << "\nRepulo  - Sebesseg: " << getSebesseg() <<
        " tomege: " << getSebesseg() <<
        " utasletszam: " << utasletszam;
}
