// 3.18. Virtuális memória
// 3.18.1. Kérje be egy lebegőpontos tömb méretét! Ha az 5 vagy kisebb, 
// akkor hozzon létre dinamikus tömböt a memóriában, ha nagyobb, akkor pedig 
// bináris fájlt a háttértáron! Készítsen struktúrát, amely tartalmaz egy 
// FILE*, double* és méret adattagot! Készítsen függvényeket: tároló 
// inicializálására és felszabadítására, tároló adott pozíciójában 
// történő olvasásra és írásra. Menüben kérje be, hogy írni vagy olvasni 
// akar, a fő függvény számára a tárolás módja legyen transzparens! 
// 3.18.1.


#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

const int limit = 5;
const std::string tempFilename = "temp.bin";

struct Store {
    std::fstream file;
    std::vector<double> memory;
    long size = 0;
    bool useFile = false;
};

void initStore(Store& store) {
    std::cout << "Size of the array: ";
    std::cin >> store.size;

    if (store.size > limit) {
        store.useFile = true;
        store.file.open(tempFilename, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
        if (!store.file) {
            std::cerr << "Failed to open temporary file!\n";
            std::exit(1);
        }

        // Initialize file with zeros
        double zero = 0.0;
        for (long i = 0; i < store.size; ++i) {
            store.file.write(reinterpret_cast<char*>(&zero), sizeof(double));
        }
    } else {
        store.memory.resize(store.size, 0.0);
    }
}

void delStore(Store& store) {
    if (store.useFile) {
        store.file.close();
        std::remove(tempFilename.c_str()); // clean up file
    } else {
        store.memory.clear();
    }
}

void readStore(Store& store) {
    int idx;
    std::cout << "Index of element to read: ";
    std::cin >> idx;

    if (idx < 0 || idx >= store.size) {
        std::cerr << "Invalid index.\n";
        return;
    }

    double result = 0.0;
    if (store.useFile) {
        store.file.seekg(idx * sizeof(double), std::ios::beg);
        store.file.read(reinterpret_cast<char*>(&result), sizeof(double));
    } else {
        result = store.memory[idx];
    }

    std::cout << "At " << idx << " there is: " << result << "\n";
}

void writeStore(Store& store) {
    int idx;
    double value;
    std::cout << "Index of element to write: ";
    std::cin >> idx;
    std::cout << "Value: ";
    std::cin >> value;

    if (idx < 0 || idx >= store.size) {
        std::cerr << "Invalid index.\n";
        return;
    }

    if (store.useFile) {
        store.file.seekp(idx * sizeof(double), std::ios::beg);
        store.file.write(reinterpret_cast<const char*>(&value), sizeof(double));
        store.file.flush();
    } else {
        store.memory[idx] = value;
    }

    std::cout << value << " is written at " << idx << "\n";
}

int main() {
    Store store;
    initStore(store);

    int selection = 0;
    while (selection != 3) {
        std::cout << "\nRead - 1\nWrite - 2\nQuit - 3\n";
        std::cin >> selection;

        switch (selection) {
            case 1:
                readStore(store);
                break;
            case 2:
                writeStore(store);
                break;
            case 3:
                break;
            default:
                std::cout << "Invalid selection.\n";
        }
    }

    delStore(store);
    return 0;
}
