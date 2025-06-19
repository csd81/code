#ifndef HATARIDO_H
#define HATARIDO_H
#include "datum.h"
#include <iostream>

class Hatarido
{   std::string nev; // szóközöket is
    Datum * alphaDatum;
    Datum * betaDatum;
    Datum * vegsoDatum;
public:
    static Datum aktualisDatum;



    Hatarido(std::string n);
    Hatarido(const Hatarido& masik);
    ~Hatarido();


    std::string getNev() const;
    void setNev(const std::string &newNev);
    Datum *getAlphaDatum() const;
    void setAlphaDatum(const Datum& n);

    Datum *getBetaDatum() const;
    void setBetaDatum(const Datum& n);

    Datum *getVegsoDatum() const;
    void setVegsoDatum(const Datum& n);
    static Datum getAktualisDatum();
    static void setAktualisDatum(const Datum &newAktualisDatum);



    void lejart();

    void hataridoTorol(const std::string h);
};

#endif // HATARIDO_H
