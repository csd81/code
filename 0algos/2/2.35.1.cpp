// 2.35. Szóbeli vizsga
// 2.35.1. Írjon programot, amelyben bekéri egy szóbeli vizsga minősítését! 
// A minősítés lehet: szörnyű, rossz, gyenge, jó, kiváló. Használjon 
// felsorolás típust! Írjon függvényt a minősítés szöveges kiírására! 
// Kérje be az ismétlő vizsga eredményét, határozza meg, hogy javított-e az 
// illető! 
// 2.35.1.


#include <iostream>
#include <string>

enum class Result { Awful = 0, Bad, Weak, Good, Excellent };

void printResult(Result r) {
    switch (r) {
        case Result::Awful:     std::cout << "awful";     break;
        case Result::Bad:       std::cout << "bad";       break;
        case Result::Weak:      std::cout << "weak";      break;
        case Result::Good:      std::cout << "good";      break;
        case Result::Excellent: std::cout << "excellent"; break;
    }
}

int main() {
    std::cout << "Enter your exam result:\n"
              << "  0=awful, 1=bad, 2=weak, 3=good, 4=excellent\n> ";
    int i1;
    std::cin >> i1;
    Result exam1 = static_cast<Result>(i1);

    std::cout << "Your first result is: ";
    printResult(exam1);
    std::cout << "\n\n";

    std::cout << "Enter your retake exam result:\n"
              << "  0=awful, 1=bad, 2=weak, 3=good, 4=excellent\n> ";
    int i2;
    std::cin >> i2;
    Result exam2 = static_cast<Result>(i2);

    std::cout << "Your retake result is: ";
    printResult(exam2);
    std::cout << "\n\n";

    if (exam2 > exam1) {
        std::cout << "Very good, you improved!\n";
    } else if (exam2 == exam1) {
        std::cout << "At least you tried!\n";
    } else {
        std::cout << "You must be very unlucky!\n";
    }

    return 0;
}
