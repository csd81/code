// 3.15.2. Valósítsa meg a „Nice Title Case” formázást! A szavak első 
// betűje nagy kivéve az alábbi szavak esetén: and, of, the, a, an, from, for, 
// in. A kivételt nem kell figyelembe venni a sor első karakterénél és egy 
// kettős pont után. Például: „The Life of an English Man and the War” 
// 3.15.2.


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <cctype>
#include <algorithm>

std::string toLower(const std::string& str) {
    std::string res = str;
    std::transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}

std::string toTitleCaseWord(const std::string& word) {
    if (word.empty()) return word;
    std::string result = toLower(word);
    result[0] = std::toupper(result[0]);
    return result;
}

std::string niceTitleCase(const std::string& input) {
    std::set<std::string> exceptions = {"and", "of", "the", "a", "an", "from", "for", "in"};

    std::istringstream iss(input);
    std::vector<std::string> words;
    std::string word;
    char prevEnd = '\0'; // store previous punctuation (for colon detection)
    bool forceCapitalize = true;

    while (iss >> word) {
        std::string cleanWord = toLower(word);

        // Remove trailing punctuation for colon detection
        char lastChar = word.back();
        bool endsWithColon = (lastChar == ':');
        if (endsWithColon) cleanWord = cleanWord.substr(0, cleanWord.size() - 1);

        if (forceCapitalize || exceptions.find(cleanWord) == exceptions.end()) {
            word = toTitleCaseWord(cleanWord);
        } else {
            word = toLower(cleanWord);
        }

        if (endsWithColon) word += ":";

        words.push_back(word);
        forceCapitalize = endsWithColon; // reset flag if colon
        prevEnd = lastChar;
    }

    // Join back into sentence
    std::ostringstream oss;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i > 0) oss << " ";
        oss << words[i];
    }

    return oss.str();
}

int main() {
    std::string input;
    std::cout << "Original string: ";
    std::getline(std::cin, input);

    std::string result = niceTitleCase(input);

    std::cout << "\nResult: \"" << result << "\"\n";
    return 0;
}
