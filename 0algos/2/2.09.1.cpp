// 2.9. Hagyományos vagy normál forma
// 2.9.1. Írjon programot, amely öt darab tömbben tárolt float típusú 
// számról kérdezi meg, hogy azt a printf %g-el történő kiírásakor 
// hagyományos (f) vagy normál (e) alakban jeleníti meg! A számot jelenítsük 
// meg először %f-el! Írjuk ki a felhasználónak, hogy tippeljen, jelenítsük 
// meg a választ %g-el, kérdezzük meg, hogy helyes volt-e a tipp! Számoljuk a 
// helyes válaszokat! 
// 2.9.1.


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>  // sprintf
#include <limits>  // std::numeric_limits

int main() {
    const int size = 5;
    double array[] = {3.456, 45697.678, -659.23, -0.0000965, 6.0000001};
    int points = 0;

    std::cout << "How do you think %%g will display the next numbers?\n";
    std::cout << "(f = fixed, e = exponential)\n";

    for (int i = 0; i < size; ++i) {
        // 1. Szám kiírás %f formában (tíz tizedesjeggyel)
        std::cout << "\n" << std::fixed << std::setprecision(10) << array[i] << "\n";

        // 2. Tipp bekérése
        std::cout << "Your guess (f/e): ";
        char guess;
        std::cin >> guess;
        guess = std::tolower(guess);

        // 3. %g formátum előállítása sprintf-fel
        char buffer[50];
        std::sprintf(buffer, "%g", array[i]);

        std::cout << "Actual output with %%g: " << buffer << "\n";

        // 4. Ellenőrzés: van-e 'e' vagy 'E' a bufferben
        bool isExponential = false;
        for (int j = 0; buffer[j] != '\0'; ++j) {
            if (buffer[j] == 'e' || buffer[j] == 'E') {
                isExponential = true;
                break;
            }
        }

        char actual = isExponential ? 'e' : 'f';

        // 5. Tipp ellenőrzése
        std::cout << "Was your selection correct? (y/n): ";
        char confirm;
        std::cin >> confirm;

        if (std::tolower(confirm) == 'y') {
            if (guess == actual) {
                ++points;
            }
        }

        // Bemenet ürítése a következő iteráció előtt
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\nYou have " << points << " out of " << size << " correct.\n";

    return 0;
}
