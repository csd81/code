// 2.3.2. Módosítsa az előző programot úgy, hogy az oldalak hossza tört 
// érték is lehessen! A program elején kérje be, hogy négyzet vagy 
// téglalapot vizsgál-e és ennek függvényében kérjen be egy vagy két oldal 
// hosszat! 

#include <iostream>
#include <limits>

int main() {
    char figure, property;
    double a = 0.0, b = 0.0;

    std::cout << "Program to calculate the area or perimeter of a rectangle or square.\n";
    std::cout << "Calculate rectangle (r) or square (s)? ";
    std::cin >> figure;

    if (figure == 'r') {
        std::cout << "a = ";
        std::cin >> a;
        std::cout << "b = ";
        std::cin >> b;

        if (a <= 0 || b <= 0) {
            std::cerr << "Side lengths must be positive.\n";
            return 1;
        }

        std::cout << "Would you like to calculate area (a) or perimeter (p)? ";
        std::cin >> property;

        if (property == 'a') {
            std::cout << "The area of the rectangle is: " << a * b << "\n";
        } else if (property == 'p') {
            std::cout << "The perimeter of the rectangle is: " << 2 * (a + b) << "\n";
        } else {
            std::cerr << "Invalid choice. Use 'a' for area or 'p' for perimeter.\n";
            return 1;
        }

    } else if (figure == 's') {
        std::cout << "a = ";
        std::cin >> a;

        if (a <= 0) {
            std::cerr << "Side length must be positive.\n";
            return 1;
        }

        std::cout << "Would you like to calculate area (a) or perimeter (p)? ";
        std::cin >> property;

        if (property == 'a') {
            std::cout << "The area of the square is: " << a * a << "\n";
        } else if (property == 'p') {
            std::cout << "The perimeter of the square is: " << 4 * a << "\n";
        } else {
            std::cerr << "Invalid choice. Use 'a' for area or 'p' for perimeter.\n";
            return 1;
        }

    } else {
        std::cerr << "Invalid shape selection. Use 'r' for rectangle or 's' for square.\n";
        return 1;
    }

    return 0;
}
