#ifndef HALMAZ_H
#define HALMAZ_H



#include <iostream>
#include <algorithm>
#include <ostream>

class Halmaz
{
    int db;
    double* tomb;

    bool tartalmaz(double d) const{
        for (int i =0; i< db; i++)
            if (tomb[i] == d)
                return true;
        return false;
    }
    void beszur(double d) {
        double* uj = new double[db + 1];
        int i=0, j=0;
        while (i<db && tomb[i]<d)
            uj[j++] = tomb[i++];
        uj[j++] = d;
        while (i<db)
            uj[j++] = tomb[i++];
        delete[] tomb;
        tomb = uj;
        ++db;
    }

    void torol(double d) {
        if (!tartalmaz(d)) return;
        double* uj = new double[db-1];
        int j =0;
        for (int i = 0; i < db; ++i){
            if (tomb[i]!=d){
                uj[j++] = tomb[i];
            }
        }
        delete[] tomb;
        tomb = uj;
        --db;
    }

public:
    Halmaz();
    Halmaz(const Halmaz& masik);
    ~Halmaz();


    Halmaz operator&(const Halmaz& masik) const;
    Halmaz operator|(const Halmaz& masik) const;
    Halmaz operator-(const Halmaz& masik) const;
    Halmaz operator^(const Halmaz& masik) const;

    Halmaz& operator&=(const Halmaz& masik);
    Halmaz& operator|=(const Halmaz& masik);
    Halmaz& operator-=(const Halmaz& masik);
    Halmaz& operator^=(const Halmaz& masik);

    Halmaz operator+(double d) const;
    Halmaz operator-(double d) const;

    Halmaz& operator=(const Halmaz& masik){
        if (this != &masik){
            delete[] tomb;
            db = masik.db;
            tomb = new double[db];
            for (int i=0; i<db; i++){
                tomb[i]=masik.tomb[i];
            }
        }
        return *this;
    }


    bool operator[](double d) const;

    bool operator<=(const Halmaz& masik) const;
    bool operator>=(const Halmaz& masik) const;
    bool operator<(const Halmaz& masik) const;
    bool operator>(const Halmaz& masik) const;
    bool operator==(const Halmaz& masik) const;
    bool operator!=(const Halmaz& masik) const;


    int meret() const;
    double legnagyobb() const;
    double legkisebb() const;
    void torol();
    Halmaz& operator<<(double d);
    Halmaz& operator>>(double d);
    double operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& os, const Halmaz& h);
};



#endif // HALMAZ_H


