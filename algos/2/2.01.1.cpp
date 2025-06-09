// 2.1.1. Írjon programot, amely bekéri egy vizsga eredményének százalékos 
// értékét és kiírja, hogy sikeres volt-e a vizsga! A siker feltétele az 
// 50%-nál jobb teljesítmény. Ötlet: ügyeljen arra, hogy az 50% még bukást 
// jelent! 
 
 
#include <iostream>
#include <iomanip>

int main() {
    double result;

    std::cout << "Enter exam result (in %): ";
    std::cin  >> result;

    if (!std::cin) {
        std::cerr << "Invalid input!\n";
        return 1;
    }

    // 50.0% is still a fail; must be >50.0 to pass
    if (result > 50.0) {
        std::cout << "Passed\n";
    } else {
        std::cout << "Failed\n";
    }

    return 0;
}
 