// 3.13. Kódolt beszéd
// 3.13.1. Írja meg a „tuvudsz ivigy beveszevelnivi” programot! A kimenet 
// csupa nagybetű legyen! írja meg azt a függvényt, amely eldönti, hogy egy 
// betű magánhangzó-e! 
// 3.13.1.


#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

bool isVowel(char c) {
    static const std::string vowels = "AEIOU";
    return vowels.find(c) != std::string::npos;
}

std::string convertToTuvudsz(const std::string& sentence) {
    std::string result;
    for (char ch : sentence) {
        char upper = std::toupper(ch);
        result += upper;
        if (isVowel(upper)) {
            result += 'V';
            result += upper;
        }
    }
    return result;
}

int main() {
    std::string input;
    std::cout << "sentence = \n";
    std::getline(std::cin, input);

    std::string transformed = convertToTuvudsz(input);
    std::cout << transformed << "\n";

    return 0;
}
