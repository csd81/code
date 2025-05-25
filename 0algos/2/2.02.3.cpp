// 2.2.3. Egy adott sor kirajzolásához is használjon ciklust! Keresse meg egy 
// sor ismétlődő mintáját és az kerüljön a ciklus magjába! Figyeljen 
// különösen a fejlécek helyes megjelenítésére. 
// 2.2.3.

#include <iostream>

constexpr int SIZE = 8;

int main() {
    // Fejléc: oszlopbetűk
    std::cout << "  |";
    for (char col = 'a'; col < 'a' + SIZE; ++col) {
        std::cout << col << " |";
    }
    std::cout << "\n";

    // Fejléc alatti elválasztó
    std::cout << " -|";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "--|";
    }

    // Táblázat sorai
    for (int row = 0; row < SIZE; ++row) {
        std::cout << "\n " << row + 1 << "|";
        for (int col = 0; col < SIZE; ++col) {
            std::cout << "  |";
        }

        // Sor alatti elválasztó
        std::cout << "\n -|";
        for (int i = 0; i < SIZE; ++i) {
            std::cout << "--|";
        }
    }

    std::cout << "\n";
    return 0;
}
