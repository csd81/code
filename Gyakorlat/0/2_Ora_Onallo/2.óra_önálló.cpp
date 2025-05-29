// Készíts egy Tarolo osztályt, amely egész számokat tárol, előre meg nem határozott mennyiségben. Az osztály legyen egy EpicToolbox névtérben. Az osztálynak két konstruktora legyen. Az egyik várjon egy számot, hozza létre a belső tömböt ekkora mérettel, és töltse fel 1,2,3,... értékekkel.A másik ne várjon paramétert, hanem olvassa be a tömb méretét, hozza létre a tömböt, majd olvassa be az elemeit is. Az osztály destruktora szabadítsa fel a tömböt. Legyen az osztálynak egy kiir függvénye, amely megjeleníti az eltárolt számokat. Készíts az osztályba egy hozzaad függvény is, amely megkap egy számot. A belső tömb méretét megnöveli eggyel, hogy az új érték elférjen benne, és a végére hozzá is teszi ezt az értéket.Készíts egy atlag függvényt az osztályba, amely visszaadja a tárolt számok átlagát. A main függvényben hozz létre egy-egy Tarolo típusú objektumot mindkét konstruktort használva. Mindkettőt töltsd fel értékekkel, majd jelenítsd is meg. A main.cpp-ben legyen egy kisebbTarolo függvény, ami megkap két Tarolo típusú objektumot. A függvény visszatér 1-gyel, ha az másodiknak van kevesebb eleme, -1-gyel, ha az elsőnek, és 0-val, ha ugyanannyi elemük van.  A függvényhez szükség lesz a Tarolo osztály megfelelő kiegészítésére. A main függvényben hívd meg ezt a függvényt a kettő létrehozott tárolóra, és jelenítsd meg az eredményt.A Tarolo osztálynak legyen egy tartomany metódusa, amely visszaadja a legnagyobb és legkisebb tárolt érték különbségét. A függvényt hívd is meg a main-ben. A Tarolo osztálynak legyen egy rendez metódusa, amely paraméterben egy logikai értéket vár. A függvény rendezze sorba a tároló elemeit, ha a paraméter értéke igaz, akkor növekvő sorrendbe, ha hamis, akkor csökkenőbe.A függvényt hívd is meg a main-ben. A Tarolo osztálynak legyen egy hozzafuz metódusa is, amely paraméterben egy másik Tarolo objektumot kap. A metódus fűzze hozzá a paraméterben kapott tároló elemeit az aktuálishoz, a sorrendet megtartva. A függvényt hívd is meg a main-ben.





#include<iostream>

namespace EpicToolbox{
class Tarolo {
    unsigned meret;
    int* tomb;
public:
    Tarolo(unsigned m) : meret(m) {
        tomb = new int[meret];
        for (unsigned i = 0; i < meret; i++){
            tomb[i]  = static_cast<int>(i + 1);
        }
    }
    Tarolo(){
        std::cout << "Add meg a tömb méretét: ";
        std::cin >> meret;
        tomb = new int[meret];
        std::cout << "Add meg a tömb elemeit: ";
        for (unsigned i = 0; i < meret; i++){
            std::cin >> tomb[i];
        }
    }

    Tarolo(const Tarolo& other) : meret(other.meret) {
        tomb = new int[meret];
        for (unsigned i = 0; i < meret; i++) {
            tomb[i] = other.tomb[i];
        }
    }

    Tarolo& operator=(const Tarolo& other) {
        if (this != &other) {
            delete[] tomb;
            meret = other.meret;
            tomb = new int[meret];
            for (unsigned i =0; i< meret; i++){
                tomb[i] = other.tomb[i];
            }
        }
        return *this;
    }



    ~Tarolo(){
        delete[] tomb;
    }

    void kiir() const {
        for (unsigned i =0; i < meret; i++){
            std::cout << tomb[i] << ' ';
        }
        std::cout  << '\n';
    }

    void hozzaad(int ujErtek){
        int* ujTomb = new int[meret+1];
        for (unsigned i =0; i<meret; ++i){
            ujTomb[i] = tomb [i];
        }
        ujTomb[meret] = ujErtek;
        ++meret;
        delete[] tomb;
        tomb = ujTomb;
    }

    double atlag() const {
        int osszeg = 0;
        for (unsigned i = 0; i < meret; ++i){
            osszeg+= tomb[i];
        }
        return static_cast<double>(osszeg)/meret;
    }

    unsigned int getMeret() const
    {
        return meret;
    }

    int tartomany() const {
        int max = tomb[0];
        for (unsigned i = 0; i < meret; ++i){
            if (tomb[i]>max){
                max =  tomb[i];
            }
        }

        int min = tomb[0];
        for (unsigned i = 0; i < meret; ++i){
            if (tomb[i]<min){
                min =  tomb[i];
            }
        }

        return max-min;
    }

    void rendez(bool novekvo){
       for (unsigned i = 0; i < meret - 1; ++i) {
            for (unsigned j = 0; j < meret - 1 - i; ++j) {
                if (novekvo){
                    if (tomb[j] > tomb[j + 1]){
                        int temp = tomb[j];
                        tomb[j] = tomb[j + 1];
                        tomb[j + 1] = temp;
                    }

                } else if (tomb[j] < tomb[j + 1]){ //csökkenő
                    int temp = tomb[j];
                    tomb[j] = tomb[j + 1];
                    tomb[j + 1] = temp;
                }
            }
        }
    }


    void hozzafuz(const Tarolo& masik){
        int* ujTomb = new int[meret + masik.meret];
        for (unsigned i = 0; i < meret; ++i) {
            ujTomb[i] = tomb[i];
        }
        for (unsigned i = 0; i < masik.meret; ++i) {
            ujTomb[meret+i] = masik.tomb[i];
        }
        meret += masik.meret;
        delete[] tomb;
        tomb = ujTomb;
    }







}; // Tarolo class
} //EpicToolbox ns

int kisebbTarolo(const EpicToolbox::Tarolo& t1, const EpicToolbox::Tarolo& t2){
    if (t1.getMeret()>t2.getMeret())
        return 1;
    else if (t1.getMeret()<t2.getMeret())
        return -1;
    else
        return 0;

}


int main() {
    using namespace EpicToolbox;

    std::cout << "Paraméteres konstruktor teszt:\n";
    Tarolo t1(5);
    t1.kiir();

    std::cout << "\nParaméter nélküli konstruktor teszt:\n";
    Tarolo t2;
    t2.kiir();

    std::cout << "\nÁtlagok:\n";
    std::cout << "t1 átlaga: " << t1.atlag() << '\n';
    std::cout << "t2 átlaga: " << t2.atlag() << '\n';

    std::cout << "\nTartományok:\n";
    std::cout << "t1 tartománya: " << t1.tartomany() << '\n';
    std::cout << "t2 tartománya: " << t2.tartomany() << '\n';

    std::cout << "\nTárolók méretösszehasonlítása:\n";
    int eredmeny = kisebbTarolo(t1, t2);
    if (eredmeny == -1)
        std::cout << "t1 kisebb méretű.\n";
    else if (eredmeny == 1)
        std::cout << "t2 kisebb méretű.\n";
    else
        std::cout << "A két tároló mérete megegyezik.\n";

    std::cout << "\nNövekvő rendezés után (t1):\n";
    t1.rendez(true);
    t1.kiir();

    std::cout << "\nCsökkenő rendezés után (t1):\n";
    t1.rendez(false);
    t1.kiir();

    std::cout << "\nHozzáfűzés után (t1 + t2):\n";
    t1.hozzafuz(t2);
    t1.kiir();

    return 0;
}

