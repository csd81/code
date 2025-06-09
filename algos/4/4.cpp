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
// c++11
// 4.1.2. Írjon függvényt, amely a lista első elemét törli! Írjon függvényt, amely ellenőrzi, hogy az tömb konzisztens-e, vagyis a benne lévő indexek a megengedett tartományban vannak-e, a start elemtől indulva nem jelentkezik kör! 

#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>

void printList(int head,
               const std::vector<int>& nextIdx,
               const std::vector<double>& data)
{
    std::cout << "[";
    for (int cur = head; cur != -1; cur = nextIdx[cur]) {
        std::cout << std::fixed << std::setprecision(2) << data[cur];
        if (nextIdx[cur] != -1) std::cout << ", ";
    }
    std::cout << "]\n";
}

// Deletes the first node in the list.
// head: index of first element (or -1 if empty).
// nextIdx: array of next‐indices; after removal, nextIdx[oldHead] is set to -1.
void deleteFirst(int& head, std::vector<int>& nextIdx) {
    if (head == -1) return;
    int old = head;
    head = nextIdx[old];
    nextIdx[old] = -1;
}

// Returns true if the list starting at head is well‐formed:
// 1) all visited indices are in [0..n-1]
// 2) no index is visited twice (no cycle)
// 3) traversal ends at -1
bool isConsistent(const std::vector<int>& nextIdx, int head) {
    int n = nextIdx.size();
    std::unordered_set<int> seen;
    int cur = head;
    while (cur != -1) {
        // 1) range check
        if (cur < 0 || cur >= n) {
            std::cerr << "Index out of bounds: " << cur << "\n";
            return false;
        }
        // 2) cycle check
        if (seen.count(cur)) {
            std::cerr << "Cycle detected at index: " << cur << "\n";
            return false;
        }
        seen.insert(cur);
        cur = nextIdx[cur];
    }
    return true;
}

int main() {
    // Initial data
    std::vector<double> data   = { 34, 12.55, 893.2, 2, 11.6, 47.5, 45.3 };
    std::vector<int>    nextIdx= { -1,   0,      4,     1,   6,    3,    5   };
    int head = 2;  // start at index 2

    std::cout << "Original list: ";
    printList(head, nextIdx, data);

    // Delete first element
    deleteFirst(head, nextIdx);
    std::cout << "After deleteFirst: ";
    if (!isConsistent(nextIdx, head)) {
        std::cout << "List is inconsistent!\n";
        return 1;
    }
    printList(head, nextIdx, data);

    return 0;
}

// c++11
// 4.1.3. Valósítsa meg hasonló módon a ciklikus listát! Listázáskor lehessen megadni, hogy honnan kezdődjék a kiírás! 4.2. Lista egy tömbbel


// c++11
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    const int N = 7;
    // Values and next‐indices for a cyclic list
    std::vector<double> data   = {34, 12.55, 893.2, 2, 11.6, 47.5, 45.3};
    std::vector<int>    nextIx = { 1,    2,    3,   4,    5,    6,    0   };

    int head;
    std::cout << "From which index should the cyclic list start? (0–" 
              << (N-1) << "): ";
    std::cin >> head;
    if (head < 0 || head >= N) {
        std::cerr << "Invalid start index!\n";
        return 1;
    }

    std::cout << "List starting at " << head << ": [";
    int cur = head;
    for (int i = 0; i < N; ++i) {
        std::cout << std::fixed << std::setprecision(2) << data[cur];
        if (i + 1 < N) std::cout << ", ";
        cur = nextIx[cur];
    }
    std::cout << "]\n";

    return 0;
}
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

// c++11
// 4.3.1. A karakteres képernyőn jelenítsen meg egy 3 hosszú, egyszeresen láncolt listát! A listát közvetlen értékadásokkal hozza létre, jelenítse meg a listát reprezentáló fej változót is! 4.1. ábra: Lehetséges képernyőkép

// c++11
#include <iostream>
#include <iomanip>

struct Node {
    int data;
    Node* next;
};

void displayNode(Node* n) {
    std::cout << "[" << n->data << ", " 
              << n->next << "] -> ";
}

int main() {
    // 1) Create three nodes with direct initialization
    Node n1{12, nullptr};
    Node n2{45, nullptr};
    Node n3{ 7, nullptr};

    // 2) Link them into a singly‐linked list
    n1.next = &n2;
    n2.next = &n3;
    n3.next = nullptr;

    // 3) The head pointer
    Node* head = &n1;

    // 4) Display the list
    std::cout << "List elements:\n  ";
    for (Node* p = head; p; p = p->next) {
        displayNode(p);
    }
    std::cout << "NULL\n\n";

    // 5) Display the head variable and its address
    std::cout << std::hex << std::showbase;
    std::cout << "head       = " << head << "\n";
    std::cout << "&head      = " << &head << "\n";
    std::cout << "head->next = " << head->next << "\n";

    return 0;
}
// c++11
// 4.3.2. Hasonló módon jelenítse meg az oda-vissza láncolt listát! 4.4. Láncolt lista dinamikus rekordokkal

