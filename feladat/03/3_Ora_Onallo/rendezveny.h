#ifndef RENDEZVENY_H
#define RENDEZVENY_H

#include "szamsor.h"
#include "szemely.h"

class Rendezveny : public Szamsor {
    Szemely* kiemeltVendeg;
public:
    Rendezveny();
    Rendezveny(const Rendezveny& r); // copy con
    ~Rendezveny() { delete kiemeltVendeg; } // destructor

    void setKiemeltVendeg(const Szemely& szemely);
    const Szemely* getKiemeltVendeg() const;
    
    void kiir() const;
    void legjobbNap() const; //  legnagyobb a létszámú nap
};

#endif // RENDEZVENY_H










