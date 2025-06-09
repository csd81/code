
// 3.16.2. Alakítsa át úgy az előző programot, hogy függvényben kérje 
// be tömb méretet és ott hozza azt létre!  
// 3.16.2.


#include <iostream>
#include <vector>
#include <iomanip>

// A tömb létrehozása és feltöltése
std::vector<double> allocArray(int& size) {
    std::cout << "\nArray size: ";
    std::cin >> size;

    std::vector<double> result(size);
    for (int i = 0; i < size; ++i) {
        std::cout << i << ". element: ";
        std::cin >> result[i];
    }

    return result;
}

int main() {
    int size;
    
    // 1. Kezdeti tömb létrehozása
    std::vector<double> array = allocArray(size);

    // 2. Méret duplázása (új elemeket hozzáfűzünk)
    array.resize(size * 2);
    for (int i = size; i < size * 2; ++i) {
        std::cout << i << ". element: ";
        std::cin >> array[i];
    }

    size *= 2; // frissített méret

    // 3. Kiírás
    std::cout << "\nThe full array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << std::fixed << std::setprecision(2) << array[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
