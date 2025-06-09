#include <iostream>
#include <string>

using namespace std;

// Spec: "A struktúra és a lenti függvények legyenek egy doboz nevű névtérben."
namespace doboz {

// Spec: "Készíts egy struktúrát, amely egy téglatest alakú doboz adatait tárolja:"
struct Doboz
{
    string nev;                   // Spec: Doboz neve: szöveg (szóköz nélküli)
    unsigned int szelesseg,       // Spec: Szélesség: előjel nélküli egész érték
                 magassag,        // Spec: Magasság: előjel nélküli egész érték
                 hosszusag;       // Spec: Hosszúság: előjel nélküli egész érték
};

// Spec: "Készíts egy függvényt, amely megkapja a dobozok tömbjét, és megjeleníti a tartalmát."
void megjelenit(const Doboz * dobozok, unsigned int db)
{
    for (unsigned int i=0; i<db; i++)
    {
        cout << "A(z) " << i+1 << ". doboz adatai:" << endl;
        cout << "  Neve: " << dobozok[i].nev << endl;
        cout << "  Szelessege: " << dobozok[i].szelesseg << endl;
        cout << "  Magassaga: " << dobozok[i].magassag << endl;
        cout << "  Hosszusaga: " << dobozok[i].hosszusag << endl;
    }
}

// Spec: "Készíts egy függvényt, amely megkap egy dobozt, és kiírja a felszínét és a térfogatát."
void felszinTerfogat(const Doboz &d)
{
    cout << "A(z) " << d.nev << " doboz felszine: ";
    cout << 2*(d.szelesseg*d.magassag + d.szelesseg*d.hosszusag + d.magassag*d.hosszusag);
    cout << " es terfogata: ";
    cout << d.szelesseg * d.magassag * d.hosszusag << endl;
}

// Spec: "Készíts egy függvényt, amely megkapja a dobozok tömbjét, illetve egy egész számot.
// A függvény foglalja újra a tömböt úgy, hogy megnöveli a méretét a megadott számmal."
void ujrafoglal(Doboz *&dobozok, unsigned int &db, unsigned int novel)
{
    Doboz *uj = new Doboz[db + novel];
    for (unsigned int i=0; i<db; i++)
        uj[i] = dobozok[i];

    delete [] dobozok;
    dobozok = uj;
    db += novel;
}

// Spec: "Készíts egy függvényt, amely megkap két dobozt. 
// A függvény határozza meg, hogy bármelyik doboz belefér-e a másikba (a dobozokat nem forgatjuk el)."
bool belefer(const Doboz &d1, const Doboz &d2)
{
    if (d1.szelesseg<=d2.szelesseg && d1.magassag<=d2.magassag && d1.hosszusag<=d2.hosszusag)
    {
        return true;
    }
    else if (d1.szelesseg>=d2.szelesseg && d1.magassag>=d2.magassag && d1.hosszusag>=d2.hosszusag)
    {
        return true;
    }
    else return false;
}

// Spec: "Az előbbi függvénynek legyen egy másik verziója, ami csak egy dobozt kap meg,
// valamint mellé egy-egy szélesség, magasság, és hosszúság értéket."
bool belefer(const Doboz &d1, unsigned int sz, unsigned int m, unsigned int h)
{
    return d1.szelesseg<=sz && d1.magassag<=m && d1.hosszusag<=h;
}

// Spec: "Készíts egy függvényt, amely megkap egy dobozt, és azt elforgatja."
// "A forgatás most fix módon történik: a szélesség, magasság, és hosszúság adatokat megcseréli."
void forgat(Doboz &d)
{
    unsigned int csere = d.szelesseg;
    d.szelesseg = d.magassag;
    d.magassag = d.hosszusag;
    d.hosszusag = csere;
}

} // namespace doboz

using namespace doboz;

int main()
{
    unsigned int dobozdb = 0;

    // Spec: "Kérd be, hogy hány doboz adatait tárolja a program."
    cout << "Mennyi doboz adatait taroljuk (a kesobbi tesztek miatt legyen legalabb 3)? ";
    cin >> dobozdb;

    // Spec: "Foglalj helyet a megfelelő számú doboznak."
    Doboz *dobozok = new Doboz[dobozdb];

    // Spec: "Olvasd be a dobozok adatait."
    for (unsigned int i=0; i<dobozdb; i++)
    {
        cout << "Kerem a(z) " << i+1 << ". doboz adatait:" << endl;
        cout << "  Neve? ";
        cin >> dobozok[i].nev;
        cout << "  Szelessege? ";
        cin >> dobozok[i].szelesseg;
        cout << "  Magassaga? ";
        cin >> dobozok[i].magassag;
        cout << "  Hosszusaga? ";
        cin >> dobozok[i].hosszusag;
    }

    cout << endl;

    // Spec: "Jelenítsd meg a dobozok adatait a függvény meghívásával."
    megjelenit(dobozok, dobozdb);

    cout << endl;

    // Spec: "Készíts egy függvényt, amely megkap egy dobozt, és kiírja a felszínét és a térfogatát."
    felszinTerfogat(dobozok[0]);

    cout << endl;

    // Spec: "Kérj be egy számot, és növeld meg a tömb méretét a függvény segítségével."
    unsigned int novel = 0;
    cout << "Mennyivel noveljuk a tomb meretet? ";
    cin >> novel;

    ujrafoglal(dobozok, dobozdb, novel);

    // Spec: "Olvasd be a tömb új elemeinek értékeit."
    for (unsigned int i=dobozdb-novel; i<dobozdb; i++)
    {
        cout << "Kerem a(z) " << i+1 << ". doboz adatait:" << endl;
        cout << "  Neve? ";
        cin >> dobozok[i].nev;
        cout << "  Szelessege? ";
        cin >> dobozok[i].szelesseg;
        cout << "  Magassaga? ";
        cin >> dobozok[i].magassag;
        cout << "  Hosszusaga? ";
        cin >> dobozok[i].hosszusag;
    }

    cout << endl;

    // Spec: "Jelenítsd meg a teljes tömböt."
    megjelenit(dobozok, dobozdb);

    // Spec: "Készíts egy függvényt, amely megkap két dobozt." (tesztelés)
    cout << dobozok[0].nev << " es " << dobozok[1].nev << " kapcsolata: " << belefer(dobozok[0], dobozok[1]) << endl;
    cout << dobozok[1].nev << " es " << dobozok[2].nev << " kapcsolata: " << belefer(dobozok[1], dobozok[2]) << endl;
    cout << dobozok[2].nev << " es " << dobozok[0].nev << " kapcsolata: " << belefer(dobozok[2], dobozok[0]) << endl;

    // Spec: "Az előbbi függvénynek legyen egy másik verziója."
    cout << dobozok[0].nev << " belefer-e 40x50x60-ba: " << belefer(dobozok[0], 40, 50, 60) << endl;
    cout << dobozok[1].nev << " belefer-e 40x50x60-ba: " << belefer(dobozok[1], 40, 50, 60) << endl;
    cout << dobozok[2].nev << " belefer-e 40x50x60-ba: " << belefer(dobozok[2], 40, 50, 60) << endl;

    // Spec: "Készíts egy függvényt, amely megkap egy dobozt, és azt elforgatja."
    forgat(dobozok[0]);

    cout << endl;
    megjelenit(dobozok, dobozdb);

    // Spec: "Szabadítsd fel a lefoglalt memóriát."
    delete [] dobozok;

    return 0;
}
