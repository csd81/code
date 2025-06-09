// 3.16. Tömbnövelés

// 3.16.1. Írjon programot, amely bekéri egy tömb méretét, lefoglalja a 
// helyet a tömb számára és feltölti elemekkel! Növelje meg a tömb 
// méretét duplájára úgy, hogy létrehoz egy új tömböt, és belemásolja a 
// régi tömböt! Töltse fel a maradék helyet is új értékekkel! 
// 3.16.1.


#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int size;
    std::cout << "Array size: ";
    std::cin >> size;

    std::vector<double> array(size);

    // 1. Elemek bekérése
    for (int i = 0; i < size; ++i) {
        std::cout << i << ". element: ";
        std::cin >> array[i];
    }

    // 2. Méret duplázása
    int oldSize = size;
    size *= 2;
    array.resize(size);

    // 3. Új elemek feltöltése
    for (int i = oldSize; i < size; ++i) {
        std::cout << i << ". element: ";
        std::cin >> array[i];
    }

    // 4. Kiírás (opcionális)
    std::cout << "\nThe full array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << std::fixed << std::setprecision(2) << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
