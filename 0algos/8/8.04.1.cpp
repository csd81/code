// C++11
// 8.4.1. Valósítson meg egy kétszeresen láncolt listát, amely ID alapján csökkenő sorrendben tartalmazza a rekordokat! Használjon őrszemeket a lista két végén! A listát egy struktúra reprezentálja, amely az őrszemeket tartalmazza! A lista elem tartalmazza az előre, hátra mutató mezőket és egy mutatót az adat struktúrára! Az adat struktúra tartalmazza következő mezőket: ID, méret, származási hely. 

 
#include <iostream>
#include <string>

// The payload stored in each node
struct DataType {
    int     ID;
    double  size;
    std::string origin;
};

// A node in the doubly‐linked list.
// Each node holds a pointer to a DataType.
struct ListNode {
    DataType*   data;
    ListNode*   prev;
    ListNode*   next;

    ListNode(DataType* d = nullptr)
      : data(d), prev(nullptr), next(nullptr) {}
};

// The list itself, with head/tail sentinels and insert/clear/print operations.
class List {
public:
    List() {
        // Initialize empty list: head ↔ tail
        head.next = &tail;
        tail.prev = &head;
    }

    ~List() {
        clear();
    }

    // Insert in descending order by ID
    void insert(DataType* d) {
        // Find first node with ID <= d->ID
        ListNode* cur = head.next;
        while (cur != &tail && cur->data->ID > d->ID) {
            cur = cur->next;
        }
        // Insert new node before cur
        ListNode* node = new ListNode(d);
        node->prev      = cur->prev;
        node->next      = cur;
        cur->prev->next = node;
        cur->prev       = node;
    }

    // Remove all elements (but not the sentinel nodes)
    void clear() {
        ListNode* cur = head.next;
        while (cur != &tail) {
            ListNode* toDelete = cur;
            cur = cur->next;
            delete toDelete;
        }
        head.next = &tail;
        tail.prev = &head;
    }

    // Print the list from head→tail (excluding sentinels)
    void print() const {
        std::cout << "List (descending by ID):\n";
        for (ListNode* cur = head.next; cur != &tail; cur = cur->next) {
            std::cout << "  (ID: " << cur->data->ID
                      << ", size: " << cur->data->size
                      << ", origin: " << cur->data->origin
                      << ")\n";
        }
    }

private:
    ListNode head;  // dummy head sentinel
    ListNode tail;  // dummy tail sentinel
};

// -----------------------------------------------------------------------------
// Demo for 8.4.1
int main() {
    List myList;

    DataType testData[] = {
        { 1,  2.3, "Hu" },
        { 7, 12.3, "Ro" },
        { 0, 45.3, "Eu" },
        { 5, 14.1, "Gb" }
    };

    for (auto& d : testData) {
        std::cout << "Inserting (ID: " << d.ID
                  << ", size: " << d.size
                  << ", origin: " << d.origin << ")\n";
        myList.insert(&d);
        myList.print();
        std::cout << "\n";
    }

    // Clean up is automatic in List destructor
    return 0;
}

