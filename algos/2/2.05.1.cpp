// 2.5. Sebességmérés
// 2.5.1. Egymásba ágyazott ciklusok segítségével határozza meg, hogy hány 
// üres iteráció tesz ki egy másodpercet, ha a ciklusváltozó egész, illetve 
// ha lebegőpontos! Minden ciklus 1000 lépést tegyen meg! Hány egymásba 
// ágyazott ciklus kell, hogy a végrehajtási idő 5-10 másodperc legyen? 
 

#include <iostream>
#include <chrono>

int main() {
    constexpr int size = 1000;

    // Egész típusú ciklusok
    auto start_int = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                // üres ciklus
            }
        }
    }
    auto end_int = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_int = end_int - start_int;

    std::cout << "Integer loop time: " << duration_int.count() << " seconds\n";

    // Lebegőpontos típusú ciklusok
    auto start_float = std::chrono::high_resolution_clock::now();
    for (float i = 0; i < size; ++i) {
        for (float j = 0; j < size; ++j) {
            for (float k = 0; k < size; ++k) {
                // üres ciklus
            }
        }
    }
    auto end_float = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_float = end_float - start_float;

    std::cout << "Floating-point loop time: " << duration_float.count() << " seconds\n";

    return 0;
}
