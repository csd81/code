// 3.4.2. Mi történik, ha a gets és a scanf részeket felcseréljük? 
// Hogyan kezelhető a helyzet? 

#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string string2, string3;

    std::cout << "String input with scanf-like (cin >>): ";
    std::cin >> string3;

    // FONTOS: elfogyasztjuk a maradék sortörést!
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "String input with gets-like (getline): ";
    std::getline(std::cin, string2);

    std::cout << "string3 (scanf style): " << string3 << "\n";
    std::cout << "string2 (gets style): " << string2 << "\n";

    return 0;
}
