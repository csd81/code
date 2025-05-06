#ifndef RENDEZVENY_H
#define RENDEZVENY_H

#include "szamsor.h"
#include "szemely.h"

class Rendezveny : public Szamsor
{
    Szemely* szemelyek;
public:
    Rendezveny();
    Rendezveny(Rendezveny& r); // copy con

    void setSzemely(Szemely* sz);
    Szemely* getSzemely();
    void kiir();
    void legjobbNap(); //  legnagyobb a létszámú nap
};

#endif // RENDEZVENY_H










