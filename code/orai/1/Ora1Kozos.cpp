#include <iostream>

using namespace std;

namespace doboz
{

struct Doboz
{
    string nev;
    unsigned szelesseg, magassag, hosszusag;
};

void kiirDobozok(const Doboz *tomb, int meret)
{
    for (int i=0; i<meret; i++)
    {
        cout << "Nev: " << tomb[i].nev
             << ", meret: " << tomb[i].szelesseg
             << "x" << tomb[i].hosszusag
             << "x" << tomb[i].magassag << endl;
    }
}

void felszinTerfogat(const Doboz &d)
{
    unsigned felszin = 2*(d.szelesseg*d.magassag +
                            d.magassag*d.hosszusag +
                            d.hosszusag*d.szelesseg);
    unsigned terfogat = d.szelesseg * d.magassag * d.hosszusag;

    cout << "Felszin: " << felszin
         << ", terfogat " << terfogat
         << endl;
}

void tombNovel(Doboz* &tomb, int &meret, int ujElemek = 5)
{
    Doboz *ujTomb = new Doboz[meret + ujElemek];
    for (int i=0; i<meret; i++)
        ujTomb[i] = tomb[i];
    delete [] tomb;
    tomb = ujTomb;
    meret += ujElemek;
}

bool belefer(const Doboz &d1, const Doboz &d2)
{
    return (d1.szelesseg <= d2.szelesseg &&
            d1.hosszusag <= d2.hosszusag &&
            d1.magassag <= d2.magassag)
        ||
           (d1.szelesseg >= d2.szelesseg &&
            d1.hosszusag >= d2.hosszusag &&
            d1.magassag >= d2.magassag);
}

bool belefer(const Doboz &d, unsigned szelesseg, unsigned magassag, unsigned hosszusag)
{
    return (d.szelesseg <= szelesseg &&
            d.hosszusag <= hosszusag &&
            d.magassag <= magassag);
}

}

// void fvg(int a, int b=1, int c=3);
// void fvg(int a, double b = 5.6);
// void f(int a, int b, int c);
// void f(double a, double b, double c);

using namespace doboz;

int main()
{
    // fvg(2);
    //f(1, 2, 4.7);

    //doboz::Doboz d;
    //Doboz d;

    int dobozokSzama;
    cout << "Mennyi doboz lesz? ";
    cin >> dobozokSzama;
    /**********/
    // Doboz *tomb;
    // tomb = new Doboz[10]; // tömb lefoglalása
    // delete [] tomb; // tömb felszabadítása
    // Doboz *egy;
    // egy = new Doboz(); // egy objektum lefoglalása
    // delete egy; // egy objektum felszabadítása
    /**********/

    Doboz *tomb = new Doboz[dobozokSzama];

    for (int i=0; i<dobozokSzama; i++)
    {
        cin >> tomb[i].nev >> tomb[i].szelesseg
            >> tomb[i].hosszusag >> tomb[i].magassag;
    }

    cout << endl << "--KIIRAS--" << endl;
    kiirDobozok(tomb, dobozokSzama);

    cout << endl << "--FELSZIN, TERFOGAT--" << endl;
    for (int i=0; i<dobozokSzama; i++)
    {
        felszinTerfogat(tomb[i]);
    }

    // tombNovel(tomb, dobozokSzama, 9);
    // tombNovel(tomb, dobozokSzama);

    belefer(tomb[0], tomb[1]);
    belefer(tomb[0], 54, 76, 23);

    delete [] tomb;
    return 0;
}
