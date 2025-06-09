// 3.32. Szótár

// 3.32.1. Írjon angol-magyar szótár programot! Fájl tartalmazza az 
// angol-magyar szópárokat! A program olvasson be egy szót a billentyűzetről! 
// A szó a két nyelv bármelyikén lehet. Ezután olvassa be a szópárokat a 
// fájlból, és keresse meg a megadott szóhoz tartozó szópárt! Az is 
// találatnak számít, ha a begépelt szó, az előtagja az egyik szótári 
// bejegyzésnek. Írja ki a képernyőre a találatokat! Az input fájl 
// formátuma: Első sor: A szópárok száma A többi sor: Angol_szó Magyar_szó 
// (szóköz karakterrel elválasztva) Egy-egy szó maximális hossza 20 karakter. 
// Példa bemenet: 5 SUN NAP DOG KUTYA BICYCLE BICIKLI VILLAGE FALU SUNSHINE 
// NAPSUTES Kimenet: Type the word: NAP Hun->Eng: NAP SUN 1 hits Kimenet: Type the 
// word: SUN Eng->Hun: SUN NAP Eng->Hun: SUNSHINE NAPSUTES 2 hits 

// 3.32.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct WordPair {
    std::string eng;
    std::string hun;
};

void search(const std::vector<WordPair>& dict, const std::string& word) {
    int hits = 0;

    for (const auto& pair : dict) {
        // Angol->Magyar: előtag egyezés vagy teljes egyezés
        if (pair.eng.find(word) == 0) {
            std::cout << "Eng->Hun: " << pair.eng << " " << pair.hun << "\n";
            ++hits;
        }
        // Magyar->Angol: csak teljes egyezés
        if (pair.hun == word) {
            std::cout << "Hun->Eng: " << pair.hun << " " << pair.eng << "\n";
            ++hits;
        }
    }

    std::cout << "\n" << hits << " hits\n";
}

int main(int argc, char* argv[]) {
    const std::string filename = (argc > 1) ? argv[1] : "dict.txt";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Hiba a fájl megnyitásakor: " << filename << "\n";
        return 1;
    }

    int num;
    file >> num;

    std::vector<WordPair> dict(num);
    for (int i = 0; i < num; ++i) {
        file >> dict[i].eng >> dict[i].hun;
    }

    std::string word;
    std::cout << "\nType the word: ";
    std::cin >> word;

    std::cout << '\n';
    search(dict, word);

    return 0;
}
