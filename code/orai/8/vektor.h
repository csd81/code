#ifndef VEKTOR_H
#define VEKTOR_H

#include <cmath>

#include <iostream>

using namespace std;

class Vektor
{
	unsigned int darab;
	double *elemek;

	// meg lehet oldani egy darab vector<double> tárolóval is, ki lehet próbálni, hogy mi változik
public:
	Vektor(unsigned int db);
	Vektor(const Vektor &masik);
	~Vektor();
    Vektor &operator=(const Vektor &masik);

	unsigned int getDarab() const;
	double getElem(unsigned int index) const;
	void setElem(unsigned int index, double elem);

    Vektor operator+(const Vektor &masik) const;
    Vektor& operator+=(const Vektor &masik);

    friend Vektor operator+(double ertek, const Vektor &v);

    Vektor &operator--();
    Vektor operator--(int);

    double& operator[](unsigned index);
    const double& operator[](unsigned index) const;
};

// Vektor operator+(const Vektor &v1, const Vektor &v2);
Vektor operator+(double ertek, const Vektor &v);

ostream &operator<<(ostream &os, const Vektor &v);


#endif // VEKTOR_H
