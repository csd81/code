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
