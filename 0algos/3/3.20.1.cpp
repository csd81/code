
// // 3.20.1. Írjon programot két nagyon nagy pozitív egész szám 
// összeadására! A számok legfeljebb 100 jegyűek. Írja ki a képernyőre a 
// két számot, majd az összegüket, a következő formátumban. A két számot 
// fájlból olvassa be, a számok szóközzel vannak elválasztva. A számokat 
// statikus karaktertömbökben tárolja! Példa bemenet: 434234643643746 
// 575434253245430 Kimenet: 434234643643746 + 575434253245430 = 1009668896889176 
// 3. 
// 3.20.1.


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

const int MAX_NUMBER_LENGTH = 101;
const std::string INPUT_FILE = "numbers.txt";

// Egyjegyű karakterek összeadása '0'-hoz viszonyítva
char addDigit(char a, char b, char carry, char& nextCarry) {
    int sum = (a - '0') + (b - '0') + (carry - '0');
    nextCarry = (sum >= 10) ? '1' : '0';
    return (sum % 10) + '0';
}

std::string addBigNumbers(const std::string& num1, const std::string& num2) {
    std::string a = num1;
    std::string b = num2;

    // Igazítsuk a rövidebb stringet nullákkal
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;

    std::string result(a.length() + 1, '0');
    char carry = '0';

    for (int i = a.length() - 1; i >= 0; --i) {
        char nextCarry = '0';
        result[i + 1] = addDigit(a[i], b[i], carry, nextCarry);
        carry = nextCarry;
    }

    result[0] = carry;
    if (result[0] == '0') {
        result.erase(0, 1); // ha nincs értelme az első '0'-nak, töröljük
    }

    return result;
}

int main() {
    std::ifstream file(INPUT_FILE);
    if (!file) {
        std::cerr << "Error opening file: " << INPUT_FILE << "\n";
        return 1;
    }

    std::string num1, num2;
    file >> num1 >> num2;

    std::string sum = addBigNumbers(num1, num2);

    std::cout << num1 << " + " << num2 << " = " << sum << "\n";

    return 0;
}
