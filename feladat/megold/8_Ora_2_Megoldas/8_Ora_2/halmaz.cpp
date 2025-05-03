#include "halmaz.h"

Halmaz::Halmaz():
	db(0),
	elemek(0)
{
}

Halmaz::Halmaz(const Halmaz &h):
	db(h.db),
	elemek(new double[h.db])
{
	for (unsigned int i=0; i<db; ++i)
		elemek[i]=h.elemek[i];
}

Halmaz::~Halmaz()
{
	delete [] elemek;
}

unsigned int Halmaz::meret() const
{
	return db;
}

// Rendezett beszuras
// Mivel az elemek rendezetten lesznek beszúrva, a többi függvény ezt figyelembe is veheti, amitől a működésük hatékonyabb lenne.
// A megoldás ezt nem teszi meg minden esetben, de extra feladatként el lehet készíteni a teljes osztályt ezen elven.
// A visszatérés Halmaz&, hogy lehessen láncolni (h<<8.5<<5<<4<<12.33;).
Halmaz &Halmaz::operator <<(double ertek)
{
	unsigned int i=0;
	while (i<db && elemek[i]<ertek) ++i;
	if (i==db || elemek[i]>ertek) // ha még nincs ilyen érték
	{
		double *ujelemek=new double[db+1];
		for (unsigned int j=0; j<i; ++j)
			ujelemek[j]=elemek[j];
		ujelemek[i]=ertek;
		for (unsigned int j=i+1; j<=db; ++j)
			ujelemek[j]=elemek[j-1];

		delete [] elemek;
		elemek=ujelemek;
		++db;
	}

	return *this;
}

Halmaz &Halmaz::operator >>(double ertek)
{
	unsigned int i=0;
	while (i<db && elemek[i]!=ertek) ++i;
	if (i<db) // csak akkor ha van ilyen elem
	{
		if (db==1) // Ha kiürülne a halmaz, akkor kezeljük is úgy.
		{
			delete [] elemek;
			db=0;
			elemek=0;
		}
		else
		{
			double *ujelemek=new double[db-1];
			for (unsigned int j=0; j<i; ++j)
				ujelemek[j]=elemek[j];
			for (unsigned int j=i+1; j<db; ++j)
				ujelemek[j-1]=elemek[j];
			delete [] elemek;
			elemek=ujelemek;
			--db;
		}
	}

	return *this;
}

Halmaz &Halmaz::operator =(const Halmaz &h)
{
	if (this!=&h)
	{
		delete [] elemek;
		db=h.db;
		elemek=new double[db];
		for (unsigned int i=0; i<db; ++i)
			elemek[i]=h.elemek[i];
	}

	return *this;
}

ostream &operator <<(ostream &os, const Halmaz &h)
{
	os<<"{";
	for (unsigned int i=0; i<h.db; ++i)
	{
		if (i>0) os<<", ";
		os<<h.elemek[i];
	}
	os<<"}";

	return os;
}

// Gyakorlatilag egy lineáris keresesés.
bool Halmaz::operator [](double ertek) const
{
	unsigned int i=0;
	while (i<db && elemek[i]!=ertek) ++i;
	return i<db;
}

// Metszet művelet: ami mindkettőben benne van. Új üres halmazhoz tegyük ezeket hozzá (felhasználhatjuk a már megírt << operátort).
Halmaz Halmaz::operator &(const Halmaz &h) const
{
	Halmaz eredmeny;
	for (unsigned int i=0; i<db; ++i)
	{
		if (h[elemek[i]]) eredmeny<<elemek[i];
	}

	return eredmeny;
}

// Unió művelet: ami legalább az egyikben benne van. A meglévő halmazhoz tegyük hozzá a másik elemeit.
Halmaz Halmaz::operator |(const Halmaz &h) const
{
	Halmaz eredmeny(*this);
	for (unsigned int i=0; i<h.db; ++i)
		eredmeny<<h.elemek[i];

	return eredmeny;
}

// Kivonás: ami a bal oldaliban benne van, de a jobb oldaliban nincs. A balból szedjük ki a jobb elemeit (>> operátor).
Halmaz Halmaz::operator -(const Halmaz &h) const
{
	Halmaz eredmeny(*this);
	for (unsigned int i=0; i<h.db; ++i)
		eredmeny>>h.elemek[i];

	return eredmeny;
}

// Kölcsönös kizárás: igazából az unióból kivonva a metszetet.
Halmaz Halmaz::operator ^(const Halmaz &h) const
{
	return (*this|h)-(*this&h);
}

Halmaz &Halmaz::operator &=(const Halmaz &h)
{
	*this=*this&h;

	return *this;
}

// Ez is lehetne *this=*this|h; de itt nem nehéz külön sem kifejteni, és gyorsabb.
Halmaz &Halmaz::operator |=(const Halmaz &h)
{
	for (unsigned int i=0; i<h.db; ++i)
		operator <<(h.elemek[i]);

	return *this;
}

Halmaz &Halmaz::operator -=(const Halmaz &h)
{
	for (unsigned int i=0; i<h.db; ++i)
		operator >>(h.elemek[i]);

	return *this;
}

Halmaz &Halmaz::operator ^=(const Halmaz &h)
{
	*this=*this^h;

	return *this;
}

Halmaz Halmaz::operator +(double ertek) const
{
	Halmaz eredmeny(*this);
	eredmeny<<ertek;
	return eredmeny;
}

Halmaz Halmaz::operator -(double ertek) const
{
	Halmaz eredmeny(*this);
	eredmeny>>ertek;
	return eredmeny;
}

// Igaz, ha a bal oldali halmaz minden eleme benne van a jobb oldaliban, és kevesebb eleme is van.
// Lineáris keresés: keressük meg az elsőt, ami nincs benne. Ha nincs ilyen, akkor mind benne van.
bool Halmaz::operator <(const Halmaz &h) const
{
	unsigned int i=0;
	while (i<db && h[elemek[i]]) ++i;

	return i==db && db<h.db;
}

// Itt meg is egyezhet a kettő.
bool Halmaz::operator <=(const Halmaz &h) const
{
	unsigned int i=0;
	while (i<db && h[elemek[i]]) ++i;

	return i==db;
}

// operator [](h.elemek[i]) : a bal oldali halmaz (this) [] operátorát hívja meg.
bool Halmaz::operator >(const Halmaz &h) const
{
	unsigned int i=0;
	while (i<h.db && operator [](h.elemek[i])) ++i;

	return i==h.db && h.db<db;
}

bool Halmaz::operator >=(const Halmaz &h) const
{
	unsigned int i=0;
	while (i<h.db && operator [](h.elemek[i])) ++i;

	return i==h.db;
}

bool Halmaz::operator ==(const Halmaz &h) const
{
	unsigned int i=0;
	while (i<db && h[elemek[i]]) ++i;

	return i==db && db==h.db;
}

bool Halmaz::operator !=(const Halmaz &h) const
{
	return !operator ==(h);
}

// Mivel rendezve tároljuk az elemeket, itt nem kell maximum keresés.
double Halmaz::legnagyobb() const
{
	return elemek[db-1];
}

// Mivel rendezve tároljuk az elemeket, itt nem kell minimum keresés.
double Halmaz::legkisebb() const
{
	return elemek[0];
}

void Halmaz::torol()
{
	delete [] elemek;
	db=0;
	elemek=0;
}
