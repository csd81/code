#ifndef SZOVEGMEZO_H
#define SZOVEGMEZO_H
#include<iostream>
#include "bevitelimezo.h"
using namespace std;

class SzovegMezo : public BeviteliMezo
{

    string szoveg;
    int maxhossz;
public:
    SzovegMezo(const string &megnevezes, bool szerkesztheto, int maxhossz);

    string getSzoveg() const;
    void setSzoveg(const string &newSzoveg);
    int getMaxhossz() const;
    bool megfelelo() const  override;
    string operator~();
    void kiir(std::ostream& os) const override {
        os << szoveg;
    }

};

#endif // SZOVEGMEZO_H
