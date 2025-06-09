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
