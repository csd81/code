// 2.2.2. Az azonos sorok kiírásához használjon ciklust! 
// 2.2.2.


#include <iostream>

constexpr int SIZE = 8;

int main() {
    std::cout << "  |a |b |c |d |e |f |g |h |\n";
    std::cout << " -|--|--|--|--|--|--|--|--|\n";

    for (int id = 0; id < SIZE; ++id) {
        std::cout << " " << id + 1 << "|  |  |  |  |  |  |  |  |\n";
        std::cout << " -|--|--|--|--|--|--|--|--|\n";
    }

    return 0;
}
