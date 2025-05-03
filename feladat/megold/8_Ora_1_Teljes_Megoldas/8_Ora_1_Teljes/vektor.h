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

	unsigned int getDarab() const;
	double getElem(unsigned int index) const;
	void setElem(unsigned int index, double elem);

	Vektor operator +(const Vektor &masik) const;
	Vektor& operator +=(const Vektor &masik);
	friend Vektor operator +(double ertek, const Vektor &v);
	Vektor& operator =(const Vektor &masik);
	Vektor& operator--(); // prefix
	Vektor operator--(int); // postfix
	friend ostream& operator <<(ostream &os, const Vektor &v);
	// ---------------------------------------
	Vektor operator -(const Vektor &masik) const;
	Vektor& operator -=(const Vektor &masik);
	friend Vektor operator -(double ertek, const Vektor &v);
	Vektor operator *(const Vektor &masik) const;
	Vektor& operator *=(const Vektor &masik);
	friend Vektor operator *(double ertek, const Vektor &v);
	Vektor operator /(const Vektor &masik) const;
	Vektor& operator /=(const Vektor &masik);
	friend Vektor operator /(double ertek, const Vektor &v);
	Vektor operator +(double ertek) const;
	Vektor operator -(double ertek) const;
	Vektor operator *(double ertek) const;
	Vektor operator /(double ertek) const;
	Vektor& operator++(); // prefix
	Vektor operator++(int); // postfix
	double& operator [](unsigned int index);
	const double& operator [](unsigned int index) const;
	double operator ^(const Vektor &masik) const;
	double operator *() const;
	Vektor operator ~() const;
	bool operator ==(const Vektor &masik) const;
	bool operator !=(const Vektor &masik) const;
	bool operator <(const Vektor &masik) const;
};

//Vektor operator +(double ertek, const Vektor &v); // Ez nem feltétlenül kell, mivel ott van az osztályban friend-ként

#endif // VEKTOR_H
