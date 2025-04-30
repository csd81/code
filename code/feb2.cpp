#include <iostream> // input/output stream
#include <string> // string : ezt most már nem kell, de a string típus miatt benne van

using namespace std; // névtér
// a std névtérben definiáljuk a cout, cin, endl stb. függvényeket, a string típusú változókat, stb.


namespace doboz // névtér
// a doboz névtérben definiáljuk a Doboz struktúrát.
{
struct Doboz{
    string nev;
    unsigned int magassag;
    unsigned int szelesseg;
    unsigned int hosszusag;
    };

void kiirDobozok(const Doboz *tomb, int dobozok_szama){ // itt a tomb pointer, mivel a tomb egy pointer
    // a tomb egy pointer, ami a Doboz típusú tömb első elemére mutat
    // a dobozok_szama pedig a tömb mérete
    // a tomb pointert nem szabad módosítani, ezért const referenciaként adjuk át.
    for (int i = 0; i < dobozok_szama; i++)
    {
        cout << "Doboz neve: " << tomb[i].nev << endl;
        cout << "Doboz magassága: " << tomb[i].magassag << endl;
        cout << "Doboz szélessége: " << tomb[i].szelesseg << endl;
        cout << "Doboz hosszúsága: " << tomb[i].hosszusag << endl;
    }
    }

void dobozFelszinTerfogat(const Doboz &d){ 
    // konstans referenciaként adjuk át a dobozt, mivel nem akarjuk módosítani
    cout << "Doboz neve: " << d.nev << endl;
    cout << "Doboz méretei: " << d.magassag << " x " 
         << d.szelesseg << " x " << d.hosszusag << endl;
    unsigned int terfogat = d.magassag * d.szelesseg * d.hosszusag;
    unsigned int felszin = 2 *   (d.magassag  * d.szelesseg 
                                + d.szelesseg * d.hosszusag 
                                + d.hosszusag * d.magassag);
    cout << "Doboz térfogata: " << terfogat << endl;
    cout << "Doboz felszíne: " << felszin << endl;
    }

void tombNovel(Doboz* &tomb, int &meret, int ujElemek =5 ){ //  itt a tomb pointer, de referenciaként adjuk át 
    // a tomb pointert referenciaként adjuk át, hogy a függvényben módosítani tudjuk
    // a meret referenciaként adjuk át, hogy a függvényben módosítani tudjuk.
    // default value ujElemek = 5, ha nem adjuk meg a második paramétert, akkor 5 elem kerül a tömbbe
    Doboz *ujTomb = new Doboz[meret + ujElemek];  
    for (int i = 0; i < meret; i++){
        ujTomb[i] = tomb[i]; 
        }

    delete [] tomb; 
    tomb = ujTomb;     
    meret += ujElemek;
    }




bool belefer(const Doboz &d1,  const Doboz &d2){ // itt a d1 és d2 pointerek, de referenciaként adjuk át
    // a d1 és d2 pointereket referenciaként adjuk át, hogy a függvényben módosítani tudjuk
    // a d1 és d2 pointerek a Doboz típusú tömb első elemére mutatnak

    return (d1.magassag <= d2.magassag && 
        d1.szelesseg <= d2.szelesseg && 
        d1.hosszusag <= d2.hosszusag) 

    || (d1.magassag  >= d2.szelesseg &&
        d1.szelesseg >= d2.hosszusag &&
        d1.hosszusag >= d2.magassag);
    }


bool belefer(const Doboz &d, unsigned szelesseg, unsigned magassag, unsigned hosszusag){ // itt a d pointer, de referenciaként adjuk át
    // a d pointert referenciaként adjuk át, hogy a függvényben módosítani tudjuk
    // a d pointer a Doboz típusú tömb első elemére mutat

    return (d.magassag <= magassag && 
        d.szelesseg <= szelesseg && 
        d.hosszusag <= hosszusag) 

    }

// this was function overloading because the function name is the same. 
// Depending on the parameters, it is a different function.

}

using namespace doboz; // a doboz névtérben definiált függvényeket és struktúrákat használjuk
// a doboz névtérben definiált Doboz struktúrát és kiirDobozok függvényt használjuk
// a doboz névtérben definiált dobozFelszinTerfogat függvényt használjuk
int main() 
{
    //doboz::Doboz d;
    //Doboz d; 
    int dobozok_szama;
    cout << "Hány dobozt szeretnél megadni? ";
    cin >> dobozok_szama;
    
    Doboz *tomb;    
    tomb = new Doboz[dobozok_szama];    


    /* 
    Doboz *tomb;    
    tomb = new Doboz[10]; // 10 doboz
    delete [] tomb; // 10 doboz felszabadítva

    Doboz *egy;
    new Doboz(); // 1 doboz
    delete egy;   // 1 doboz felszabadítva
    */


    for (int i = 0; i < dobozok_szama; i++)
    {
        cout << "Kérem a doboz nevét: ";
        cin >> tomb[i].nev;
        cout << "Kérem a doboz magasságát: ";
        cin >> tomb[i].magassag;
        cout << "Kérem a doboz szélességét: ";
        cin >> tomb[i].szelesseg;
        cout << "Kérem a doboz hosszúságát: ";
        cin >> tomb[i].hosszusag;
    }


    kiirDobozok(tomb, dobozok_szama);

    dobozFelszinTerfogat(tomb[0]); // a dobozFelszinTerfogat függvényben a tomb[0] pointert adunk át
    // a dobozFelszinTerfogat függvényben a tomb[0] pointert adunk át.


    tombNovel(tomb, dobozok_szama, 9);
    tombNovel(tomb, dobozok_szama); // using default value 
    // only last parameter can be default value, or going back from right and skipping last 2.

    belefer(tomb[0], tomb[1]); // itt a tomb[0] és tomb[1] pointereket adjuk át, ezért az első függvény
    belefer(tomb[0], 1, 2, 3);  // itt a tomb[0] pointert adjuk át, ezért a második függvény

    delete [] tomb; // memória felszabadítása
    return 0;
}