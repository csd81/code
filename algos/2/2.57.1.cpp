// 2.57. Lottó
// 2.57.1. Írjon lottó-generáló programot! A program generáljon 1 és 90 
// között 5 különböző pozitív egész számot! Egy fájl tippeket tartalmaz. 
// Olvassa be a tippeket a fájlból, majd hasonlítsa össze őket a generált 
// számokkal! Írja ki a képernyőre a generált nyerőszámokat, és azt, hogy 
// hány embernek van 1-es, 2-es, 3as, 4-es, illetve 5-ös találata a lottón! Az 
// input fájl formátuma: Első sor: a tippek száma Minden további sor 5 tippet 
// tartalmaz, szóköz karakterekkel elválasztva. Példa bemenet: 6 5 64 23 80 42 
// 4 34 44 62 72 75 43 3 64 80 53 52 21 56 10 1 37 87 9 53 75 10 64 69 78 Kimenet: 
// Generated numbers: 55, 64, 68, 75, 50 There is 1 1 hit There are 2 2 hits There 
// is 0 3 hit There is 0 4 hit There is 0 5 hit 
// 2.57.1.

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>

const std::string DEFAULT_INPUTFILE = "tipp1.txt";

void getNumbers(std::vector<int>& numbers) {
    numbers.clear();
    while (numbers.size() < 5) {
        int num = rand() % 90 + 1;
        if (std::find(numbers.begin(), numbers.end(), num) == numbers.end()) {
            numbers.push_back(num);
        }
    }
    std::sort(numbers.begin(), numbers.end());
}

void printNumbers(const std::vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i];
        if (i < numbers.size() - 1)
            std::cout << ", ";
    }
    std::cout << "\n";
}

void initHits(std::vector<int>& hits) {
    hits.assign(5, 0);
}

void check(std::ifstream& file, const std::vector<int>& draw, std::vector<int>& hits) {
    int count;
    file >> count;

    for (int i = 0; i < count; ++i) {
        std::set<int> tip;
        for (int j = 0; j < 5; ++j) {
            int num;
            file >> num;
            tip.insert(num);
        }

        int match = 0;
        for (int num : draw) {
            if (tip.count(num)) {
                ++match;
            }
        }

        if (match > 0 && match <= 5) {
            hits[match - 1]++;
        }
    }
}

void printHits(const std::vector<int>& hits) {
    for (size_t i = 0; i < hits.size(); ++i) {
        std::cout << "There ";
        if (hits[i] == 1)
            std::cout << "is ";
        else
            std::cout << "are ";
        std::cout << hits[i] << " " << (i + 1) << " hit";
        if (hits[i] != 1) std::cout << "s";
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::ifstream file(argc > 1 ? argv[1] : DEFAULT_INPUTFILE);
    if (!file) {
        std::cerr << "Error opening input file.\n";
        return 1;
    }

    std::vector<int> numbers;
    std::vector<int> hits(5);

    getNumbers(numbers);
    initHits(hits);

    std::cout << "Generated numbers: ";
    printNumbers(numbers);

    check(file, numbers, hits);
    printHits(hits);

    file.close();
    return 0;
}
