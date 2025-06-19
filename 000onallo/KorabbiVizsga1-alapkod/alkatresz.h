#ifndef ALKATRESZ_H
#define ALKATRESZ_H
#include <iostream>
using namespace std;

class Alkatresz
{
    string gyarto;
    string tipus;
public:
    static int ertekHatar;
    Alkatresz();
    Alkatresz(const string &gyarto, const string &tipus);
    virtual ~Alkatresz();
    string getGyarto() const;
    string getTipus() const;
    virtual int ar() const = 0;
    virtual void kiir() const;
    friend bool operator<(const Alkatresz& a, int i);

    friend ostream&  operator<<(ostream&, const Alkatresz&);
    string  operator!() const;



    int teljesAr() const;


    static int getErtekHatar();
    static void setErtekHatar(int newErtekHatar);
};


#endif // ALKATRESZ_H
