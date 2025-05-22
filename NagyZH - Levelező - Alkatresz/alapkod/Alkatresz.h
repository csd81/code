#ifndef ALKATRESZ_H
#define ALKATRESZ_H

#include <iostream>
#include <string>


class Alkatresz {
protected:
    std::string gyarto;
    std::string tipus;
    static int ertekHatar;

public:
        Alkatresz(const string& g, const string& t) : gyarto(g), tipus(t) {}
    virtual ~Alkatresz() {}
    
    string getGyarto() const { return gyarto; }
    string getTipus() const { return tipus; }

    virtual int ar() const = 0;

    virtual void kiir() const {
        std::cout << gyarto << " -- " << tipus << ":" << ar() << endl;
    }

    virtual int teljesAr() const {

        int alap = ar();
        if (alap <= ertekHatar) return alap;
        if (alap <= 2 * ertekHatar) return alap+14000;
        return alap + 32000;
    }

    
    static int getErtekHatar() {return ertekHatar}
    static void setErtekHatar(int ertek) { ertekHatar = ertek; }
        
    bool operator<(int ertek) const {return ar() < ertek; }

    friend ostream& operator<<(ostream& os, const Alkatresz& a) {
        os << a. gyarto << " -- " << a.tipus << " : " << a.ar();
        return os;
    }
    
    string operator!() const { return gyarto + " " + tipus; }
};

int Alkatresz::ertekHatar = 450000;

#endif