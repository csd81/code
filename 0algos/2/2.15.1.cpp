// 2.15. Típuskonverzió
// 2.15.1. Írjon programot, amely bekér egy double értéket kiírja az eredeti 
// értéket a float, int, short int, char típussá konvertált változatok 
// nagyságát és értékeit! A változók méretei jobbra legyenek rendezve és 
// az értékek kiírása azonos oszlopban kezdődjön! 

#include <iostream>
#include <iomanip>
#include <limits>

int main() {
    double doubleValue;

    std::cout << std::fixed << std::setprecision(20);
    std::cout << std::setw(20) << "doubleValue = ";
    std::cin >> doubleValue;

    float floatValue = static_cast<float>(doubleValue);
    int intValue = static_cast<int>(floatValue);
    short shortIntValue = static_cast<short>(intValue);
    char charValue = static_cast<char>(shortIntValue);

    std::cout << std::setw(20) << "size of double = " << std::setw(2) << sizeof(doubleValue)
              << "  doubleValue = " << std::setw(25) << doubleValue << "\n";

    std::cout << std::setw(20) << "size of float = " << std::setw(2) << sizeof(floatValue)
              << "  floatValue = " << std::setw(25) << floatValue << "\n";

    std::cout << std::setw(20) << "size of int = " << std::setw(2) << sizeof(intValue)
              << "  intValue = " << std::setw(25) << intValue << "\n";

    std::cout << std::setw(20) << "size of short int = " << std::setw(2) << sizeof(shortIntValue)
              << "  shortIntValue = " << std::setw(25) << shortIntValue << "\n";

    std::cout << std::setw(20) << "size of char = " << std::setw(2) << sizeof(charValue)
              << "  charValue = " << std::setw(25) << static_cast<int>(charValue) << "\n";

    return 0;
}
