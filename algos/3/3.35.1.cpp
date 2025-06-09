// 3.35.  Térkép

// 3.35.1. Egy fájl egy magassági térképet tartalmaz. A magasságok pozitív 
// egész számok. Írjon programot, amely beolvassa ezt a térképet egy 
// mátrixba, kiírja a képernyőre és kiszámítja az adott területen az 
// alföld, dombság, hegység és magashegység arányát! A mátrix legyen 
// dinamikus! A magassági intervallumok a következők: 0 <= magasság < 250 250 
// <= magasság < 500 500 <= magasság < 1500 1500 <= magasság alföld dombság 
// hegység magashegység Az input fájl formátuma: Első sor: number1 number2 A 
// number1 a sorok, number2 az oszlopok számát adja meg. Ezután number1 db sor 
// következik, minden sorban number2 db, szóköz karakterrel elválasztott 
// érték található. 

// Példa bemenet: 5 5 200 210 220 218 230 0 1600 322 31 1000 
// 332 320 43 1 545 2000 32 252 0 321 1320 2123 324 21 43 

// Kimenet: 200 210 220 218 
// 230 0 1600 322 31 1000 332 320 1 545 2000 32 252 0 321 1320 2123 324 Lowland: 
// 52 % Hill: 24 % Mountain: 12 % High mountain: 12 % 

// 3.35.1.

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

const int HILL = 250;
const int MOUNTAIN = 500;
const int HIGHMOUNTAIN = 1500;

using Map = std::vector<std::vector<int>>;

void readMap(std::ifstream& file, Map& map, int& rows, int& cols) {
    file >> rows >> cols;
    map.resize(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            file >> map[i][j];
}

void printMap(const Map& map) {
    std::cout << "\nThe map:\n\n";
    for (const auto& row : map) {
        for (int val : row)
            std::cout << std::setw(5) << val;
        std::cout << '\n';
    }
}

void countTerrains(const Map& map) {
    int lowland = 0, hill = 0, mountain = 0, highmountain = 0;
    int total = 0;

    for (const auto& row : map) {
        for (int h : row) {
            ++total;
            if (h < HILL)
                ++lowland;
            else if (h < MOUNTAIN)
                ++hill;
            else if (h < HIGHMOUNTAIN)
                ++mountain;
            else
                ++highmountain;
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nLowland: "       << (lowland * 100.0 / total)      << " %\n";
    std::cout << "Hill: "            << (hill * 100.0 / total)         << " %\n";
    std::cout << "Mountain: "        << (mountain * 100.0 / total)     << " %\n";
    std::cout << "High mountain: "   << (highmountain * 100.0 / total) << " %\n\n";
}

int main(int argc, char* argv[]) {
    std::string filename = (argc > 1) ? argv[1] : "map1.txt";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Hiba a fájl megnyitásakor: " << filename << '\n';
        return 1;
    }

    Map map;
    int rows, cols;
    readMap(file, map, rows, cols);
    file.close();

    printMap(map);
    countTerrains(map);

    return 0;
}

