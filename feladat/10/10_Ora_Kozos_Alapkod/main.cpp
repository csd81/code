#include <iostream>
#include "helyszin.h"

using namespace std;

int main()
{

    cout << endl << endl << "Helyszin::betolt() teszt" << endl;
    Helyszin h;
    h.betolt("kozpont.json");

    cout << endl << endl << "Helyszin::kiir() teszt" << endl;
    h.kiir();


    cout << endl << endl << "Helyszin::esemenyHosszKiir() teszt" << endl;
    h.esemenyHosszKiir("kimenet.json");



	cout << endl << endl << "Vege" << endl;
	return 0;
}
