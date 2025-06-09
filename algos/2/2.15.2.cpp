
// 2.15.2. Határozza meg az eredeti és a konvertált értékek közötti 
// különbségeket! 

#include <iostream>
#include <iomanip>

int main() {
    double number;

    std::cout << "Mennyi legyen a szam? ";
    std::cin >> number;

    float floatVal = static_cast<float>(number);
    int intVal = static_cast<int>(number);
    short shortVal = static_cast<short>(number);
    char charVal = static_cast<char>(number);

    std::cout << std::fixed << std::setprecision(10);

    std::cout << "Double - float: " << number - floatVal << "\n";
    std::cout << "Double - int:   " << number - intVal << "\n";
    
    std::cout << std::setprecision(2); // csak a további kettőnél legyen 2 jegy
    std::cout << "Double - short: " << number - shortVal << "\n";
    std::cout << "Double - char:  " << number - static_cast<int>(charVal) << "\n";

    return 0;
}
