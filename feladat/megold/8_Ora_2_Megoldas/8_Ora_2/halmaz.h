#ifndef HALMAZ_H
#define HALMAZ_H

#include <iostream>

using namespace std;

class Halmaz
{
	unsigned int db;
	double *elemek;
public:
	Halmaz();
	Halmaz(const Halmaz &h);
	~Halmaz();

	unsigned int meret() const;

	Halmaz &operator <<(double ertek);
	Halmaz &operator >>(double ertek);

	Halmaz &operator =(const Halmaz &h);

	friend ostream &operator <<(ostream &os, const Halmaz &h);

	bool operator [](double ertek) const;

	Halmaz operator &(const Halmaz &h) const;
	Halmaz operator |(const Halmaz &h) const;
	Halmaz operator -(const Halmaz &h) const;
	Halmaz operator ^(const Halmaz &h) const;

	Halmaz &operator &=(const Halmaz &h);
	Halmaz &operator |=(const Halmaz &h);
	Halmaz &operator -=(const Halmaz &h);
	Halmaz &operator ^=(const Halmaz &h);

	Halmaz operator +(double ertek) const;
	Halmaz operator -(double ertek) const;

	bool operator <(const Halmaz &h) const;
	bool operator <=(const Halmaz &h) const;
	bool operator >(const Halmaz &h) const;
	bool operator >=(const Halmaz &h) const;
	bool operator ==(const Halmaz &h) const;
	bool operator !=(const Halmaz &h) const;

	double legnagyobb() const;
	double legkisebb() const;
	void torol();

};

#endif // HALMAZ_H
