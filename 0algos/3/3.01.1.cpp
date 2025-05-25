//  3. Tömbök és mátrixok feladatai 
// 3.1. Egy sztring címei
/* 3.1.1. Készítsünk programot, amely bekér egy legfeljebb 6 karakter 
hosszú sztringet és a karakteres képernyőn megjeleníti azt úgy, hogy 
kiírja az egyes karakterek értékeit, karakteresen és ASCII kóddal 16-os 
számrendszerben, valamint kiírja az egyes karakter változóknak a neveit és 
ezeknek a címeit. Ötlet mutatók kiírásához használja a %p-t!  
*/

#include <iostream>
#include <iomanip>   // std::hex, std::setw
#include <string>

int main() {
    const int size = 6;
    char str[size + 1] = {};  // +1 a nullterminátor miatt

    std::cout << "string = ";
    std::cin >> std::setw(size + 1) >> str; // maximum 6 karakter

    std::cout << "The string is: " << str << '\n';

    std::cout << "The static string address, str: " << static_cast<void*>(str) << '\n';
    std::cout << "The dynamic string address, &str: " << static_cast<void*>(&str) << '\n';

    std::cout << "\nCharacters: ";
    for (int i = 0; i < size; ++i) {
        std::cout << '\'' << str[i] << "' ";
    }

    std::cout << "\nASCII (hex): ";
    for (int i = 0; i < size; ++i) {
        if (str[i] == '\0') std::cout << "0x";
        std::cout << "0x" << std::hex << std::uppercase
                  << static_cast<int>(static_cast<unsigned char>(str[i])) << ' ';
    }

    std::cout << std::dec << "\nVariable names: ";
    for (int i = 0; i < size; ++i) {
        std::cout << "str[" << i << "] ";
    }

    std::cout << "\nAddresses: ";
    for (int i = 0; i < size; ++i) {
        std::cout << static_cast<void*>(&str[i]) << ' ';
    }

    std::cout << '\n';
    return 0;
}
