// 3.9. Csúsztatás
// 3.9.1. Írjon függvényt, amely 3 cím szerint átadott float paraméter 
// értékét (a, b és c) elcsúsztatja a következő módon: ciklikus eltolás: 
// a → b, b → c, c → a, nem ciklikus eltolás: a → b, b → c, 0 → a! 
// Egy negyedik paraméter jelezze, hogy az eltolás ciklikus-e! 
// 3.9.1.


#include <iostream>
#include <iomanip>

// Segédfüggvény az értékek kiírására
void print(float a, float b, float c) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "a=" << a << " b=" << b << " c=" << c << "\n";
}

// Csúsztatás: cyclic==true esetén ciklikus, különben 0-t kap az első
void shift(float& a, float& b, float& c, bool cyclic) {
    float temp = c;
    c = b;
    b = a;
    if (cyclic) a = temp;
    else a = 0.0f;
}

int main() {
    float x1, x2, x3;

    std::cout << "Provide the next number: ";
    std::cin >> x1;
    std::cout << "Provide the next number: ";
    std::cin >> x2;
    std::cout << "Provide the next number: ";
    std::cin >> x3;

    std::cout << "\nOriginal: ";
    print(x1, x2, x3);

    shift(x1, x2, x3, true);
    std::cout << "After cyclic shift: ";
    print(x1, x2, x3);

    shift(x1, x2, x3, false);
    std::cout << "After non-cyclic shift: ";
    print(x1, x2, x3);

    return 0;
}
