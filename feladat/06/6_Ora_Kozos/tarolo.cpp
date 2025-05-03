#include "tarolo.h"

#include <iostream>

using namespace std;

Tarolo::Tarolo()
{
	for (unsigned int i=0; i<TAROLO_KAPACITAS; i++)
		tomb[i]=0;
}


// Tarolo::Tarolo(const Tarolo& masik) : db(masik.db) {
//     for (int i = 0; i < 5; ++i) {
//         if (masik.jarmuvek[i]) {
//             // Dinamikus típus vizsgálat másoláshoz
//             const Hajo* hajoPtr = dynamic_cast<Hajo*>(masik.jarmuvek[i]);
//             const Repulo* repuloPtr = dynamic_cast<Repulo*>(masik.jarmuvek[i]);

//             if (hajoPtr)
//                 jarmuvek[i] = new Hajo(*hajoPtr); // Hajo másoló konstruktor
//             else if (repuloPtr)
//                 jarmuvek[i] = new Repulo(*repuloPtr); // Repulo másoló konstruktor
//             else
//                 jarmuvek[i] = nullptr; // ismeretlen típus
//         } else {
//             jarmuvek[i] = nullptr;
//         }
//     }
// }



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
