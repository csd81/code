#include "szemely.h"

#include <iostream>

Szemely::Szemely(const std::string &v, const std::string &k, unsigned int kor):
	vnev(v),
	knev(k),
	eletkor(kor)
{
}

const std::string &Szemely::getVezetekNev() const
{
	return vnev;
}

const std::string &Szemely::getKeresztNev() const
{
	return knev;
}

std::string Szemely::teljesNev() const
{
	return vnev + " " + knev; // Figyelem: itt a művelet új változót hoz létre, ami megszűnik a függvény végén. Így nem lehet referenciával visszatérni.
}

unsigned int Szemely::getEletkor() const
{
	return eletkor;
}

void Szemely::kiir() const
{
    std::cout << vnev << " " << knev << ": " << eletkor << std::endl;
}

bool Szemely::fiatalabb(const Szemely &masik) const
{
    return (this->eletkor < masik.getEletkor());
}
