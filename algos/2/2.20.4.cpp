// 2.20.4. Négyzet helyett téglalap mozogjon vízszintesen a szélekről visszapattanva! 
// 2.20.4.


#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>

void clearScreen() {
    std::system("clear"); // Windows esetén: std::system("cls");
}

void wait(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void drawRectangleAt(int x, int width = 5, int height = 3) {
    std::string space(x, ' ');
    std::string stars(width, '*');
    for (int i = 0; i < height; ++i)
        std::cout << space << stars << '\n';
}

int main() {
    const int screenWidth = 80;
    const int rectWidth = 5;
    const int maxX = screenWidth - rectWidth;
    int x = 0;
    bool movingRight = true;

    while (true) {
        clearScreen();
        drawRectangleAt(x);

        wait(1);

        if (movingRight) {
            if (x >= maxX)
                movingRight = false;
            else
                x++;
        } else {
            if (x <= 0)
                movingRight = true;
            else
                x--;
        }
    }

    return 0;
}
