// 3.27.2. Legyen a tartalmazott szó, a mostani „THE” is bemenet! Ha több 
// lehetséges visszakódolás van, akkor jelenítse meg az összest! 
// 3.27.2.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

const std::string DEFAULT_INPUTFILE = "codedmsg.txt";
const int MAX_WORD_LEN = 15;
const int ALPHABET_LEN = 26;

using Message = std::vector<std::string>;

int readMessage(const std::string& filename, Message& msg) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Cannot open file!\n";
        return 0;
    }

    int num;
    file >> num;
    msg.resize(num);
    for (int i = 0; i < num; ++i) {
        file >> msg[i];
    }

    return num;
}

std::string shiftChar(char c, int shift) {
    return std::string(1, static_cast<char>('A' + (c - 'A' + shift + ALPHABET_LEN) % ALPHABET_LEN));
}

Message shiftMessage(const Message& msg, int shift) {
    Message shifted = msg;
    for (std::string& word : shifted) {
        for (char& ch : word) {
            ch = 'A' + (ch - 'A' + shift + ALPHABET_LEN) % ALPHABET_LEN;
        }
    }
    return shifted;
}

bool containsKnownWord(const Message& msg, const std::string& knownWord) {
    for (const auto& word : msg) {
        if (word.find(knownWord) != std::string::npos) {
            return true;
        }
    }
    return false;
}

void printMessage(const Message& msg) {
    for (const auto& word : msg)
        std::cout << word << " ";
    std::cout << '\n';
}

int main(int argc, char* argv[]) {
    std::string filename = (argc > 1) ? argv[1] : DEFAULT_INPUTFILE;
    Message codedMessage;

    if (readMessage(filename, codedMessage) == 0)
        return 1;

    std::string knownWord;
    std::cout << "Known word: ";
    std::cin >> knownWord;

    // Convert known word to uppercase for consistency
    std::transform(knownWord.begin(), knownWord.end(), knownWord.begin(), ::toupper);

    std::cout << "\nThe coded message:\n";
    printMessage(codedMessage);

    std::cout << "\nPossible decodings containing \"" << knownWord << "\":\n";
    for (int shift = 1; shift < ALPHABET_LEN; ++shift) {
        Message decoded = shiftMessage(codedMessage, shift);
        if (containsKnownWord(decoded, knownWord)) {
            std::cout << "Shift " << shift << ": ";
            printMessage(decoded);
        }
    }

    return 0;
}

