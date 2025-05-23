/*
3.45. Jegyek átlaga Aladár év végén szeretné kiszámolni, hogy 
mely tantárgyból hányasra áll. Minden tárgyból sok jegyet szerzett, 
ezért úgy véli, fárasztó munka lenne kézzel átlagokat számolni, ezért 
számítógépes segítséghez folyamodik.

3.45.1. Írjon programot Aladárnak, amely beolvas 10 jegyet, majd kiszámolja 
azok számtani átlagát! 

3.45.1.
*/


#include <iostream>
#include <vector>

constexpr int N = 10;

int main() {
    std::vector<int> jegyek(N);
    int osszeg = 0;

    std::cout << "Kérem a " << N << " jegyet:\n";

    for (int i = 0; i < N; ++i) {
        std::cout << i + 1 << ". jegy: ";
        std::cin >> jegyek[i];
        osszeg += jegyek[i];
    }

    double atlag = static_cast<double>(osszeg) / N;

    std::cout << "A jegyek számtani átlaga: " << atlag << std::endl;

    return 0;
}


