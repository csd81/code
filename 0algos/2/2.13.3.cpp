// 2.13.3. Folytassa az előző programot úgy, hogy bekér még két bit 
// pozíciót! Az elsőnél törölje a bitet a másodiknál negálja. Minden 
// részeredményt írjon ki a képernyőre! 
// 2.13.3.


#include <iostream>
#include <bitset>
#include <limits>

constexpr int SIZE = 8;

void printBinary(const std::string& label, std::bitset<SIZE> bits) {
    std::cout << label << ": " << bits << " (decimal: " << bits.to_ulong() << ")\n";
}

int main() {
    unsigned int input;
    std::cout << "Enter a number (0-255): ";
    std::cin >> input;

    if (input > 255) {
        std::cerr << "Invalid input. Must be 0–255.\n";
        return 1;
    }

    std::bitset<SIZE> bits(input);
    printBinary("Original", bits);

    // 1. Bekérjük a pozíciót, ahol 1-re állítjuk a bitet (1 = legalsó)
    int setPosition;
    std::cout << "Enter a bit position to SET to 1 (1-8): ";
    std::cin >> setPosition;

    if (setPosition < 1 || setPosition > 8) {
        std::cerr << "Invalid position.\n";
        return 1;
    }

    bits.set(setPosition - 1, true);
    printBinary("After SET", bits);

    // 2. Bekérjük a törlendő és negálandó bitek pozícióját
    int deletePos, negatePos;
    std::cout << "Enter two positions: first to DELETE, second to NEGATE (1-8): ";
    std::cin >> deletePos >> negatePos;

    if (deletePos < 1 || deletePos > 8 || negatePos < 1 || negatePos > 8) {
        std::cerr << "Invalid positions.\n";
        return 1;
    }

    // 3. Bit törlés: balra shifteljük az összes bitet a megadott pozíció felett
    std::bitset<SIZE> deletedBits;
    int j = SIZE - 1;
    for (int i = SIZE - 1; i >= 0; --i) {
        if (i == deletePos - 1) continue;  // kihagyjuk a törlendő bitet
        if (j >= 1) {
            deletedBits[j - 1] = bits[i];
            --j;
        }
    }
    printBinary("After DELETE", deletedBits);

    // 4. Bit negálás
    int negateIndex = negatePos - 1;
    if (negateIndex < 7) {
        deletedBits.flip(negateIndex);
    }
    printBinary("After DELETE + NEGATE", deletedBits);

    return 0;
}
