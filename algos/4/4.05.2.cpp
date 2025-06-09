// c++11
// 4.5.2. Írjon metódust az aktuális mutató abszolút mozgatására, adott sorszámú elem törlésére, adott objektum törlésére, a teljes lista törlésére, aktuális mutató utáni beszúrásra! 4.6. Lista



// c++11
#include <iostream>
#include <string>

template<typename T>
class DoublyLinkedList {
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& v): data(v), prev(nullptr), next(nullptr) {}
    };
    Node *head, *tail, *act;
    int sz;

public:
    DoublyLinkedList(): head(nullptr), tail(nullptr), act(nullptr), sz(0) {}
    ~DoublyLinkedList() { clear(); }

    // Delete the entire list
    void clear() {
        Node* p = head;
        while (p) {
            Node* nxt = p->next;
            delete p;
            p = nxt;
        }
        head = tail = act = nullptr;
        sz = 0;
    }

    // Return number of elements
    int size() const { return sz; }

    // Search for first element == value
    T* search(const T& value) const {
        for (Node* p = head; p; p = p->next)
            if (p->data == value)
                return &p->data;
        return nullptr;
    }

    // Move current pointer by offset (positive = forward, negative = back)
    void moveAct(int offset) {
        if (!act) return;
        while (offset > 0 && act->next) { act = act->next; --offset; }
        while (offset < 0 && act->prev) { act = act->prev; ++offset; }
    }

    // Move current pointer to absolute 1-based index
    void moveAbs(int index) {
        if (index < 1 || index > sz) return;
        act = head;
        for (int i = 1; i < index; ++i) 
            act = act->next;
    }

    // Insert newValue *after* the current pointer
    // If list is empty, becomes sole element; if act==nullptr, appends at end
    void insertAfterAct(const T& newValue) {
        Node* node = new Node(newValue);
        ++sz;
        if (!head) {
            head = tail = act = node;
            return;
        }
        if (!act) {
            // no current: append
            tail->next = node;
            node->prev = tail;
            tail = node;
            act = node;
            return;
        }
        Node* nxt = act->next;
        act->next = node;
        node->prev = act;
        node->next = nxt;
        if (nxt) 
            nxt->prev = node;
        else 
            tail = node;
        act = node;
    }

    // Delete the current element
    void delAct() {
        if (!act) return;
        Node* toDel = act;
        Node* before = act->prev;
        Node* after  = act->next;
        if (before) before->next = after; else head = after;
        if (after ) after->prev = before; else tail = before;
        act = after ? after : before;
        delete toDel;
        --sz;
    }

    // Delete element at 1-based index
    void delAbs(int index) {
        if (index < 1 || index > sz) return;
        moveAbs(index);
        delAct();
    }

    // Delete all elements equal to value
    void delObject(const T& value) {
        Node* p = head;
        while (p) {
            Node* nxt = p->next;
            if (p->data == value) {
                if (act == p) act = nxt;
                if (p->prev) p->prev->next = p->next; else head = p->next;
                if (p->next) p->next->prev = p->prev; else tail = p->prev;
                delete p;
                --sz;
            }
            p = nxt;
        }
    }

    // Access current element
    T* getElem() const { 
        return act ? &act->data : nullptr; 
    }

    // Print entire list
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& L) {
        for (Node* p = L.head; p; p = p->next) {
            os << p->data;
            if (p->next) os << " -> ";
        }
        return os;
    }
};

// Example element class
class Airplane {
public:
    int id;
    int passengers;
    Airplane(int i = 0, int p = 0): id(i), passengers(p) {}
    bool operator==(const Airplane& o) const {
        return id == o.id && passengers == o.passengers;
    }
    friend std::ostream& operator<<(std::ostream& os, const Airplane& a) {
        return os << "(id:" << a.id << ", pass:" << a.passengers << ")";
    }
};

int main() {
    DoublyLinkedList<Airplane> list;
    // Insert some airplanes
    list.insertAfterAct({1, 100});
    list.insertAfterAct({2, 150});
    list.insertAfterAct({3, 200});
    list.insertAfterAct({4, 250});
    std::cout << "After inserts:\n" << list << "\n";

    // Move absolute to 2nd element
    list.moveAbs(2);
    std::cout << "Current at 2: " << *list.getElem() << "\n";

    // Delete by absolute index
    list.delAbs(3);
    std::cout << "After delAbs(3):\n" << list << "\n";

    // Search for id==2
    Airplane key(2,150);
    auto found = list.search(key);
    if (found) std::cout << "Found: " << *found << "\n";

    // Delete object matching key
    list.delObject(key);
    std::cout << "After delObject(id=2):\n" << list << "\n";

    // Insert after current pointer
    list.moveAbs(1);
    list.insertAfterAct({5,300});
    std::cout << "After insertAfterAct at pos 1:\n" << list << "\n";

    // Clear all
    list.clear();
    std::cout << "After clear:\n" << list << "\n";

    return 0;
}
