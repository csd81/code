#ifndef DATUMLISTA_H
#define DATUMLISTA_H
#include "datum.h"
#include <iostream>

namespace Naptar{
class DatumLista
{
    unsigned int darab;
    Datum * datumok;
    std::string megjegyzes;
    static unsigned int maxDarab;


public:
    DatumLista(int d, std::string m);
    ~DatumLista();
    DatumLista(const DatumLista& masik);
    DatumLista& operator=(const DatumLista& masik);



    static void setMaxDarab(unsigned int md);
    static unsigned int getMaxDarab();

    std::string getMegjegyzes() const;
    Datum  getDatum(unsigned int i) const;
    unsigned int getDarab() const;


    void setMegjegyzes(std::string m);
    void setDatum(unsigned int i, Datum d);
    void hozzaad(const Datum& d);
    Datum legkorabbi() const;

};





} // namespace Naptar



#endif // DATUMLISTA_H








