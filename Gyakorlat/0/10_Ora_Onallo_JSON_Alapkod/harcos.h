#ifndef HARCOS_H
#define HARCOS_H

#include "karakter.h"

class Harcos : public Karakter
{
    string fegyver;
public:

    Harcos(const string &nev, int szint, const string &fegyver);
    int eletero() const;
    int sebzes() const;
    void kiir() const;
};

#endif // HARCOS_H







