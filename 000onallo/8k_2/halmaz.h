#ifndef HALMAZ_H
#define HALMAZ_H
#include<iostream>

class Halmaz
{
    int darab;
    double * tomb;
public:
    Halmaz();
    Halmaz(int db);
    Halmaz(const Halmaz& masik);
    ~Halmaz();
    int meret();

    Halmaz& operator=(const Halmaz& masik);

    friend Halmaz& operator<<(Halmaz& h, double elem);
    friend Halmaz& operator>>(Halmaz& h, double elem);

    friend std::ostream& operator<<(std::ostream& os, const Halmaz&);

    bool operator[](double elem) const;

    friend Halmaz operator&(const Halmaz& h1, const Halmaz& h2); //metszt
    friend Halmaz operator|(const Halmaz& h1, const Halmaz& h2); //unió
    friend Halmaz operator-(const Halmaz& h1, const Halmaz& h2); //-
    friend Halmaz operator^(const Halmaz& h1, const Halmaz& h2); //xor

    Halmaz& operator&=(const Halmaz& masik);
    Halmaz& operator|=(const Halmaz& masik);
    Halmaz& operator-=(const Halmaz& masik);
    Halmaz& operator^=(const Halmaz& masik);



    friend Halmaz operator+(const Halmaz& h, double d);
    friend Halmaz operator-(const Halmaz& h, double d);

    friend bool operator<(const Halmaz& h1, const Halmaz& h2);
    friend bool operator<=(const Halmaz& h1, const Halmaz& h2);

    friend bool operator>(const Halmaz& h1, const Halmaz& h2);
    friend bool operator>=(const Halmaz& h1, const Halmaz& h2);

    friend bool operator==(const Halmaz& h1, const Halmaz& h2);
    friend bool operator!=(const Halmaz& h1, const Halmaz& h2);

double legnagyobb() const;
double legkisebb() const;
void torol();




};

#endif // HALMAZ_H


