// 2.41.2. Módosítsa a programot úgy, hogy csak minden egész másodpercben 
// írja ki az eltelt időt! 
// 2.41.2.

#include <iostream>
#include <chrono>
#include <thread>

int main() {
    using namespace std::chrono;

    auto start = steady_clock::now();
    int lastPrintedSecond = -1;

    while (true) {
        auto now = steady_clock::now();
        int elapsedSeconds = duration_cast<seconds>(now - start).count();

        if (elapsedSeconds != lastPrintedSecond) {
            std::cout << elapsedSeconds << " seconds elapsed\n";
            lastPrintedSecond = elapsedSeconds;
        }

        if (elapsedSeconds >= 11) break;

        std::this_thread::sleep_for(milliseconds(50));
    }

    return 0;
}
