#ifndef HATARIDO_H
#define HATARIDO_H

#include <string>
#include "datum.h"

using namespace std;

class Hatarido
{
    string nev;
    Datum *alphaDatum;
    Datum *betaDatum;
    Datum *vegsoDatum;

    static Datum aktualisDatum;

public:
    Hatarido(const string &_nev);
    ~Hatarido();
    string getNev() const;
    void setNev(const string &newNev);
    Datum *getAlphaDatum() const;
    void setAlphaDatum(const Datum &d);
    Datum *getBetaDatum() const;
    void setBetaDatum(const Datum &d);
    Datum *getVegsoDatum() const;
    void setVegsoDatum(const Datum &d);

    static Datum getAktualisDatum();
    static void setAktualisDatum(const Datum &d);
};

#endif // HATARIDO_H
