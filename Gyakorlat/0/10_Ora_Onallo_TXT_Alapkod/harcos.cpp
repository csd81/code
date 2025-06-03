#include "harcos.h"
#include <iostream>

Harcos::Harcos(const std::string &_nev, int _szint, const std::string &_fegyver) : Karakter(_nev, _szint), fegyver(_fegyver) {}

int Harcos::eletero() const{
    return 12 + getSzint() * 6;
}


int Harcos::sebzes() const{
    return 5 + getSzint() * 2;
}

void Harcos::kiir() const {
    std::cout << nev << ": " << getSzint() << ". szintu harcos, fegyver: " << fegyver << std::endl;
}



