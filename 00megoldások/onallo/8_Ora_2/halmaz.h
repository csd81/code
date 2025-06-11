#ifndef HALMAZ_H
#define HALMAZ_H

#include <iostream>

using namespace std;

/*
 * Halmaz osztály:
 * A feladat szerint létre kell hozni egy Halmaz osztályt, amely double értékeket tárol egy átméreteződő tömbben,
 * amely mindig pontosan akkora, amennyi számot tárol. A konstruktor nem vár paramétert.
 * Az operátorok különböző méretű halmazokra is működniük kell, így a megfelelő átméretezésre figyelni kell.
 */

class Halmaz
{
	unsigned int db;
	double *elemek;

public:

	// Konstruktor: paraméter nélküli
	Halmaz();

	// Másoló konstruktor
	Halmaz(const Halmaz &h);

	// Destruktor
	~Halmaz();

	/*
	 * meret() függvény:
	 * Készíts a Halmaz osztályba egy meret függvényt, amely visszaadja a halmaz méretét (eltárolt elemek számát).
	 */
	unsigned int meret() const;

	/*
	 * << operátor hozzáadáshoz:
	 * Definiálj egy << operátort, amellyel elemeket lehet hozzáadni.
	 * A halmazban minden elem csak egyszer szerepelhet.
	 * A belső tömbben az elemek növekvő sorrendben szerepeljenek.
	 */
	Halmaz &operator <<(double ertek);

	/*
	 * >> operátor:
	 * Definiálj egy >> operátort, amivel a halmazból ki lehet venni elemeket.
	 * A halmazban nem létező elemet figyelmen kívül kell hagyni.
	 */
	Halmaz &operator >>(double ertek);

	/*
	 * = operátor:
	 * Definiálj az = operátort, amivel egy halmazt másolni lehet.
	 */
	Halmaz &operator =(const Halmaz &h);

	/*
	 * << operátor kiíráshoz:
	 * Definiálj egy << operátort, amivel a halmaz elemeit lehet kiírni bármilyen kimeneti folyamra.
	 * Új sor ne legyen a kiírás végén. Pl.: {4, 5, 8.5, 12.33}
	 */
	friend ostream &operator <<(ostream &os, const Halmaz &h);

	/*
	 * [] operátor:
	 * Definiálj egy [] operátort, ami a paraméterben kapott számra visszaadja, hogy az a halmaznak eleme-e vagy nem.
	 */
	bool operator [](double ertek) const;

	/*
	 * & operátor:
	 * Definiálj egy & operátort, amely két halmazra elvégzi a metszet műveletet, és visszatér az eredménnyel.
	 */
	Halmaz operator &(const Halmaz &h) const;

	/*
	 * | operátor:
	 * Definiálj egy | operátort, amely két halmazra elvégzi az unió műveletet, és visszatér az eredménnyel.
	 */
	Halmaz operator |(const Halmaz &h) const;

	/*
	 * - operátor:
	 * Definiálj egy - operátort, amely két halmazra elvégzi a halmazkivonás műveletet, és visszatér az eredménnyel.
	 */
	Halmaz operator -(const Halmaz &h) const;

	/*
	 * ^ operátor:
	 * Definiálj egy ^ operátort, amely két halmazra elvégzi a kölcsönös kizárás műveletet, és visszatér az eredménnyel.
	 */
	Halmaz operator ^(const Halmaz &h) const;

	/*
	 * &=, |=, -=, ^= operátorok:
	 * Definiáld az előző operátorok azon verzióját, amelyek a bal oldali halmazt módosítják.
	 */
	Halmaz &operator &=(const Halmaz &h);
	Halmaz &operator |=(const Halmaz &h);
	Halmaz &operator -=(const Halmaz &h);
	Halmaz &operator ^=(const Halmaz &h);

	/*
	 * + operátor:
	 * Definiálj egy + operátort, amelynek bal oldalán a halmaz van, jobb oldalán egy lebegőpontos szám.
	 * Eredménye egy új halmaz, amely az eredeti halmazhoz hozzáadja a számot.
	 */
	Halmaz operator +(double ertek) const;

	/*
	 * - operátor:
	 * Definiálj egy - operátort, amelynek bal oldalán a halmaz van, jobb oldalán egy lebegőpontos szám.
	 * Eredménye egy új halmaz, amely az eredeti halmazból kivonja a számot.
	 */
	Halmaz operator -(double ertek) const;

	/*
	 * <, <=, >, >= operátorok:
	 * Definiálj egy < operátort, amely akkor tér vissza igaz értékkel, ha a bal oldali halmaz valódi részhalmaza a jobb oldalinak.
	 * Definiálj <=, >, >= operátorokat is a megfelelő viszonyokhoz.
	 */
	bool operator <(const Halmaz &h) const;
	bool operator <=(const Halmaz &h) const;
	bool operator >(const Halmaz &h) const;
	bool operator >=(const Halmaz &h) const;

	/*
	 * ==, != operátorok:
	 * Definiáld az == operátort, amely akkor tér vissza igazzal, ha a két halmaz megegyezik.
	 * Definiáld a != operátort is, ami az ellenkezőjét csinálja.
	 */
	bool operator ==(const Halmaz &h) const;
	bool operator !=(const Halmaz &h) const;

	/*
	 * legnagyobb() függvény:
	 * Készíts egy legnagyobb függvényt, amely visszaadja a halmazban tárolt legnagyobb elemet.
	 */
	double legnagyobb() const;

	/*
	 * legkisebb() függvény:
	 * Készíts egy legkisebb függvényt, amely visszaadja a halmazban tárolt legkisebb elemet.
	 */
	double legkisebb() const;

	/*
	 * torol() függvény:
	 * Készíts egy torol függvényt, amely kitöröl minden elemet a halmazból.
	 */
	void torol();

};

#endif // HALMAZ_H
