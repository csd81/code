// 3.19. Gépelés

// 3.19.1. Készítsen gépelést tanító programot! Sztring tömbben 
// tároljon 20 különféle szót! Kérje be, hogy hány szót akar gépelni, 
// véletlenszerűen válasszon ki egyet, amit megjelenít, és aztán várja azt 
// bemenetként! Hibás bevitel esetén kérje be újból a szót! A gyakorlás 
// végén írja ki az eltelt időt és a helyes és elrontott szavak számát! 

// 3.19.1.


#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>

int main() {
    std::vector<std::string> words = {
        "element", "size", "love", "ball", "toy", "gambit", "cruiser", "shadow",
        "console", "Atlantis", "port", "staple", "Leonardo", "bug", "hope",
        "vanity", "time", "issue", "fan", "strength"
    };

    int trial;
    int errors = 0;
    std::string input;

    std::cout << "How many words would you like to type: ";
    std::cin >> trial;
    std::cin.ignore(); // clear newline after number

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, words.size() - 1);

    // Start timer
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < trial; ++i) {
        std::string target = words[dist(gen)];
        std::cout << "type: " << target << std::endl;

        std::getline(std::cin, input);
        while (input != target) {
            std::cout << "error!\n";
            ++errors;
            std::getline(std::cin, input);
        }
    }

    // Stop timer
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = finish - start;

    // Output
    std::cout << "Elapsed time: " << duration.count() << " seconds\n";
    std::cout << "Number of good trials: " << trial
              << ", bad trials: " << errors << "\n";

    return 0;
}
