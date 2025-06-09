// c++11
// 8.4.2. Egészítse ki a lista struktúrát egy egésszel, amely az elemek számát mutatja a listában!
// Módosítsa a függvényeket, hogy azok kezeljék az új adattagot! 
 

#include <iostream>
#include <string>

// -----------------------------------------------------------------------------
// The payload stored in each node
struct DataType {
    int     ID;
    double  size;
    std::string origin;
};

// A node in the doubly–linked list
struct ListNode {
    DataType    data;
    ListNode*   prev;
    ListNode*   next;

    ListNode(const DataType& d = DataType{})
      : data(d), prev(nullptr), next(nullptr) {}
};

// The list itself, with head/tail sentinels and a count of elements
class List {
public:
    List()
      : _count(0)
    {
        // initialize empty list:
        _head.next = &_tail;
        _tail.prev = &_head;
    }

    ~List() {
        clear();
    }

    // Insert in ascending order by ID
    void insert(const DataType& d) {
        // find first node with data.ID >= d.ID
        ListNode* cur = _head.next;
        while (cur != &_tail && cur->data.ID < d.ID) {
            cur = cur->next;
        }
        // insert new node before cur
        ListNode* node = new ListNode(d);
        node->prev      = cur->prev;
        node->next      = cur;
        cur->prev->next = node;
        cur->prev       = node;

        ++_count;
    }

    // Remove all elements
    void clear() {
        ListNode* cur = _head.next;
        while (cur != &_tail) {
            ListNode* toDelete = cur;
            cur = cur->next;
            delete toDelete;
        }
        _head.next = &_tail;
        _tail.prev = &_head;
        _count = 0;
    }

    // Print the entire list and the count
    void display() const {
        std::cout << "List elements (" << _count << "): ";
        ListNode* cur = _head.next;
        while (cur != &_tail) {
            std::cout
                << "(ID: "   << cur->data.ID
                << ", size: " << cur->data.size
                << ", origin: " << cur->data.origin
                << ")";

            cur = cur->next;
            if (cur != &_tail)
                std::cout << " <-> ";
        }
        std::cout << "\n";
    }

    // Return the number of elements
    int size() const { return _count; }

private:
    ListNode _head;   // dummy head (no data)
    ListNode _tail;   // dummy tail (no data)
    int      _count;  // number of real elements
};

// -----------------------------------------------------------------------------
// Demonstration of 8.4.2:
int main() {
    List myList;

    DataType testData[] = {
        { 1,  2.3, "Hu" },
        { 7, 12.3, "Ro" },
        { 0, 45.3, "Eu" },
        { 5, 14.1, "Gb" }
    };

    for (const auto& d : testData) {
        std::cout << "Inserting (ID: " << d.ID
                  << ", size: " << d.size
                  << ", origin: " << d.origin << ")\n";
        myList.insert(d);
        myList.display();
        std::cout << "\n";
    }

    std::cout << "Final count: " << myList.size() << "\n";

    // teardown happens in destructor
    return 0;
}
 