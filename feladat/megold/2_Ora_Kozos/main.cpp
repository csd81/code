#include <iostream>
#include "szamok.h"

using namespace std;

void kiir(const Tarolo::Szamok &sz)
{
	for (unsigned int i=0; i<sz.darabLeker(); i++)
	{
		if (i>0) cout << ", ";
		cout <<sz.ertekLeker(i);
	}
	cout << endl;
}

int main()
{
	Tarolo::Szamok sz1(3,4.5), sz2(5);

	// pár teszt
	kiir(sz1);
	kiir(sz2);
	cout << sz1.ertekLeker(9) << endl;
	sz2.ertekBeallit(6,9.8);
	sz2.ertekBeallit(3,-3.8);
	kiir(sz2);

	// tényleges manuális feltöltés
	for (unsigned int i=0; i<sz1.darabLeker(); i++)
	{
		double tmp;
		cout << "Kerem az erteket a(z) " << i << ". indexre: ";
		cin >> tmp;
		sz1.ertekBeallit(i, tmp);
	}
	for (unsigned int i=0; i<sz2.darabLeker(); i++)
	{
		double tmp;
		cout << "Kerem az erteket a(z) " << i << ". indexre: ";
		cin >> tmp;
		sz2.ertekBeallit(i, tmp);
	}
	kiir(sz1);
	kiir(sz2);
	return 0;
}
