

// 3. Legyen egy Verseny osztály az alábbi két adattaggal: megnevezés (string), és a próbálkozásokat tároló vektor (vector<Probalkozas>).
// 4. A Verseny osztálynak legyen konstruktora, ami egy paramétert várjon: egy fájl elérési útját (string), amiből az objektum adatait fel kell tölteni. A fájl elején a verseny megnevezése van, majd az egyes próbálkozások adatai a fent megadott sorrendben a fájl végéig. Sem a megnevezés, sem a versenyzők neve nem tartalmaz whitespace-t.
// 5. Legyen a Verseny osztályban egy kiir függvény, ami kiírja egy sorba a verseny megnevezését, ezután soronként az egyes próbálkozások adatait, mindent szóközzel elválasztva.
// 6. Legyen a kiir függvénynek egy olyan második változata, ami egyetlen paraméterben egy tetszőleges kimeneti folyamot kap, és oda végzi el a kiírást (tipp: az eredeti kiir függvény átalakításával is megoldható).
// 7. Legyen a kiir függvénynek egy olyan harmadik változata, ami egyetlen paraméterben egy fájl elérési útját kapja meg (string), és az adott nevű fájlba végzi el a kiírást, annak tartalmát felülírva.
// 8. Legyen a Verseny osztályban egy uj függvény, ami három paraméterben egy új próbálkozás adatait kapja meg. Szúrja be a próbálkozást a tároló vektor végére.
// 9. Legyen a Verseny osztályban egy ervenyesDobasok függvény, ami egy vector<double> formájában visszaadja az összes érvényesen dobott távolságot.
// 10. A main függvényben a megadott helyen kérdezd le az v változóban tárolt Verseny-ből az érvényes dobásokat az előző függvénnyel, majd írd is ki azokat.
// 11. Legyen a Verseny osztályban egy nevSzerint függvény, ami két paraméterben megkapja egy versenyző nevét (string), és sima referenciaként egy vector<Probalkozas> tárolót. Törölje a kapott tároló tartalmát, majd töltse fel a versenyen az adott nevű versenyzőhöz tartozó próbálkozásokkal.

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



        vector<Probalkozas> pv  {
            Probalkozas(),
            Probalkozas(),
            Probalkozas()    };

        kiirProbalkozasVektor(pv);



        pv[0].setNev("Sandor");
        pv[0].setTavolsag(29.9);
        pv[0].setErvenyes(1);
        pv[1].setNev("Jozsef");
        pv[1].setTavolsag(31.8);
        pv[1].setErvenyes(0);
        pv[2].setNev("Benedek");
        pv[2].setTavolsag(32.7);
        pv[2].setErvenyes(0);
        pv.resize(5);
        kiirProbalkozasVektor(pv);






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
vector<double> ervenyes = v.ervenyesDobasok();
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

// A feladat egy dobóverseny adatait tárolni. Adott a Probalkozas osztály, ami egy versenyző egy dobásának adatait tárolja: versenyző neve (string), dobott távolság (double), illetve, hogy a dobás érvényes volt-e (bool). Ilyen próbálkozásokból egyszerre többet kell majd tárolni a Verseny osztályban. A teszteléshez a mellékelt verseny1.txt szöveges fájlt a projekt build könyvtárába kell másolni. Ugyanebben a build könyvtárban fognak megjelenni a program által megírt kimeneti fájlok is. Amelyik függvény lehet const, az legyen is az.

// Előkészületek
// 1. Legyen a Probalkozas osztályban paraméter nélküli konstruktor. A név "ismeretlen", a távolság 0, az érvényesség false legyen. (Szükséges később a vector<Probalkozas> teljeskörű működéséhez.)

// 2. A main függvény elején, a jelölt helyen hajtsd végre az alábbi műveleteket:
// • Hozz létre egy kezdetben három elemet tartalmazó vector<Probalkozas> tárolót.
// • Írasd ki a tartalmát a main elején lévő kiirProbalkozasVektor függvény meghívásával.
// • Írd át a tároló három elemét tetszőleges adattartalmú, egyéb Probalkozas-okra.
// • Méretezd át a tárolót öt eleműre.
// • Ismét írasd ki a tartalmát.

// Verseny osztály
// 3. Legyen egy Verseny osztály az alábbi két adattaggal: megnevezés (string), és a próbálkozásokat tároló vektor (vector<Probalkozas>).
// 4. A Verseny osztálynak legyen konstruktora, ami egy paramétert várjon: egy fájl elérési útját (string), amiből az objektum adatait fel kell tölteni. A fájl elején a verseny megnevezése van, majd az egyes próbálkozások adatai a fent megadott sorrendben a fájl végéig. Sem a megnevezés, sem a versenyzők neve nem tartalmaz whitespace-t.
// 5. Legyen a Verseny osztályban egy kiir függvény, ami kiírja egy sorba a verseny megnevezését, ezután soronként az egyes próbálkozások adatait, mindent szóközzel elválasztva.
// 6. Legyen a kiir függvénynek egy olyan második változata, ami egyetlen paraméterben egy tetszőleges kimeneti folyamot kap, és oda végzi el a kiírást (tipp: az eredeti kiir függvény átalakításával is megoldható).
// 7. Legyen a kiir függvénynek egy olyan harmadik változata, ami egyetlen paraméterben egy fájl elérési útját kapja meg (string), és az adott nevű fájlba végzi el a kiírást, annak tartalmát felülírva.
// 8. Legyen a Verseny osztályban egy uj függvény, ami három paraméterben egy új próbálkozás adatait kapja meg. Szúrja be a próbálkozást a tároló vektor végére.
// 9. Legyen a Verseny osztályban egy ervenyesDobasok függvény, ami egy vector<double> formájában visszaadja az összes érvényesen dobott távolságot.
// 10. A main függvényben a megadott helyen kérdezd le az v változóban tárolt Verseny-ből az érvényes dobásokat az előző függvénnyel, majd írd is ki azokat.
// 11. Legyen a Verseny osztályban egy nevSzerint függvény, ami két paraméterben megkapja egy versenyző nevét (string), és sima referenciaként egy vector<Probalkozas> tárolót. Törölje a kapott tároló tartalmát, majd töltse fel a versenyen az adott nevű versenyzőhöz tartozó próbálkozásokkal.
