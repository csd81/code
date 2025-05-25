// 2.3.3. Bővítse ki a programot úgy, hogy az oldalak hossza csak pozitív 
// érték lehet, síkidomválasztáskor a kis és a nagy betűket is fogadjuk el, 
// ha rossz választ adtunk, akkor az jelezzük, vegyük be a választható idomok 
// közé a szabályos háromszöget!
// 2.3.3.

#include <iostream>
#include <cmath>
#include <cctype>  // tolower

int main() {
    char figure, prop;
    double a = 0.0, b = 0.0;

    std::cout << "Program to calculate the area or perimeter of a rectangle, square or regular triangle.\n";
    std::cout << "Choose a shape - rectangle (r), square (s), triangle (t): ";
    std::cin >> figure;
    figure = std::tolower(figure);

    if (figure == 'r') {
        std::cout << "a = ";
        std::cin >> a;
        std::cout << "b = ";
        std::cin >> b;

        if (a <= 0 || b <= 0) {
            std::cerr << "Error: Side lengths must be positive.\n";
            return 1;
        }

        std::cout << "Calculate area (a) or perimeter (p)? ";
        std::cin >> prop;
        prop = std::tolower(prop);

        if (prop == 'a') {
            std::cout << "The area of the rectangle is: " << a * b << "\n";
        } else if (prop == 'p') {
            std::cout << "The perimeter of the rectangle is: " << 2 * (a + b) << "\n";
        } else {
            std::cerr << "Invalid calculation type. Use 'a' or 'p'.\n";
            return 1;
        }

    } else if (figure == 's') {
        std::cout << "a = ";
        std::cin >> a;

        if (a <= 0) {
            std::cerr << "Error: Side length must be positive.\n";
            return 1;
        }

        std::cout << "Calculate area (a) or perimeter (p)? ";
        std::cin >> prop;
        prop = std::tolower(prop);

        if (prop == 'a') {
            std::cout << "The area of the square is: " << a * a << "\n";
        } else if (prop == 'p') {
            std::cout << "The perimeter of the square is: " << 4 * a << "\n";
        } else {
            std::cerr << "Invalid calculation type. Use 'a' or 'p'.\n";
            return 1;
        }

    } else if (figure == 't') {
        std::cout << "a = ";
        std::cin >> a;

        if (a <= 0) {
            std::cerr << "Error: Side length must be positive.\n";
            return 1;
        }

        std::cout << "Calculate area (a) or perimeter (p)? ";
        std::cin >> prop;
        prop = std::tolower(prop);

        if (prop == 'a') {
            double area = (a * a * std::sqrt(3)) / 4;
            std::cout << "The area of the regular triangle is: " << area << "\n";
        } else if (prop == 'p') {
            std::cout << "The perimeter of the regular triangle is: " << 3 * a << "\n";
        } else {
            std::cerr << "Invalid calculation type. Use 'a' or 'p'.\n";
            return 1;
        }

    } else {
        std::cerr << "Invalid shape selection! Use 'r', 's', or 't'.\n";
        return 1;
    }

    return 0;
}
