// 2.8.2. Az előző feladathoz hasonlóan írassuk ki a következő sorokat: _ 
// _+235 _-1.291E4 00026 0XAB2 1.64e-003 
// 2.8.2.


#include <iostream>
#include <iomanip>

int main() {
    int a = 235;
    int c = 26;
    int d = 2 * 1 + 11 * 16 + 10 * 16 * 16; // 0xAB2
    float b = -12910.0f;
    float e = 0.00164f;

    // %+6d → előjeles, 6 széles
    std::cout << std::setw(6) << std::showpos << a << std::endl;

    // %12.3E → 12 széles, 3 tizedesjegy, nagy E
    std::cout << std::setw(12) << std::uppercase << std::scientific << std::setprecision(3) << b << std::endl;

    // %05d → 5 karakter, nullával feltöltve
    std::cout << std::setfill('0') << std::setw(5) << std::noshowpos << std::dec << c << std::endl;

    // %#X → hexadecimális nagybetűkkel, 0X prefix
    std::cout << std::uppercase << std::showbase << std::hex << d << std::endl;

    // %.2e → kis e, 2 tizedesjegy
    std::cout << std::defaultfloat << std::setprecision(2) << std::scientific << std::nouppercase << e << std::endl;

    return 0;
}
