#include "tarolo.h"

#include <iostream>

using namespace std;

namespace EpicToolbox {

Tarolo::Tarolo(unsigned int db):
	darab(db)
{
	tomb=new int[db];
	for (unsigned int i=0; i<db; i++)
		tomb[i]=i;
}

Tarolo::Tarolo()
{
	cout << "Kerem a tomb meretet: ";
	cin >> darab;
	tomb=new int[darab];
	for (unsigned int i=0; i<darab; i++)
	{
		cout << "Kerem a(z) " << i+1 << ". elemet: ";
		cin >> tomb[i];
	}
}

Tarolo::~Tarolo()
{
	delete [] tomb;
}

void Tarolo::kiir() const
{
	for (unsigned int i=0; i<darab; i++)
	{
		if (i>0) cout << ", ";
		cout << tomb[i];
	}
	cout << endl;
}

void Tarolo::hozzaad(int ertek)
{
	int *uj=new int[darab+1];
	for (unsigned int i=0; i<darab; i++)
		uj[i]=tomb[i];
	uj[darab]=ertek;
	darab++;
	delete [] tomb;
	tomb=uj;
}

double Tarolo::atlag() const
{
	double sum=0.0;
	for (unsigned int i=0; i<darab; i++)
		sum+=tomb[i];
	return sum/darab;
}

unsigned int Tarolo::darabLeker() const
{
	return darab;
}

int Tarolo::tartomany() const
{
	int max_idx=0, min_idx=0;
	for (unsigned int i=0; i<darab; i++)
	{
		if (tomb[i]>tomb[max_idx]) max_idx=i;
		if (tomb[i]<tomb[min_idx]) min_idx=i;
	}
	return tomb[max_idx]-tomb[min_idx];
}

void Tarolo::rendez(bool novekvo)
{
	for (unsigned int i=0; i<darab-1; i++)
	{
		unsigned int idx=i;
		if (novekvo)
		{
			for (unsigned int k=i+1; k<darab; k++)
			{
				if (tomb[k]<tomb[idx]) idx=k;
			}
		}
		else
		{
			for (unsigned int k=i+1; k<darab; k++)
			{
				if (tomb[k]>tomb[idx]) idx=k;
			}
		}
		if (idx!=i)
		{
			int csere=tomb[i];
			tomb[i]=tomb[idx];
			tomb[idx]=csere;
		}
	}
}

void Tarolo::hozzafuz(const Tarolo &masik)
{
	// 1. megoldáas: használjuk fel a hozzaad metódust
//	for (unsigned int i=0; i<masik.darab; i++)
//		this->hozzaad(masik.tomb[i]);

	// 2. megoldás: oldjunk meg mindent itt (ez most hatékonyabb)
	int *uj=new int[this->darab+masik.darab];
	for (unsigned int i=0; i<this->darab; i++)
		uj[i]=this->tomb[i];
	for (unsigned int i=0; i<masik.darab; i++)
		uj[this->darab+i]=masik.tomb[i];
	this->darab+=masik.darab;
	delete [] this->tomb;
	this->tomb=uj;
}

} // namespace EpicToolbox
