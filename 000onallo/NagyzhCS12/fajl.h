#ifndef FAJL_H
#define FAJL_H
#include <iostream>

class Fajl
{
protected:
    std::string nev;
    int meret;
    int fontossag;
public:
    Fajl(const std::string &nev, int meret, int fontossag);
    virtual ~Fajl() ;

    std::string getNev() const;
    int getMeret() const;
    int getFontos() const;
    void setFontos(int newFontossag);

    virtual void adatok() const = 0;
};

#endif // FAJL_H
