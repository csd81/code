// 2.8. Formázott kimenet
// 2.8.1. printf segítségével írja ki a következő sorokat, úgy hogy 
// változókban tárolja az egyes értékeket! A szóközt „_”-al jelöljük. 
// A kiírandó szöveg: _+12.45 _-234.1 +57967.2 +134567 
// 2.8.1.


#include <iostream>
#include <iomanip>

int main() {
    float a = 12.45f;
    float b = -234.1f;
    float c = 57967.2f;
    float d = 134567.0f;

    // %+7.2f → szélesség 7, 2 tizedes, mindig előjel
    std::cout << std::setw(7) << std::showpos << std::fixed << std::setprecision(2) << a << "\n";

    // %7.1f → szélesség 7, 1 tizedes, negatív miatt - ott van
    std::cout << std::setw(7) << std::noshowpos << std::fixed << std::setprecision(1) << b << "\n";

    // %+8.1f → szélesség 8, 1 tizedes, mindig előjel
    std::cout << std::setw(8) << std::showpos << std::fixed << std::setprecision(1) << c << "\n";

    // %+6.0f → szélesség 6, 0 tizedes, mindig előjel
    std::cout << std::setw(6) << std::showpos << std::fixed << std::setprecision(0) << d << "\n";

    return 0;
}
