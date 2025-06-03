
#include <iostream>
#include "karakter.h"

Karakter::Karakter(const std::string &nev, int szint) : nev(nev),
    szint(szint)
{}


std::string Karakter::getNev() const { return nev; }

int Karakter::getSzint() const { return szint; }



