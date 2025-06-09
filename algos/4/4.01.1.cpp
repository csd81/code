// c++11
// 4.1.1. Készítsen programot, amelyben egy (nem ciklikus) láncolt listát két tömbbel reprezentál! Az egyik tömb az elemek értékeit, a másik a következő elem indexét tartalmazza. Egész változó tartalmazza a lista első elemének az indexét! Inicializálja a tömböket a következő értékekkel: értékek: {34, 12.55, 893.2, 2, 11.6, 47.5, 45.3}, indexek: {-1, 0, 4, 1, 6, 3, 5}! A kettes indexű elem a lista első tagja. Írjon függvényt a lista elemeinek listázáshoz! Írjon függvényt az utolsó elem törléséhez, törölje egyenként az elemeket és minden törlés után listázza az elemeket! Hogyan kell módosítani a programot, ha törlés után elem beszúrása következik? 
 

#include <iostream>
#include <iomanip>

static const int LIST_SIZE = 7;

// Print the list values starting from head
void printList(int head, const int nextIdx[], const double data[]) {
    std::cout << "[";
    int idx = head;
    bool first = true;
    while (idx != -1) {
        if (!first) std::cout << ", ";
        first = false;
        std::cout << std::fixed << std::setprecision(2) << data[idx];
        idx = nextIdx[idx];
    }
    std::cout << "]\n";
}

// Delete the last element in the list
void deleteLast(int &head, int nextIdx[]) {
    if (head == -1) return;
    // single element
    if (nextIdx[head] == -1) {
        head = -1;
        return;
    }
    // find penultimate
    int prev = head;
    int cur  = nextIdx[head];
    while (nextIdx[cur] != -1) {
        prev = cur;
        cur  = nextIdx[cur];
    }
    // remove last
    nextIdx[prev] = -1;
}

int main() {
    double data[LIST_SIZE] = {34, 12.55, 893.2, 2, 11.6, 47.5, 45.3};
    int nextIdx[LIST_SIZE] = {-1,   0,     4,     1,    6,    3,    5};
    int head = 2;  // start at index 2

    std::cout << "Initial list: ";
    printList(head, nextIdx, data);

    // delete until empty
    while (head != -1) {
        deleteLast(head, nextIdx);
        printList(head, nextIdx, data);
    }

    return 0;
}
