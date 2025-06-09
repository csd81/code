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
