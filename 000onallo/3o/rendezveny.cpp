#include "rendezveny.h"
#include "szemely.h"
#include <iostream>


Szemely *Rendezveny::getKiemeltVendeg() const
{
    return kiemelt;
}

void Rendezveny::setKiemeltVendeg(const Szemely& newKiemelt)
{
    kiemelt =  new Szemely(newKiemelt.getVezetekNev(), newKiemelt.getKeresztNev(), newKiemelt.getEletkor());
}

Rendezveny::Rendezveny() : Szamsor(7)
{
    kiemelt = nullptr;
}

Rendezveny::Rendezveny(Rendezveny &masik) : Szamsor(masik)
{
    if (masik.kiemelt != nullptr)
        kiemelt = new Szemely(*masik.kiemelt);
    else
        kiemelt = nullptr;
}

Rendezveny::~Rendezveny()
{
    if (kiemelt != nullptr)
        delete kiemelt;

}

Rendezveny& Rendezveny::operator=(Rendezveny &masik)
{
    if (this != &masik) {
        Szamsor::operator=(masik); // Alaposztály másolása

        delete kiemelt;
        if (masik.kiemelt != nullptr)
            kiemelt = new Szemely(*masik.kiemelt);
        else
            kiemelt = nullptr;
    }
    return *this;
}

void Rendezveny::legjobbNap() const
{
    unsigned int index =0;
    int max = getErtek(0);
    for (unsigned int i =0; i < 7; i++){
        if (getErtek(i) > max){
            max = getErtek(i);
            index = i;

        }
    }
    std::cout << "A legjobb nap: " << index + 1 << ". nap, " << max << " fővel." << std::endl;

}


void Rendezveny::kiir() const
{
    for (unsigned int i = 0; i < 7; i++){
        std::cout << getErtek(i) << " ";

    }
   std::cout << std::endl;

    if (kiemelt != nullptr) {
        std::cout << "Kiemelt vendég: "
        << kiemelt->teljesNev()
        << ", életkor: " << kiemelt->getEletkor()
        << std::endl;
    }
}