// c++11
#include <iostream>
#include <iomanip>

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

void displayForward(Node* head) {
    std::cout << "Forward: ";
    for (Node* p = head; p; p = p->next) {
        std::cout << "[" << p->data << ", next=" << p->next << "] -> ";
    }
    std::cout << "NULL\n";
}

void displayBackward(Node* tail) {
    std::cout << "Backward: ";
    for (Node* p = tail; p; p = p->prev) {
        std::cout << "[" << p->data << ", prev=" << p->prev << "] -> ";
    }
    std::cout << "NULL\n";
}

int main() {
    // 1) Create three nodes
    Node n1(12), n2(45), n3(7);

    // 2) Link them
    n1.next = &n2;
    n2.prev = &n1;
    n2.next = &n3;
    n3.prev = &n2;

    // 3) Identify head and tail
    Node* head = &n1;
    Node* tail = &n3;

    // 4) Display forward and backward
    std::cout << std::hex << std::showbase;
    displayForward(head);
    std::cout << " head address: " << head
              << "  &head: " << &head << "\n";
    displayBackward(tail);
    std::cout << " tail address: " << tail
              << "  &tail: " << &tail << "\n";

    return 0;
}
// c++11
// 4.4.1. Írjon programot, amely dinamikus struktúrákkal valósítja meg az egyszeresen láncolt listát! Minden rekord tárolja a következő adatokat egy motorról: név, ár, teljesítmény! Valósítsa meg a beszúrást az x. elem után, a listázást és a listatörlést függvényekkel! Ha nincs x darab eleme a listának, akkor a lista végére szúrjon be! Őrszemmel tárolja a lista fejét! Adjon 4 elemet a listához, mindig a második elem után! 


// c++11
#include <iostream>
#include <string>

// Node for a singly‐linked list storing motorcycle data
struct Node {
    std::string name;
    int price;
    double power;
    Node* next;
    Node(const std::string& n, int p, double pw)
      : name(n), price(p), power(pw), next(nullptr) {}
};

// Create a new node by reading from stdin
Node* createNode() {
    std::string name;
    int price;
    double power;

    std::cout << "Enter motorcycle name: ";
    std::cin >> name;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter power: ";
    std::cin >> power;

    return new Node(name, price, power);
}

// Insert newNode after the x-th real element (1-based).
// If the list has fewer than x elements, appends at the end.
// sentinel is a dummy head whose .next points to the first real node.
void insertAfter(Node* sentinel, Node* newNode, int x) {
    Node* prev = sentinel;
    Node* cur = sentinel->next;
    int remaining = x;

    // Move forward up to x steps, or until cur is null
    while (remaining > 0 && cur) {
        prev = cur;
        cur = cur->next;
        --remaining;
    }
    // Splice newNode between prev and cur
    prev->next = newNode;
    newNode->next = cur;
}

// Print all elements in the list
void listList(Node* sentinel) {
    std::cout << "List elements:\n";
    Node* cur = sentinel->next;
    int idx = 1;
    while (cur) {
        std::cout << "  " << idx++
                  << ". (name: " << cur->name
                  << ", price: " << cur->price
                  << ", power: " << cur->power
                  << ")\n";
        cur = cur->next;
    }
    if (idx == 1) {
        std::cout << "  [empty]\n";
    }
}

// Delete all real nodes and reset the list
void deleteList(Node* sentinel) {
    Node* cur = sentinel->next;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    sentinel->next = nullptr;
}

int main() {
    // Sentinel node: dummy head
    Node sentinel("", 0, 0.0);
    sentinel.next = nullptr;

    // Add 4 motorcycles, each after the 2nd element
    const int INSERT_AFTER = 2;
    for (int i = 0; i < 4; ++i) {
        std::cout << "\n-- Insertion #" << (i+1) << " --\n";
        Node* node = createNode();
        insertAfter(&sentinel, node, INSERT_AFTER);
        listList(&sentinel);
    }

    // Clean up
    deleteList(&sentinel);
    return 0;
}

//4.4.2. Készítsen függvényt adott sorszámú elem törlésére! 


// c++11
#include <iostream>
#include <string>

