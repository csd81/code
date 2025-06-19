#ifndef SZAMLASEGED_H
#define SZAMLASEGED_H

#include<string>

using namespace std;

class SzamlaSeged
{
public:
    SzamlaSeged();
    // számlaszám formátum fixen: 12345678-87654321 (2x8)
    static int* szamjegyek(const string& szamlaszam){
        static int szamjegyek[16];
        int j = 0;
        for(size_t i = 0; i < szamlaszam.size(); ++i){
            char szamjegy = szamlaszam[i];
            if(szamjegy != '-'){
                szamjegyek[j++] = szamjegy - '0';
            }
        }
        return szamjegyek;
    }
};

#endif // SZAMLASEGED_H
