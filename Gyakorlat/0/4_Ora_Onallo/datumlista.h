#ifndef DATUMLISTA_H
#define DATUMLISTA_H

#include "datum.h"

#include <string>
namespace Naptar{

class DatumLista
{
    int db;
    std::string megjegyzes;
    Datum* datumok;

public:
    DatumLista(int d, std::string megjegyzes);
    DatumLista(DatumLista &dl);
    ~DatumLista();

    int getDarab() const;

    std::string getMegjegyzes() const;
    void setMegjegyzes(const std::string &newMegjegyzes);
    Datum getDatum(int index) const;
    void setDatum(int index, Datum newDatum);

    void hozzaad(Datum d);
    Datum legkorabbi();

    static int maxDarab;


    static int getMaxDarab();
    static void setMaxDarab(int newMaxDarab);
};

}

#endif // DATUMLISTA_H









