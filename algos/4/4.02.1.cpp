// c++11
// 4.2.1. Készítsen programot, amelyben egy (nem ciklikus) láncolt listát statikus tömbbel reprezentál, úgy, hogy a tömb rekordokat tartalmaz, amelyekben név, életkor és a következő elem indexe adattag szerepel! írjon függvényt, amely a lista elejére fűz be új elemet! Az új rekord helyét a tömbben véletlen szám generátorral határozza meg a következő módon: létrehoz egy véletlen indexet;
// ha az azon indexhez tartozó rekord következő elem adattag értéke -2, akkor a kérdéses rekord nem tartalmaz hasznos információt vagyis nem használt rekordról van szó;
// egyébként nézzünk meg egy másik véletlen indexű elemet! (A módszer hátránya, hogy ha nincs több szabad hely, akkor a foglalás végtelen ciklusba kerül, a korrekt megoldás az lenne, ha külön tartanánk nyílván a szabad helyeket.) 

// c++11
#include <iostream>
#include <string>
#include <array>
#include <random>
#include <iomanip>

struct Element {
    std::string name;
    int age;
    int next;   // index of next element in list, -1=end, -2=unused
};

// Print the list starting at head
void printList(int head, const std::array<Element,5>& list) {
    std::cout << "[";
    for (int cur = head; cur != -1; cur = list[cur].next) {
        std::cout << "(" << list[cur].name << ", " << list[cur].age << ")";
        if (list[cur].next != -1) std::cout << ", ";
    }
    std::cout << "]\n";
}

// Find a free slot by random trials; assumes at least one slot has next == -2
int freeSpace(const std::array<Element,5>& list) {
    static std::mt19937_64 eng{333};                        // fixed seed
    std::uniform_int_distribution<int> dist(0, list.size()-1);
    int idx;
    do {
        idx = dist(eng);
    } while (list[idx].next != -2);
    return idx;
}

// Insert a new element at the front of the list
void addFirst(int& head, std::array<Element,5>& list) {
    std::string name;
    int age;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter age:  ";
    std::cin >> age;

    int slot = freeSpace(list);
    list[slot].name = name;
    list[slot].age = age;
    list[slot].next = head;  // old head (could be -1)
    head = slot;
}

int main(){
    // 0..4 array, all slots initially unused (next = -2)
    std::array<Element,5> list;
    for (auto& e : list) {
        e.next = -2;
    }
    int head = -1; // empty list

    std::cout << "Initial list: ";
    printList(head, list);

    // Add three elements at front
    for (int i = 0; i < 3; ++i) {
        addFirst(head, list);
        std::cout << "After addFirst: ";
        printList(head, list);
    }

    return 0;
}

