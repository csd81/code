// 3.8. Kockadobás
// 3.8.1. Írjon programot, amely kockadobást szimulál véletlen számok 
// generálásával! Kérjen be egy sorozat hosszt, x-t, és addig generáljon 
// véletlen számokat, amíg nem jelenik meg egymás után x darab hatos! Hány 
// dobás után kaptuk meg a kívánt eredményt? Számolja az egyes dobások 
// gyakoriságát! 

// 3.8.1.

#include <iostream>
#include <vector>
#include <random>

int main() {
    int repeatRequired;
    std::cout << "How many consecutive 6s do you want: ";
    std::cin >> repeatRequired;

    if (repeatRequired <= 0) {
        std::cout << "Invalid input. Must be at least 1.\n";
        return 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 6);

    std::vector<int> frequency(6, 0);
    int repeatAct = 0;
    int trial = 0;

    while (repeatAct != repeatRequired) {
        int num = dist(gen);
        frequency[num - 1]++;
        if (num == 6)
            repeatAct++;
        else
            repeatAct = 0;
        trial++;
    }

    std::cout << "It took " << trial << " rolls to get " 
              << repeatRequired << " consecutive 6s.\n\n";
    std::cout << "Roll frequencies:\n";
    for (int i = 0; i < 6; ++i) {
        std::cout << frequency[i] << " occurrences of " << (i + 1) << "\n";
    }

    return 0;
}

