// c++11
// 4.2.2. Írjon függvényt a lista kiíratásához! Egyenként adjon elemeket a listához és írja ki az eredmény listát! 
// 4.2.3. Módosítsa úgy az előző programot, hogy jelezze, ha nem sikeres az elem hozzáadása, mert betelt a tároló tömb! Dinamikus tömbben tárolja a listát, ha tömb betelne, akkor foglaljon le egy nagyobb tömböt! Valósítsa meg a lista végére beszúró függvényt! 4.3. Lista szerkezet

// 4.2.2.-4.2.3.

// c++11
#include <iostream>
#include <string>

// Element in our “linked list in an array”
struct Element {
    std::string name;
    int age;
    int next;  // -1 = end of list, -2 = unused
};

static int capacity;
static Element* arr;
static int head, tail;

// Find a free slot, resizing the array if necessary
int getFreeSlot() {
    // look for an unused slot
    for (int i = 0; i < capacity; ++i) {
        if (arr[i].next == -2) {
            return i;
        }
    }
    // none free → resize array
    int oldCap = capacity;
    capacity *= 2;
    std::cout << "Array full; reallocating to capacity " << capacity << "\n";
    Element* newArr = new Element[capacity];
    // copy old data
    for (int i = 0; i < oldCap; ++i) {
        newArr[i] = arr[i];
    }
    // mark new slots unused
    for (int i = oldCap; i < capacity; ++i) {
        newArr[i].next = -2;
    }
    delete[] arr;
    arr = newArr;
    return oldCap;  // first new free slot
}

// Insert at front
void addFirst(const std::string& name, int age) {
    int idx = getFreeSlot();
    arr[idx].name = name;
    arr[idx].age  = age;
    arr[idx].next = head;
    head = idx;
    if (tail == -1) {
        // first element
        tail = idx;
    }
}

// Insert at end
void addLast(const std::string& name, int age) {
    int idx = getFreeSlot();
    arr[idx].name = name;
    arr[idx].age  = age;
    arr[idx].next = -1;
    if (tail == -1) {
        // empty list
        head = tail = idx;
    } else {
        arr[tail].next = idx;
        tail = idx;
    }
}

// Print the list from head
void printList() {
    std::cout << "[";
    bool first = true;
    for (int cur = head; cur != -1; cur = arr[cur].next) {
        if (!first) std::cout << ", ";
        std::cout << "(" << arr[cur].name << ", " << arr[cur].age << ")";
        first = false;
    }
    std::cout << "]\n";
}

int main() {
    // Initial small capacity
    capacity = 3;
    arr = new Element[capacity];
    for (int i = 0; i < capacity; ++i) {
        arr[i].next = -2;  // mark all slots unused
    }
    head = tail = -1;

    std::cout << "Initial list: ";
    printList();

    // Add one element at front
    {
        std::string name;
        int age;
        std::cout << "addFirst - name: ";
        std::cin >> name;
        std::cout << "addFirst - age:  ";
        std::cin >> age;
        addFirst(name, age);
        printList();
    }

    // Now add several at end, prompting each time
    for (int i = 0; i < 11; ++i) {
        std::string name;
        int age;
        std::cout << "addLast  - name: ";
        std::cin >> name;
        std::cout << "addLast  - age:  ";
        std::cin >> age;
        addLast(name, age);
        printList();
    }

    delete[] arr;
    return 0;
}

