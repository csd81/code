// 3.5.2. Oldja meg, hogy az utolsó szám után ne jelenjen meg vessző a 
// kiírásnál és hogy a tömb nagyságát szabadon lehessen meghatározni! 
// 3.5.2.

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    int size;
    std::cout << "Size of array? ";
    std::cin >> size;

    std::vector<float> tomb(size);

    for (int i = 0; i < size; ++i) {
        tomb[i] = std::sqrt(static_cast<float>(i));
    }

    std::cout << std::fixed << std::setprecision(4);

    for (int i = 0; i < size; ++i) {
        std::cout << tomb[i];
        if (i != size - 1)
            std::cout << ", ";
    }
    std::cout << "\n";

    return 0;
}
