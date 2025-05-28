#include <iostream>
#include <string>

using namespace std;

namespace doboz {

struct Doboz {
    string nev;
    unsigned szelesseg;
    unsigned magassag;
    unsigned hosszusag;
};

void kiir(Doboz* d, int db){
    for (int i=0; i<db; i++){
        cout << "\n" << i+1 <<". neve: "
        << d[i].nev;
        cout << "\n" << i+1 <<". sz: "
        << d[i].szelesseg;
        cout << "\n" << i+1 <<". m: "
        << d[i].magassag;
        cout << "\n" << i+1 <<". h: "
        << d[i].hosszusag;
    }
}


void felszinTerfogat(const Doboz &d){
    int f;
    int t;
    int s = d.szelesseg;
    int m = d.magassag;
    int h = d.hosszusag;
    f = 2*(s * m + s * h + m * h);
    t = s * m * h;
    cout << "f:" << f << "\n";
    cout << "t:" << t << "\n";
}

Doboz* tombNovel(Doboz* regiTomb, int &regiMeret, int plusz){
    Doboz* ujTomb = new Doboz[regiMeret + plusz];
    for(int i = 0; i < regiMeret; i++){
        ujTomb[i] = regiTomb[i];
    }
    delete[] regiTomb;

    return ujTomb;
}

bool belefer(Doboz& d1,Doboz& d2){
    return (d1.szelesseg <=d2.szelesseg &&
            d1.magassag <=d2.magassag &&
            d1.hosszusag <=d2.hosszusag) ||
            (d1.szelesseg >=d2.szelesseg &&
            d1.magassag >=d2.magassag &&
            d1.hosszusag >=d2.hosszusag);
}

bool belefer(Doboz& d, unsigned sz,unsigned m,unsigned h){
    return (d.szelesseg <=sz &&
            d.magassag <=m &&
            d.hosszusag <=h);
}
void forgat(Doboz& d) {
    unsigned temp = d.szelesseg;
    d.szelesseg = d.magassag;
    d.magassag = d.hosszusag;
    d.hosszusag = temp;
}


} // doboz
using namespace doboz;
int main(){
    int darab;
    cout << "darab?";
    cin >> darab;

    Doboz* dobozok = new Doboz[darab];

    for (int i=0; i<darab; i++){
        cout << "\n" << i+1 <<". neve: ";
        cin >> dobozok[i].nev;
        cout << "\n" << i+1 <<". sz: ";
        cin >> dobozok[i].szelesseg;
        cout << "\n" << i+1 <<". m: ";
        cin >> dobozok[i].magassag;
        cout << "\n" << i+1 <<". h: ";
        cin >> dobozok[i].hosszusag;
    }
    kiir(dobozok, darab);

    int plus;
    cout << "mennyi uj?";
    cin >> plus;
    dobozok = tombNovel(dobozok,darab,plus);


    darab += plus;
     cout << "\nA tömb mérete mostantól: " << darab << " doboz.\n";

    for (int i = darab; i < darab+plus; i++){
         cout << "\n" << i+1 <<". neve: ";
         cin >> dobozok[i].nev;
         cout << "\n" << i+1 <<". sz: ";
         cin >> dobozok[i].szelesseg;
         cout << "\n" << i+1 <<". m: ";
         cin >> dobozok[i].magassag;
         cout << "\n" << i+1 <<". h: ";
         cin >> dobozok[i].hosszusag;
     }

cout << "\nA teljes dobozlista:\n";
     kiir(dobozok,darab+plus);

    delete [] dobozok;
    return 0;
}




