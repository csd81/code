#include "szovegesszin.h"




SzovegesSzin::SzovegesSzin(string input)
{
    static map<string, tuple<char,char,char>> szinek ={
        {"fekete",{0,0,0}},
        {"feher",{255,255,255}},
        {"kek",{0,0,255}},
        {"piros",{255,0,0}},
        {"zold",{0,255,0}},
        {"cian",{0,255,255}},
        {"magenta",{255,0,255}},
        {"sarga",{255,255,0}}
    };
    if (!input.empty() && input[0]=='#' && input.length()==7){
        int r = Szin::hexatSzamma(input[1]) *16 + Szin::hexatSzamma(input[2]);
        int g = Szin::hexatSzamma(input[3]) *16 + Szin::hexatSzamma(input[4]);
        int b = Szin::hexatSzamma(input[5]) *16 + Szin::hexatSzamma(input[6]);

        this->r = r;
        this->g = g;
        this->b = b;
        nev = input;
    } else if (szinek.count(input)){
        tuple<unsigned char, unsigned char, unsigned char> rgb = szinek[input];
        unsigned char r = get<0>(rgb);
        unsigned char g = get<1>(rgb);
        unsigned char b = get<2>(rgb);

        this->r = r;
        this->g = g;
        this->b = b;

        nev = input;
    } else {
        this->r = 0;
        this->g = 0;
        this->b = 0;
        nev = "fekete";
    }
}

string SzovegesSzin::printCode() const  {
        return nev;
    }

