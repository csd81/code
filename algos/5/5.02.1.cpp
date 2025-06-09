// c++11
// 5.2.1. Írjon programot, amely számokat olvas be a billentyűzetről addig, amíg a beolvasott szám nem 0!
// Tárolja a számokat egy veremben, amit láncolt listával valósítson meg.
// A 0 gépelése után a program olvassa ki a számokat a veremből, és írja a képernyőre! 
// Valósítsa meg a push és pop függvényeket, valamint a lista felszabadítását!
// Példa: Type a number: 1 Type a number: 5 Type a number: 7 Type a number: 0 7 5 1 5.3. Sor

#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int v, Node* n) : value(v), next(n) {}
};

class Stack {
    Node* head;
    int count;
public:
    Stack() : head(nullptr), count(0) {}
    ~Stack() { clear(); }

    void push(int v) {
        head = new Node(v, head);
        ++count;
    }

    bool pop(int& out) {
        if (!head) return false;
        Node* tmp = head;
        out = head->value;
        head = head->next;
        delete tmp;
        --count;
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void clear() {
        int _;
        while (pop(_)) {}
    }

    int size() const {
        return count;
    }
};

int main() {
    Stack s;
    int num;

    do {
        std::cout << "Type a number: ";
        std::cin >> num;
        if (num != 0) {
            s.push(num);
        }
    } while (num != 0);

    std::cout << "\nPopped values in LIFO order:\n";
    while (!s.isEmpty()) {
        s.pop(num);
        std::cout << num << "\n";
    }

    return 0;
}
