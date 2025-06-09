// 3.46. Nyúltenyésztés

// 3.46.1. Mr. Fibonacci elhatározta, hogy belevág a nyúltenyésztésbe. Az 
// első hónapban vesz egy újszülött nyúlpárt. Minden nyúl 2 hónap után 
// válik termékennyé. Minden hónapban minden termékeny nyúlpár egy új 
// nyúlpárt szül. A nyulakat etetni kell, minden nyúl egy zsák nyúltápot 
// fogyaszt el minden hónapban és egy nyúlpár se pusztul el. Írjon programot, 
// amely meghatározza, hogy hány zsák nyúltápot kell vásárolni egy évre, 
// ha az első hónapban 1 nyúlpár van! 

// 3.46.2. Bővítse ki az előző programot úgy, hogy 3 évre előre számoljon, 
// figyelembe véve, hogy Mr. Fibonacci minden év elején eladja a termékeny 
// nyulak 90 %-át, és a terméketlenek 95 %-át! Amennyiben az eladandó nyulak 
// mennyisége nem egész szám, úgy ezt az értéket mindig lefele kerekítjük. 
// Például 101 termékeny nyúl esetén 90-et adunk el. 3.47. Jegyek

// 3.46.1.-3.46.2.


#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    using ull = unsigned long long;
    
    ull termeketlen = 1; // 1 pár nyúl az elején (újszülött)
    ull egyhonapos = 0;
    ull termekeny = 0;

    ull total_nyulpar = 1;
    ull total_tap = 2; // 1 pár nyúl = 2 nyúl = 2 zsák

    const int evek = 3;

    for (int ev = 1; ev <= evek; ++ev) {
        for (int honap = 1; honap <= 12; ++honap) {
            ull uj_nyulpar = termekeny;

            // Frissítjük az állapotokat
            termekeny += egyhonapos;
            egyhonapos = termeketlen;
            termeketlen = uj_nyulpar;

            ull havi_nyulpar = termekeny + egyhonapos + termeketlen;
            total_nyulpar += uj_nyulpar;
            total_tap += havi_nyulpar * 2;
        }

        // Év végén eladások
        ull eladott_termekeny = static_cast<ull>(std::floor(termekeny * 0.9));
        ull eladott_termeketlen = static_cast<ull>(std::floor((termeketlen + egyhonapos) * 0.95));

        std::cout << "\n[Év " << ev << " vége] Eladás előtt:\n";
        std::cout << "  Termekeny: " << termekeny << "\n";
        std::cout << "  Termeketlen: " << (termeketlen + egyhonapos) << "\n";

        termekeny -= eladott_termekeny;

        // Termeketlen = (újszülött + egyhonapos), újraosztjuk:
        ull marado_termeketlen = termeketlen + egyhonapos - eladott_termeketlen;
        egyhonapos = 0;
        termeketlen = marado_termeketlen;

        std::cout << "  Eladás után:\n";
        std::cout << "    Termekeny: " << termekeny << "\n";
        std::cout << "    Termeketlen: " << termeketlen << "\n";
    }

    std::cout << "\nÖsszesen szükséges nyúltáp (3 évre): " << total_tap << " zsák\n";

    return 0;
}
