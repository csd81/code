#include <iostream>
#include <fstream>
#include "datumlista.h"

using namespace std;
using namespace Naptar;

void datumListaKiir(const DatumLista &dl)
{
    cout << dl.getMegjegyzes() << endl;
    for (unsigned int i = 0; i < dl.getDarab(); i++)
    {
        const Datum &d = dl.getDatum(i);
        cout << "  " << i + 1 << ". datum: " << d.getEv() << "." << d.getHonap() << "." << d.getNap() << endl;
    }
}

int main()
{
    // Spec: Main-ben a fenti metódusokat használva kell a projektet tesztelni.

    // Létrehozás
    cout << "Kerek egy megjegyzest: ";
    string megj;
    getline(cin, megj);
    DatumLista dl1(3, megj);

    // setMegjegyzes, getMegjegyzes
    cout << dl1.getMegjegyzes() << endl;
    dl1.setMegjegyzes("At is allitom");
    cout << dl1.getMegjegyzes() << endl;

    // Dátumok bekérése és beállítása (setDatum)
    cout << endl;
    dl1.setDatum(10000, Datum(1, 1, 1)); // Ez nem csinál semmit
    for (unsigned int i = 0; i < dl1.getDarab(); i++)
    {
        unsigned int e, h, n;
        cout << "Kerek egy datumot (ev, honap, nap): ";
        cin >> e >> h >> n;
        dl1.setDatum(i, Datum(e, h, n));
    }
    datumListaKiir(dl1);

    // Másolat készítése (másoló konstruktor)
    cout << endl;
    DatumLista dl2(dl1);
    datumListaKiir(dl1);
    datumListaKiir(dl2);

    // Hozzáadás (hozzaad), legkorabbi()
    cout << endl;
    dl1.hozzaad(Datum(2018, 10, 10));
    dl1.hozzaad(Datum(2019, 11, 11));
    datumListaKiir(dl1);
    const Datum &legkorabbi = dl1.legkorabbi();
    cout << "A legkorabbi datum: " << legkorabbi.getEv() << "." << legkorabbi.getHonap() << "." << legkorabbi.getNap() << endl;

    // Statikus maxDarab használata
    cout << "Max meret: " << DatumLista::getMaxDarab() << endl;
    dl1.hozzaad(Datum(2025, 2, 5));
    dl1.hozzaad(Datum(2030, 12, 23)); // Ez már nem fér bele
    datumListaKiir(dl1);

    // MaxDarab növelése
    DatumLista::setMaxDarab(8);
    cout << "Max meret: " << DatumLista::getMaxDarab() << endl;
    dl1.hozzaad(Datum(2012, 6, 18));
    dl1.hozzaad(Datum(2015, 7, 30));
    datumListaKiir(dl1);

    return 0;
}
