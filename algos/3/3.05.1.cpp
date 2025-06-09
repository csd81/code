// 3.5.1. Írjon programot, amelyben egy 5 hosszú statikus float tömb minden 
// elemébe a hozzátartozó index gyökét írja be! Használjon for ciklust az 
// egyes elemek eléréséhez és az eredmény kiírásához! Az egyes értékek 
// vesszővel legyenek elválasztva! 
// 3.5.1


#include <iostream>
#include <array>
#include <cmath>
#include <iomanip>

int main() {
    std::array<float, 5> tomb;

    // 1. feltöltés index gyökeivel
    for (size_t i = 0; i < tomb.size(); ++i) {
        tomb[i] = std::sqrt(static_cast<float>(i));
    }

    // 2. kiírás vesszőkkel
    std::cout << std::fixed << std::setprecision(4);
    for (size_t i = 0; i < tomb.size(); ++i) {
        std::cout << tomb[i];
        if (i < tomb.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;

    return 0;
}
