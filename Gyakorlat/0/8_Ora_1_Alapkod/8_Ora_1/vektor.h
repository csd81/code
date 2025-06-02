#ifndef VEKTOR_H
#define VEKTOR_H

#include <cmath>

#include <iostream>

using namespace std;

class Vektor
{
    unsigned int meret;
	double *elemek;

	// meg lehet oldani egy darab vector<double> tárolóval is, ki lehet próbálni, hogy mi változik
public:
    Vektor(unsigned int meret);
	Vektor(const Vektor &masik);
    Vektor& operator=(const Vektor& masik);
	~Vektor();

	unsigned int getDarab() const;
	double getElem(unsigned int index) const;
	void setElem(unsigned int index, double elem);

    Vektor operator+(const Vektor& masik) const;

    Vektor operator-(const Vektor& masik) const;

    Vektor operator*(const Vektor& masik) const;

    Vektor operator/(const Vektor& masik) const;

    Vektor& operator+=(const Vektor& masik);

    Vektor& operator-=(const Vektor& masik);

    Vektor& operator*=(const Vektor& masik);

    Vektor& operator/=(const Vektor& masik);

    bool operator==(const Vektor& masik);

    Vektor& operator--();

    Vektor operator--(int);

    Vektor& operator++();

    Vektor operator++(int);

    void operator<<(ostream& os) const;


    Vektor operator*(double skalar) const;
    Vektor operator/(double skalar) const;
    Vektor operator-(double skalar) const;
    Vektor operator+(double skalar) const;

    double& operator[](unsigned int index);
    const double& operator[](unsigned int index) const;
    double operator^(const Vektor& masik) const;
    double operator*() const;
    Vektor operator~() const;
    bool operator!=(const Vektor& masik);
    bool operator<(const Vektor& masik);


};


#endif // VEKTOR_H
Vektor operator*(double skalar, const Vektor& v){
    Vektor eredmeny(v.getDarab());
    for (unsigned int i = 0; i < v.getDarab(); ++i)
        eredmeny.setElem(i, skalar * v.getElem(i));
    return eredmeny;
}

Vektor operator/(double skalar, const Vektor& v){
    Vektor eredmeny(v.getDarab());
    for (unsigned int i = 0; i < v.getDarab(); ++i)
        eredmeny.setElem(i, skalar / v.getElem(i));
    return eredmeny;
}
Vektor operator-(double skalar, const Vektor& v){
    Vektor eredmeny(v.getDarab());
    for (unsigned int i = 0; i < v.getDarab(); ++i)
        eredmeny.setElem(i, skalar - v.getElem(i));
    return eredmeny;
}
Vektor operator+(double skalar, const Vektor& v){
    Vektor eredmeny(v.getDarab());
    for (unsigned int i = 0; i < v.getDarab(); ++i)
        eredmeny.setElem(i, skalar + v.getElem(i));
    return eredmeny;
}




ostream& operator<<(ostream& bal, const Vektor& jobb){
    bal << "(";
    for (unsigned int i = 0; i < jobb.getDarab(); ++i) {
        bal << jobb.getElem(i);
        if (i < jobb.getDarab() - 1)
            bal << ", ";
    }
    bal << ")";
    return bal;
}

