// 3.12.1. Készítsen magánhangzó statisztikát egy bekért sorról! A 
// magánhangzó kis és nagy betűs alakját nem különböztetjük meg, csak az 
// angol magánhangzókat tekintjük. 
// 3.12.1.


#include <iostream>
#include <string>
#include <cctype>
#include <map>

int main() {
    std::string line;
    std::cout << "text=\n";
    std::getline(std::cin, line);

    std::map<char, int> vowelCount = {
        {'A', 0}, {'E', 0}, {'I', 0}, {'O', 0}, {'U', 0}
    };

    for (char ch : line) {
        char upper = std::toupper(static_cast<unsigned char>(ch));
        if (vowelCount.count(upper)) {
            vowelCount[upper]++;
        }
    }

    std::cout << "\nVowel statistics:\n";
    for (const auto& pair : vowelCount) {
        std::cout << " " << static_cast<char>(std::tolower(pair.first)) << "," << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
