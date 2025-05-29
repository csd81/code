#include <iostream>
#include "hallgato.h"


Hallgato::Hallgato(const std::string& vnev,
                   const std::string& knev,
                   unsigned int kor,
                   const std::string& neptunKod,
                   unsigned int felev)
    : Szemely(vnev, knev, kor),
    neptun(neptunKod),
    felevek(felev)
{}

unsigned int Hallgato::getFelevek() const
{
    return felevek;
}

void Hallgato::setFelevek(unsigned int newFelevek)
{
    felevek = newFelevek;
}

std::string Hallgato::getNeptun() const
{
    return neptun;
}





void Hallgato::kiir() const
{
    Szemely::kiir();
    std::cout << "Neptun: " << neptun
              << ", Felevek: " << felevek
              << endl;
}



bool Hallgato::furcsa() const
{
    unsigned int elvartEletkor = 18 + (felevek - 1);
    return getEletkor() < elvartEletkor;
}




























