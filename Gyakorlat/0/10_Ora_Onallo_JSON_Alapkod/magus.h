#ifndef MAGUS_H
#define MAGUS_H

#include "karakter.h"

class Magus : public Karakter
{
    int mana;
public:
    Magus();
    Magus(const string &nev, int szint, int mana);
    int eletero() const;
    int sebzes() const;
    void kiir() const;

};

#endif // MAGUS_H




