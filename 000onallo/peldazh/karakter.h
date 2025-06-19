#ifndef KARAKTER_H
#define KARAKTER_H


#include <iostream>
#include "akcio.h"
using namespace std;

class Karakter
{

protected:
    string nev;
    int pont;
    string tipus;
public:

    Karakter(const string &nev, int pont);
    virtual ~Karakter();
    string getNev() const;
    int getPont() const;
    virtual bool vegrehajt(Akcio&) =0;
    void setPont(int newPont);
    string getTipus() const;
    void setTipus(const string &newTipus);
};

#endif // KARAKTER_H
