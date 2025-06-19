#include "helyszin.h"
#include "json.hpp"


using namespace nlohmann;

void Helyszin::betolt(const string &jsonFajl)
{
        ifstream ifs(jsonFajl);
        json data;
        ifs >> data;
        nev = data["nev"];
        cim = data["cim"];
    for (size_t i=0; i< data["esemenyek"].size(); i++){

            string nev = data["esemenyek"][i]["nev"];
            string datum = data["esemenyek"][i]["datum"];
            int kezdete = data["esemenyek"][i]["kezdete"];
            int vege = data["esemenyek"][i]["vege"];
            int resztvevokSzama = data["esemenyek"][i]["resztvevok"];
            esemenyek.push_back(Esemeny(nev,datum,kezdete,vege,resztvevokSzama));
        }
}

void Helyszin::kiir(){
    std::cout << "Helyszin: "<<nev<< "("<<cim<<")\n";
    std::cout << "Esemenyek:\n";
    for (auto e: esemenyek){
        std::cout << e.getNev()<< ": "
        <<e.getDatum()<< " "
        <<e.getKezdete()<< ":00 - "
        <<e.getVege()<<":00 ("
        <<e.getResztvevokSzama()<<")\n";
    }
}

void Helyszin::esemenyHosszKiir(const string &kimenetiFajl)
{
    json object;
    object = json::array();
        for (auto e: esemenyek){
        string nev = e.getNev();
        int hossz = e.getVege()-e.getKezdete();
        object.push_back({ {"esemeny", nev},  {"hossz", hossz } });
        }



    ofstream ofs(kimenetiFajl);
    ofs << object.dump(4);
}
