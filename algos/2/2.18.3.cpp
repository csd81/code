// 2.18.3. Valósítsa meg a visszafele történő konverziót! 
// 2.18.3.


#include <iostream>
#include <string>
#include <vector>

std::string arabicToRoman(int number) {
    std::vector<std::pair<int, std::string>> romanMap = {
        {1000, "M"}, {900, "CM"},
        {500, "D"},  {400, "CD"},
        {100, "C"},  {90, "XC"},
        {50, "L"},   {40, "XL"},
        {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},
        {1, "I"}
    };

    std::string result;

    for (const auto& pair : romanMap) {
        while (number >= pair.first) {
            result += pair.second;
            number -= pair.first;
        }
    }

    return result;
}

int main() {
    int number;

    std::cout << "Arabic number (1–4999): ";
    std::cin >> number;

    if (number < 1 || number > 4999) {
        std::cerr << "Number out of range!\n";
        return 1;
    }

    std::string roman = arabicToRoman(number);
    std::cout << "Roman numeral: " << roman << "\n";

    return 0;
}
