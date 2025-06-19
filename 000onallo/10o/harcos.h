#ifndef HARCOS_H
#define HARCOS_H

#include "karakter.h"

class Harcos : public Karakter
{   std::string fegyver;
public:

    Harcos(const std::string &nev, int szint, string fegyver);
    int eletero() const override;
    int sebzes() const override;
    void kiir() const override;
};

#endif // HARCOS_H
