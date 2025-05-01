#include "helyszin.h"
#include <fstream>
#include <iostream>
#include "json.hpp"

using namespace nlohmann;

void Helyszin::betolt(const string &fajlnev)
{
    ifstream input(fajlnev);
    if (!input.is_open())
    {
        cout << "Cannot open " << fajlnev << endl;
        return;
    }
    json data;
    data = json::parse(input);
    // input >> data;

    nev = data["nev"];
    cim = data["cim"];

    for (unsigned i=0; i<data["esemenyek"].size(); i++)
    {
        // Esemeny uj(data["esemenyek"][i]["nev"],
        //            data["esemenyek"][i]["datum"],
        //            data["esemenyek"][i]["kezdete"],
        //            data["esemenyek"][i]["vege"],
        //            data["esemenyek"][i]["resztvevok"]);
        // esemenyek.push_back(uj);

        const json &esemeny = data["esemenyek"][i];
        Esemeny uj(esemeny["nev"],
                   esemeny["datum"],
                   esemeny["kezdete"],
                   esemeny["vege"],
                   esemeny["resztvevok"]);
        esemenyek.push_back(uj);
    }

}

void Helyszin::kiir() const
{
    cout << nev << " (" << cim << "):" << endl;
    for (unsigned i=0; i<esemenyek.size(); i++)
    {
        cout << "  " << esemenyek[i].getNev()
             << " (" << esemenyek[i].getDatum()
             << " " << esemenyek[i].getKezdete()
             << "-" << esemenyek[i].getVege()
             << "): " << esemenyek[i].getResztvevokSzama() << " fo"
             << endl;
    }
}

void Helyszin::esemenyHosszKiir(const string &fajlnev) const
{
    // json result = json::array();
    // for (unsigned i=0; i<esemenyek.size(); i++)
    // {
    //     json e = json::object();
    //     e["esemeny"] = esemenyek[i].getNev();
    //     e["hossz"] = esemenyek[i].getVege() - esemenyek[i].getKezdete();
    //     result.push_back(e);
    // }

    json result;
    for (unsigned i=0; i<esemenyek.size(); i++)
    {
        result[i]["esemeny"] = esemenyek[i].getNev();
        result[i]["hossz"] = esemenyek[i].getVege() - esemenyek[i].getKezdete();
    }

    ofstream output(fajlnev);
    // output << setw(2) << result;
    output << result.dump(2);
}
