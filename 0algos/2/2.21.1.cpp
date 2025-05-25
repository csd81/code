// 2.21. Legnagyobb közös osztó
// 2.21.1. Írjon programot, amely kiszámolja két szám legnagyobb közös 
// osztóját a következő algoritmus segítségével! ciklus amíg a két szám 
// nem egyenlő a nagyobb szám értékét csökkentsük a kisebb számmal 
// 2.21.1.

#include <iostream>

int main() {
    int x, y;

    std::cout << "Give me the first number: ";
    std::cin >> x;

    std::cout << "Give me the second number: ";
    std::cin >> y;

    while (x != y) {
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }

    std::cout << "The greatest common divisor: " << x << std::endl;

    return 0;
}

