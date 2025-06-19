#include <iostream>

#include "barlangfeltaro.h"
#include "csoport.h"
#include "szemely.h"
#include "turavezeto.h"
#include "turazo.h"
#include "utvonal.h"

using namespace std;

int main() {
  // utvonal teszt
  cout << endl << "Utvonal teszt" << endl;
  Utvonal konnyu("Konnyu Tura", 50, 3);  // 50 a hossz, 3 a nehezseg
  Utvonal hosszu("Hosszu Tura", 300, 2);
  Utvonal nehez("Nehez Tura", 30, 6);
  Utvonal extrem("Extrem Tura", 280, 5);
  cout << konnyu << endl
       << hosszu << endl
       << nehez << endl
       << extrem << endl;  // Nev: Konnyu Tura, hossz: 50, nehezseg: 3
                           // Nev: Hosszu Tura, hossz: 300, nehezseg: 2
                           // Nev: Nehez Tura, hossz: 30, nehezseg: 6
                           // Nev: Extrem Tura, hossz: 280, nehezseg: 5

  {  // Turazo teszt
    cout << endl << "Turazo teszt" << endl;
    Szemely *sz =
        new Turazo("Julcsi", 23, 350, 4);  // 23 eves, 350 a maxtav, 4 a szint
    sz->kiir();                            // nev: Julcsi, eletkor: 23
                                           //	 utvonalbiras: 350, szint: 4
    cout << sz->resztvehet(konnyu) << " " << sz->resztvehet(hosszu) << " "
         << sz->resztvehet(nehez) << " " << sz->resztvehet(extrem) << " "
         << endl;  // 1 1 0 0
    delete sz;
    sz = new Turazo("Jozsi", 18, 100, 7);
    sz->kiir();  // nev: Jozsi, eletkor: 18
                 //	 utvonalbiras: 100, szint: 7
    cout << sz->resztvehet(konnyu) << " " << sz->resztvehet(hosszu) << " "
         << sz->resztvehet(nehez) << " " << sz->resztvehet(extrem) << " "
         << endl;  // 1 0 1 0
    delete sz;
    sz = new Turazo("Istvan", 30, 290, 5);
    sz->kiir();  // nev: Istvan, eletkor: 30
                 //	 utvonalbiras: 290, szint: 5
    cout << sz->resztvehet(konnyu) << " " << sz->resztvehet(hosszu) << " "
         << sz->resztvehet(nehez) << " " << sz->resztvehet(extrem) << " "
         << endl;  // 1 0 0 1
    delete sz;
  }

  {  // Turavezeto teszt
    cout << endl << "Turavezeto teszt" << endl;
    Szemely *sz =
        new Turavezeto("Adam", 29, 6, 7);  // 25 eves, 5 a szint, 7 eve vezet
    sz->kiir();                            // nev: Adam, eletkor: 29
                                           //	 szint: 6, tapasztalat: 7
    cout << sz->resztvehet(konnyu) << " " << sz->resztvehet(hosszu) << " "
         << sz->resztvehet(nehez) << " " << sz->resztvehet(extrem) << " "
         << endl;  // 1 1 1 1
    delete sz;
    sz = new Turavezeto("Evelin", 35, 5, 13);
    sz->kiir();  // nev: Evelin, eletkor: 35
                 //	 szint: 5, tapasztalat: 13
    cout << sz->resztvehet(konnyu) << " " << sz->resztvehet(hosszu) << " "
         << sz->resztvehet(nehez) << " " << sz->resztvehet(extrem) << " "
         << endl;  // 1 1 1 1
    delete sz;
    sz = new Turavezeto("Andi", 28, 4, 6);
    sz->kiir();  // nev: Andi, eletkor: 28
                 //	 szint: 4, tapasztalat: 6
    cout << sz->resztvehet(konnyu) << " " << sz->resztvehet(hosszu) << " "
         << sz->resztvehet(nehez) << " " << sz->resztvehet(extrem) << " "
         << endl;  // 1 1 0 0
    delete sz;
  }

  {  // Barlangfeltaro teszt
    cout << endl << "Barlangfeltaro teszt" << endl;
    Szemely *sz = new Barlangfeltaro(
        "Elemer", 45, 15,
        50);     // 45 eves, 15 eve csinalja, 50 barlangot tart fel
    sz->kiir();  // nev: Elemer, eletkor: 45
                 //	 tapasztalat: 15, feltart barlangok: 50
    cout << sz->resztvehet(konnyu) << " " << sz->resztvehet(hosszu) << " "
         << sz->resztvehet(nehez) << " " << sz->resztvehet(extrem) << " "
         << endl;  // 1 1 1 1
    delete sz;
    sz = new Barlangfeltaro("Anna", 40, 11, 35);
    sz->kiir();  // nev: Anna, eletkor: 40
                 //	 tapasztalat: 11, feltart barlangok: 35
    cout << sz->resztvehet(konnyu) << " " << sz->resztvehet(hosszu) << " "
         << sz->resztvehet(nehez) << " " << sz->resztvehet(extrem) << " "
         << endl;  // 1 1 1 1
    delete sz;
    sz = new Barlangfeltaro("Ferenc", 44, 19, 60);
    sz->kiir();  // nev: Ferenc, eletkor: 44
                 //	 tapasztalat: 19, feltart barlangok: 60
    cout << sz->resztvehet(konnyu) << " " << sz->resztvehet(hosszu) << " "
         << sz->resztvehet(nehez) << " " << sz->resztvehet(extrem) << " "
         << endl;  // 1 1 1 1
    delete sz;
  }

  {  // Csoport teszt #1, += operátor
    cout << endl << "Csoport teszt #1, operator +=" << endl;
    Csoport cs1;
    cs1 += new Turazo("1T1", 35, 150, 6);
    cs1 += new Turazo("1T2", 36, 190, 5);
    cs1 += new Turazo("1T3", 37, 250, 4);
    cs1 += new Turavezeto("1V1", 35, 5, 14);
    cs1 += new Turazo("1T4", 38, 50, 3);

    // Csoport teszt: [] operátor
    cout << endl << "Csoport teszt: operator []" << endl;
    Szemely *sz1 = cs1[4];
    cout << "4. Szemely:" << endl;
    if (sz1)
      sz1->kiir();  // nev: 1T4, eletkor: 38
                    //	 utvonalbiras: 50, szint: 3
    else
      cout << "Nincs 4. szemely" << endl;
    Szemely *sz2 = cs1[5];
    cout << "5. Szemely:" << endl;
    if (sz2)
      sz2->kiir();
    else
      cout << "Nincs 5. szemely" << endl;  // Nincs 5. szemely
    Szemely *sz3 = cs1[2];
    cout << "2. Szemely:" << endl;
    if (sz3)
      sz3->kiir();  // nev: 1T3, eletkor: 37
                    //	 utvonalbiras: 250, szint: 4
    else
      cout << "Nincs 2. szemely" << endl;

    // Csoport teszt: kiir függvény
    cout << endl << "Csoport teszt: kiir" << endl;
    cs1.kiir();
    //		nev: 1T1, eletkor: 35
    //			utvonalbiras: 150, szint: 6
    //		nev: 1T2, eletkor: 36
    //			utvonalbiras: 190, szint: 5
    //		nev: 1T3, eletkor: 37
    //			utvonalbiras: 250, szint: 4
    //		nev: 1V1, eletkor: 35
    //			szint: 5, tapasztalat: 14
    //		nev: 1T4, eletkor: 38
    //			utvonalbiras: 50, szint: 3

    // Csoport teszt: alkalmas függvény
    cout << endl << "Csoport teszt: alkalmas" << endl;
    cout << cs1.alkalmas(konnyu) << " " << cs1.alkalmas(hosszu) << " "
         << cs1.alkalmas(nehez) << " " << cs1.alkalmas(extrem) << " "
         << endl;  // 1 0 0 0
    cs1 += new Turazo("1T5", 30, 150, 3);
    cout << cs1.alkalmas(konnyu) << " " << cs1.alkalmas(hosszu) << " "
         << cs1.alkalmas(nehez) << " " << cs1.alkalmas(extrem) << " "
         << endl;                          // 1 0 0 0
    cs1 += new Turazo("1T6", 35, 150, 5);  // ezzel sokan lennenek mar
    cout << cs1.alkalmas(konnyu) << " " << cs1.alkalmas(hosszu) << " "
         << cs1.alkalmas(nehez) << " " << cs1.alkalmas(extrem) << " "
         << endl;                            // 0 0 0 0
    cs1 += new Turavezeto("1V2", 29, 4, 8);  // igy mar megint jo
    cout << cs1.alkalmas(konnyu) << " " << cs1.alkalmas(hosszu) << " "
         << cs1.alkalmas(nehez) << " " << cs1.alkalmas(extrem) << " "
         << endl;  // 1 0 0 0

    // Csoport teszt: maximum függvény
    cout << endl << "Csoport teszt: maximum" << endl;
    cs1.maximum();  // A tavolsagi korlat: 50, a szintkorlat: 3

    // Csoport teszt #2
    cout << endl << "Csoport teszt #2" << endl;
    Csoport cs2;
    cs2 += new Turazo("2T1", 35, 280, 6);
    cs2 += new Turazo("2T2", 36, 290, 5);
    cs2 += new Turazo("2T3", 37, 310, 5);
    cs2 += new Turavezeto("2V1", 35, 5, 14);
    cs2 += new Turazo("2T4", 38, 290, 5);
    cs2 += new Barlangfeltaro("2F1", 35, 14, 30);
    cs2.kiir();
    //		nev: 2T1, eletkor: 35
    //			utvonalbiras: 280, szint: 6
    //		nev: 2T2, eletkor: 36
    //			utvonalbiras: 290, szint: 5
    //		nev: 2T3, eletkor: 37
    //			utvonalbiras: 310, szint: 5
    //		nev: 2V1, eletkor: 35
    //			szint: 5, tapasztalat: 14
    //		nev: 2T4, eletkor: 38
    //			utvonalbiras: 290, szint: 5
    //		nev: 2F1, eletkor: 35
    //			tapasztalat: 14, feltart barlangok: 30
    cout << cs2.alkalmas(konnyu) << " " << cs2.alkalmas(hosszu) << " "
         << cs2.alkalmas(nehez) << " " << cs2.alkalmas(extrem) << " "
         << endl;   // 1 0 0 1
    cs2.maximum();  // A tavolsagi korlat: 280, a szintkorlat: 5

    // Csoport teszt #3
    cout << endl << "Csoport teszt #3" << endl;
    Csoport cs3;
    cs3 += new Turavezeto("3V1", 35, 5, 14);
    cs3 += new Barlangfeltaro("3F1", 35, 14, 30);
    cs3 += new Turavezeto("3V2", 39, 6, 15);
    cs3 += new Barlangfeltaro("3F2", 50, 19, 56);
    cs3.kiir();
    //		nev: 3V1, eletkor: 35
    //			szint: 5, tapasztalat: 14
    //		nev: 3F1, eletkor: 35
    //			tapasztalat: 14, feltart barlangok: 30
    //		nev: 3V2, eletkor: 39
    //			szint: 6, tapasztalat: 15
    //		nev: 3F2, eletkor: 50
    //			tapasztalat: 19, feltart barlangok: 56
    cout << cs3.alkalmas(konnyu) << " " << cs3.alkalmas(hosszu) << " "
         << cs3.alkalmas(nehez) << " " << cs3.alkalmas(extrem) << " "
         << endl;   // 1 1 1 1
    cs3.maximum();  // Tavolsagi korlat nincs, a szintkorlat: 6

    // Csoport = teszt
    cout << endl << "Csoport = teszt" << endl;
    cs2 = cs1 = cs3;
    cout << "cs1:" << endl;
    cs1.kiir();
    //		cs1:
    //		nev: 3V1, eletkor: 35
    //			szint: 5, tapasztalat: 14
    //		nev: 3F1, eletkor: 35
    //			tapasztalat: 14, feltart barlangok: 30
    //		nev: 3V2, eletkor: 39
    //			szint: 6, tapasztalat: 15
    //		nev: 3F2, eletkor: 50
    //			tapasztalat: 19, feltart barlangok: 56
    cout << "cs2:" << endl;
    cs2.kiir();
    //		cs2:
    //		nev: 3V1, eletkor: 35
    //			szint: 5, tapasztalat: 14
    //		nev: 3F1, eletkor: 35
    //			tapasztalat: 14, feltart barlangok: 30
    //		nev: 3V2, eletkor: 39
    //			szint: 6, tapasztalat: 15
    //		nev: 3F2, eletkor: 50
    //			tapasztalat: 19, feltart barlangok: 56
    cout << "cs3:" << endl;
    cs3.kiir();
    //		cs3:
    //		nev: 3V1, eletkor: 35
    //			szint: 5, tapasztalat: 14
    //		nev: 3F1, eletkor: 35
    //			tapasztalat: 14, feltart barlangok: 30
    //		nev: 3V2, eletkor: 39
    //			szint: 6, tapasztalat: 15
    //		nev: 3F2, eletkor: 50
    //			tapasztalat: 19, feltart barlangok: 56
  }

  return 0;
}
