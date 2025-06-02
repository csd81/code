#ifndef IJASZ_H
#define IJASZ_H

#include "karakter.h"

class Ijasz : public Karakter
{
    int pontossag;
public:
    Ijasz(const string &nev, int szint, int pontossag);
    int eletero() const;
    int sebzes() const;
    void kiir() const;
};

#endif // IJASZ_H




