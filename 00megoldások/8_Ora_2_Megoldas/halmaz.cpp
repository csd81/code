#include "halmaz.h"

/*
 * Konstruktor:
 * A Halmaz osztály konstruktorának nem kell paramétert várnia.
 * Inicializáljuk a belső pointert nullptr-ra (0) és a darabszámot 0-ra.
 */
Halmaz::Halmaz():
	db(0),
	elemek(0)
{
}

/*
 * Másoló konstruktor:
 * A feladat szerint létre kell hozni egy másoló konstruktort.
 * Dinamikusan másoljuk az összes elemet egy új tömbbe.
 */
Halmaz::Halmaz(const Halmaz &h):
	db(h.db),
	elemek(new double[h.db])
{
	for (unsigned int i=0; i<db; ++i)
		elemek[i]=h.elemek[i];
}

/*
 * Destruktor:
 * A dinamikusan lefoglalt memória felszabadítása.
 * A feladat külön kiemeli, hogy minden lefoglalt memória megfelelően legyen felszabadítva.
 */
Halmaz::~Halmaz()
{
	delete [] elemek;
}

/*
 * meret() függvény:
 * Visszaadja a halmaz aktuális méretét (eltárolt elemek száma).
 */
unsigned int Halmaz::meret() const
{
	return db;
}

/*
 * << operátor (hozzáadás):
 * Elemet ad a halmazhoz. Csak akkor kerülhet bele, ha még nincs benne.
 * A belső tömb mindig növekvő sorrendben tárolja az elemeket.
 * Ha már benne van az érték, nem történik semmi.
 * A visszatérési érték Halmaz& típusú, hogy az operátorok láncolhatók legyenek.
 */
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

/*
 * >> operátor (eltávolítás):
 * Kiveszi a megadott elemet a halmazból, ha az benne van.
 * Ha a halmaz kiürül, akkor a pointer is nullptr lesz.
 */
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

/*
 * = operátor:
 * A halmaz mélységi másolását végzi. Ha önmagának akarjuk másolni, nem csinál semmit.
 */
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

/*
 * << operátor (kiíráshoz):
 * A halmaz tartalmát írja ki formázott formában: {elem1, elem2, ...}
 * Új sor nincs a végén.
 */
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

/*
 * [] operátor:
 * Visszaadja, hogy a megadott szám eleme-e a halmaznak.
 * Lineáris keresést használ.
 */
bool Halmaz::operator [](double ertek) const
{
	unsigned int i=0;
	while (i<db && elemek[i]!=ertek) ++i;
	return i<db;
}

/*
 * & operátor:
 * Metszet: azok az elemek, amelyek mindkét halmazban benne vannak.
 */
Halmaz Halmaz::operator &(const Halmaz &h) const
{
	Halmaz eredmeny;
	for (unsigned int i=0; i<db; ++i)
	{
		if (h[elemek[i]]) eredmeny<<elemek[i];
	}

	return eredmeny;
}

/*
 * | operátor:
 * Unió: minden egyedi elem, amely legalább egyik halmazban szerepel.
 */
Halmaz Halmaz::operator |(const Halmaz &h) const
{
	Halmaz eredmeny(*this);
	for (unsigned int i=0; i<h.db; ++i)
		eredmeny<<h.elemek[i];

	return eredmeny;
}

/*
 * - operátor:
 * Kivonás: a bal oldali halmazból kivonjuk a jobb oldali elemeit.
 */
Halmaz Halmaz::operator -(const Halmaz &h) const
{
	Halmaz eredmeny(*this);
	for (unsigned int i=0; i<h.db; ++i)
		eredmeny>>h.elemek[i];

	return eredmeny;
}

/*
 * ^ operátor:
 * Kölcsönös kizárás: unióból kivonjuk a metszetet.
 */
Halmaz Halmaz::operator ^(const Halmaz &h) const
{
	return (*this|h)-(*this&h);
}

