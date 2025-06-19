#include "memoria.h"

int Memoria::getKapacitas() const
{
    return kapacitas;
}

int Memoria::getSebesseg() const
{
    return sebesseg;
}

int Memoria::ar() const
{
    return kapacitas * 800 + sebesseg * 7;
}


Memoria::Memoria(const string &gyarto, const string &tipus, int kapacitas, int sebesseg) : Alkatresz(gyarto, tipus),
    kapacitas(kapacitas),
    sebesseg(sebesseg)
{}
