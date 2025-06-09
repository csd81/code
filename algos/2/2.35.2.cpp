// 2.35.2. Oldja meg az eredeti feladatot #define-ok segítségével! Vezesse be a 
// közepes minősítést! Miért jobb felsorolás típust használni define helyett? 

// 2.35.2. 


#include <iostream>
#include <string>

// 1) #define-okkal
#define AWFUL     0
#define BAD       1
#define WEAK      2
#define MEDIUM    3
#define GOOD      4
#define EXCELLENT 5

void printResult(int r) {
    switch (r) {
        case AWFUL:     std::cout << "awful";     break;
        case BAD:       std::cout << "bad";       break;
        case WEAK:      std::cout << "weak";      break;
        case MEDIUM:    std::cout << "medium";    break;
        case GOOD:      std::cout << "good";      break;
        case EXCELLENT: std::cout << "excellent"; break;
        default:        std::cout << "unknown";  break;
    }
}

int main() {
    int exam1, exam2;

    std::cout << "Enter your exam result (0=awful,1=bad,2=weak,3=medium,4=good,5=excellent): ";
    std::cin >> exam1;

    std::cout << "First result: ";
    printResult(exam1);
    std::cout << "\n\n";

    std::cout << "Enter your retake exam result: ";
    std::cin >> exam2;

    std::cout << "Retake result: ";
    printResult(exam2);
    std::cout << "\n\n";

    if (exam2 > exam1) {
        std::cout << "Very good, you improved!\n";
    }
    else if (exam2 == exam1) {
        std::cout << "At least you tried!\n";
    }
    else {
        std::cout << "You must be very unlucky!\n";
    }

    return 0;
}
