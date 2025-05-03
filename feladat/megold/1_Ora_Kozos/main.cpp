#include <iostream>
#include <string>

using namespace std;

namespace doboz {

struct Doboz
{
	string nev;
	unsigned int szelesseg, magassag, hosszusag;
};

void megjelenit(const Doboz * dobozok, unsigned int db)
{
	for (unsigned int i=0; i<db; i++)
	{
		cout << "A(z) " << i+1 << ". doboz adatai:" << endl;
		cout << "  Neve: " << dobozok[i].nev << endl;
		cout << "  Szelessege: " << dobozok[i].szelesseg << endl;
		cout << "  Magassaga: " << dobozok[i].magassag << endl;
		cout << "  Hosszusaga: " << dobozok[i].hosszusag << endl;
	}
}

void felszinTerfogat(const Doboz &d)
{
	cout << "A(z) " << d.nev << " doboz felszine: ";
	cout << 2*(d.szelesseg*d.magassag+d.szelesseg*d.hosszusag+d.magassag*d.hosszusag);
	cout << " es terfogata: ";
	cout << d.szelesseg*d.magassag*d.hosszusag << endl;
}

void ujrafoglal(Doboz *&dobozok, unsigned int &db, unsigned int novel)
{
	Doboz *uj=new Doboz[db+novel];
	for (unsigned int i=0; i<db; i++)
		uj[i]=dobozok[i];

	delete [] dobozok;
	dobozok=uj;
	db+=novel;
}

bool belefer(const Doboz &d1, const Doboz &d2)
{
	if (d1.szelesseg<=d2.szelesseg && d1.magassag<=d2.magassag && d1.hosszusag<=d2.hosszusag)
	{
		return true;
	}
	else if (d1.szelesseg>=d2.szelesseg && d1.magassag>=d2.magassag && d1.hosszusag>=d2.hosszusag)
	{
		return true;
	}
	else return false;
}

bool belefer(const Doboz &d1, unsigned int sz, unsigned int m, unsigned int h)
{
	return d1.szelesseg<=sz && d1.magassag<=m && d1.hosszusag<=h;
}

void forgat(Doboz &d)
{
	unsigned int csere=d.szelesseg;
	d.szelesseg=d.magassag;
	d.magassag=d.hosszusag;
	d.hosszusag=csere;
}

}

using namespace doboz;

int main()
{
	unsigned int dobozdb=0;
	cout << "Mennyi doboz adatait taroljuk (a kesobbi tesztek miatt legyen legalabb 3)? ";
	cin >> dobozdb;
	Doboz *dobozok=new Doboz[dobozdb];
	for (unsigned int i=0; i<dobozdb; i++)
	{
		cout << "Kerem a(z) " << i+1 << ". doboz adatait:" << endl;
		cout << "  Neve? ";
		cin >> dobozok[i].nev;
		cout << "  Szelessege? ";
		cin >> dobozok[i].szelesseg;
		cout << "  Magassaga? ";
		cin >> dobozok[i].magassag;
		cout << "  Hosszusaga? ";
		cin >> dobozok[i].hosszusag;
	}

	cout << endl;
	megjelenit(dobozok, dobozdb);

	cout << endl;
	felszinTerfogat(dobozok[0]);

	cout << endl;
	unsigned int novel=0;
	cout << "Mennyivel noveljuk a tomb meretet? ";
	cin >> novel;
	ujrafoglal(dobozok, dobozdb, novel);
	for (unsigned int i=dobozdb-novel; i<dobozdb; i++)
	{
		cout << "Kerem a(z) " << i+1 << ". doboz adatait:" << endl;
		cout << "  Neve? ";
		cin >> dobozok[i].nev;
		cout << "  Szelessege? ";
		cin >> dobozok[i].szelesseg;
		cout << "  Magassaga? ";
		cin >> dobozok[i].magassag;
		cout << "  Hosszusaga? ";
		cin >> dobozok[i].hosszusag;
	}
	cout << endl;
	megjelenit(dobozok, dobozdb);

	cout << dobozok[0].nev << " es " << dobozok[1].nev << " kapcsolata: " << belefer(dobozok[0], dobozok[1]) << endl;
	cout << dobozok[1].nev << " es " << dobozok[2].nev << " kapcsolata: " << belefer(dobozok[1], dobozok[2]) << endl;
	cout << dobozok[2].nev << " es " << dobozok[0].nev << " kapcsolata: " << belefer(dobozok[2], dobozok[0]) << endl;
	cout << dobozok[0].nev << " belefer-e 40x50x60-ba: " << belefer(dobozok[0], 40, 50, 60) << endl;
	cout << dobozok[1].nev << " belefer-e 40x50x60-ba: " << belefer(dobozok[1], 40, 50, 60) << endl;
	cout << dobozok[2].nev << " belefer-e 40x50x60-ba: " << belefer(dobozok[2], 40, 50, 60) << endl;

	forgat(dobozok[0]);
	cout << endl;
	megjelenit(dobozok, dobozdb);

	delete [] dobozok;
	return 0;
}