// Node type for a singly‐linked list of motorcycles
struct Node {
    std::string name;
    int price;
    double power;
    Node* next;
    Node(const std::string& n, int p, double pw)
      : name(n), price(p), power(pw), next(nullptr) {}
};

// Create a new node by reading from stdin
Node* createNode() {
    std::string name;
    int price;
    double power;
    std::cout << "Enter name: ";
    std::cin  >> name;
    std::cout << "Enter price: ";
    std::cin  >> price;
    std::cout << "Enter power: ";
    std::cin  >> power;
    return new Node(name, price, power);
}

// Insert `newNode` after the x-th element (1-based) of the real list.
// If the list has fewer than x elements, appends at end.
void insertAfter(Node* sentinel, Node* newNode, int x) {
    Node* prev = sentinel;
    Node* cur  = sentinel->next;
    int     cnt = x;
    while (cnt > 0 && cur) {
        prev = cur;
        cur  = cur->next;
        --cnt;
    }
    prev->next    = newNode;
    newNode->next = cur;
}

// Delete the element at position `place` (1-based) in the real list.
// If `place` is out of range, does nothing.
void deleteAt(Node* sentinel, int place) {
    if (place <= 0) return;
    Node* prev = sentinel;
    Node* cur  = sentinel->next;
    int   cnt  = place - 1;
    // advance cnt steps so that cur points at the target node
    while (cnt > 0 && cur) {
        prev = cur;
        cur  = cur->next;
        --cnt;
    }
    if (!cur) return;              // out of range
    prev->next = cur->next;
    delete cur;
}

// Print all real elements in the list
void printList(Node* sentinel) {
    std::cout << "[";
    Node* cur = sentinel->next;
    bool first = true;
    while (cur) {
        if (!first) std::cout << ", ";
        std::cout << "("
                  << cur->name   << ", "
                  << cur->price  << ", "
                  << cur->power  << ")";
        first = false;
        cur = cur->next;
    }
    std::cout << "]\n";
}

// Delete all real nodes
void deleteAll(Node* sentinel) {
    Node* cur = sentinel->next;
    while (cur) {
        Node* tmp = cur->next;
        delete cur;
        cur = tmp;
    }
    sentinel->next = nullptr;
}

int main() {
    // Sentinel head
    Node sentinel("", 0, 0.0);

    // Add 4 nodes, always after the 2nd position
    const int POS = 2;
    for (int i = 1; i <= 4; ++i) {
        std::cout << "\n--- Insertion #" << i << " ---\n";
        Node* node = createNode();
        insertAfter(&sentinel, node, POS);
        std::cout << "List now: ";
        printList(&sentinel);
    }

    // Demonstrate deleteAt
    std::cout << "\nEnter position to delete (1-based): ";
    int pos;
    std::cin >> pos;
    deleteAt(&sentinel, pos);
    std::cout << "After deleteAt(" << pos << "): ";
    printList(&sentinel);

    // Clean up
    deleteAll(&sentinel);
    return 0;
}
// c++11
// 4.4.3. Írjon függvényeket, amelyek adott mezők alapján keresnek meg elemeket!
// Legyen olyan változat, amely megadja az első előfordulást, adott indexű elemtől tekintve az első előfordulást, az összes előfordulást! Írjon függvényt, amely sorszám alapján felcserél két elemet, adott tulajdonságú elemeket töröl ki, fordítva járja be a listát (és írja ki az elemeit)! 4.5. Sablon


// c++11
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Node {
    std::string name;
    int price;
    double power;
    Node* next;
    Node(const std::string& n, int p, double pw)
      : name(n), price(p), power(pw), next(nullptr) {}
};

// Helpers to print one node
void printNode(const Node* t) {
    std::cout << "("
              << t->name << ", "
              << t->price << ", "
              << t->power << ")";
}

// 1. Search functions

// First occurrence by name
Node* searchFirstByName(Node* head, const std::string& target) {
    for (Node* p = head->next; p; p = p->next)
        if (p->name == target) 
            return p;
    return nullptr;
}
// First after index (1-based)
Node* searchFirstByNameAfter(Node* head,
                             const std::string& target,
                             int afterIndex)
{
    Node* p = head->next;
    for (int i = 1; p && i <= afterIndex; ++i) 
        p = p->next;
    for (; p; p = p->next)
        if (p->name == target) 
            return p;
    return nullptr;
}
// All occurrences by name
std::vector<Node*> searchAllByName(Node* head,
                                   const std::string& target)
{
    std::vector<Node*> out;
    for (Node* p = head->next; p; p = p->next)
        if (p->name == target) 
            out.push_back(p);
    return out;
}

