// 3.28.2. Írja át úgy az előző programot, hogy lehessen a keresésnél egy ? 
// vagy egy * karaktert használni! A ? egy tetszőleges karakter helyett állhat, 
// a * pedig a sztring végén lehet és azt jelezi, hogy még valamennyi karakter 
// hátra van. Ha egy minta több program nevére is illeszkedik, akkor jelenítse 
// meg mindet! 
// 3.28.2.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

const std::string DEFAULT_INPUTFILE = "cds.txt";
const size_t MAX_WORD_LENGTH = 16;

struct CD {
    std::string name;
    std::vector<std::string> programs;
};

// Wildcard string comparison with support for ? and terminal *
bool wildcardMatch(const std::string& pattern, const std::string& text) {
    size_t pLen = pattern.length();
    size_t tLen = text.length();

    for (size_t i = 0; i < pLen; ++i) {
        if (pattern[i] == '*') {
            return text.substr(0, i) == pattern.substr(0, i);
        }
        if (i >= tLen || (pattern[i] != '?' && pattern[i] != text[i])) {
            return false;
        }
    }
    return tLen == pLen;
}

std::vector<CD> readCDs(std::ifstream& file) {
    int cdCount;
    file >> cdCount;
    std::vector<CD> cds(cdCount);

    for (int i = 0; i < cdCount; ++i) {
        file >> cds[i].name;
        int progCount;
        file >> progCount;
        cds[i].programs.resize(progCount);
        for (int j = 0; j < progCount; ++j) {
            file >> cds[i].programs[j];
        }
    }
    return cds;
}

void searchPrograms(const std::vector<CD>& cds, const std::string& pattern) {
    bool found = false;
    for (const auto& cd : cds) {
        for (const auto& prog : cd.programs) {
            if (wildcardMatch(pattern, prog)) {
                std::cout << "The " << prog << " is here: " << cd.name << "\n";
                found = true;
            }
        }
    }
    if (!found) {
        std::cout << pattern << " does not exist!\n";
    }
}

int main(int argc, char* argv[]) {
    std::string filename = argc > 1 ? argv[1] : DEFAULT_INPUTFILE;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << "\n";
        return 1;
    }

    auto cds = readCDs(file);
    file.close();

    std::string pattern;
    std::cout << "Program name (use * or ? as wildcards): ";
    std::cin >> pattern;

    searchPrograms(cds, pattern);

    return 0;
}
