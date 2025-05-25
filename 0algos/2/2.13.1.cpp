// 2.13.1. Kérjen be egy előjel nélküli karakter típusú változót 
// egészként és írja ki a kettes számrendszerbeli alakját! 
// 2.13.1.

#include <iostream>
#include <bitset>

int main() {
    int input = 0;

    std::cout << "number = ";
    std::cin >> input;

    // Ellenőrizzük, hogy belefér-e az unsigned char tartományába (0–255)
    if (input < 0 || input > 255) {
        std::cerr << "Hibás érték! Csak 0 és 255 közötti számokat fogadunk el.\n";
        return 1;
    }

    unsigned char number = static_cast<unsigned char>(input);
    unsigned char delMask = 0x80;

    std::cout << "Its value in number system 2: ";

    for (int i = 0; i < 8; ++i) {
        unsigned char result = number & delMask;
        std::cout << (result ? 1 : 0);
        delMask >>= 1;
    }

    std::cout << '\n';
    return 0;
}
