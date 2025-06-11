#include <iostream>
#include "szamok.h"

using namespace std;

// A kiir függvény megkap egy Szamok objektumot és kiírja a tömb tartalmát vesszővel elválasztva
void kiir(const Tarolo::Szamok &sz)
{
    for (unsigned int i = 0; i < sz.darabLeker(); i++)
    {
        if (i > 0) cout << ", ";
        cout << sz.ertekLeker(i);  // az érték kiírása
    }
    cout << endl;
}

int main()
{
    // Két objektum példányosítása: egyik 3 elemű, minden érték 4.5, a másik 5 elemű, default 0
    Tarolo::Szamok sz1(3, 4.5), sz2(5);

    // Tesztesetek – kezdeti értékek kiírása
    kiir(sz1);
    kiir(sz2);

    // Hibás indexek tesztelése: 9 túl nagy sz1-hez; 6 túl nagy sz2-höz (nem okoz hibát)
    cout << sz1.ertekLeker(9) << endl;
    sz2.ertekBeallit(6, 9.8);  // nem történik semmi

    // Érvényes indexű beállítás (3. index)
    sz2.ertekBeallit(3, -3.8);
    kiir(sz2);

    // Felhasználótól értékbekérés mindkét objektum feltöltéséhez
    for (unsigned int i = 0; i < sz1.darabLeker(); i++)
    {
        double tmp;
        cout << "Kerem az erteket a(z) " << i << ". indexre: ";
        cin >> tmp;
        sz1.ertekBeallit(i, tmp);
    }

    for (unsigned int i = 0; i < sz2.darabLeker(); i++)
    {
        double tmp;
        cout << "Kerem az erteket a(z) " << i << ". indexre: ";
        cin >> tmp;
        sz2.ertekBeallit(i, tmp);
    }

    // Végső tartalom kiírása
    kiir(sz1);
    kiir(sz2);
    return 0;
}
