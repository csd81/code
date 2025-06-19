#ifndef SZAMBEVITEL_H
#define SZAMBEVITEL_H

#include "elem.h"

class SzamBevitel : public Elem
{
    int ertek;
public:
    SzamBevitel();
    SzamBevitel(int x, int y, int szelesseg, int magassag, int ertek);
    int getErtek() const;
    void kirajzol() override;
    void aktival(int egesz = 5) override;
    SzamBevitel& operator<<(int szam);



    // Elem interface
public:
    Elem *clone() const override;
};

#endif // SZAMBEVITEL_H




