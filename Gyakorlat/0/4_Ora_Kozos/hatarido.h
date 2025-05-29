#ifndef HATARIDO_H
#define HATARIDO_H
#include "datum.h"
#include <iostream>
#include <string>

class Hatarido
{
    std::string nev;
    Datum* alphaDatum;
    Datum* betaDatum;
    Datum* vegsoDatum;
public:
    Hatarido(std::string n);

    Hatarido(Hatarido& h);
    ~Hatarido();

    std::string getNev() const;
    void setNev(const std::string &newNev);
    Datum *getAlphaDatum() const;
    void setAlphaDatum(const Datum &newAlphaDatum);
    Datum *getBetaDatum() const;
    void setBetaDatum(const Datum &newBetaDatum);
    Datum *getVegsoDatum() const;
    void setVegsoDatum(const Datum &newVegsoDatum);

    static Datum getAktualisDatum();
    static void setAktualisDatum(Datum akt);
    static Datum aktualisDatum;

    void lejart();
    void hataridoTorol(Datum* d);
    void hataridoTorol(const std::string& tipus);

};

#endif // HATARIDO_H









// A bejegyzett határidőket lehessen törölni is egy hataridoTorol metódus segítségével, amely megkapja paraméterben hogy melyik határidőt törölje.

// Készíts másoló konstruktort a Hatarido osztályhoz.
