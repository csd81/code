#include "processzor.h"

int Processzor::getOrajel() const
{
    return orajel;
}

int Processzor::getMagok() const
{
    return magok;
}

int Processzor::ar() const
{
    return orajel * 11 + magok * 16000;
}


Processzor::Processzor(const string &gyarto, const string &tipus, int orajel, int magok) : Alkatresz(gyarto, tipus),
    orajel(orajel),
    magok(magok)
{}
