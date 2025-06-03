#include "magus.h"


Magus::Magus(const std::string &_nev, int _szint, int _mana) : Karakter(_nev, _szint), mana(_mana) {}

int Magus::eletero() const
{
    return 8 + szint * 3 + (mana / 5);
}

int Magus::sebzes() const
{
    return 4 + szint * 2 + (mana / 10) * 3;
}

void Magus::kiir() const
{
    std::cout << nev << ": " << szint << ". szintu magus, mana: " << mana << std::endl;
}
