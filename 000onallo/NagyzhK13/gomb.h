#ifndef GOMB_H
#define GOMB_H
#include <iostream>
#include "elem.h"

class Gomb : public Elem
{
    std::string szoveg;
    int megnyomasok;

public:
    Gomb(int x, int y, int szelesseg, int magassag, const std::string &szoveg);
    Gomb(int x, int y, int szelesseg, int magassag, const std::string &szoveg, int megnyomasok);
    std::string getSzoveg() const;
    int getMegnyomasok() const;
    void kirajzol() override;
    void aktival(int egesz = 5) override;
    bool operator==(const Gomb&);


    // Elem interface
public:
    Elem *clone() const override;
};

#endif // GOMB_H
