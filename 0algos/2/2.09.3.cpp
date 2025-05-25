// 2.9.3. Alakítsuk át a programot úgy, hogy minden iterációban kérje be a 
// %g-ben használt pontosságot is! A válasz ne csak az legyen, hogy 
// hagyományos vagy normál formában történik a kiírás, hanem pontosan meg 
// kell adni számot a megfelelő formában! 
// 2.9.3.

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>  // sprintf
#include <cstring> // strcmp

int main() {
    const int size = 5;
    double myArray[size] = {3.456, 45697.678, -659.23, -0.0000965, 6.0000001};
    int points = 0;

    std::cout << "How do you think the %g will display the next numbers? Type it exactly!\n";

    for (int i = 0; i < size; ++i) {
        std::cout << "\n" << std::setw(15) << std::setprecision(10) << std::fixed << myArray[i] << "\n";
        
        int precision;
        std::cout << "How long should the %g precision be? ";
        std::cin >> precision;

        // Formázott sztring létrehozása a %g alapján
        char buffer[50];
        int strLength = std::sprintf(buffer, "%.*g", precision, myArray[i]);

        std::string tip;
        std::cout << "Your tip: ";
        std::cin >> tip;

        std::string correctAnswer(buffer);

        std::cout << "Formatted output with %g: " << correctAnswer << "\n";

        if (tip == correctAnswer) {
            std::cout << "Correct!\n";
            ++points;
        } else {
            std::cout << "Incorrect!\n";
        }
    }

    double percentage = static_cast<double>(points) / size * 100.0;
    std::cout << "You achieved a(n) " << std::fixed << std::setprecision(0) << percentage << " % result.\n";

    return 0;
}
