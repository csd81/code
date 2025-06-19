#ifndef PROCESSZOR_H
#define PROCESSZOR_H

#include "alkatresz.h"

class Processzor : public Alkatresz
{
    int orajel, magok;

public:
    Processzor(const string &gyarto, const string &tipus, int orajel, int magok);

    int getOrajel() const;
    int getMagok() const;

    int ar() const override;
    // void kiir() const override;
};

#endif // PROCESSZOR_H
