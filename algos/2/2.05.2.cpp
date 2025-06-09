// 2.5.2. Határozza meg az összeadás, szorzás, osztás, hatványozás 
// időigényét úgy, hogy az előző program legbelsejébe beírja a megfelelő 
// utasítást!
 

#include <iostream>
#include <chrono>
#include <cmath>

int main() {
    constexpr int size = 1000;
    int a;
    int b = 2364;
    int c = 9754;

    // Összeadás mérése
    auto start_add = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                a = b + c;
            }
        }
    }
    auto end_add = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_add = end_add - start_add;
    std::cout << "Addition time: " << duration_add.count() << " seconds\n";


    // Szorzás mérése
    auto start_mul = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                a = b * c;
            }
        }
    }
    auto end_mul = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_mul = end_mul - start_mul;
    std::cout << "Multiplication time: " << duration_mul.count() << " seconds\n";


    // Osztás mérése
    auto start_div = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                a = b / c;
            }
        }
    }
    auto end_div = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_div = end_div - start_div;
    std::cout << "Division time: " << duration_div.count() << " seconds\n";


    // Hatványozás mérése
    auto start_pow = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                a = std::pow(b, 2);  // vagy pow(b, c); de az drágább
            }
        }
    }
    auto end_pow = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_pow = end_pow - start_pow;
    std::cout << "Exponentiation time (pow): " << duration_pow.count() << " seconds\n";

    return 0;
}
