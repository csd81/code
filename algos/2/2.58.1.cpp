// 2.58. Hanoi tornyai
// 2.58.1. A Hanoi tornyai játék 3 rudat tartalmaz (start, segéd, cél). Az 
// első rúdon N db korong van egymás fölött, amelyek különböző 
// méretűek. A korongok fentről lefelé növekvő sorrendben következnek, 
// legnagyobb van legalul, a legkisebb legfelül, ahogyan az ábrán látható. A 
// feladat a következő: a korongokat át kell rakni a start rúdról a célra, a 
// segédrúd segítségével. Az átrakás szabálya, hogy nagyobb korongot 
// kisebbre nem rakhatunk rá. Írjon programot ennek a feladatnak a 
// szimulálására! A program argumentumként megkapja N értékét. Kezdetben 
// minden korong a start rúdon van. Minden lépésben kérdezze meg, melyik 
// rúdról melyikre tegyük át a legfelső korongot! Ha ez nem ellenkezik a 
// szabályokkal, helyezzük át a korongot! Minden mozgatás után írja ki a 
// képernyőre a korongok helyzetét, a példában látható módon! Ha a 
// felhasználó 0-t gépel, vagy minden korong a cél rúdon van, a program 
// véget ér. Használjon dinamikus tömböket és struktúrákat a korongok 
// helyének tárolására! 2.4. ábra: Hanoi tornyai szemléltetése Példa 
// bemenet: ************************************* Source: 3, 2, 1 Auxiliary: 0 
// Destination: 0 From: aux To: src Incorrect step! 
// ************************************* Source: 3, 2, 1 Auxiliary: 0 Destination: 
// 0 From: src To: aux ************************************* Source: 3, 2 
// Auxiliary: 1 Destination: 0 From: src To: dst 
// ************************************* Source: 3 Auxiliary: 1 Destination: 2 
// From: aux To: dst ************************************* Source: 3 Auxiliary: 0 
// Destination: 2, 1 From: 0 The disks are not on the destination! 
// ************************************* Source: 3 Auxiliary: 0 Destination: 2, 1 
// 2.58.1.


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>

const int DEFAULT_RINGNUM = 3;

struct Tower {
    std::vector<int> disks;
    std::string name;
    int maxHeight;

    Tower(int height, bool full, const std::string& towerName)
        : disks(full ? height : 0), name(towerName), maxHeight(height) {
        if (full) {
            for (int i = height; i >= 1; --i)
                disks[height - i] = i;
        }
    }

    void print() const {
        std::cout << name << ": ";
        if (disks.empty()) {
            std::cout << "0\n";
            return;
        }
        for (size_t i = 0; i < disks.size(); ++i) {
            std::cout << disks[i];
            if (i < disks.size() - 1) std::cout << ", ";
        }
        std::cout << "\n";
    }

    int top() const {
        return disks.empty() ? 0 : disks.back();
    }

    void push(int val) {
        disks.push_back(val);
    }

    int pop() {
        int val = disks.back();
        disks.pop_back();
        return val;
    }

    bool isComplete() const {
        if (disks.size() != static_cast<size_t>(maxHeight)) return false;
        for (int i = maxHeight; i >= 1; --i)
            if (disks[maxHeight - i] != i)
                return false;
        return true;
    }
};

int getIndex(const std::string& name) {
    if (name == "src") return 0;
    if (name == "aux") return 1;
    if (name == "dst") return 2;
    return -1;
}

bool isMoveValid(int from, int to, const std::vector<Tower>& towers) {
    if (from < 0 || to < 0 || from == to) return false;
    if (towers[from].disks.empty()) return false;
    if (!towers[to].disks.empty() && towers[from].top() > towers[to].top()) return false;
    return true;
}

int main(int argc, char* argv[]) {
    int maxRings = argc > 1 ? std::atoi(argv[1]) : DEFAULT_RINGNUM;

    std::vector<Tower> towers;
    towers.emplace_back(maxRings, true, "Source");
    towers.emplace_back(maxRings, false, "Auxiliary");
    towers.emplace_back(maxRings, false, "Destination");

    std::string from, to;
    bool giveUp = false;

    do {
        std::cout << "\n\n*************************************\n\n";
        for (const auto& t : towers) t.print();

        std::cout << "From: ";
        std::cin >> from;
        if (from != "0") {
            std::cout << "To: ";
            std::cin >> to;
        }

        giveUp = (from == "0" || to == "0");

        if (!giveUp) {
            int f = getIndex(from);
            int t = getIndex(to);
            if (isMoveValid(f, t, towers)) {
                int disk = towers[f].pop();
                towers[t].push(disk);
            } else {
                std::cout << "Incorrect step!\n";
            }
        }

    } while (!giveUp && !towers[2].isComplete());

    std::cout << "\n\n*************************************\n\n";
    for (const auto& t : towers) t.print();

    if (giveUp)
        std::cout << "The disks are not on the destination!\n";
    else
        std::cout << "The disks are on their place!\n";

    return 0;
}
