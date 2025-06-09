// 2.8.1. printf segítségével írja ki a következő sorokat, úgy hogy 
// változókban tárolja az egyes értékeket! A szóközt „_”-al jelöljük. 
// A kiírandó szöveg: _+12.45 _-234.1 +57967.2 +134567 

#include <iostream>
#include <iomanip>

int main() {
    float a = 12.45f;
    float b = -234.1f;
    float c = 57967.2f;
    float d = 134567.0f;

    // Kiírás formázottan
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "_" << std::showpos << a << " ";
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "_" << b << " ";
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << c << " ";
    
    std::cout << std::fixed << std::setprecision(0);
    std::cout << d << "\n";

    return 0;
}