// (Similarly for price:)
Node* searchFirstByPrice(Node* head, int target) {
    for (Node* p = head->next; p; p = p->next)
        if (p->price == target) 
            return p;
    return nullptr;
}
Node* searchFirstByPriceAfter(Node* head, int target, int afterIndex) {
    Node* p = head->next;
    for (int i = 1; p && i <= afterIndex; ++i) 
        p = p->next;
    for (; p; p = p->next)
        if (p->price == target) 
            return p;
    return nullptr;
}
std::vector<Node*> searchAllByPrice(Node* head, int target) {
    std::vector<Node*> out;
    for (Node* p = head->next; p; p = p->next)
        if (p->price == target) 
            out.push_back(p);
    return out;
}

// (And for power:)
Node* searchFirstByPower(Node* head, double target) {
    for (Node* p = head->next; p; p = p->next)
        if (p->power == target) 
            return p;
    return nullptr;
}
Node* searchFirstByPowerAfter(Node* head, double target, int afterIndex) {
    Node* p = head->next;
    for (int i = 1; p && i <= afterIndex; ++i) 
        p = p->next;
    for (; p; p = p->next)
        if (p->power == target) 
            return p;
    return nullptr;
}
std::vector<Node*> searchAllByPower(Node* head, double target) {
    std::vector<Node*> out;
    for (Node* p = head->next; p; p = p->next)
        if (p->power == target) 
            out.push_back(p);
    return out;
}

// 2. Swap two elements by 1-based index i, j.  Returns false if either index out of range.
bool swapByPosition(Node* head, int i, int j) {
    if (i == j) return true;
    // find prev pointers for positions i and j
    Node *prevI = head, *prevJ = head;
    for (int k = 1; k < i && prevI->next; ++k) 
        prevI = prevI->next;
    for (int k = 1; k < j && prevJ->next; ++k) 
        prevJ = prevJ->next;
    if (!prevI->next || !prevJ->next) 
        return false;

    Node *nodeI = prevI->next, *nodeJ = prevJ->next;
    // if adjacent or same, handle carefully
    if (prevI->next == prevJ) {
        // i immediately before j
        prevI->next = nodeJ;
        nodeI->next = nodeJ->next;
        nodeJ->next = nodeI;
    } else if (prevJ->next == prevI) {
        // j immediately before i
        prevJ->next = nodeI;
        nodeJ->next = nodeI->next;
        nodeI->next = nodeJ;
    } else {
        // non‐adjacent
        std::swap(prevI->next, prevJ->next);
        std::swap(nodeI->next, nodeJ->next);
    }
    return true;
}

// 3. Delete by property
void deleteByName(Node* head, const std::string& target) {
    Node* prev = head;
    while (prev->next) {
        if (prev->next->name == target) {
            Node* toDel = prev->next;
            prev->next = toDel->next;
            delete toDel;
        } else {
            prev = prev->next;
        }
    }
}
void deleteByPrice(Node* head, int target) {
    Node* prev = head;
    while (prev->next) {
        if (prev->next->price == target) {
            Node* toDel = prev->next;
            prev->next = toDel->next;
            delete toDel;
        } else {
            prev = prev->next;
        }
    }
}
void deleteByPower(Node* head, double target) {
    Node* prev = head;
    while (prev->next) {
        if (prev->next->power == target) {
            Node* toDel = prev->next;
            prev->next = toDel->next;
            delete toDel;
        } else {
            prev = prev->next;
        }
    }
}

// 4. Print list in reverse order
void printReverse(Node* node) {
    if (!node) return;
    printReverse(node->next);
    printNode(node);
    if (node->next) std::cout << " -> ";
}

// Utility to print the whole list forward
void printList(Node* head) {
    bool first = true;
    for (Node* p = head->next; p; p = p->next) {
        if (!first) std::cout << " -> ";
        printNode(p);
        first = false;
    }
    std::cout << "\n";
}

