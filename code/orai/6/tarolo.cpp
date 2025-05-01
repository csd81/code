#include "tarolo.h"
// #include "hajo.h"
// #include "repulo.h"

#include <iostream>

using namespace std;

Tarolo::Tarolo()
{
	for (unsigned int i=0; i<TAROLO_KAPACITAS; i++)
		tomb[i]=0;
}

Tarolo::Tarolo(const Tarolo &masik)
{
    for (unsigned i=0; i<TAROLO_KAPACITAS; i++)
    {
        // Hajo *h = dynamic_cast<Hajo*>(masik.tomb[i]);
        // Repulo *r = dynamic_cast<Repulo*>(masik.tomb[i]);
        // if (h != nullptr)
        //     this->tomb[i] = new Hajo(*h);
        // else if (r != nullptr)
        //     this->tomb[i] = new Repulo(*r);
        // else
        //     this->tomb[i] = nullptr;
        if (masik.tomb[i] == nullptr)
            this->tomb[i] = nullptr;
        else
            this->tomb[i] = masik.tomb[i]->clone();
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
