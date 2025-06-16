#include "datumlista.h"
#include "datum.h"
#include <iostream>

namespace Naptar{

unsigned int Naptar::DatumLista::maxDarab = 6;

DatumLista::DatumLista(int d, std::string m) : darab(d), megjegyzes(m)
{
    datumok = new Datum[darab];
}

DatumLista::~DatumLista()
{
    delete [] datumok;
}

DatumLista::DatumLista(const DatumLista &masik): darab(masik.darab), megjegyzes(masik.megjegyzes)
{
        datumok = new Datum[darab];
        for (unsigned int i=0; i< masik.getDarab(); i++){
            datumok[i]=masik.datumok[i];
        }
}

DatumLista &DatumLista::operator=(const DatumLista &masik)
{
    if (this != &masik){
        darab = masik.darab;
        megjegyzes = masik.megjegyzes;

        delete[] datumok;
        datumok = new Datum[darab];
        for (unsigned int i=0; i< masik.getDarab(); i++){
            datumok[i]=masik.datumok[i];
        }

    }
    return *this;
}

std::string DatumLista::getMegjegyzes() const
{
    return megjegyzes;
}

void DatumLista::setMegjegyzes(std::string m)
{
    megjegyzes=m;
}


void DatumLista::setDatum(unsigned int i, Datum d)
{
    if (i<darab)
       datumok[i] = d;
    else
        std::cerr << "index érvénytelen";
}

Datum DatumLista::getDatum(unsigned int i) const
{
    return datumok[i];
}

unsigned int DatumLista::getDarab() const
{
    return darab;
}



void DatumLista::hozzaad(const Datum &d)
{
    if (darab+1 <= maxDarab){

    Datum * temp = new Datum[darab+1];
    for (unsigned int i=0;i<darab; ++i){
        temp[i]=datumok[i];
    }
    temp[darab] = d;
    delete[] datumok;
    datumok = temp;
    darab++;
    }
}

Datum DatumLista::legkorabbi() const
{
    Datum lk = datumok[0];
    for (unsigned int i=1;i<darab; ++i){
        if (datumok[i].korabbi(lk))
          lk =  datumok[i];
    }
    return lk;
}

unsigned int DatumLista::getMaxDarab()
{
    return maxDarab;
}

void DatumLista::setMaxDarab(unsigned int md)
{
    maxDarab = md;
}



} // namespace
