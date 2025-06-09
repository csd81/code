// 2.20. Négyzet animáció
// 2.20.1. Készítsen a karakteres képernyőn videót egy leeső négyzetről! A 
// négyzet 3*3 csillagból álljon! Miután megjelenített egy képet, várjon 
// rövid ideig, törölje a képernyőt és jelenítse meg a következő képet 
// egy sorral lejjebb! Feltesszük, hogy a karakteres képernyő 80*25-ös. 
// 2.20.1.


#include <iostream>
#include <chrono>
#include <thread>

void clearScreen() {
    // Platformfüggetlen képernyőürítés (egyszerű, nem tökéletes)
    std::cout << std::string(50, '\n');
}

void drawSquareAt(int y) {
    clearScreen();

    // Üres sorok, amíg a négyzet "le nem ér"
    for (int i = 0; i < y; ++i) {
        std::cout << '\n';
    }

    // 3x3 csillagblokk
    for (int i = 0; i < 3; ++i) {
        std::cout << " ***\n";
    }
}

int main() {
    const int screenHeight = 25;
    const int squareHeight = 3;
    const int maxY = screenHeight - squareHeight;

    for (int y = 0; y <= maxY; ++y) {
        drawSquareAt(y);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
