#ifndef HATARIDO_H
#define HATARIDO_H

#include "datum.h"
#include <string>

class Hatarido
{
    std::string nev;
    Datum* alpha;
    Datum* beta;
    Datum* vegso;
    static Datum aktualisDatum;

public:
    Hatarido(std::string n);
    ~Hatarido();

    Hatarido(const Hatarido& other);



    std::string getNev() const;
    void setNev(std::string n);
    Datum* getAlphaDatum() const;
    void setAlphaDatum(Datum* al);
    Datum* getBetaDatum() const;
    void setBetaDatum(Datum* b);
    Datum* getVegsoDatum() const;
    void setVegsoDatum(Datum* v);
    static void setAktualisDatum(const Datum& aktualis);
    static Datum getAktualisDatum();
    void lejart() const;
    void hataridoTorol(std::string tipus);

    //copy con

};

#endif // HATARIDO_H
