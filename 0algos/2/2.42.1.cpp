// 2.42. Időpont formázása
// 2.42.1. Írjon programot, amely 10 másodpercen keresztül folytonosan kiírja 
// az aktuális időt ezredmásodperc pontossággal! Használja az _ftime és 
// ctime függvényeket! 
// 2.42.1.


#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>

int main() {
    using namespace std::chrono;

    auto start = steady_clock::now();

    while (duration_cast<seconds>(steady_clock::now() - start).count() < 10) {
        auto now = system_clock::now();
        auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

        std::time_t t = system_clock::to_time_t(now);
        std::tm* localTime = std::localtime(&t);

        std::cout << std::put_time(localTime, "%H:%M:%S") << "."
                  << std::setfill('0') << std::setw(3) << ms.count() << std::endl;

        std::this_thread::sleep_for(milliseconds(100));  // frissítés minden 100ms
    }

    return 0;
}
