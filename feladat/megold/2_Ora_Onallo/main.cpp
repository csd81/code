#include <iostream>
#include "tarolo.h"

using namespace std;
using namespace EpicToolbox;

int kisebbTarolo(const Tarolo &t1, const Tarolo &t2)
{
	if (t1.darabLeker()>t2.darabLeker()) return 1;
	else if (t1.darabLeker()<t2.darabLeker()) return -1;
	else return 0;
}

int main()
{
	Tarolo t1(5);
	t1.kiir();
	Tarolo t2;
	t2.kiir();

	cout << endl;
	t1.hozzaad(111);
	t1.hozzaad(112);
	t1.hozzaad(113);
	t1.hozzaad(114);
	t2.hozzaad(222);
	t2.hozzaad(223);
	t1.kiir();
	t2.kiir();

	cout << endl;
	cout << kisebbTarolo(t1,t2) << endl;

	cout << endl;
	cout << t1.tartomany() << endl;
	cout << t2.tartomany() << endl;

	cout << endl;
	t1.rendez(false);
	t2.rendez(true);
	t1.kiir();
	t2.kiir();

	cout << endl;
	t1.hozzafuz(t2);
	t1.kiir();

	return 0;
}
