// 2.9.2. Alakítsuk át a programot úgy, hogy ne a tipp helyességét kérjük 
// be, hanem magát a tippet! Használjunk sprintf parancsot és használjuk ki 
// azt, hogy normál forma mindig tartalmaz egy 'e' betűt. A program elején 
// kérjük be a tömb nagyságát, a program végén, %-ban adjuk meg a helyes 
// megoldások számát! 
// 2.9.2.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>  // sprintf

int main() {
    int size;
    std::cout << "Enter the number of values: ";
    std::cin >> size;

    std::vector<double> myArray(size);
    std::cout << "Enter " << size << " double values:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> myArray[i];
    }

    int points = 0;
    std::cout << "How do you think the %g will display the next numbers? Use 'e' for scientific and 'f' for normal form.\n";

    for (int i = 0; i < size; ++i) {
        std::cout << "\n" << std::setw(15) << std::setprecision(10) << std::fixed << myArray[i] << "\n";

        // Formázzuk sprintf-fel
        char buffer[50];
        std::sprintf(buffer, "%g", myArray[i]);

        std::cout << "Your guess? (e / f): ";
        char choice;
        std::cin >> choice;

        // Ellenőrizzük, van-e 'e' a sprintf által generált stringben
        char correctChoice = 'f';
        for (int j = 0; buffer[j] != '\0'; ++j) {
            if (buffer[j] == 'e' || buffer[j] == 'E') {
                correctChoice = 'e';
                break;
            }
        }

        std::cout << "Formatted with %g: " << buffer << "\n";

        if (choice == correctChoice) {
            std::cout << "Correct!\n";
            ++points;
        } else {
            std::cout << "Incorrect!\n";
        }
    }

    double percentage = static_cast<double>(points) / size * 100.0;
    std::cout << "You achieved a(n) " << std::fixed << std::setprecision(0) << percentage << "% result.\n";

    return 0;
}
