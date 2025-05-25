// 2.38. Szövegfájl
// 2.38.1. Írjon programot, amely bekéri a következő információkat: 
// minimális érték, maximális érték fájl név, adatok száma! Generáljon 
// adott számú véletlen számot a megfelelő határok között és mentse el 
// azokat egy szövegfájlba külön sorokba! 
// 2.38.1.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
    std::string fileName;
    int min, max, count;

    std::cout << "This program will save random numbers into a text file.\n";
    std::cout << "File name: ";
    std::cin >> fileName;
    std::cout << "Minimum number: ";
    std::cin >> min;
    std::cout << "Maximum number: ";
    std::cin >> max;
    std::cout << "Number of values to generate: ";
    std::cin >> count;

    if (min > max) {
        std::cerr << "Error: min cannot be greater than max.\n";
        return 1;
    }

    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "Error: cannot open file for writing.\n";
        return 1;
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < count; ++i) {
        int value = std::rand() % (max - min + 1) + min;
        outFile << value << '\n';
    }

    outFile.close();
    std::cout << "Random numbers saved successfully to '" << fileName << "'.\n";

    return 0;
}
