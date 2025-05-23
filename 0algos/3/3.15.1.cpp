// 3.15. Kisbetű - nagybetű

// 3.15.1. Írjon programot, amely bekért mondatot formáz adott választás 
// szerint! Menüből választhatóak a következő lehetőségek: UPPER CASE 
// (mindent nagybetűre), lower case (mindent kisbetűre), tOGGLE CASE (kis 
// betűket nagyra és nagyokat kicsire), Sentense case (a sor első betűje nagy 
// csak), Title Case (minden szókezdő betű nagy). Mind a konvertálások, mind 
// a menü függvénnyel legyen megoldva! 
// 3.15.1.

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

// UPPER CASE
std::string toUpperCase(const std::string& input) {
    std::string result = input;
    for (char& c : result)
        c = std::toupper(c);
    return result;
}

// lower case
std::string toLowerCase(const std::string& input) {
    std::string result = input;
    for (char& c : result)
        c = std::tolower(c);
    return result;
}

// tOGGLE CASE
std::string toggleCase(const std::string& input) {
    std::string result = input;
    for (char& c : result) {
        if (std::islower(c)) c = std::toupper(c);
        else if (std::isupper(c)) c = std::tolower(c);
    }
    return result;
}

// Sentence case
std::string sentenceCase(const std::string& input) {
    std::string result = toLowerCase(input);
    for (size_t i = 0; i < result.size(); ++i) {
        if (!std::isspace(result[i])) {
            result[i] = std::toupper(result[i]);
            break;
        }
    }
    return result;
}

// Title Case
std::string titleCase(const std::string& input) {
    std::string result = toLowerCase(input);
    bool newWord = true;
    for (char& c : result) {
        if (std::isspace(c)) {
            newWord = true;
        } else if (newWord) {
            c = std::toupper(c);
            newWord = false;
        }
    }
    return result;
}

int menu() {
    int choice;
    std::cout << "1. UPPER CASE\n";
    std::cout << "2. lower case\n";
    std::cout << "3. tOGGLE CASE\n";
    std::cout << "4. Sentence case\n";
    std::cout << "5. Title Case\n";
    std::cout << "Select an option: ";
    std::cin >> choice;
    std::cin.ignore(); // remove leftover newline
    return choice;
}

int main() {
    std::string myString;
    std::cout << "Original string: ";
    std::getline(std::cin, myString);

    int choice = menu();

    std::string result;
    switch (choice) {
        case 1: result = toUpperCase(myString); break;
        case 2: result = toLowerCase(myString); break;
        case 3: result = toggleCase(myString); break;
        case 4: result = sentenceCase(myString); break;
        case 5: result = titleCase(myString); break;
        default: std::cout << "Invalid choice.\n"; return 1;
    }

    std::cout << "\nResult: \"" << result << "\"\n";
    return 0;
}

