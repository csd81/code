// 3.11.1. Írjon programot, amely egy szöveg minden negyedik karakterét 
// kihagyja, ha az nem white space! inicializálja úgy a sztringet, hogy abban 
// több sor legyen és ezek a sorok a program kódban is sorokban legyenek 
// (külön idézőjel párok felhasználásával)! A néggyel való 
// oszthatóságot külön függvénnyel valósítsa meg! 
// 3.11.1.


#include <iostream>
#include <string>
#include <cctype>

// Ellenőrzi, hogy a szám osztható-e 4-gyel
bool divisibleBy4(int num) {
    return num % 4 == 0;
}

int main() {
    std::string s = 
        "The project will scale up to 1,200 marine sites,\n"
        "including different conditions such as surface waters,\n"
        "waters near methane emissions from the sea floor, and deep-sea sediments.";

    int visibleCharIndex = 0; // csak nem-whitespace karakterek indexelésére

    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (std::isspace(static_cast<unsigned char>(c))) {
            std::cout << c; // whitespace-eket mindig kiírjuk
        } else {
            if (!divisibleBy4(visibleCharIndex)) {
                std::cout << c;
            }
            ++visibleCharIndex; // csak nem-whitespace-ekre növeljük
        }
    }

    return 0;
}
