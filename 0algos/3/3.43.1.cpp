/*
3.43. Statisztika

3.43.1. Egy 5000 fős település lakosainak adatait kell feldolgoznunk. Van 
egy fájlunk, amely a lakosok életkorát tartalmazza. Írjon programot, amely 
kiírja a képernyőre, hogy mennyi kiskorú, felnőtt, nyugdíjas él a 
teleülésen! Kiskorúnak számít az, aki még nem töltötte be a 18. 
életévét, egyébként a felnőttek közé soroljuk. A nyugdíjkorhatár 62 
év. 

3.43.2. Bővítse ki az előző programot úgy, hogy a program kiírja, hogy 
hányan születtek a második világháború alatt (1939-1945). Az aktuális 
év 2010. 

3.43.3. Bővítse ki az előző programot úgy, hogy a program kiírja azt is, 
hogy hányan születtek szökőévben! Szökőévnek számítanak azok az 
évek, ahol az évszám osztható 4-el, de a 100-asra végződőek közül csak 
azok, amelyek oszthatóak 400-al. Ez alapján szökőév volt 1992, 1996, de 
1900 nem, viszont 2000 igen. 

3.43.1.-3.34.3.

 
*/

 
#include <iostream>
#include <fstream>
#include <string>

constexpr int AKTUALIS_EV = 2010;

bool szokoev(int ev) {
    return (ev % 4 == 0 && ev % 100 != 0) || (ev % 400 == 0);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Használat: " << argv[0] << " fajlnev.txt\n";
        return EXIT_FAILURE;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Nem sikerült megnyitni a fájlt: " << argv[1] << '\n';
        return EXIT_FAILURE;
    }

    int kiskoru = 0;
    int felnott = 0;
    int nyugdijas = 0;
    int vh2 = 0;
    int szokoevben = 0;

    int eletkor;
    while (file >> eletkor) {
        int ev = AKTUALIS_EV - eletkor;

        // Életkori kategóriák
        if (eletkor < 18) {
            ++kiskoru;
        } else {
            ++felnott;
            if (eletkor >= 62) {
                ++nyugdijas;
            }
        }

        // 2. világháború alatt születettek
        if (ev >= 1939 && ev <= 1945) {
            ++vh2;
        }

        // Szökőév ellenőrzés
        if (szokoev(ev)) {
            ++szokoevben;
        }
    }

    // Kiírás
    std::cout << "Kiskorúak száma: " << kiskoru << '\n';
    std::cout << "Felnőttek száma: " << felnott << '\n';
    std::cout << "Nyugdíjasok száma: " << nyugdijas << '\n';
    std::cout << "Második világháború alatt születettek: " << vh2 << '\n';
    std::cout << "Szökőévben születettek: " << szokoevben << '\n';

    return 0;
}

