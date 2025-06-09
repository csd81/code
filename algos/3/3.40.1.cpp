
// 3.40. Sztring tokenizáló

// 3.40.1. Írjon sztring tokenizáló programot! A felhasználó egy sztringet 
// gépel be, amely több szóból állhat, a szavakat egy vagy több szóköz 
// karakter választja el. Ezután a program számolja meg a sztringben lévő 
// szavakat, foglaljon le dinamikus tömböket a szavak számára, és másolja be 
// az egyes szavakat a lefoglalt karaktertömbökbe! Írja ki a program a 
// képernyőre az eredeti sztringet, és az egyes szavakat! 
// Példa bemenet: 
// This is a simple example. 
// The typed text: "This is a 
// 1.: "This" 
// 2.: "is" 
// 3.: "a" 
// 4.: "simple" 
// 5.: "example." simple example." 

// 3.40.1.


#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string line;

    std::cout << "Enter a sentence: ";
    if (!std::getline(std::cin, line)) {
        std::cerr << "Input error!\n";
        return 1;
    }

    std::cout << "The typed text: \"" << line << "\"\n";

    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string word;

    while (iss >> word) {
        tokens.push_back(word);
    }

    for (size_t i = 0; i < tokens.size(); ++i) {
        std::cout << (i + 1) << ".: \"" << tokens[i] << "\"\n";
    }

    return 0;
}
