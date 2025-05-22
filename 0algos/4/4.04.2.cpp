
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