int main(){
    // sentinel
    Node sentinel("",0,0.0);

    // build some sample data
    auto append = [&](const std::string& n,int pr,double pw){
        Node* cur = &sentinel;
        while (cur->next) cur = cur->next;
        cur->next = new Node(n,pr,pw);
    };
    append("Alice", 100, 1.1);
    append("Bob",   200, 2.2);
    append("Carol", 100, 3.3);
    append("Dave",  300, 2.2);
    append("Eve",   200, 1.1);

    std::cout << "Original list:\n";
    printList(&sentinel);

    std::cout << "\n1) searchFirstByName(\"Bob\"):\n";
    if (auto p = searchFirstByName(&sentinel, "Bob")) printNode(p), std::cout<<"\n";

    std::cout << "\n2) searchFirstByPriceAfter(200, 2):\n";
    if (auto p = searchFirstByPriceAfter(&sentinel, 200, 2)) printNode(p), std::cout<<"\n";

    std::cout << "\n3) searchAllByPower(2.2):\n";
    for (auto p : searchAllByPower(&sentinel, 2.2)) {
        printNode(p); std::cout<<"\n";
    }

    std::cout << "\n4) swapByPosition(2,5):\n";
    swapByPosition(&sentinel,2,5);
    printList(&sentinel);

    std::cout << "\n5) deleteByName(\"Alice\") and deleteByPower(1.1):\n";
    deleteByName(&sentinel,"Alice");
    deleteByPower(&sentinel,1.1);
    printList(&sentinel);

    std::cout << "\n6) printReverse:\n";
    printReverse(sentinel.next);
    std::cout << "\n";

    // cleanup
    Node* cur = sentinel.next;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    return 0;
}
// c++11
// 4.5.1. Készítsen egy repülőgép osztályt azonosító, utasok, előző, következő adattagokkal! Készítsen kétszeresen láncolt listát, sablon osztállyal! Tárolja a lista elejét, végét és az aktuális elemet! Valósítsa meg a következő metódusokat: konstruktor, destruktor, adott elem keresése, elem beszúrása aktuális elem elé, aktuális elem törlése, aktuális mutató mozgatása relatív indexszel, aktuális elem referenciájának visszaadása, elemszám visszaadása, kiíró operátor. Tesztelje a listát a repülőgép osztály felhasználásával! 

// c++11
#include <iostream>
#include <string>

// Airplane class
class Airplane {
public:
    int id;
    int passengers;
    Airplane(int i = 0, int p = 0)
      : id(i), passengers(p) {}
    bool operator==(const Airplane& other) const {
        return id == other.id && passengers == other.passengers;
    }
    friend std::ostream& operator<<(std::ostream& os, const Airplane& a) {
        os << "(id:" << a.id << ", passengers:" << a.passengers << ")";
        return os;
    }
};

// Doubly‐linked list template
template<typename T>
class List {
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& d) : data(d), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    Node* act;      // current element
    int   count;

public:
    List() : head(nullptr), tail(nullptr), act(nullptr), count(0) {}
    ~List() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    // Find first occurrence equal to val; returns pointer or nullptr
    T* search(const T& val) const {
        for (Node* p = head; p; p = p->next)
            if (p->data == val)
                return &p->data;
        return nullptr;
    }

    // Insert new element before act; if list empty or act==nullptr, append at end
    void insert(const T& val) {
        Node* node = new Node(val);
        ++count;
        if (!head) {
            head = tail = act = node;
            return;
        }
        if (!act) {
            // no current: append at end
            tail->next = node;
            node->prev = tail;
            tail = node;
            act = node;
            return;
        }
        // insert before act
        node->next = act;
        node->prev = act->prev;
        if (act->prev)
            act->prev->next = node;
        else
            head = node;
        act->prev = node;
        act = node;
    }

    // Delete act, move act to next if possible, else to prev
    void delAct() {
        if (!act) return;
        Node* toDel = act;
        Node* left  = act->prev;
        Node* right = act->next;
        if (left)  left->next = right; else head = right;
        if (right) right->prev = left; else tail = left;
        // choose new act
        act = right ? right : left;
        delete toDel;
        --count;
    }

    // Move act by offset steps (positive = forward, negative = backward)
    void moveAct(int offset) {
        if (!head) return;
        if (!act) act = head;
        while (offset > 0 && act->next) { act = act->next; --offset; }
        while (offset < 0 && act->prev) { act = act->prev; ++offset; }
    }

    // Return reference to current element (undefined if act==nullptr)
    T& getElem() const {
        return act->data;
    }
    // Return number of elements
    int getElemNum() const {
        return count;
    }

    // Output operator: print all elements in order
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& lst);
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const List<U>& lst) {
    if (!lst.head) {
        os << "empty\n";
        return os;
    }
    for (auto p = lst.head; p; p = p->next) {
        os << p->data;
        if (p->next) os << ", ";
    }
    os << "\n";
    return os;
}

// Test with Airplane
int main() {
    Airplane a1(1, 500), a2(2, 450), a3(3, 220), a4(4, 260);
    List<Airplane> flights;

    std::cout << "Initial: " << flights;

    flights.insert(a1);
    std::cout << "After insert a1: " << flights;

    flights.insert(a2);
    std::cout << "After insert a2: " << flights;

    flights.insert(a3);
    std::cout << "After insert a3: " << flights;

    flights.insert(a4);
    std::cout << "After insert a4: " << flights;

    std::cout << "Count: " << flights.getElemNum() << "\n";
    std::cout << "Current elem: " << flights.getElem() << "\n";

    flights.moveAct(2);
    std::cout << "MoveAct(2), current: " << flights.getElem() << "\n";

    flights.delAct();
    std::cout << "After delAct: " << flights;

    flights.moveAct(-2);
    std::cout << "MoveAct(-2), current: " << flights.getElem() << "\n";

    flights.delAct();
    std::cout << "After another delAct: " << flights;
    std::cout << "Current: " << flights.getElem() << "\n";

    return 0;
}

