#include "tarolo.h"

#include <iostream>

using namespace std;

Tarolo::Tarolo()
{
	for (unsigned int i=0; i<TAROLO_KAPACITAS; i++)
        tomb[i] = nullptr;
}

Tarolo::Tarolo(const Tarolo &other)
{


    for (unsigned int i=0; i<TAROLO_KAPACITAS; i++)
    {
        if (other.tomb[i])
            tomb[i] =  other.tomb[i]->clone();
        else
            tomb[i] = nullptr;
    }
}

Tarolo::~Tarolo()
{
	for (unsigned int i=0; i<TAROLO_KAPACITAS; i++)
		if (tomb[i]) delete tomb[i];
}

void Tarolo::beallit(unsigned int index, Jarmu *j)
{
	if (index<TAROLO_KAPACITAS)
	{
		if (tomb[index]) delete tomb[index];
		tomb[index]=j;
	}
    else
    {
        delete j; // avoid memory leak on invalid index!
    }
}

void Tarolo::megjelenit() const
{
	cout << "tartalom:" << endl;
	for (unsigned int i=0; i<TAROLO_KAPACITAS; i++)
	{
		cout << i << ".: ";
		if (tomb[i]) tomb[i]->kiir();
		else cout << "ures" << endl;
	}
}
