// 2.19. Háromszög
// 2.19.1. Rajzoljon ki a karakteres képernyőre egy derékszögű, egyenlő 
// szárú háromszöget csillagokból dupla for ciklus segítségével! 
// 2.19.1.


#include <iostream>

int main() {
    int size = 15;

    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}
