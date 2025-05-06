#include "rendezveny.h"
#include <iostream>

using namespace std;

Rendezveny::Rendezveny() :
    Szamsor(7), 
    kiemeltVendeg(nullptr) {}

Rendezveny::Rendezveny(const Rendezveny &r) : Szamsor(r), kiemeltVendeg(nullptr) {
    if (r.kiemeltVendeg != nullptr) {
        kiemeltVendeg = new Szemely(*r.kiemeltVendeg);
    } else {
        kiemeltVendeg = nullptr;
    }
}
Rendezveny::~Rendezveny() {
    delete kiemeltVendeg;
}
     
void Rendezveny::setKiemeltVendeg(const Szemely& szemely) {
    if (kiemeltVendeg != nullptr) {
        delete kiemeltVendeg;
    }
    kiemeltVendeg = new Szemely(szemely);
}
const Szemely* Rendezveny::getKiemeltVendeg() const {
    return kiemeltVendeg;
}

void Rendezveny::kiir() const {
    cout << "Kiemelt vendég: ";
    if (kiemeltVendeg != nullptr) {
        kiemeltVendeg->kiir();
    } else {
        cout << "Nincs kiemelt vendeg." << endl;
    }
    cout << "Resztvevok szama naponta:" << endl;
    for (unsigned int i = 0; i < getDarab(); i++) {
        cout << "Nap " << i + 1 << ": " << getErtek(i) << endl; 
    }
}

void Rendezveny::legjobbNap() const {
    int max = getErtek(0);
    int index = 0;
    for (unsigned int i = 1; i < getDarab(); ++i) {
        if (getErtek(i) > max) {
            max = getErtek(i);
            index = i;
        }
    }
    cout << "A legnagyobb letszam a " << (index + 1) << ". napon volt: " << max << " fo." << endl;
}



// Készíts a Rendezveny-be egy legjobbNap függvényt, amely kiírja, hogy a rendezvény hanyadik
// napján volt a legnagyobb a létszám.

