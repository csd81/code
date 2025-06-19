#include "bevitelimezo.h"



string BeviteliMezo::getMegnevezes() const
{
    return megnevezes;
}

bool BeviteliMezo::getSzerkesztheto() const
{
    return szerkesztheto;
}

void BeviteliMezo::setSzerkesztheto(bool newSzerkesztheto)
{
    szerkesztheto = newSzerkesztheto;
}

BeviteliMezo::BeviteliMezo(const string &megnevezes, bool szerkesztheto) : megnevezes(megnevezes),
    szerkesztheto(szerkesztheto)
{}

BeviteliMezo::~BeviteliMezo()
{

}
