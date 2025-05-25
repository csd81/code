// 2.1.2. Kérjen be pontszámot, amelynek -25 és 50 közé kell esnie! A vizsga 
// sikerességét csak akkor vizsgálja, ha a pontszám a helyes intervallumban 
// van! A siker feltétele a 25 pontnál jobb eredmény. 
// 2.1.2.

 
// 2.1.2. Kérjen be pontszámot, amely -25 és 50 közé kell essen!
// A vizsga sikeres, ha a pontszám > 25.

#include <iostream>
#include <limits>  // std::numeric_limits

int main() {
    float result;

    std::cout << "Add meg a pontszámot (-25 és 50 között): ";
    std::cin >> result;

    // Ellenőrizzük, hogy a bemenet valid és az intervallumban van-e
    if (std::cin.fail()) {
        std::cerr << "Hibás bemenet! Számot kellett volna megadni.\n";
        return 1;
    }

    if (result >= -25.0f && result <= 50.0f) {
        if (result > 25.0f) {
            std::cout << "A vizsga SIKERES.\n";
        } else {
            std::cout << "A vizsga SIKERTELEN.\n";
        }
    } else {
        std::cout << "A megadott pontszám kívül esik a megengedett tartományon!\n";
    }

    return 0;
}
