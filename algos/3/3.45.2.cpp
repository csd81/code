// 3.45.2. Bővítse ki az előző programot úgy, hogy 0 végjelig olvassa be a 
// jegyeket és úgy végzi el a számolást! 

// 3.45.3. Fejlessze tovább a programot úgy, hogy a jegyek szórását is 
// meghatározza! Határozza meg az egyes jegyek átlagtól való eltérésit, 
// utána ezen eltérések négyezeteinek az átlagát, majd az így kapott 
// eredmény gyökét! 

// 3.45.2-3.45.3.


#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    std::vector<int> jegyek;
    int jegy, i = 1;
    int osszeg = 0;

    std::cout << "Jegyek beolvasása (0 végjelig):\n";
    do {
        std::cout << i++ << ". jegy: ";
        std::cin >> jegy;
        if (jegy > 0) {
            jegyek.push_back(jegy);
            osszeg += jegy;
        }
    } while (jegy > 0);

    if (jegyek.empty()) {
        std::cout << "Nincsenek érvényes jegyek!\n";
        return 0;
    }

    double atlag = static_cast<double>(osszeg) / jegyek.size();

    // Szórás számítása
    double elteres_osszeg = 0.0;
    for (int j : jegyek) {
        elteres_osszeg += std::pow(j - atlag, 2);
    }

    double szoras = std::sqrt(elteres_osszeg / jegyek.size());

    // Eredmények kiírása
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nA jegyek számtani átlaga: " << atlag << '\n';
    std::cout << "A jegyek szórása: " << szoras << '\n';

    return 0;
}
