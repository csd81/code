#include "hallgato.h"
#include <iostream>

unsigned int Hallgato::getFelevek() const
{
    return felevek;
}

void Hallgato::setFelevek(unsigned int newFelevek)
{
    felevek = newFelevek;
}

std::string Hallgato::getNeptunKod() const
{
    return neptunKod;
}

void Hallgato::kiir() const
{
    Szemely::kiir();
    std::cout << "felevek: " << felevek << " " << "neptunKod: " << neptunKod << std::endl << std::endl;
}

void Hallgato::furcsa()
{
    bool b     = (this->getEletkor()-felevek/2) < 18;

    std::cout << (b? "túl fiatal\n" : "hallgató életkora ok.\n");
}


Hallgato::Hallgato(const std::string &v, const std::string &k, unsigned int kor, const std::string &neptunKod, unsigned int felevek) : Szemely(v, k, kor),
    felevek(felevek),
    neptunKod(neptunKod)
{}
