// 2.20.2. Módosítsa úgy a programot, hogy amint a négyzet eltűnik alul, 
// felül jelenjen meg újból! 
// 2.20.2.

#include <iostream>
#include <thread>
#include <chrono>

void clearScreen() {
    // Linux, macOS esetén:
    std::system("clear");
    // Windows esetén cseréld erre: system("cls");
}

void wait(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void drawSquareAt(int y, int screenHeight = 25) {
    clearScreen();

    // Üres sorok a pozícióig
    for (int i = 0; i < y; ++i)
        std::cout << "\n";

    // Kirajzolás (maximum 3 sor)
    for (int i = 0; i < 3 && (y + i) < screenHeight; ++i)
        std::cout << "***\n";
}

int main() {
    const int screenHeight = 25;
    const int squareHeight = 3;

    int y = 0;

    while (true) {
        drawSquareAt(y, screenHeight);
        wait(1);

        y++;
        if (y > screenHeight - squareHeight)
            y = 0;  // visszaugrik felülre
    }

    return 0;
}
