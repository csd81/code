
// c++11
// 5.3.1. Írjon programot, amely számokat olvas be a billentyűzetről addig, amíg a beolvasott szám nem 0! Tárolja ezeket egy sorban, amit láncolt listával valósíts meg! A 0 gépelése után a program olvassa ki a számokat a sorból, és írja a képernyőre! Valósítsa meg a push és pop függvényeket, valamint a lista felszabadítását! Példa: Type a number: 10 Type a number: 43 Type a number: 2 Type a number: 5 Type a number: 0 2 5 5.4. Fordított lengyelforma


#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

class Queue {
    Node* head;
    Node* tail;
    int count;

public:
    Queue() : head(nullptr), tail(nullptr), count(0) {}
    ~Queue() { clear(); }

    // Push to the back
    void push(int v) {
        Node* n = new Node(v);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        ++count;
    }

    // Pop from the front; returns false if empty
    bool pop(int &out) {
        if (!head) return false;
        Node* n = head;
        out = n->value;
        head = head->next;
        if (!head) tail = nullptr;
        delete n;
        --count;
        return true;
    }

    bool isEmpty() const { return count == 0; }
    int size() const { return count; }

    void clear() {
        int tmp;
        while (pop(tmp)) {}
    }
};

int main() {
    Queue q;
    int num;

    // Read until 0
    do {
        std::cout << "Type a number: ";
        std::cin >> num;
        if (num != 0) q.push(num);
    } while (num != 0);

    std::cout << "\nDequeued values:\n";
    while (!q.isEmpty()) {
        q.pop(num);
        std::cout << num << "\n";
    }

    return 0;
}
