#ifndef IJASZ_H
#define IJASZ_H

#include "karakter.h"

class Ijasz : public Karakter
{
    int pontossag;
public:
    Ijasz(const std::string &nev, int szint, int pontossag);
    int eletero() const override;
    int sebzes() const override;
    void kiir() const override;
};

#endif // IJASZ_H