// c++11
// 4.5.2. Írjon metódust az aktuális mutató abszolút mozgatására, adott sorszámú elem törlésére, adott objektum törlésére, a teljes lista törlésére, aktuális mutató utáni beszúrásra! 4.6. Lista



// c++11
#include <iostream>
#include <string>

template<typename T>
class DoublyLinkedList {
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& v): data(v), prev(nullptr), next(nullptr) {}
    };
    Node *head, *tail, *act;
    int sz;

public:
    DoublyLinkedList(): head(nullptr), tail(nullptr), act(nullptr), sz(0) {}
    ~DoublyLinkedList() { clear(); }

    // Delete the entire list
    void clear() {
        Node* p = head;
        while (p) {
            Node* nxt = p->next;
            delete p;
            p = nxt;
        }
        head = tail = act = nullptr;
        sz = 0;
    }

    // Return number of elements
    int size() const { return sz; }

    // Search for first element == value
    T* search(const T& value) const {
        for (Node* p = head; p; p = p->next)
            if (p->data == value)
                return &p->data;
        return nullptr;
    }

    // Move current pointer by offset (positive = forward, negative = back)
    void moveAct(int offset) {
        if (!act) return;
        while (offset > 0 && act->next) { act = act->next; --offset; }
        while (offset < 0 && act->prev) { act = act->prev; ++offset; }
    }

    // Move current pointer to absolute 1-based index
    void moveAbs(int index) {
        if (index < 1 || index > sz) return;
        act = head;
        for (int i = 1; i < index; ++i) 
            act = act->next;
    }

    // Insert newValue *after* the current pointer
    // If list is empty, becomes sole element; if act==nullptr, appends at end
    void insertAfterAct(const T& newValue) {
        Node* node = new Node(newValue);
        ++sz;
        if (!head) {
            head = tail = act = node;
            return;
        }
        if (!act) {
            // no current: append
            tail->next = node;
            node->prev = tail;
            tail = node;
            act = node;
            return;
        }
        Node* nxt = act->next;
        act->next = node;
        node->prev = act;
        node->next = nxt;
        if (nxt) 
            nxt->prev = node;
        else 
            tail = node;
        act = node;
    }

    // Delete the current element
    void delAct() {
        if (!act) return;
        Node* toDel = act;
        Node* before = act->prev;
        Node* after  = act->next;
        if (before) before->next = after; else head = after;
        if (after ) after->prev = before; else tail = before;
        act = after ? after : before;
        delete toDel;
        --sz;
    }

    // Delete element at 1-based index
    void delAbs(int index) {
        if (index < 1 || index > sz) return;
        moveAbs(index);
        delAct();
    }

    // Delete all elements equal to value
    void delObject(const T& value) {
        Node* p = head;
        while (p) {
            Node* nxt = p->next;
            if (p->data == value) {
                if (act == p) act = nxt;
                if (p->prev) p->prev->next = p->next; else head = p->next;
                if (p->next) p->next->prev = p->prev; else tail = p->prev;
                delete p;
                --sz;
            }
            p = nxt;
        }
    }

    // Access current element
    T* getElem() const { 
        return act ? &act->data : nullptr; 
    }

    // Print entire list
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& L) {
        for (Node* p = L.head; p; p = p->next) {
            os << p->data;
            if (p->next) os << " -> ";
        }
        return os;
    }
};

// Example element class
class Airplane {
public:
    int id;
    int passengers;
    Airplane(int i = 0, int p = 0): id(i), passengers(p) {}
    bool operator==(const Airplane& o) const {
        return id == o.id && passengers == o.passengers;
    }
    friend std::ostream& operator<<(std::ostream& os, const Airplane& a) {
        return os << "(id:" << a.id << ", pass:" << a.passengers << ")";
    }
};

