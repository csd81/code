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
