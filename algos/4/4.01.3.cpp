// c++11
// 4.1.3. Valósítsa meg hasonló módon a ciklikus listát! Listázáskor lehessen megadni, hogy honnan kezdődjék a kiírás! 4.2. Lista egy tömbbel


// c++11
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    const int N = 7;
    // Values and next‐indices for a cyclic list
    std::vector<double> data   = {34, 12.55, 893.2, 2, 11.6, 47.5, 45.3};
    std::vector<int>    nextIx = { 1,    2,    3,   4,    5,    6,    0   };

    int head;
    std::cout << "From which index should the cyclic list start? (0–" 
              << (N-1) << "): ";
    std::cin >> head;
    if (head < 0 || head >= N) {
        std::cerr << "Invalid start index!\n";
        return 1;
    }

    std::cout << "List starting at " << head << ": [";
    int cur = head;
    for (int i = 0; i < N; ++i) {
        std::cout << std::fixed << std::setprecision(2) << data[cur];
        if (i + 1 < N) std::cout << ", ";
        cur = nextIx[cur];
    }
    std::cout << "]\n";

    return 0;
}
