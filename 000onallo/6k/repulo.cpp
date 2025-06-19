#include "repulo.h"

// Repulo::Repulo() {}

Repulo::Repulo(int utasletszam, unsigned int t, unsigned int s) : Jarmu(t, s),
    utasletszam(utasletszam)
{}

void Repulo::kiir() const
{
    std::cout << "tomeg: " << this->getTomeg() << ", sebesseg: " << this->getSebesseg() << std::endl;
    std::cout << "utasletszam: " << utasletszam << std::endl;
}

Jarmu* Repulo::clone() const  { return new Repulo(*this); }
