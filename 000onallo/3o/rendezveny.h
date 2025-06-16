#ifndef RENDEZVENY_H
#define RENDEZVENY_H

#include "szamsor.h"
#include "szemely.h"

class Rendezveny : public Szamsor
{
    Szemely* kiemelt;
public:
    Rendezveny();
    Rendezveny(Rendezveny& masik);
    ~Rendezveny();
    Rendezveny& operator=(Rendezveny& masik);
    void legjobbNap() const;
    void kiir() const;
    Szemely *getKiemeltVendeg() const;
    void setKiemeltVendeg(const Szemely& newKiemelt);
};

#endif // RENDEZVENY_H








