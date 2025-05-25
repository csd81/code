// 2.24. Deriválás
// 2.24.1. Írjon függvényt és hozzá tartozó programot, amely a 3x3-2x2+6x-1 
// függvénynek megadja az 1., 2. vagy 3. deriváltjának az értékét egy adott 
// pontban! A függvény paraméterei: hányadik deriváltról van szó, milyen 
// pontban tekintjük a deriváltat. A függvény visszatérési értéke: a 
// derivált értéke. 
// 2.24.1.


#include <iostream>
#include <iomanip>

float deriv(int whichDerivate, float where) {
    float result;
    switch (whichDerivate) {
        case 1:
            result = 9 * where * where - 4 * where + 6;
            break;
        case 2:
            result = 18 * where - 4;
            break;
        case 3:
            result = 18;
            break;
        default:
            result = 0;
            std::cerr << "Invalid derivative order (" << whichDerivate << "). Only 1, 2, or 3 allowed.\n";
            break;
    }
    return result;
}

int main() {
    float where;

    std::cout << "Where do you want to calculate the derivative? ";
    std::cin >> where;

    for (int i = 1; i <= 4; ++i) {
        float value = deriv(i, where);
        std::cout << "The " << i << ". derivative of 3x^3 - 2x^2 + 6x - 1 at x = "
                  << std::fixed << std::setprecision(2) << where
                  << " is: " << value << '\n';
    }

    return 0;
}