/*
 * &= operátor:
 * Bal oldali halmaz metszete a jobbal.
 */
Halmaz &Halmaz::operator &=(const Halmaz &h)
{
	*this=*this&h;
	return *this;
}

/*
 * |= operátor:
 * Bal oldali halmaz uniója a jobbal.
 */
Halmaz &Halmaz::operator |=(const Halmaz &h)
{
	for (unsigned int i=0; i<h.db; ++i)
		operator <<(h.elemek[i]);

	return *this;
}

/*
 * -= operátor:
 * Bal oldali halmazból kivonjuk a jobbat.
 */
Halmaz &Halmaz::operator -=(const Halmaz &h)
{
	for (unsigned int i=0; i<h.db; ++i)
		operator >>(h.elemek[i]);

	return *this;
}

/*
 * ^= operátor:
 * Bal oldali halmazból kiszámoljuk a kölcsönös kizárást a jobbal.
 */
Halmaz &Halmaz::operator ^=(const Halmaz &h)
{
	*this=*this^h;
	return *this;
}

/*
 * + operátor:
 * A megadott számot hozzáadja egy új halmazhoz.
 */
Halmaz Halmaz::operator +(double ertek) const
{
	Halmaz eredmeny(*this);
	eredmeny<<ertek;
	return eredmeny;
}

/*
 * - operátor:
 * A megadott számot eltávolítja egy új halmazból.
 */
Halmaz Halmaz::operator -(double ertek) const
{
	Halmaz eredmeny(*this);
	eredmeny>>ertek;
	return eredmeny;
}

/*
 * < operátor:
 * Igaz, ha a bal oldali halmaz valódi részhalmaza a jobbnak.
 */
bool Halmaz::operator <(const Halmaz &h) const
{
	unsigned int i=0;
	while (i<db && h[elemek[i]]) ++i;

	return i==db && db<h.db;
}

/*
 * <= operátor:
 * Igaz, ha a bal oldali halmaz részhalmaza a jobbnak (egyezhetnek is).
 */
bool Halmaz::operator <=(const Halmaz &h) const
{
	unsigned int i=0;
	while (i<db && h[elemek[i]]) ++i;

	return i==db;
}

/*
 * > operátor:
 * Igaz, ha a jobb oldali halmaz valódi részhalmaza a balnak.
 */
bool Halmaz::operator >(const Halmaz &h) const
{
	unsigned int i=0;
	while (i<h.db && operator [](h.elemek[i])) ++i;

	return i==h.db && h.db<db;
}

/*
 * >= operátor:
 * Igaz, ha a jobb oldali halmaz részhalmaza a balnak (egyezhetnek is).
 */
bool Halmaz::operator >=(const Halmaz &h) const
{
	unsigned int i=0;
	while (i<h.db && operator [](h.elemek[i])) ++i;

	return i==h.db;
}

/*
 * == operátor:
 * Igaz, ha a két halmaz megegyezik.
 */
bool Halmaz::operator ==(const Halmaz &h) const
{
	unsigned int i=0;
	while (i<db && h[elemek[i]]) ++i;

	return i==db && db==h.db;
}

/*
 * != operátor:
 * Igaz, ha a két halmaz különbözik.
 */
bool Halmaz::operator !=(const Halmaz &h) const
{
	return !operator ==(h);
}

/*
 * legnagyobb():
 * Visszaadja a legnagyobb elemet.
 * A tömb rendezett, így ez az utolsó.
 */
double Halmaz::legnagyobb() const
{
	return elemek[db-1];
}

/*
 * legkisebb():
 * Visszaadja a legkisebb elemet.
 * A tömb rendezett, így ez az első.
 */
double Halmaz::legkisebb() const
{
	return elemek[0];
}

/*
 * torol():
 * A halmaz összes elemét törli.
 */
void Halmaz::torol()
{
	delete [] elemek;
	db=0;
	elemek=0;
}
