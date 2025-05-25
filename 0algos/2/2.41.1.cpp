// 2.41. Stopper
// 2.41.1. Készítsünk stopperórát, amely a program indításától eltelt 
// időt írja ki folyamatosan! A program 11 másodperc után álljon meg! 
// 2.41.1.

#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

int main() {
    using namespace std::chrono;

    auto start = steady_clock::now();
    double elapsedSeconds = 0.0;

    while (elapsedSeconds < 11.0) {
        auto now = steady_clock::now();
        elapsedSeconds = duration_cast<duration<double>>(now - start).count();

        std::cout << std::fixed << std::setprecision(3)
                  << "\rElapsed time: " << elapsedSeconds << " s" << std::flush;

        std::this_thread::sleep_for(milliseconds(100)); // kis késleltetés
    }

    std::cout << "\nStopwatch finished (11 seconds).\n";
    return 0;
}
