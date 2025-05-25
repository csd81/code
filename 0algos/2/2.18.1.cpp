// 2.18. Római számok
// 2.18.1. Írjon programot, amely megadja, hogy mik a római számjegyek (I, V, 
// L, C, D, M) arab megfelelői! Kérjen be egy római számjegyet, konvertálja 
// nagybetűre, ha szükséges és adja meg a szám értéket! 
// 2.18.1.

 
#include <iostream>
#include <cctype> // for std::toupper

int main() {
    char romanChar;

    std::cout << "Roman to Arabic number converter\n";
    std::cout << "Give me a Roman numeral character (I, V, X, L, C, D, M): ";
    std::cin >> romanChar;

    romanChar = std::toupper(romanChar);  // Kisbetűből nagybetű

    switch (romanChar) {
        case 'I':
            std::cout << "Arabic: 1\n";
            break;
        case 'V':
            std::cout << "Arabic: 5\n";
            break;
        case 'X':
            std::cout << "Arabic: 10\n";
            break;
        case 'L':
            std::cout << "Arabic: 50\n";
            break;
        case 'C':
            std::cout << "Arabic: 100\n";
            break;
        case 'D':
            std::cout << "Arabic: 500\n";
            break;
        case 'M':
            std::cout << "Arabic: 1000\n";
            break;
        default:
            std::cout << "Wrong character!\n";
            break;
    }

    return 0;
}
