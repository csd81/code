#include "tarolo.h"
#include "repulo.h"
#include "hajo.h"

#include <iostream>

using namespace std;

// Konstruktor: minden helyet üresre állítunk.
Tarolo::Tarolo()
{
    for (unsigned int i=0; i<TAROLO_KAPACITAS; i++)
        tomb[i]=0;
}

// Destruktor: minden lefoglalt memória felszabadítása.
Tarolo::~Tarolo()
{
    for (unsigned int i=0; i<TAROLO_KAPACITAS; i++)
        if (tomb[i]) delete tomb[i];
}

// Egy adott indexre állítunk be egy jármű mutatót.
// Ha már volt ott jármű, azt előbb töröljük. Ha az index érvénytelen, a kapott járművet töröljük.
void Tarolo::beallit(unsigned int index, Jarmu *j)
{
    if (index<TAROLO_KAPACITAS)
    {
        if (tomb[index]) delete tomb[index];
        tomb[index]=j;
    }
    else
    {
        delete j;
    }
}

// A Tarolo tartalmát jelenítjük meg, soronként.
// Ha adott helyen nincs jármű, akkor 'ures' felirat jelenik meg.
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

// Másoló konstruktor - másolni kell a tárolt járműveket is (deep copy).
// Dinamikus cast segítségével detektáljuk a típusokat, és azok alapján példányosítunk új objektumot.
Tarolo::Tarolo(const Tarolo &t)
{
    for (unsigned int i=0; i<TAROLO_KAPACITAS; i++)
    {
        if (t.tomb[i]==0) tomb[i]=0;
        else
        {
            Repulo *r=dynamic_cast<Repulo*>(t.tomb[i]);
            Hajo *h=dynamic_cast<Hajo*>(t.tomb[i]);
            if (r) tomb[i]=new Repulo(*r);
            else if (h) tomb[i]=new Hajo(*h);
        }
    }
}
