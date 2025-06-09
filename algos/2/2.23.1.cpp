// 2.23. continue, break
// 2.23.1. Írjon programot, amely osztást végez el egy hátul tesztelős 
// ciklusban! Használjon végtelen ciklust, amelyet majd break paranccsal fog 
// megszakítani! Kérje be a két változót! Ha az osztandó abszolút értéke 
// nagyobb, mint 100, akkor hiba üzenet után hajtsa végre a következő 
// iterációt! Ha az osztó értéke 0, akkor szakítsa meg a ciklust! Szintén 
// szakítsa meg a ciklust, ha már három osztást elvégzett! 
// 2.23.1.
 
#include <iostream>
#include <cmath>

int main() {
    int count = 0;
    float x, y;

    while (true) {
        std::cout << "x = ";
        std::cin >> x;
        std::cout << "y = ";
        std::cin >> y;

        if (std::fabs(x) > 100.0f) {
            std::cout << "x is too big!\n\n";
            continue;
        }

        if (y == 0.0f) {
            std::cout << "y equals 0!\n";
            break;
        }

        std::cout << x << " / " << y << " = " << (x / y) << "\n\n";

        count++;
        if (count == 3) {
            break;
        }
    }

    return 0;
}
