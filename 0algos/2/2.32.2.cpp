// 2.32.2. Módosítsa úgy a programot, hogy a ventilátor változó értékét 
// tegye egyenlővé egy másik változóval, módosítsa az eredeti változóban 
// a gyártót és a leírást! Írassa ki újból mindkét struktúrát! Milyen 
// furcsaságot tapasztal? Hogy lehet azt korrigálni? 
// 2.32.2.


#include <iostream>
#include <string>
#include <limits>    // for std::numeric_limits
#include <iomanip>   // for std::fixed, std::setprecision

struct Fan {
    std::string manufacturer;
    int         productNumber;
    std::string description;
    float       price;
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
    std::cout << "\nFan data\n"
              << "manufacturer:   " << rec.manufacturer  << "\n"
              << "product number: " << rec.productNumber << "\n"
              << "description:    " << rec.description   << "\n"
              << "price:          "
              << std::fixed << std::setprecision(2)
              << rec.price << " HUF\n";
}

int main() {
    Fan fan1 = readFan();
    Fan fan2 = fan1;  // deep copy of std::string fields

    // Modify the original
    fan1.manufacturer = "NewManufacturer";
    fan1.description  = "A completely new description";

    std::cout << "\n== Fan 1 ==\n";
    printFan(fan1);

    std::cout << "\n== Fan 2 ==\n";
    printFan(fan2);

    return 0;
}
