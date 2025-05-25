// 2.33. Többszörösen összetett típus
// 2.33.1. Írjon programot, amelyben szemlélteti a karakteres képernyőn a 
// struktúrák elhelyezkedését a memóriában! Hozzon létre egy osztály 
// típusú struktúrát: hallgatók száma, hallgatók Neptun kódjai (statikus 
// sztring tömb), hallgatók pontszámai (statikus lebegőpontos tömb)! Írjon 
// függvényt, amely megjelenti a paraméterként átadott struktúra 
// adattagjainak a címeit és értékeit (a tömb típusú mezőknek csak az 
// első elemét kell megjeleníteni)! Írja ki azt is, hogy milyen más módon 
// tud az adott címre hivatkozni! Ezt az információt is paraméterként adja 
// át a kiíró függvénynek! Hozzon létre kételemű tömböt osztály 
// típusú struktúrákból! Inicializálja a tömböt és hívja meg mindkét 
// elemre a kiíró függvényt! 
// 2.33.1.

#include <iostream>
#include <array>
#include <iomanip>

struct Course {
    int sNum;
    std::array<std::string, 100> sCode;
    std::array<float,       100> sPoints;
};

void printCourse(const Course& c, const std::array<std::array<std::string,3>,4>& comments) {
    // címek
    std::cout << std::left << std::setw(12) << "Address:"
              << std::setw(20) << &c
              << std::setw(20) << &c.sCode
              << &c.sPoints << "\n";

    // értékek (első elem)
    std::cout << std::setw(12) << "Value:"
              << std::setw(20) << c.sNum
              << std::setw(20) << c.sCode[0]
              << c.sPoints[0] << "\n";

    // kommentek
    for (int i = 0; i < 4; ++i) {
        std::cout << std::setw(12) << ""
                  << std::setw(20) << comments[i][0]
                  << std::setw(20) << comments[i][1]
                  << comments[i][2] << "\n";
    }
}

int main() {
    // inicializálás
    Course courses[2];
    courses[0].sNum = 3;
    courses[0].sCode = { "AA34","BE3E","CLY56" };
    courses[0].sPoints = { 16.4f,23.2f,40.0f };

    courses[1].sNum = 2;
    courses[1].sCode = { "NMA444","SE63" };
    courses[1].sPoints = { 13.2f,50.0f };

    std::array<std::array<std::string,3>,4> comments = {{
        { "course[0]",   "",              ""               },
        { "course[0].sNum","course[0].sCode","course[0].sPoints" },
        { "",            "course[0].sCode[0]","course[0].sPoints[0]" },
        { "",            "",              "course[0].sCode[0][0]" }
    }};

    printCourse(courses[0], comments);

    std::cout << "\n";

    // átírjuk a kommenteket index 1-re
    for (auto& row : comments)
        for (auto& cell : row)
            for (auto& ch : cell)
                if (ch=='0') ch='1';

    printCourse(courses[1], comments);

    return 0;
}
