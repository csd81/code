#ifndef VEKTOR_H
#define VEKTOR_H

#include <cmath>

#include <iostream>



class Vektor
{
	unsigned int darab;
	double *elemek;

	// meg lehet oldani egy darab vector<double> tárolóval is, ki lehet próbálni, hogy mi változik
public:
	Vektor(unsigned int db);
	Vektor(const Vektor &masik);
	~Vektor();

	unsigned int getDarab() const;
	double getElem(unsigned int index) const;
	void setElem(unsigned int index, double elem);

    friend Vektor operator+(const Vektor& v1, const Vektor& v2);
    friend Vektor operator-(const Vektor& v1, const Vektor& v2);
    friend Vektor operator*(const Vektor& v1, const Vektor& v2);
    friend Vektor operator/(const Vektor& v1, const Vektor& v2);
    friend double operator^(const Vektor& v1, const Vektor& v2);

    Vektor& operator+=(const Vektor& masik);
    Vektor& operator-=(const Vektor& masik);
    Vektor& operator/=(const Vektor& masik);
    Vektor& operator*=(const Vektor& masik);
    friend Vektor operator+(double d, const Vektor& v);
    friend Vektor operator-(double d, const Vektor& v);
    friend Vektor operator/(double d, const Vektor& v);
    friend Vektor operator*(double d, const Vektor& v);
    Vektor& operator=(const Vektor& masik);
    friend Vektor operator+(const Vektor& v, double d);
    friend Vektor operator-(const Vektor& v, double d);
    friend Vektor operator*(const Vektor& v, double d);
    friend Vektor operator/(const Vektor& v, double d);
    Vektor& operator--();
    Vektor operator--(int);
    Vektor& operator++();
    Vektor operator++(int);
    friend std::ostream &operator<<(std::ostream& os, const Vektor& v);

    double& operator[](unsigned int i);
    const double& operator[](unsigned int i) const;

    double operator*() const;
    Vektor operator~() const;

    friend bool operator==(const Vektor& v1, const Vektor& v2);
    friend bool operator!=(const Vektor& v1, const Vektor& v2);
    friend bool operator<(const Vektor& v1, const Vektor& v2);




};





#endif // VEKTOR_H


