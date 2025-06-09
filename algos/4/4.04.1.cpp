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
