// 3.9.2. 3 változó helyett egy 3 elemű tömbön végezze el az 
// elcsúsztatást! 
// 3.9.2.

 
#include <iostream>
#include <array>

void print(const std::array<float, 3>& a) {
    for (size_t i = 0; i < a.size(); ++i)
        std::cout << "a[" << i << "] = " << a[i] << "  ";
    std::cout << "\n";
}

void shift(std::array<float, 3>& a, bool cyclic) {
    float temp = a[2];
    a[2] = a[1];
    a[1] = a[0];
    a[0] = cyclic ? temp : 0.0f;
}

int main() {
    std::array<float, 3> x;

    for (size_t i = 0; i < x.size(); ++i) {
        std::cout << "Provide the next number: ";
        std::cin >> x[i];
    }

    std::cout << "Original: ";
    print(x);

    shift(x, true);
    std::cout << "After cyclic shift: ";
    print(x);

    shift(x, false);
    std::cout << "After non-cyclic shift: ";
    print(x);

    return 0;
}
