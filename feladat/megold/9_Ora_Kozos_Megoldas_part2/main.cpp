#include <iostream>
#include <string>
#include "tomb.h"

using namespace std;

void doubleTombKiir(const TombAlap<double> *t)
{
	for (int i=0; i<t->meret(); i++)
		cout << t->leker(i) << endl;
}

// ide kellenek a sablonos tombKiir verziók
template <class Tipus>
void tombKiir(const TombAlap<Tipus> *t)
{
	for (int i=0; i<t->meret(); i++)
		cout << t->leker(i) << endl;
}

template <class Tipus>
void tombKiir(const TombAlap<Tipus> &t)
{
	for (int i=0; i<t.meret(); i++)
	{
		cout << t.elem(i) << endl; // vagy:
//		cout << t[i] << endl;
	}
}

int main()
{

	cout << endl << endl;
	cout << "Tomb letrehozas teszt" << endl;
	Tomb<double,5> dtomb;
	Tomb<string,9> stomb;

	cout << endl << endl;
	cout << "Tomb meret teszt" << endl;
	cout << dtomb.meret() << endl; // 5
	cout << stomb.meret() << endl; // 9


	cout << endl << endl;
	cout << "Tomb beallit teszt" << endl;
	dtomb.beallit(0,4.5);
	dtomb.beallit(1,7.8);
	dtomb.beallit(2,-2.4);
	dtomb.beallit(3,0);
	dtomb.beallit(4,1.8);
	dtomb.beallit(5,12.3); // Ez mar nem csinal semmit

	stomb.beallit(0,"szoveg1");
	stomb.beallit(1,"alma");
	stomb.beallit(2,"fa");
	stomb.beallit(3,"ures");
	stomb.beallit(4,"valami");
	stomb.beallit(5,"hosszabb szoveg tobb szoval");
	stomb.beallit(6,"what");
	stomb.beallit(7,"valar morghulis");
	stomb.beallit(8,"Aaaaaaaaaaaaaaaaaaa");


	cout << endl << endl;
	cout << "Tomb leker teszt" << endl;
	for (int i=0; i<dtomb.meret(); i++)
		cout << dtomb.leker(i) << " "; // 4.5 7.8 -2.4 0 1.8
	cout << endl;

	cout << endl;
	for (int i=0; i<stomb.meret(); i++)
		cout << stomb.leker(i) << endl;

	// szoveg1
	// alma
	// fa
	// ures
	// valami
	// hosszabb szoveg tobb szoval
	// what
	// valar morghulis
	// Aaaaaaaaaaaaaaaaaaa


	cout << endl << endl;
	cout << "Tomb elem teszt" << endl;
	cout << dtomb.elem(2) << endl; // -2.4
	dtomb.elem(2)=14.5;
	cout << dtomb.elem(2) << endl; // 14.5

	const Tomb<double,5> &ref=dtomb;
	cout << ref.elem(2) << endl; // 14.5

	cout << stomb.elem(4) << endl; // valami
	stomb.elem(4)="valami mas";
	cout << stomb.elem(4) << endl; // valami mas


	cout << endl << endl;
	cout << "Tomb operator [] teszt" << endl;
	cout << dtomb[1] << endl; // 7.8
	dtomb[1]=6.7;
	cout << dtomb[1] << endl; // 6.7

	cout << ref[1] << endl; // 6.7

	cout << stomb[3] << endl; // ures
	stomb[3]="nem ures";
	cout << stomb[3] << endl; // nem ures


	cout << endl << endl;
	cout << "TombAlap teszt a kiir fuggvennyel" << endl;
	Tomb<double, 7> dtomb2;
	for (int i=0; i<7; i++)
		dtomb2.beallit(i, 1.2*i);
	cout << "dtomb:" << endl;
	doubleTombKiir(&dtomb);
	cout << endl << "dtomb2:" << endl;
	doubleTombKiir(&dtomb2);

	cout << endl << endl;
	cout << "tombKiir teszt (mutato)" << endl;
	cout << "dtomb:" << endl;
	tombKiir<double>(&dtomb);
	// vagy ki is találja magának:
	cout << endl << "stomb:" << endl;
	tombKiir(&stomb);

	cout << endl << endl;
	cout << "tombKiir teszt (referencia)" << endl;
	cout << "stomb:" << endl;
	tombKiir<string>(stomb);
	// vagy ki is találja magának:
	cout << endl << "dtomb2:" << endl;
	tombKiir(dtomb2);

	return 0;
}
