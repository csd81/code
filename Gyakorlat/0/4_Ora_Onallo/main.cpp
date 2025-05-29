
// Készíts egy DatumLista osztályt, amely dátumokat (Datum típus) tárol.

// A tárolt dátumok mennyiségét a konstruktorban kapja meg az osztály, és foglaljon helyet ennyi dátumnak (a megadott Datum osztállyal ez alapból nem működik, azt ki kell kicsit egészíteni).

// Az osztály tároljon még egy megjegyzést (egy szöveg, ami akár szóközöket is tartalmazhat).

// Ezt is kapja meg a konstruktor paraméterben.

// Legyen az osztálynak beállító és lekérő függvénye mind a megjegyzéshez, mind az egyes dátumokhoz (setMegjegyzes, getMegjegyzes, setDatum, getDatum), valamint lekérő függvény a dátumok darabszámához is (getDarab).

// Egy dátum lekérésénél most nem kell ellenőrizni az indexet, de a beállításnál igen.

// Készíts az osztályhoz másoló konstruktort.

// Készíts az osztályhoz egy hozzaad függvényt, amely megkap egy dátumot és hozzáadja az osztályhoz, megnövelve a tároló méretét.

// Készíts az osztályban egy legkorabbi függvényt, amely visszaadja a dátumok közül a legkorábbit (feltételezhetjük, hogy van dátum az osztályban).

// Az osztályban legyen egy statikus adattag, ami a tömb maximális méretét tárolja.

// Kezdetben az értéke legyen 6, de lehessen lekérdezni és átállítani (getMaxDarab, setMaxDarab).

// Ha a hozzaad függvény ne növelhesse a tömb méretét az itt eltárolt maximum érték fölé.

// Az elképzelhető, hogy a maximum méretet utólag állítjuk kisebbre, mint a tömb elemszáma, de ezzel most nem foglalkozunk.

#include <iostream>
#include <fstream>
#include "datumlista.h"

using namespace std;
using namespace Naptar;

void datumListaKiir(const DatumLista &dl)
{
    cout << dl.getMegjegyzes() << endl;
    for (unsigned int i=0; i < static_cast<unsigned int>(dl.getDarab()); i++)
    {
        const Datum &d=dl.getDatum(i); // Azért, hogy ne kelljen mindig leírni a gettert
        cout << "  " << i+1 << ". datum: " << d.getEv() << "." << d.getHonap() << "." << d.getNap() << endl;
    }
}

int main()
{
//	// Létrehozás
    cout << "Kerek egy megjegyzest: ";
    string megj;
    getline(cin, megj);
    DatumLista dl1(3, megj);
    cout << dl1.getMegjegyzes() << endl;
    dl1.setMegjegyzes("At is allitom");
    cout << dl1.getMegjegyzes() << endl;

    // Dátumok bekérése és beállítása
    cout << endl;
    dl1.setDatum(10000, Datum(1,1,1)); // Ez nem csinál semmit
    for (unsigned int i=0; i< static_cast<unsigned int>(dl1.getDarab()); i++)
    {
        unsigned int e, h, n;
        cout << "Kerek egy datumot (ev, honap, nap): ";
        cin >> e >> h >> n;
        dl1.setDatum(i, Datum(e,h,n));
    }
    datumListaKiir(dl1);

    // Másolat készítése
    cout << endl;
    DatumLista dl2(dl1);
    datumListaKiir(dl1);
    datumListaKiir(dl2);
    dl2.setMegjegyzes("Ez a masodik");
    dl2.setDatum(0,Datum(1900,1,1));
    datumListaKiir(dl1);
    datumListaKiir(dl2);

    // Hozzáadás és legkorábbi
    cout << endl;
    dl1.hozzaad(Datum(2018,10,10));
    dl1.hozzaad(Datum(2019,11,11));
    datumListaKiir(dl1);
    const Datum &legkorabbi=dl1.legkorabbi();
    cout << "A legkorabbi datum: " << legkorabbi.getEv() << "." << legkorabbi.getHonap() << "." << legkorabbi.getNap() << endl;

    // Statikus max darabszám
    cout << "Max meret: " << DatumLista::getMaxDarab() << endl;
    dl1.hozzaad(Datum(2025,2,5)); // Ez még belefér
    dl1.hozzaad(Datum(2030,12,23)); // Ez már nem
    datumListaKiir(dl1);
    DatumLista::setMaxDarab(8);
    cout << "Max meret: " << DatumLista::getMaxDarab() << endl;
    dl1.hozzaad(Datum(2012,6,18)); // Mostmár belefér
    dl1.hozzaad(Datum(2015,7,30)); // Mostmár belefér
    dl1.hozzaad(Datum(2017,2,21)); //Ez már nem
    datumListaKiir(dl1);
    DatumLista::setMaxDarab(5);
    cout << "Max meret: " << DatumLista::getMaxDarab() << endl;
    dl2.hozzaad(Datum(2025,2,5)); // Ez még belefér
    dl2.hozzaad(Datum(2025,8,25)); // Ez még belefér
    dl2.hozzaad(Datum(2030,12,23)); // Ez már nem
    datumListaKiir(dl2);


	return 0;
}

// A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat.

// A megoldás bizonyos feladatoknál ezekhez a kódokhoz is hozzá kell nyúlni, és a teszteléshez a main függvényben a nem használt kódokat ki lehet kommentezni.

// Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.

// A meglévő Datum osztály, valamint a készítendő DatumLista osztály legyenek a Naptar névtérben.

// Készíts egy DatumLista osztályt, amely dátumokat (Datum típus) tárol.

// A tárolt dátumok mennyiségét a konstruktorban kapja meg az osztály, és foglaljon helyet ennyi dátumnak (a megadott Datum osztállyal ez alapból nem működik, azt ki kell kicsit egészíteni).

// Az osztály tároljon még egy megjegyzést (egy szöveg, ami akár szóközöket is tartalmazhat).

// Ezt is kapja meg a konstruktor paraméterben.

// Legyen az osztálynak beállító és lekérő függvénye mind a megjegyzéshez, mind az egyes dátumokhoz (setMegjegyzes, getMegjegyzes, setDatum, getDatum), valamint lekérő függvény a dátumok darabszámához is (getDarab).

// Egy dátum lekérésénél most nem kell ellenőrizni az indexet, de a beállításnál igen.

// Készíts az osztályhoz másoló konstruktort.

// Készíts az osztályhoz egy hozzaad függvényt, amely megkap egy dátumot és hozzáadja az osztályhoz, megnövelve a tároló méretét.

// Készíts az osztályban egy legkorabbi függvényt, amely visszaadja a dátumok közül a legkorábbit (feltételezhetjük, hogy van dátum az osztályban).

// Az osztályban legyen egy statikus adattag, ami a tömb maximális méretét tárolja.

// Kezdetben az értéke legyen 6, de lehessen lekérdezni és átállítani (getMaxDarab, setMaxDarab).

// Ha a hozzaad függvény ne növelhesse a tömb méretét az itt eltárolt maximum érték fölé.

// Az elképzelhető, hogy a maximum méretet utólag állítjuk kisebbre, mint a tömb elemszáma, de ezzel most nem foglalkozunk.
