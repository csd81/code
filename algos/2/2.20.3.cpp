// 2.20.3. Módosítsa úgy a programot, hogy négyzet helyett háromszög 
// jelenjen meg, ami alulról pattanjon vissza! 
// 2.20.3.

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

void clearScreen() {
    std::system("clear"); // Windows esetén: std::system("cls");
}

void wait(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void drawTriangleAt(int y) {
    // Előtte üres sorok
    for (int i = 0; i < y; ++i)
        std::cout << "\n";

    // Háromszög rajzolása (3 soros, középre zárt)
    for (int row = 0; row < 3; ++row) {
        // szóközök a csillagok előtt
        for (int s = 0; s < 2 - row; ++s)
            std::cout << ' ';
        // csillagok (2 * row + 1 darab)
        for (int star = 0; star < 2 * row + 1; ++star)
            std::cout << '*';
        std::cout << "\n";
    }
}

int main() {
    int position = 0;
    bool goingDown = true;
    const int screenHeight = 25;
    const int triangleHeight = 3;
    const int maxY = screenHeight - triangleHeight;

    while (true) {
        clearScreen();
        drawTriangleAt(position);
        wait(1);

        // irányváltás logika
        if (goingDown) {
            if (position >= maxY)
                goingDown = false;
            else
                position++;
        } else {
            if (position <= 0)
                goingDown = true;
            else
                position--;
        }
    }

    return 0;
}
