#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;


struct Auto {
    std::string rendszam;
    int evjarat;
    int ar;
};

int main()
{
    string be_fajl;
    string ki_fajl;
    getline(cin, be_fajl);
    getline(cin, ki_fajl);

    ifstream be(be_fajl);


    vector<Auto> autok;

    Auto a;
    while (be >> a.rendszam >> a.evjarat >> a.ar) {
        if (a.evjarat >=2000){
            autok.push_back(a);
        }
    }
    be.close();

    std::sort(autok.begin(),
            autok.end(),
        [](const Auto& a, const Auto& b){
        return a.ar < b.ar;
    });

    std::ofstream ki(ki_fajl);

    for (const auto& auto_adat : autok) {
        ki << auto_adat.rendszam
           << " "
           << auto_adat.evjarat
        << " "
        << auto_adat.ar
           << "\n";
    }


    ki.close();
    return 0;
}
