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

