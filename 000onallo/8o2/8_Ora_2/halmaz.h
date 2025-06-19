#ifndef HALMAZ_H
#define HALMAZ_H
#include <iostream>

class Halmaz
{
protected:
    int darab;
    double * tomb;
public:
    Halmaz();
    Halmaz(const Halmaz& masik);
    Halmaz& operator=(const Halmaz& masik);
    ~Halmaz();
    int meret() const;
    friend Halmaz& operator<<(Halmaz& h, double elem);
    friend Halmaz& operator>>(Halmaz& h, double elem);
    friend std::ostream& operator<<(std::ostream& os, const Halmaz& h);

    bool operator[](double elem);

    friend Halmaz operator&(const Halmaz& h1, const Halmaz& h2);
    friend Halmaz operator|(const Halmaz& h1, const Halmaz& h2);
    friend Halmaz operator-(const Halmaz& h1, const Halmaz& h2);
    friend Halmaz operator^(const Halmaz& h1, const Halmaz& h2);

    Halmaz& operator&=(const Halmaz& h2);
    Halmaz& operator|=(const Halmaz& h2);
    Halmaz& operator-=(const Halmaz& h2);
    Halmaz& operator^=(const Halmaz& h2);

    friend Halmaz operator+(const Halmaz& h, double szam);
    friend Halmaz operator-(const Halmaz& h, double szam);

    friend bool operator<(const Halmaz& h1, const Halmaz& h2);
    friend bool operator<=(const Halmaz& bal, const Halmaz& jobb);
    friend bool operator>(const Halmaz& h1, const Halmaz& h2);
    friend bool operator>=(const Halmaz& h1, const Halmaz& h2);

    friend bool operator==(const Halmaz& h1, const Halmaz& h2);
    friend bool operator!=(const Halmaz& h1, const Halmaz& h2);

    double legnagyobb();
    double legkisebb();
    void torol();
};

#endif // HALMAZ_H
