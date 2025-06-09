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
