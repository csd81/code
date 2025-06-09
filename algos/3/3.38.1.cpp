// 3.38. Morze kód

// 3.38.1. Írjon programot, ami egy üzenetet Morze kóddá alakít! Az üzenet 
// begépelése után a program foglaljon le memóriát a kódolt üzenet 
// számára, kódolja az üzenetet és jelenítse meg azt! Használja az alábbi 
// sztring tömböt az egye karakterek leképezésére! A szóköz karakter kódja 
// 5 pont. char* morsecodes[26] = { ".=", "=...", "=.=.", "=..", ".", "..=.", 
// "==.", "....", "..", ".===", "=.=", ".=..", "==", "=.", "===", ".==.", "==.=", 
// ".=.", "...", "=", "..=", "...=", ".==", "=..=", "=.==", "==.."};
// Példa bemenet: Az üzenet: SOS I AM WRITING A TEST Üzenet: "SOS I AM WRITING 
// A TEST" A kódolt üzenet: 
// "...===................===......==.=...=..=.==.......=.....=....=" 

// 3.38.1.:

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

const std::string morsecodes[26] = {
    ".=", "=...", "=.=.", "=..", ".", "..=.", "==.", "....", "..", ".===",
    "=.=", ".=..", "==", "=.", "===", ".==.", "==.=", ".=.", "...", "=",
    "..=", "...=", ".==", "=..=", "=.==", "==.."
};

const std::string SZOKOZ = ".....";

std::string toUpper(const std::string& input) {
    std::string result;
    for (char ch : input)
        result += std::toupper(static_cast<unsigned char>(ch));
    return result;
}

std::string morseEncode(const std::string& message) {
    std::string result;
    for (char ch : message) {
        if (ch == ' ') {
            result += SZOKOZ;
        } else if (std::isupper(ch)) {
            result += morsecodes[ch - 'A'];
        }
        // Optional: ignore other characters or handle them
    }
    return result;
}

int main() {
    std::string message;
    std::cout << "The message: ";
    std::getline(std::cin, message);

    message = toUpper(message);

    std::cout << "Message: \"" << message << "\"\n";

    std::string morse = morseEncode(message);

    std::cout << "The coded message: \"" << morse << "\"\n";

    return 0;
}

