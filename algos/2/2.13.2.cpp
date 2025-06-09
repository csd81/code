// 2.13.2. Kérjen be egy számot és az előző programmal írja ki a kettes 
// számrendszerbeli alakját! Kérjen be egy bit pozíciót és állítsa azt a 
// bitet egyesre! Írja ki az új értéket tízes és kettes számrendszerben is! 
// 2.13.2.

#include <iostream>
#include <bitset>
#include <cmath>     // csak akkor kell, ha pow-ot használnánk, de itt nem fogjuk

constexpr int SIZE = 8;

int main() {
    int input;
    std::cout << "Number = ";
    std::cin >> input;

    // Érvényességellenőrzés
    if (input < 0 || input > 255) {
        std::cerr << "Hibás érték! Csak 0 és 255 közötti számokat fogadunk el.\n";
        return 1;
    }

    unsigned char number = static_cast<unsigned char>(input);
    std::bitset<SIZE> bits(number);

    std::cout << "Its value in system 2: " << bits << "\n";

    // Bitpozíció bekérése
    int position;
    std::cout << "Please enter a position (1 = lowest bit): ";
    std::cin >> position;

    if (position < 1 || position > 8) {
        std::cerr << "Érvénytelen pozíció! Csak 1 és 8 között adhatsz meg pozíciót.\n";
        return 1;
    }

    // Beállítjuk a kívánt bitet 1-re (pozíció 1-től 8-ig, bitset indexe 0-tól)
    bits.set(position - 1, true);

    // Új érték meghatározása
    unsigned char newNumber = static_cast<unsigned char>(bits.to_ulong());

    // Új bináris és decimális érték kiírása
    std::cout << "Here comes the new number in system 2:  " << bits << "\n";
    std::cout << "Here comes the new number in system 10: " << static_cast<int>(newNumber) << "\n";

    return 0;
}
