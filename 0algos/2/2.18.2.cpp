// 2.18.2. Ne csak egy darab számjegyet, hanem egy több karakterből álló 
// számot alakítson át! 
// 2.18.2.

#include <iostream>
#include <string>
#include <cctype> // for toupper

int romanCharToValue(char ch) {
    switch (ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToArabic(const std::string& roman) {
    int total = 0;
    int prev = 0;

    for (int i = roman.size() - 1; i >= 0; --i) {
        char ch = std::toupper(roman[i]);
        int value = romanCharToValue(ch);

        if (value < prev)
            total -= value;
        else
            total += value;

        prev = value;
    }

    return total;
}

int main() {
    std::string roman;

    std::cout << "Roman number: ";
    std::cin >> roman;

    int result = romanToArabic(roman);
    std::cout << "Arabic value: " << result << "\n";

    return 0;
}
