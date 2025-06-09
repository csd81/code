// 2.19.2. Fordítsa el a háromszöget úgy, hogy a másik befogó kerüljön  alulra! 
// 2.19.2.

#include <iostream>

int main() {
    int size = 6;

    for (int i = 0; i < size; ++i) {
        for (int j = 1; j <= size; ++j) {
            if (j <= size - i - 1)
                std::cout << ' ';
            else
                std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}
