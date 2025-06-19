#ifndef ADATMEGJELENITO_H
#define ADATMEGJELENITO_H
#include <iostream>
using namespace std;

class AdatMegjelenito
{
    string szin;
    bool lathato;
    int lathatocount;
public:
    AdatMegjelenito(const string &szin, bool lathato);
    virtual ~AdatMegjelenito();

    string getSzin() const;
    bool getLathato() const;
    void setLathato(bool newLathato);

    virtual void megjelenit() const = 0;

    int getLathatocount() const;
    void setLathatocount(int newLathatocount);
};

#endif // ADATMEGJELENITO_H


