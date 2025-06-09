// 3.41. Szavak kicserélése

// 3.41.1. Egy fájlban egy legfeljebb 1000 karakter hosszú sztring található. 
// Írjon programot, amely beolvassa ezt a fájlt, majd bekér a felhasználótól 
// két szót! A második szó nem lehet hosszabb az elsőnél. A program keresse 
// meg az első szó minden előfordulását a szövegben, és cserélje ki a 
// második szóra. Írja ki a képernyőre az új szöveget, és a találatok 
// számát! 

// Példa: 
// The original text: "This is a very simple text that can help 
// for you to understand the task. " 
// Type a word: simple 
// Type the new word: easy 1 hits 
// The new text: "This is a very easy text that can help for you to 
// understand the task. " 

// 3.41.1.

#include <iostream>
#include <fstream>
#include <string>

int replaceWords(std::string& text, const std::string& from, const std::string& to) {
    if (to.size() > from.size()) {
        std::cerr << "Hiba: a csere szó nem lehet hosszabb, mint az eredeti!\n";
        return -1;
    }

    int hits = 0;
    size_t pos = 0;
    while ((pos = text.find(from, pos)) != std::string::npos) {
        text.replace(pos, to.length(), to);
        // ha rövidebb lett a szó, a szöveget igazítjuk
        if (to.length() < from.length()) {
            text.erase(pos + to.length(), from.length() - to.length());
        }
        ++hits;
        pos += to.length(); // lépés a következő lehetséges találatra
    }
    return hits;
}

int main(int argc, char* argv[]) {
    const std::string filename = (argc > 1) ? argv[1] : "text.txt";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Nem sikerült megnyitni a fájlt: " << filename << '\n';
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::cout << "The original text: \"" << text << "\"\n\n";

    std::string word1, word2;
    std::cout << "Type a word: ";
    std::cin >> word1;

    std::cout << "Type the new word: ";
    std::cin >> word2;

    int hits = replaceWords(text, word1, word2);
    if (hits >= 0) {
        std::cout << "\n" << hits << " hits\n";
        std::cout << "The new text: \"" << text << "\"\n";
    }

    return 0;
}

