// 3.34. Amőba játék

// 3.34.1. Írjon egy egyszerű amőba játékot, 3x3-as pályára! Két játékos 
// játszhat a programmal, akik a saját jelüket helyezhetik a mezőkbe 
// felváltva (X vagy O). Az a játékos nyeri a játszmát, akinek 3 jele lesz 
// egy sorban, oszlopban vagy átlóban. Ha nincs több üres cella, vagy a 
// játékosok valamelyike nyer, a játék véget ér. A programnak minden lépés 
// után ki kell rajzolnia a játéktábla aktuális állását karakteresen! 
// Feltételezzük, hogy mindkét játékos megfelelő pozíciót ad meg minden 
// lépésben. 
// Példa bemenet: 
// A B C ------
// 1| | | | ------
// 2| | | | ------
// 3| | | | 
// // ------
// First player 
// Target: A1 A B C ------1|X| | | ------2| | | | ------3| | | 
// | ------Second player Target: B1 A B C ------1|X|O| | ------2| | | | ------3| | 
// | | ------- First player Target: A2 A B C ------1|X|O| | ------2|X| | | 
// ------3| | | | ------Second player Target: A3 A B C ------1|X|O| | ------2|X| | 
// | ------3|O| | | ------First player Target: B2 A B C ------1|X|O| | 
// ------2|X|X| | ------3|O| | | ------- Second player Target: C1 A B C 
// ------1|X|O|O| ------2|X|X| | ------3|O| | | ------First player Target: C3 A B 
// C ------1|X|O|O| ------2|X|X| | ------3|O| |X| ------First player won! 

// 3.34.1.

#include <iostream>
#include <string>
#include <cctype>

const int SIZE = 3;
const char SIGN1 = 'X';
const char SIGN2 = 'O';

using TTable = char[SIZE][SIZE];

void InitTable(TTable table) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            table[i][j] = ' ';
}

void PrintTable(const TTable table) {
    std::cout << "   A   B   C\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << " " << i + 1 << " ";
        for (int j = 0; j < SIZE; ++j) {
            std::cout << "|" << table[j][i];
        }
        std::cout << "|\n";
        std::cout << "  ---+---+---\n";
    }
}

bool Win(const TTable table, char ch) {
    for (int i = 0; i < SIZE; ++i) {
        if ((table[0][i] == ch && table[1][i] == ch && table[2][i] == ch) || // row
            (table[i][0] == ch && table[i][1] == ch && table[i][2] == ch))   // col
            return true;
    }
    return (table[0][0] == ch && table[1][1] == ch && table[2][2] == ch) ||
           (table[2][0] == ch && table[1][1] == ch && table[0][2] == ch);
}

bool Drawn(const TTable table) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (table[i][j] == ' ')
                return false;
    return true;
}

bool ValidCoord(char col, char row, int& x, int& y) {
    col = toupper(col);
    if (col < 'A' || col >= 'A' + SIZE || row < '1' || row >= '1' + SIZE)
        return false;
    x = col - 'A';
    y = row - '1';
    return true;
}

void Play(TTable table) {
    int player = 0;
    std::string input;
    int x, y;

    while (true) {
        PrintTable(table);
        std::cout << (player == 0 ? "First player" : "Second player") << " turn (e.g., A1): ";
        std::cin >> input;
        if (input == "0") {
            std::cout << "Game cancelled.\n";
            return;
        }

        if (input.size() < 2 || !ValidCoord(input[0], input[1], x, y)) {
            std::cout << "Invalid input! Try again.\n";
            continue;
        }

        if (table[x][y] != ' ') {
            std::cout << "Cell already taken! Try another.\n";
            continue;
        }

        table[x][y] = (player == 0 ? SIGN1 : SIGN2);

        if (Win(table, table[x][y])) {
            PrintTable(table);
            std::cout << (player == 0 ? "First" : "Second") << " player won!\n";
            return;
        }

        if (Drawn(table)) {
            PrintTable(table);
            std::cout << "Draw! Game over.\n";
            return;
        }

        player = 1 - player;
    }
}

int main() {
    TTable table;
    InitTable(table);
    Play(table);
    return 0;
}

