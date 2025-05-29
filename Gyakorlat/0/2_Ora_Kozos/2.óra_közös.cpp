/* Készíts egy Szamok osztályt, amely lebegőpontos számok tömbjét tárolja. Az osztály legyen a Tarolo névtérben. A tárolt tömb méretét nem tudjuk előre, viszont az osztály konstruktor kapja meg ezt az értéket, és foglaljon helyet a tömbnek. A konstruktornak legyen egy második paramétere, mely alapértelmezetten 0. Létrehozáskor a tömb minden eleme ezt az értéket vegye fel.A Szamok osztály destruktora szabadítsa fel az előző feladatban lefoglalt memóriát.
Az osztályban egy darabLeker függvény segítségével lehessen lekérdezni az eltárolt értékek számát.  Legyen az osztálynak egy ertekBeallit függvénye, amely megkapja a tömbnek egy (nem feltétlenül érvényes) indexét, valamint egy számot.  A tömb adott helyén lévő számot átállítja a paraméterben kapottra.  Érvénytelen index esetén a függvény ne csináljon semmit.  Legyen az osztálynak egy ertekLeker függvénye, amely megkapja a tömbnek egy (nem feltétlenül érvényes) indexét.  A függvény térjen vissza a tömb adott helyén lévő számmal.  Érvénytelen index esetén a függvény -10^8 értékkel térjen vissza. A main.cpp-ben lévő kódokat úgy írd meg, hogy a using namespace utasítást NEM használod a Tarolo névtérre.  Készíts a main.cpp-be egy kiir függvényt, amely paraméterben megkap egy Szamok objektumot, és megjeleníti a tárolt értékeket egy sorban, vesszővel elválasztva. A main függvényben hozz létre két Szamok objektumot, és töltsd fel értékekkel, majd jelenítsd is meg.
*/

#include <iostream>

namespace Tarolo{
class Szamok {
    unsigned meret;
    double* tomb;
public:
    Szamok(unsigned meret, double ertek = 0):
        meret(meret)
    {
        tomb = new double[meret];
        for (int i = 0; i < meret; i++){
            tomb[i] = ertek;
        }
    }

    // Másoló konstruktor

    Szamok(const Szamok& other) : meret(other.meret){
        tomb = new double[meret];
        for(int i = 0; i < meret; i++) {
            tomb[i] = other.tomb[i];
        }
    }


    ~Szamok(){
        delete[] tomb;
    }
    unsigned darabLeker() const {
        return meret;
    }
    void ertekBeallit(unsigned index, double ertek){
        if (index < meret){
            tomb[index]=ertek;
        }

    }
    double ertekLeker(unsigned index) const {
        if (index < meret){
            return tomb[index];
        } else
            return -1e8;
    }

};
} //Tarolo


void kiir(Tarolo::Szamok& sz){
    unsigned db = sz.darabLeker();
    for (unsigned i = 0; i < db; i++){
        std::cout << sz.ertekLeker(i);
        if (i < db -1)
            std::cout << ",";
    }
    std::cout << std::endl;
}

int main(){

    Tarolo::Szamok sz1(7, 4.4);
    Tarolo::Szamok sz2(4, 4.4);

    sz1.ertekBeallit(2, 8.8);
    sz2.ertekBeallit(0, 3.3);

    kiir(sz1);
    kiir(sz2);
    return 0;
}


