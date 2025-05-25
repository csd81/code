// 2.32. Ventilátor
// 2.32.1. Írjon programot, amelyben létrehoz egy ventilátor típust: gyártó 
// (statikus tömb), termékszám, leírás (dinamikus tömb), ár! Írjon 
// függvényt, amely bekéri az adattagok értékét és a rekordot 
// visszatérési értékként adja vissza! Szintén írjon függvényt a 
// struktúra kiírásához!
// 2.32.1.



#include <iostream>
#include <string>
#include <limits>    // ide kell a numeric_limits
#include <iomanip>   // ide kell a fixed és setprecision

struct Fan {
    std::string manufacturer;
    int productNumber;
    std::string description;
    float price;
};

Fan readFan() {
    Fan rec;
    std::cout << "Provide the data of the fan!\n";

    std::cout << "manufacturer: ";
    std::getline(std::cin, rec.manufacturer);

    std::cout << "product number: ";
    std::cin >> rec.productNumber;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "description: ";
    std::getline(std::cin, rec.description);

    std::cout << "price: ";
    std::cin >> rec.price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return rec;
}

void printFan(const Fan& rec) {
    std::cout << "\nFan data\n";
    std::cout << "manufacturer:   " << rec.manufacturer  << "\n";
    std::cout << "product number: " << rec.productNumber << "\n";
    std::cout << "description:    " << rec.description   << "\n";
    std::cout << "price:          "
              << std::fixed << std::setprecision(2)
              << rec.price << " HUF\n";
}

int main() {
    Fan myFan = readFan();
    printFan(myFan);
    return 0;
}
