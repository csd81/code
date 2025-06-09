// 3.8.2. Módosítsa úgy az előző programot, hogy egy x értékre 30-szor 
// fusson le a program! Átlagosan hány dobás szükséges x darab egymást 
// követő hatoshoz? 
// 3.8.2.


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <numeric> // for std::accumulate

int main() {
    int repeatRequired;
    std::cout << "How many consecutive 6s do you want: ";
    std::cin >> repeatRequired;

    const int NUM_RUNS = 30;
    std::vector<int> trials(NUM_RUNS);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < NUM_RUNS; ++i) {
        int repeatCount = 0;
        int trial = 0;

        while (repeatCount < repeatRequired) {
            int roll = std::rand() % 6 + 1;
            trial++;
            if (roll == 6) {
                repeatCount++;
            } else {
                repeatCount = 0;
            }
        }

        trials[i] = trial;
    }

    int sum = std::accumulate(trials.begin(), trials.end(), 0);
    double average = static_cast<double>(sum) / NUM_RUNS;

    std::cout << "\nIt's needed on average " << average
              << " random number(s) to generate "
              << repeatRequired << " consecutive 6s.\n";

    return 0;
}
