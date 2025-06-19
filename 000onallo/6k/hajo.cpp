#include "hajo.h"

// Hajo::Hajo() {}

Hajo::Hajo(int teherbiras, unsigned int t, unsigned int s) : Jarmu(t, s),
    teherbiras(teherbiras)
{}

void Hajo::kiir() const
{
    std::cout << "tomeg: " << this->getTomeg() << ", sebesseg: " << this->getSebesseg() << std::endl;
    std::cout << "teherbiras: " << teherbiras << std::endl;
}

Jarmu* Hajo::clone() const  { return new Hajo(*this); }

