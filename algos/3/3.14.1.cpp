// 3.14. Sztring kivonás
// 3.14.1. Írjon programot, amely egy sztringből kivon egy másikat! 
// Például: almafavirág - fa = almavirág. Ha a második paraméter nincs az 
// elsőben, akkor ne változzon az első paraméter érétke! 
// 3.14.1.

#include <iostream>
#include <string>

// kivonás függvény
void subtract(std::string& from, const std::string& what) {
    size_t pos = from.find(what);
    if (pos != std::string::npos) {
        from.erase(pos, what.length());
    }
}

int main() {
    std::string from, what;

    std::cout << "Subtract from: ";
    std::cin >> from;

    std::cout << "Subtract what: ";
    std::cin >> what;

    subtract(from, what);

    std::cout << "\nThe reduced word is: " << from << "\n";

    return 0;
}

