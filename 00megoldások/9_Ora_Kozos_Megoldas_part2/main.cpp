#include <iostream>
#include <string>
#include "tomb.h"

using namespace std;

// doubleTombKiir: csak double típusú TombAlap objektumot kezel
void doubleTombKiir(const TombAlap<double> *t)
{
    for (int i = 0; i < t->meret(); i++)
        cout << t->leker(i) << endl;
}

// Általános sablonos tombKiir, mutatós verzió
template <class Tipus>
void tombKiir(const TombAlap<Tipus> *t)
{
    for (int i = 0; i < t->meret(); i++)
        cout << t->leker(i) << endl;
}

// Általános sablonos tombKiir, referencias verzió
template <class Tipus>
void tombKiir(const TombAlap<Tipus>& t)
{
    for (int i = 0; i < t.meret(); i++)
        cout << t.leker(i) << endl;
}

int main()
{
    // Tomb létrehozás teszt
    Tomb<double,5> dtomb;
    Tomb<string,9> stomb;

    // Tomb méret teszt
    cout << dtomb.meret() << endl; // elvárt: 5
    cout << stomb.meret() << endl; // elvárt: 9

    // Tomb beallit teszt
    // Érvénytelen indexű beallit nem csinál semmit
    dtomb.beallit(0,4.5);
    dtomb.beallit(1,7.8);
    dtomb.beallit(2,-2.4);
    dtomb.beallit(3,0);
    dtomb.beallit(4,1.8);
    dtomb.beallit(5,12.3); // érvénytelen index

    stomb.beallit(0,"szoveg1");
    stomb.beallit(1,"alma");
    stomb.beallit(2,"fa");
    stomb.beallit(3,"ures");
    stomb.beallit(4,"valami");
    stomb.beallit(5,"hosszabb szoveg tobb szoval");
    stomb.beallit(6,"what");
    stomb.beallit(7,"valar morghulis");
    stomb.beallit(8,"Aaaaaaaaaaaaaaaaaaa");

    // Tomb leker teszt
    for (int i = 0; i < dtomb.meret(); i++)
        cout << dtomb.leker(i) << " ";
    cout << endl;

    for (int i = 0; i < stomb.meret(); i++)
        cout << stomb.leker(i) << endl;

    // Tomb elem teszt
    cout << dtomb.elem(2) << endl;
    dtomb.elem(2) = 14.5;
    cout << dtomb.elem(2) << endl;

    const Tomb<double,5> &ref = dtomb;
    cout << ref.elem(2) << endl;

    cout << stomb.elem(4) << endl;
    stomb.elem(4) = "valami mas";
    cout << stomb.elem(4) << endl;

    // Tomb operator [] teszt
    cout << dtomb[1] << endl;
    dtomb[1] = 6.7;
    cout << dtomb[1] << endl;
    cout << ref[1] << endl;

    cout << stomb[3] << endl;
    stomb[3] = "nem ures";
    cout << stomb[3] << endl;

    // TombAlap teszt a kiir fuggvennyel
    Tomb<double, 7> dtomb2;
    for (int i = 0; i < 7; i++)
        dtomb2.beallit(i, 1.2 * i);

    cout << "dtomb:" << endl;
    doubleTombKiir(&dtomb);
    cout << endl << "dtomb2:" << endl;
    doubleTombKiir(&dtomb2);

    // tombKiir teszt (mutató)
    cout << "dtomb:" << endl;
    tombKiir<double>(&dtomb);
    cout << endl << "stomb:" << endl;
    tombKiir(&stomb);

    // tombKiir teszt (referencia)
    cout << "stomb:" << endl;
    tombKiir<string>(stomb);
    cout << endl << "dtomb2:" << endl;
    tombKiir(dtomb2);

    return 0;
}
