#include "datumlista.h"
#include <iostream>
namespace Naptar{


int DatumLista::maxDarab = 6;

int DatumLista::getDarab() const
{
    return db;
}




std::string DatumLista::getMegjegyzes() const
{
    return megjegyzes;
}

void DatumLista::setMegjegyzes(const std::string &newMegjegyzes)
{
    megjegyzes = newMegjegyzes;
}

Datum DatumLista::getDatum(int index) const
{

        return datumok[index];

}

void DatumLista::setDatum(int index, Datum newDatum)
{
    if(index<db){
        datumok[index] = newDatum;
    }
}

void DatumLista::hozzaad(Datum d)
{
    if (db<maxDarab){
    Datum* ujDatumok = new Datum[db+1];
    for (int i=0; i < db; i++){
        ujDatumok[i] = datumok[i];

    }
    ujDatumok[db] = d;
        db++;
        delete [] datumok;
        datumok = ujDatumok;
}
}

Datum DatumLista::legkorabbi()
{
    Datum legk = datumok[0];
    for (int i = 1; i < db; i++){
        if(datumok[i].getEv() < legk.getEv() ||
            (datumok[i].getEv() ==  legk.getEv() &&
                                                  datumok[i].getHonap() < legk.getHonap()) ||
            (datumok[i].getEv() == legk.getEv() && datumok[i].getHonap() == legk.getHonap() && datumok[i].getNap() < legk.getNap())
            )
        {
         legk = datumok[i];
        }

    }

    return legk;
}

int DatumLista::getMaxDarab()
{
    return maxDarab;
}

void DatumLista::setMaxDarab(int newMaxDarab)
{
    maxDarab = newMaxDarab;
}



DatumLista::DatumLista(int d,std::string megjegyzes) : db(d), megjegyzes(megjegyzes)
{
    datumok = new Datum[db];
}

DatumLista::DatumLista(DatumLista &dl) : db(dl.db), megjegyzes(dl.megjegyzes)
{
    datumok = new Datum[db];
    for (int i=0; i < db; i++){
        datumok[i] = dl.datumok[i];
    }

}

DatumLista::~DatumLista()
{
    delete[] datumok;
}




} // Naptar