int main() {
    DoublyLinkedList<Airplane> list;
    // Insert some airplanes
    list.insertAfterAct({1, 100});
    list.insertAfterAct({2, 150});
    list.insertAfterAct({3, 200});
    list.insertAfterAct({4, 250});
    std::cout << "After inserts:\n" << list << "\n";

    // Move absolute to 2nd element
    list.moveAbs(2);
    std::cout << "Current at 2: " << *list.getElem() << "\n";

    // Delete by absolute index
    list.delAbs(3);
    std::cout << "After delAbs(3):\n" << list << "\n";

    // Search for id==2
    Airplane key(2,150);
    auto found = list.search(key);
    if (found) std::cout << "Found: " << *found << "\n";

    // Delete object matching key
    list.delObject(key);
    std::cout << "After delObject(id=2):\n" << list << "\n";

    // Insert after current pointer
    list.moveAbs(1);
    list.insertAfterAct({5,300});
    std::cout << "After insertAfterAct at pos 1:\n" << list << "\n";

    // Clear all
    list.clear();
    std::cout << "After clear:\n" << list << "\n";

    return 0;
}
// 4.6.1. Írjon programot, amely számokat olvas be a billentyűzetről addig, amíg a beolvasott szám nem 0! A program fűzze a beolvasott számot egy egyszeresen láncolt lista végére! A -1 gépelése után írja ki a képernyőre a lista tartalmát! Valósítsa meg az add és print függvényeket, valamint a lista felszabadítását! Példa: Type a number: 10 Type a number: 20 Type a number: 30 Type a number: -1 The list: 10 20 30 Type a number: 40 Type a number: 50 Type a number: -1 The list: 10 20 30 40 50 Type a number: 0 4.7. Prímszita


// c++11
#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;
    Node* tail;
public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}
    ~SinglyLinkedList() { clear(); }

    // Add a new node with value d at the end
    void add(int d) {
        Node* n = new Node(d);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    // Print all elements on one line
    void print() const {
        if (!head) {
            std::cout << "The list is empty\n";
            return;
        }
        std::cout << "The list:";
        for (Node* p = head; p; p = p->next) {
            std::cout << " " << p->data;
        }
        std::cout << "\n";
    }

    // Free all nodes
    void clear() {
        Node* p = head;
        while (p) {
            Node* nxt = p->next;
            delete p;
            p = nxt;
        }
        head = tail = nullptr;
    }
};

int main() {
    SinglyLinkedList list;
    int num;

    while (true) {
        std::cout << "Type a number: ";
        std::cin >> num;
        if (!std::cin) break;       // handle EOF or error
        if (num == 0) break;        // terminate
        if (num == -1) {
            list.print();           // print on -1
        } else {
            list.add(num);          // otherwise add
        }
    }

    // list destructor will free memory
    return 0;
}
// c++11
// 4.7.1. Kérjünk be egy tetszőleges egész számot (n), majd egy listába tegyük be 2-től n-ig a természetes számokat! Vegyünk ki minden nem prím számot a listából! Ötlet: a lista első eleme (2) prím, minden olyan számot törlünk, amely osztható ezzel a számmal (az első iterációban 2 kivételével az összes páros szám törlődik). A megmaradt elemek közül a következő ismét prím, töröljük ennek is minden többszörösét. Ezt ismételjük addig, amíg a lista végére nem érünk, ekkor írjuk ki a listát! 4.8. Halmazműveletek

 

// c++11
#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

