// 2.24.3. Tetszőleges negyed-fokú polinomnak határozza meg a deriváltját 
// adott pontban! Legyen a függvénynek egy harmadik paramétere, ahol jelezzük, 
// ha hiba történt, vagyis ha az első paraméter értéke helytelen, vagyis 
// négynél nagyobb! 
// 2.24.3.

#include <iostream>
#include <cmath>
#include <iomanip>

float deriv(int order, float x, float a4, float a3, float a2, float a1, float a0, bool& error) {
    error = false;

    switch (order) {
        case 1:
            return 4 * a4 * std::pow(x, 3) + 3 * a3 * std::pow(x, 2) + 2 * a2 * x + a1;
        case 2:
            return 12 * a4 * std::pow(x, 2) + 6 * a3 * x + 2 * a2;
        case 3:
            return 24 * a4 * x + 6 * a3;
        case 4:
            return 24 * a4;
        default:
            error = true;
            return 0.0f;
    }
}

int main() {
    float a4, a3, a2, a1, a0, x;
    int order;

    std::cout << "Enter the coefficients of the polynomial:\n";
    std::cout << "x^4: "; std::cin >> a4;
    std::cout << "x^3: "; std::cin >> a3;
    std::cout << "x^2: "; std::cin >> a2;
    std::cout << "x^1: "; std::cin >> a1;
    std::cout << "constant: "; std::cin >> a0;

    std::cout << "\nYou entered: ";
    bool printed = false;
    if (a4) { std::cout << a4 << "x^4 "; printed = true; }
    if (a3) { std::cout << (printed ? "+ " : "") << a3 << "x^3 "; printed = true; }
    if (a2) { std::cout << (printed ? "+ " : "") << a2 << "x^2 "; printed = true; }
    if (a1) { std::cout << (printed ? "+ " : "") << a1 << "x "; printed = true; }
    if (a0) { std::cout << (printed ? "+ " : "") << a0; }
    if (!printed) { std::cout << "0"; }
    std::cout << "\n";

    std::cout << "\nWhich derivative (1–4)? ";
    std::cin >> order;

    std::cout << "Where do you want to evaluate it (x)? ";
    std::cin >> x;

    bool error = false;
    float result = deriv(order, x, a4, a3, a2, a1, a0, error);

    if (error) {
        std::cerr << "Error: only derivatives 1 to 4 are supported.\n";
    } else {
        std::cout << "The " << order << ". derivative at x = "
                  << std::fixed << std::setprecision(2) << x
                  << " is: " << std::setprecision(6) << result << "\n";
    }

    return 0;
}
