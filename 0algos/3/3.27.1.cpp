// 3.27. Caesar dekódoló
// 3.27.1. A Cézár-kódolás a következőképpen működik: Minden karaktert 
// egy előre meghatározott N pozícióval eltolunk. Például, ha N = 1, az 
// „APPLE” szó BQQMD lesz, ugyanis A-ból B lett, P-ből Q, stb. Ha N = 1, 
// Z-ből A lesz. Példa N = 3-ra: eredeti szöveg: THE QUICK BROWN FOX JUMPS OVER 
// THE LAZY DOG kódolt szöveg: WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ Az 
// ellenségtől egy kódolt üzenetet kaptunk. Nem ismerjük N értékét, de a 
// kémünk azt állítja, hogy az eredeti üzenet szavai közt szerepel a 
// „THE” szó. Írjon programot, amely beolvassa a kódolt üzenetet a 
// „codedmessage.txt” fájlból, és megfejti, mi volt az eredeti üzenet! N 
// értéke 1 és 26 közt van, a programnak tehát meg kell vizsgálnia minden 
// N-t, amíg az üzenet nem tartalmazza a „THE” szót. Az üzenet 
// tárolására használjon dinamikus tömböt! Ábra: Caesar kódolás 
// szemléltetése Az input fájl formátuma: Első sor: Az üzenet szavainak 
// száma. Második sor: Az üzenet szavai, egy-egy szóköz karakterrel 
// elválasztva. Példa bemenet: 9 WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ 
// Kimenet: The coded message: WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ The 
// original message: THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG 
// 3.27.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

const std::string DEFAULT_FILENAME = "codedmsg.txt";
const std::string KNOWN_WORD = "THE";
const int ALPHABET_LEN = 26;

using Message = std::vector<std::string>;

bool readMessage(const std::string& filename, Message& msg) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file: " << filename << "\n";
        return false;
    }

    int wordCount;
    file >> wordCount;
    msg.resize(wordCount);

    for (int i = 0; i < wordCount; ++i) {
        file >> msg[i];
    }

    return true;
}

void printMessage(const Message& msg) {
    for (const auto& word : msg)
        std::cout << word << " ";
    std::cout << "\n";
}

std::string caesarShift(const std::string& word, int shift) {
    std::string result = word;
    for (char& ch : result) {
        ch = 'A' + (ch - 'A' + shift + ALPHABET_LEN) % ALPHABET_LEN;
    }
    return result;
}

Message shiftMessage(const Message& msg, int shift) {
    Message shifted = msg;
    for (auto& word : shifted) {
        word = caesarShift(word, shift);
    }
    return shifted;
}

bool containsWord(const Message& msg, const std::string& word) {
    for (const auto& w : msg) {
        if (w == word) return true;
    }
    return false;
}

int main(int argc, char* argv[]) {
    std::string filename = (argc > 1) ? argv[1] : DEFAULT_FILENAME;
    Message codedMessage;

    if (!readMessage(filename, codedMessage))
        return 1;

    std::cout << "The coded message:\n";
    printMessage(codedMessage);

    for (int shift = 1; shift < ALPHABET_LEN; ++shift) {
        Message decoded = shiftMessage(codedMessage, shift);
        if (containsWord(decoded, KNOWN_WORD)) {
            std::cout << "\nThe original message (shift = " << shift << "):\n";
            printMessage(decoded);
            return 0;
        }
    }

    std::cout << "\nNo matching message containing \"" << KNOWN_WORD << "\" was found.\n";
    return 0;
}
