// 3.13.2. Bővítse úgy a programot, hogy az új sztring egy megfelelően 
// hosszú dinamikus tömbbe kerüljön! Készítse el a visszafele kódoló 
// függvényt! 

// 3.13.2.


#include <iostream>
#include <string>
#include <cctype>
#include <memory>

int main() {
    std::string original;
    std::cout << "Sentence: ";
    std::getline(std::cin, original);

    size_t len = original.length();
    // Dinamikus tömb a feldolgozott karakterekhez (+1 a null terminátor miatt)
    std::unique_ptr<char[]> newVer(new char[len + 1]);

    size_t idxJ = 0;
    for (size_t idxI = 0; idxI < len; ++idxI) {
        char current = std::toupper(original[idxI]);

        if (current != 'V') {
            newVer[idxJ++] = current;
        } else {
            if (idxI + 2 < len &&
                std::toupper(original[idxI]) == std::toupper(original[idxI + 2])) {
                newVer[idxJ++] = std::toupper(original[idxI++]);
                newVer[idxJ++] = std::toupper(original[idxI++]);
                idxI++; // skip 3rd (visszafele kódolt karakter)
            } else {
                // csak kihagyjuk a V-t
            }
        }
    }

    newVer[idxJ] = '\0'; // null-terminátor

    std::cout << newVer.get() << std::endl;

    return 0;
}
