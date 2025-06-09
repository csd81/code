// 3.12.2. Készítsen statisztikát egy szövegben lévő szavak és mondatok 
// számáról! 
// 3.12.2.


#include <iostream>
#include <string>

int main() {
    std::string text;
    std::cout << "Text: ";
    std::getline(std::cin, text);

    int sentence = 0;
    int word = 0;
    bool inWord = false;

    for (char c : text) {
        if (std::isspace(static_cast<unsigned char>(c))) {
            if (inWord) {
                word++;
                inWord = false;
            }
        } else {
            inWord = true;
        }

        if (c == '.' || c == '!' || c == '?') {
            sentence++;
        }
    }

    // If the last character was part of a word
    if (inWord) {
        word++;
    }

    std::cout << "\nText statistics:\n";
    std::cout << "Words: " << word << "\n";
    std::cout << "Sentences: " << sentence << "\n";

    return 0;
}
