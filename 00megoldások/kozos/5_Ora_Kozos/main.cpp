#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "verseny.h"

void kiirProbalkozasVektor (const vector<Probalkozas>& pv)
{
    for (size_t i=0;i<pv.size();i++)
    {
        cout << pv[i].getNev() << " ";
        cout << pv[i].getTavolsag() << " ";
        cout << pv[i].getErvenyes() << endl;
    }
    cout << endl;
}

int main()
{
    cout << "main() eleje!" << endl << endl;

    {
        // ide keruljon a vector<Problakozas>-os feladat megoldasa:
        vector<Probalkozas> tarolo(3);
        kiirProbalkozasVektor(tarolo);
        tarolo[0] = Probalkozas("Sandor",29.9,1);
        tarolo[1] = Probalkozas("Jozsef",31.8,0);
        tarolo[2] = Probalkozas("Benedek",32.7,0);
        tarolo.resize(5);
        kiirProbalkozasVektor(tarolo);
    }
    // ismeretlen 0 0
    // ismeretlen 0 0
    // ismeretlen 0 0
    //
    // Sandor 29.9 1
    // Jozsef 31.8 0
    // Benedek 32.7 0
    // ismeretlen 0 0
    // ismeretlen 0 0

    // konstruktor teszt (egyelore nincs output)
    Verseny v("verseny1.txt");
    const Verseny& v_cref = v;

    // kiir() 1. verzio teszt
    v_cref.kiir();
    cout << endl;
    // Verseny1
    // Anita 35.91 1
    // Bea 40.17 1
    // Csilla 39.93 1
    // Diana 36.98 1
    // Emma 37.11 1
    // Emma 39.22 0
    // Diana 37.12 1
    // Anita 38.88 0
    // Anita 35.92 1
    // Csilla 38.5 0

    // kiir() 2. verzio teszt (lasd a keletkezett fajl tartalmat!)
    {
        ofstream masolat("verseny1-masolat1.txt");
        v_cref.kiir(masolat);
    }

    // kiir() 3. verzio teszt (lasd a keletkezett fajl tartalmat!)
    v_cref.kiir("verseny1-masolat2.txt");

    // uj() teszt
    v.uj("Diana",40.31,0);
    v.uj("Diana",40.29,1);
    v.kiir();
    cout << endl;
    // Verseny1
    // Anita 35.91 1
    // Bea 40.17 1
    // Csilla 39.93 1
    // Diana 36.98 1
    // Emma 37.11 1
    // Emma 39.22 0
    // Diana 37.12 1
    // Anita 38.88 0
    // Anita 35.92 1
    // Csilla 38.5 0
    // Diana 40.31 0
    // Diana 40.29 1

    // ervenyesDobasok() teszt
    {
        cout << "Ervenyes dobasok listaja:" << endl;
        // itt kerdezd le es ird ki az ervenyes dobasokat:
        vector<double> dobasok;
        dobasok = v_cref.ervenyesDobasok();
        for (size_t i=0;i<dobasok.size();i++)
            cout << dobasok[i] << " ";
        cout << endl;
        cout << endl;
    }
    // Ervenyes dobasok listaja:
    // 35.91 40.17 39.93 36.98 37.11 37.12 35.92 40.29

    // nevSzerint() teszt
    vector<Probalkozas> prob;
    prob.push_back(Probalkozas("Torlendo1",9999.99,0));
    prob.push_back(Probalkozas("Torlendo2",9999.99,0));
    prob.push_back(Probalkozas("Torlendo3",9999.99,0));
    v_cref.nevSzerint("Anita",prob);
    for (size_t i=0;i<prob.size();i++)
    {
        cout << prob[i].getNev() << " ";
        cout << prob[i].getTavolsag() << " ";
        cout << prob[i].getErvenyes() << endl;
    }
    cout << endl;
    // Anita 35.91 1
    // Anita 38.88 0
    // Anita 35.92 1

    cout << "main() vege!" << endl;
    return 0;
}