// Build a linked list of integers from 2 up to n
Node* buildList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 2; i <= n; ++i) {
        Node* node = new Node(i);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// Remove from the list after p all nodes whose value is a multiple of p->value
void removeMultiples(Node* p) {
    Node* prev = p;
    Node* cur  = p->next;
    while (cur) {
        Node* nxt = cur->next;
        if (cur->value % p->value == 0) {
            prev->next = nxt;
            delete cur;
        } else {
            prev = cur;
        }
        cur = nxt;
    }
}

// Sieve of Eratosthenes on the linked list
void sieve(Node*& head) {
    for (Node* p = head; p; p = p->next) {
        removeMultiples(p);
    }
}

// Print all values in the list, separated by spaces
void printList(Node* head) {
    bool first = true;
    for (Node* p = head; p; p = p->next) {
        if (!first) std::cout << ' ';
        std::cout << p->value;
        first = false;
    }
    std::cout << "\n";
}

// Free all nodes in the list
void freeList(Node* head) {
    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
}

int main() {
    int n;
    std::cin >> n;
    if (n < 2) return 0;

    Node* head = buildList(n);
    sieve(head);
    printList(head);
    freeList(head);
    return 0;
}
// c++11
// 4.8.1. Hozzunk létre két rendezett listát, majd készítsük el a két lista unióját, az eredményt az első listában tároljuk! 


#include <iostream>
#include <vector>

// Simple singly-linked list node
struct Node {
    int value;
    Node* next;
    Node(int v): value(v), next(nullptr) {}
};

// Build a sorted linked list from a vector of values
Node* buildList(const std::vector<int>& vals) {
    Node* head = nullptr;
    Node** tail = &head;
    for (int v : vals) {
        *tail = new Node(v);
        tail = &((*tail)->next);
    }
    return head;
}

// Print a list, one element per line
void printList(const char* title, Node* head) {
    std::cout << title << ":\n";
    int idx = 1;
    for (Node* p = head; p; p = p->next, ++idx) {
        std::cout << "  " << idx << ". element: " << p->value << "\n";
    }
}

// Free all nodes
void freeList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// Destructively form the union of two sorted lists.
// All values appearing in either list1 or list2 (without duplicates),
// sorted. Result is in list1; list2's nodes are spliced in.
Node* unionLists(Node* list1, Node* list2) {
    Node dummy(0);
    Node* tail = &dummy;
    Node* p1 = list1;
    Node* p2 = list2;

    while (p1 && p2) {
        if (p1->value < p2->value) {
            tail->next = p1;
            p1 = p1->next;
            tail = tail->next;
        }
        else if (p1->value > p2->value) {
            tail->next = p2;
            p2 = p2->next;
            tail = tail->next;
        }
        else {
            // equal: include only one, advance both
            tail->next = p1;
            p1 = p1->next;
            Node* tmp = p2;
            p2 = p2->next;
            delete tmp;        // delete the duplicate node from list2
            tail = tail->next;
        }
    }
    // attach any remaining nodes
    if (p1) {
        tail->next = p1;
    } else {
        tail->next = p2;
    }

    return dummy.next;
}

int main() {
    // Two sorted integer arrays
    int arr1[] = {1,2,4,5,6,8,9,10,13};
    int arr2[] = {0,2,3,5,6,7,9,11,12,13};

    std::vector<int> v1(std::begin(arr1), std::end(arr1));
    std::vector<int> v2(std::begin(arr2), std::end(arr2));

    // Build two lists
    Node* list1 = buildList(v1);
    Node* list2 = buildList(v2);

    // Print initial lists
    printList("First list",  list1);
    printList("Second list", list2);

    // Union into list1
    list1 = unionLists(list1, list2);

    // list2's nodes have been merged/deleted; avoid double-free
    list2 = nullptr;

    // Print the union result (in list1)
    printList("\nFirst list after union", list1);

    // Clean up
    freeList(list1);
    return 0;
}
// c++11
// 4.8.2. Unió helyett a két lista metszetét képezzük!  


#include <iostream>
#include <vector>

// A simple singly‐linked list node
struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

// Build a sorted linked list from a vector of ints
Node* buildList(const std::vector<int>& vals) {
    Node* head = nullptr;
    Node** tail = &head;
    for (int v : vals) {
        *tail = new Node(v);
        tail = &((*tail)->next);
    }
    return head;
}

// Print the list, one element per line
void printList(Node* head) {
    int idx = 1;
    for (Node* p = head; p; p = p->next, ++idx) {
        std::cout << idx << ". element: " << p->value << "\n";
    }
}

// Free all nodes in the list
void freeList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// Destructively intersect list1 with list2 (both sorted).
// Returns the new head of list1; list2 is left unchanged.
Node* intersect(Node* list1, Node* list2) {
    Node dummy(0);
    dummy.next = list1;
    Node* prev = &dummy;
    Node* p1 = list1;
    Node* p2 = list2;

    while (p1 && p2) {
        if (p1->value < p2->value) {
            // remove p1
            prev->next = p1->next;
            delete p1;
            p1 = prev->next;
        }
        else if (p1->value > p2->value) {
            // skip ahead in list2
            p2 = p2->next;
        }
        else {
            // match: keep p1
            prev = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    // any remaining p1 nodes are not in intersection: remove them
    while (p1) {
        prev->next = p1->next;
        delete p1;
        p1 = prev->next;
    }
    return dummy.next;
}

int main() {
    // Two sorted arrays
    int numbers1[] = {0, 1, 5, 7, 9, 13, 19, 96};
    int numbers2[] = {1, 4, 9, 15, 19, 25, 37, 45};
    std::vector<int> v1(std::begin(numbers1), std::end(numbers1));
    std::vector<int> v2(std::begin(numbers2), std::end(numbers2));

    // Build lists
    Node* list1 = buildList(v1);
    Node* list2 = buildList(v2);

    std::cout << "First list:\n";
    printList(list1);

    std::cout << "\nSecond list:\n";
    printList(list2);

    // Intersect list1 with list2
    list1 = intersect(list1, list2);

    std::cout << "\nFirst list after intersection:\n";
    printList(list1);

    // Clean up
    freeList(list1);
    freeList(list2);
    return 0;
}
