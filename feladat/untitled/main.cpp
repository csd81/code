#include <iostream>
#include <fstream>
#include "szamok.h"

using namespace std;

void kiir(const Szamok &s){
    for (unsigned int i=0; i < s.darabLeker(); i++)
    {
        cout << s.ertekLeker(i);
    }
    cout << endl;

}


int main()
{
    Szamok elso(5);
    Szamok masik(7,1.2);

    elso.ertekBeallit(0,2.3);
    elso.ertekBeallit(1,1.3);
    elso.ertekBeallit(2,5.3);
    elso.ertekBeallit(3,22.3);
    elso.ertekBeallit(4,12.3);

    masik.ertekBeallit(0,2.4);
    masik.ertekBeallit(1,2.4);
    masik.ertekBeallit(2,2.4);
    masik.ertekBeallit(3,2.4);
    masik.ertekBeallit(4,2.4);
    masik.ertekBeallit(5,2.4);
    masik.ertekBeallit(6,2.4);

    cout << elso.darabLeker() << endl;
    cout << masik.darabLeker() << endl;

    kiir(elso);
    kiir(masik);

    ifstream input("be.txt");
    if(!input.is_open()){
        cout << "error";
        return 0;
    }
    input.close();
    int i1, i2;
    input >>  i1 >> i2;

    ofstream output;
    output.open("be.txt");
    output << "acl";
    output << endl;
    output.close();
    return 0;
}
