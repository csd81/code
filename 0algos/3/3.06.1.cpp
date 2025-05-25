// 3.6. Tömb reprezentálása
// 3.6.1. A karakteres képernyőn reprezentáljon egy 4 hosszú egész tömböt! 
// Kérje be a tömb elemeit és írja ki az értékeket '*' szimbólumokból 
// készített négyzetekbe! Adja meg az egyes elemek indexeit és címeit! Írja 
// ki a tömb mint mutató értékét és annak a címét! 
// 3.6.1.


#include <iostream>
#include <iomanip>

int main() {
    const int size = 4;
    int tomb[size];

    // 1. Értékek bekérése
    for (int i = 0; i < size; ++i) {
        std::cout << "The " << i << ". value: ";
        std::cin >> tomb[i];
    }

    // 2. Felső csillagsor (keret)
    std::cout << std::setw(20) << " ";
    for (int i = 0; i < size; ++i) {
        std::cout << std::string(12, '*');
    }
    std::cout << "\n";

    // 3. Értékek sor keretben
    std::cout << std::setw(20) << " ";
    for (int i = 0; i < size; ++i) {
        std::cout << "*" << std::setw(10) << tomb[i] << "*";
    }
    std::cout << "\n";

    // 4. Alsó csillagsor (keret)
    std::cout << std::setw(20) << " ";
    for (int i = 0; i < size; ++i) {
        std::cout << std::string(12, '*');
    }
    std::cout << "\n";

    // 5. Indexek
    std::cout << std::setw(20) << "index: ";
    for (int i = 0; i < size; ++i) {
        std::cout << std::left << std::setw(13) << i;
    }
    std::cout << "\n";

    // 6. Címek (elemek)
    std::cout << std::setw(20) << "address: ";
    for (int i = 0; i < size; ++i) {
        std::cout << std::left << std::setw(13) << static_cast<const void*>(&tomb[i]);
    }
    std::cout << "\n";

    // 7. A tömb mutatóként és címként
    std::cout << std::setw(20) << "tomb: " << static_cast<const void*>(tomb) << "\n";
    std::cout << std::setw(20) << "&tomb: " << static_cast<const void*>(&tomb) << "\n";

    // 8. Tömb mérete
    std::cout << std::setw(20) << "tomb size: " << size << "\n";

    return 0;
}
