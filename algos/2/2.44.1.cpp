// 2.44. Milyen nap?
// 2.44.1. Írjon programot, amely véletlenszerűen meghatároz egy évet, 
// hónapot, napot és utána tippelni kell, hogy az a hét illetve év napjai 
// közül a hányadik! Adja meg hogy helyesek voltak-e a tippek! 
// 2.44.1.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>

int main() {
    int year, month, day, guessWeekDay, guessYearDay;
    std::tm tmBuffer = {};

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    year = std::rand() % 40 + 1970;
    month = std::rand() % 12 + 1;
    day = std::rand() % 30 + 1;

    tmBuffer.tm_year = year - 1900;  // tm_year: years since 1900
    tmBuffer.tm_mon = month - 1;     // tm_mon: 0-11
    tmBuffer.tm_mday = day;
    tmBuffer.tm_hour = 0;
    tmBuffer.tm_min = 0;
    tmBuffer.tm_sec = 0;
    tmBuffer.tm_isdst = -1;

    std::cout << "What is the day of the week on " << month << "/" << day << " " << year << "?\n";
    std::cout << "0 - Sunday, 1 - Monday, ..., 6 - Saturday\nYour guess: ";
    std::cin >> guessWeekDay;

    std::mktime(&tmBuffer);  // fills in tm_wday and tm_yday

    char buffer[30];
    std::strftime(buffer, sizeof(buffer), "%A", &tmBuffer);

    if (tmBuffer.tm_wday == guessWeekDay) {
        std::cout << "You are right! " << month << "/" << day << " " << year << " is really " << buffer << ".\n";
    } else {
        std::cout << "You are wrong. " << month << "/" << day << " " << year << " is " << buffer << ".\n";
    }

    std::cout << "\nWhat is the day of the year on the same date? ";
    std::cin >> guessYearDay;

    if (tmBuffer.tm_yday == guessYearDay) {
        std::cout << "You are right! " << month << "/" << day << " " << year
                  << " is the " << tmBuffer.tm_yday << "th day of the year.\n";
    } else {
        std::cout << "You are wrong. " << month << "/" << day << " " << year
                  << " is the " << tmBuffer.tm_yday << "th day of the year.\n";
    }

    return 0;
}
