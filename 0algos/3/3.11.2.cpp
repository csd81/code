// 3.11.2. Módosítsa úgy a programot, hogy a magánhangzókat hagyja ki, de 
// csak akkor, ha nem egy szó elején vannak! 
// 3.11.2.

 #include <iostream>
#include <string>
#include <cctype>
#include <set>

// Segédfüggvény: eldönti, hogy a karakter magánhangzó-e (angol)
bool isVowel(char c) {
    static const std::set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    return vowels.count(std::tolower(static_cast<unsigned char>(c))) > 0;
}

int main() {
    std::string text =
        "The project will scale up to 1,200 marine sites,\n"
        "including different conditions such as surface waters,\n"
        "waters near methane emissions from the sea floor, and "
        "deep sea sediments.";

    bool atWordStart = true;

    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];

        if (std::isspace(static_cast<unsigned char>(c)) || std::ispunct(static_cast<unsigned char>(c))) {
            atWordStart = true;
            std::cout << c; // minden szóköz és írásjel változatlanul kimegy
        } else {
            if (isVowel(c) && !atWordStart) {
                // nem írjuk ki a nem szóbeli magánhangzót
            } else {
                std::cout << c;
            }
            atWordStart = false;
        }
    }

    return 0;
}
