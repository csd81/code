// 3.29. Leltár
// 3.29.1. Egy cég termékek vásárlásával és eladásával foglalkozik. Az 
// év elején 10.000 Ft-ja van. Egy fájlban tárolja az információkat a 
// termékekről, az eladásokról és a beszerzésekről. Írjon programot, amely 
// a fájlból beolvassa az adatokat, és megmondja az egyes termékek 
// mennyiségét, illetve a cég egyenlegét az eladások és beszerzések után! 
// Használjon dinamikus tömböket és struktúrákat az adatok tárolására! Az 
// input fájl formátuma: Első sor: Number1 - a termékek száma A következő 
// Number1 db sor: String Number2 Number3 Number4 String: az i-edik termék neve 
// Number2: az i-edik termék mennyisége Number3: az i-edik termék beszerzési 
// ára Number4: az i-edik termék eladási ára Number5: a termékekkel 
// kapcsolatos adás-vételek száma Az ezután következő Number5 db sor: 
// Number6 Number7 Number6: Az aktuális termék indexe (nem a neve, hanem a 
// sorszáma) Number7: Ha ez a szám pozitív, a cég beszerzett a Number6-os 
// termékből Number7 db-ot, beszerzési áron;
// ha negatív, akkor a cég a Number6-os termékből eladott Number7 abszolút 
// értékének megfelelő számú darabot, eladási áron. Példa bemenet: 2 
// hammer 100 500 800 screwdriver 50 300 400 2 1 10 2 -5 A példafájl esetében 
// kétféle termékünk van: 100 db hammer és 50 db screwdriver. A cég 500 
// Ft-ért tud hammer-t beszerezni, és 800 Ft-ért tudja eladni. 2 féle 
// termékmozgás történt, először vásároltak 500 Ft/db áron 10 db 
// hammer-t, majd 400 Ft/db áron eladtak 5 db screwdriver-t. Kimenet: Inventory: 
// **************************************** hammer: Count: 100 Purchase price: 500 
// Shop price: 800 screwdriver: Count: 50 Purchase price: 300 Shop price: 400 
// Inventory: **************************************** hammer: Count: 110 Purchase 
// price: 500 Shop price: 800 screwdriver: Count: 45 Purchase price: 300 Shop 
// price: 400 We have got 7000 HUF 
// 3.29.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>

const std::string DEFAULT_INPUTFILE = "inventory.txt";
const int START_MONEY = 10000;

struct Good {
    std::string name;
    int count;
    int purchasePrice;
    int shopPrice;
};

void printInventory(const std::vector<Good>& goods) {
    std::cout << "Inventory:\n****************************************\n";
    for (const auto& g : goods) {
        std::cout << g.name << ":\n"
                  << "\tCount: " << g.count << "\n"
                  << "\tPurchase price: " << g.purchasePrice << "\n"
                  << "\tShop price: " << g.shopPrice << "\n";
    }
}

std::vector<Good> readGoods(std::ifstream& in) {
    int num;
    in >> num;
    std::vector<Good> goods(num);
    for (int i = 0; i < num; ++i) {
        in >> goods[i].name >> goods[i].count >> goods[i].purchasePrice >> goods[i].shopPrice;
    }
    return goods;
}

int applyTransactions(std::ifstream& in, std::vector<Good>& goods, int startingMoney) {
    int numLogs;
    in >> numLogs;
    int balance = startingMoney;

    for (int i = 0; i < numLogs; ++i) {
        int productIndex, amount;
        in >> productIndex >> amount;

        --productIndex; // zero-based indexing

        if (productIndex < 0 || productIndex >= static_cast<int>(goods.size())) {
            std::cerr << "Invalid product index: " << productIndex + 1 << "\n";
            continue;
        }

        goods[productIndex].count += amount;

        if (amount > 0)
            balance -= amount * goods[productIndex].purchasePrice;
        else
            balance += std::abs(amount) * goods[productIndex].shopPrice;
    }

    return balance;
}

int main(int argc, char* argv[]) {
    std::string filename = (argc > 1) ? argv[1] : DEFAULT_INPUTFILE;
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Error opening file: " << filename << "\n";
        return EXIT_FAILURE;
    }

    try {
        std::vector<Good> goods = readGoods(in);

        printInventory(goods);

        int finalMoney = applyTransactions(in, goods, START_MONEY);

        printInventory(goods);

        std::cout << "We have got " << finalMoney << " HUF\n";
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

