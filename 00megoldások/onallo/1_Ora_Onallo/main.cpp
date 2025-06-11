#include <iostream>
#include <string>

using namespace std;

#define T 3 // Spec: "A program tárolja fixen 3 tárgy eredményeit."

// Spec: "A struktúra és a lenti függvények legyenek egy egyetem nevű névtérben."
namespace egyetem {

// Spec: "Készíts egy struktúrát, amely tantárgy eredményeit tárolja:"
struct Tantargy
{
    string kod;                 // Spec: Tárgy kódja: szöveg (szóköz nélküli)
    unsigned int jegyszam,      // Spec: Jegyek száma: előjel nélküli egész
                 *jegyek;       // Spec: Jegyek: előjel nélküli egészek tömbje (dinamikus)
};

// Spec: "Készíts egy függvényt, amely megkap egy tantárgyat, és megjeleníti az adatait."
void megjelenit(const Tantargy &t)
{
    cout << "  Kodja: " << t.kod << endl;
    cout << "  Jegyek szama: " << t.jegyszam << endl;
    cout << "Jegyek: ";
    for (unsigned int j=0; j<t.jegyszam; j++)
    {
        if (j!=0) cout << ", ";
        cout << t.jegyek[j];
    }
    cout << endl;
}

// Spec: "Készíts egy függvényt, amely megkap egy tantárgyat, és visszaadja a jegyek átlagát."
double atlag(const Tantargy &t)
{
    double osszeg=0;
    for (unsigned int i=0; i<t.jegyszam; i++)
        osszeg+=t.jegyek[i];
    return osszeg/t.jegyszam;
}

// Spec: "Készíts egy függvényt, amely megkap egy tantárgyat és egy előjel nélküli egészet."
// "A függvény foglalja újra a tantárgyhoz tartozó jegyek tömbjét a megadott méretűre."
// "Ha nő a méret, akkor összes új jegy legyen 5-ös."
void ujrafoglal(Tantargy &t, unsigned int ujmeret)
{
    unsigned int *uj=new unsigned int[ujmeret];
    if (t.jegyszam < ujmeret)
    {
        for (unsigned int i=0; i<t.jegyszam; i++)
            uj[i]=t.jegyek[i];
        for (unsigned int i=t.jegyszam; i<ujmeret; i++)
            uj[i]=5; // Spec: új jegyek 5-ös
    }
    else
    {
        // Ha csökken a méret, a nem elférő jegyek eltűnnek
        for (unsigned int i=0; i<ujmeret; i++)
            uj[i]=t.jegyek[i];
    }
    delete [] t.jegyek;
    t.jegyek=uj;
    t.jegyszam=ujmeret;
}

// Spec: "Az előző függvénynek legyen egy olyan verziója, amely vár plusz két paramétert."
// "Ha a tömb mérete nő, az új jegyek ezen két paraméter legyenek, váltakozva."
void ujrafoglal(Tantargy &t, unsigned int ujmeret, unsigned int egyik, unsigned int masik)
{
    unsigned int *uj=new unsigned int[ujmeret];
    if (t.jegyszam < ujmeret)
    {
        for (unsigned int i=0; i<t.jegyszam; i++)
            uj[i]=t.jegyek[i];
        bool elso_jon=true;
        for (unsigned int i=t.jegyszam; i<ujmeret; i++)
        {
            if (elso_jon)
                uj[i]=egyik;
            else
                uj[i]=masik;
            elso_jon=!elso_jon;
        }
    }
    else
    {
        for (unsigned int i=0; i<ujmeret; i++)
            uj[i]=t.jegyek[i];
    }
    delete [] t.jegyek;
    t.jegyek=uj;
    t.jegyszam=ujmeret;
}

// Spec: "Készíts egy függvényt, amely megkap egy tárgyat, és felszabadítja a hozzá tartozó tömböt."
void felszabadit(Tantargy &t)
{
    delete [] t.jegyek;
    t.jegyek=nullptr;
}

} // namespace egyetem

using namespace egyetem;

int main()
{
    // Spec: "A program tárolja fixen 3 tárgy eredményeit."
    Tantargy targyak[T];

    // Spec: "Olvasd be a tárgyak adatait."
    for (unsigned int i=0; i<T; i++)
    {
        cout << "Kerem a(z) " << i+1 << ". targy adatait:" << endl;
        cout << "  Kodja: ";
        cin >> targyak[i].kod;
        cout << "  Jegyek szama: ";
        cin >> targyak[i].jegyszam;
        // Spec: "helyet foglalni a jegyek tömbjének"
        targyak[i].jegyek=new unsigned int[targyak[i].jegyszam];
        // Spec: "be kell kérni a jegyeket is"
        cout << "Kerem a jegyeket (" << targyak[i].jegyszam << " db):" << endl;
        for (unsigned int j=0; j<targyak[i].jegyszam; j++)
            cin >> targyak[i].jegyek[j];
    }

    cout << endl;
    // Spec: "Jelenítsd meg a tantárgyak adatait a függvény segítségével."
    for (unsigned int i=0; i<T; i++)
    {
        cout << "A(z) " << i+1 << ". targy adatai:" << endl;
        megjelenit(targyak[i]);
    }

    cout << endl;
    // Spec: "Az előző függvény segítségével keresd meg azt a tantárgyat, ahol az átlag a legmagasabb."
    unsigned int max_idx=0;
    double max_atlag=atlag(targyak[0]); // Hogy ne kelljen mindig újra kiszámolni.
    for (unsigned int i=1; i<T; i++)
    {
        double tatlag=atlag(targyak[i]);
        if (tatlag>max_atlag)
        {
            max_atlag=tatlag;
            max_idx=i;
        }
    }
    cout << "A legnagyobb atlaggal rendelkezo targy adatai:" << endl;
    megjelenit(targyak[max_idx]);
    cout << "  Atlag: " << max_atlag << endl;

    cout << endl;
    // Spec: "Minden tantárgyhoz kérj be egy számot, és az előbbi függvény segítségével méretezd át a jegyek tömbjét."
    for (unsigned int i=0; i<T; i++)
    {
        unsigned int ujmeret=0;
        cout << "Mekkora legyen az uj tomb a(z) " << targyak[i].kod << " targyhoz? ";
        cin >> ujmeret;
        ujrafoglal(targyak[i], ujmeret);
    }

    // Spec: "Jelenítsd meg a tantárgyak adatait a függvény segítségével."
    for (unsigned int i=0; i<T; i++)
    {
        cout << "A(z) " << i+1 << ". targy adatai:" << endl;
        megjelenit(targyak[i]);
    }

    cout << endl;
    // Spec: "Az előző függvénynek legyen egy olyan verziója, amely vár plusz két paramétert."
    ujrafoglal(targyak[0], 10, 2, 4);
    cout << "A(z) " << 1 << ". targy adatai:" << endl;
    megjelenit(targyak[0]);

    // Spec: "Szabadítsd fel az összes lefoglalt memóriát a függvény meghívásával."
    for (unsigned int i=0; i<T; i++)
    {
        felszabadit(targyak[i]);
    }

    return 0;
}
