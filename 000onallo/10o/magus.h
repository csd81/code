#ifndef MAGUS_H
#define MAGUS_H

#include "karakter.h"

class Magus : public Karakter
{   int mana;
public:
    Magus(const std::string &nev, int szint, int mana);

    int eletero() const override;
    int sebzes() const override;
    void kiir() const override;
};

#endif // MAGUS_H
