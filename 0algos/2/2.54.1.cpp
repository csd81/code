// 2.54. Hazárdjáték
// 2.54.1. Írjon hazárdjátékot! A szabályok a következők: A játék 
// kezdetekor a játékosnak 1000 Ft-ja van. A program generál egy véletlen 
// számot, a játékosnak pedig meg kell adnia egy tippet, és egy tétet. Ha 
// eltalálja a számot, megkapja a tét összegét, ha nem, elveszíti. Ezután a 
// program megkérdezi: „Try again? (y/n)”, a játékosnak pedig egy „y” 
// vagy egy „n” karakterrel kell válaszolnia. Ha újból próbálkozik, akkor 
// a program új számot generál. A játék addig folytatódik, amíg a 
// játékosnak van pénze, vagy amíg nem szeretné befejezni a játékot. 3 
// különböző szint van: a „könnyű”, amelyben a program 1 és 5 közötti 
// számot generál, a „közepes”, amelyben 1 és 10 közötti számot 
// generál, és a „nehéz”, amelyben 1 és 15 közötti számot generál. A 
// szintet a játék megkezdése előtt választja ki a játékos, egy egyszerű 
// menü segítségével. A játék végén a program írja ki a képernyőre, 
// mennyit nyert vagy veszített a játékos. Példa játék: Choose the 
// difficulty! Easy:...........1 Medium:.........2 Hard:...........3 2 You have 
// 1000 HUF now. Take your stake: 10 What's your tip (1..10)? 5 You've hit the 
// number! You have 1010 HUF! Try again? (y/n) y Take your stake: 1000 What's your 
// tip (1..10)? 1 The number was 7 You have 10 HUF! Try again? (y/n) n 
// Congratulations! You get 10 HUF! 

// 2.54.1.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

const int MIN_TIP = 1;
const int EASY_MAX = 5;
const int MEDIUM_MAX = 10;
const int HARD_MAX = 15;
const int START_MONEY = 1000;

int getStake() {
    int stake;
    do {
        std::cout << "Take your stake: ";
        std::cin >> stake;
        if (stake <= 0)
            std::cout << "The stake must be greater than zero!\n";
    } while (stake <= 0);
    return stake;
}

int getTip(int min, int max) {
    int tip;
    do {
        std::cout << "What's your tip (" << min << ".." << max << ")? ";
        std::cin >> tip;
        if (tip < min || tip > max)
            std::cout << "The tip must be between " << min << " and " << max << "!\n";
    } while (tip < min || tip > max);
    return tip;
}

int getMax() {
    int difficulty;
    do {
        std::cout << "Choose the difficulty!\n\n";
        std::cout << "\tEasy:...........1\n";
        std::cout << "\tMedium:.........2\n";
        std::cout << "\tHard:...........3\n\n";
        std::cin >> difficulty;
        if (difficulty < 1 || difficulty > 3)
            std::cout << "Wrong number!\n";
    } while (difficulty < 1 || difficulty > 3);

    switch (difficulty) {
        case 1: return EASY_MAX;
        case 2: return MEDIUM_MAX;
        case 3: return HARD_MAX;
    }
    return 0; // Should never reach here
}

int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int money = START_MONEY;
    int maxRange = getMax();
    std::cout << "You have " << money << " HUF now.\n";

    std::string again;

    do {
        std::cout << "\n\n";
        int stake = getStake();
        if (stake > money) {
            std::cout << "You don't have enough money! Try again.\n";
            continue;
        }

        int num = getRandom(MIN_TIP, maxRange);
        int tip = getTip(MIN_TIP, maxRange);

        if (tip == num) {
            money += stake;
            std::cout << "You've hit the number!\nYou have " << money << " HUF!\n";
        } else {
            std::cout << "The number was " << num << "\n";
            money -= stake;
            std::cout << "You have " << money << " HUF!\n";
        }

        if (money > 0) {
            std::cout << "Try again? (y/n): ";
            std::cin >> again;
        }

    } while ((money > 0) && (again[0] == 'y' || again[0] == 'Y'));

    if (money > 0)
        std::cout << "Congratulations!\nYou get " << money << " HUF!\n";
    else
        std::cout << "I'm sorry, you lost everything.\n";

    return 0;
}
