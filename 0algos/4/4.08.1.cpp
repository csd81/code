// c++11
// 4.8.1. Hozzunk létre két rendezett listát, majd készítsük el a két lista unióját, az eredményt az első listában tároljuk! 


#include <iostream>
#include <vector>

// Simple singly-linked list node
struct Node {
    int value;
    Node* next;
    Node(int v): value(v), next(nullptr) {}
};

// Build a sorted linked list from a vector of values
Node* buildList(const std::vector<int>& vals) {
    Node* head = nullptr;
    Node** tail = &head;
    for (int v : vals) {
        *tail = new Node(v);
        tail = &((*tail)->next);
    }
    return head;
}

// Print a list, one element per line
void printList(const char* title, Node* head) {
    std::cout << title << ":\n";
    int idx = 1;
    for (Node* p = head; p; p = p->next, ++idx) {
        std::cout << "  " << idx << ". element: " << p->value << "\n";
    }
}

// Free all nodes
void freeList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// Destructively form the union of two sorted lists.
// All values appearing in either list1 or list2 (without duplicates),
// sorted. Result is in list1; list2's nodes are spliced in.
Node* unionLists(Node* list1, Node* list2) {
    Node dummy(0);
    Node* tail = &dummy;
    Node* p1 = list1;
    Node* p2 = list2;

    while (p1 && p2) {
        if (p1->value < p2->value) {
            tail->next = p1;
            p1 = p1->next;
            tail = tail->next;
        }
        else if (p1->value > p2->value) {
            tail->next = p2;
            p2 = p2->next;
            tail = tail->next;
        }
        else {
            // equal: include only one, advance both
            tail->next = p1;
            p1 = p1->next;
            Node* tmp = p2;
            p2 = p2->next;
            delete tmp;        // delete the duplicate node from list2
            tail = tail->next;
        }
    }
    // attach any remaining nodes
    if (p1) {
        tail->next = p1;
    } else {
        tail->next = p2;
    }

    return dummy.next;
}

int main() {
    // Two sorted integer arrays
    int arr1[] = {1,2,4,5,6,8,9,10,13};
    int arr2[] = {0,2,3,5,6,7,9,11,12,13};

    std::vector<int> v1(std::begin(arr1), std::end(arr1));
    std::vector<int> v2(std::begin(arr2), std::end(arr2));

    // Build two lists
    Node* list1 = buildList(v1);
    Node* list2 = buildList(v2);

    // Print initial lists
    printList("First list",  list1);
    printList("Second list", list2);

    // Union into list1
    list1 = unionLists(list1, list2);

    // list2's nodes have been merged/deleted; avoid double-free
    list2 = nullptr;

    // Print the union result (in list1)
    printList("\nFirst list after union", list1);

    // Clean up
    freeList(list1);
    return 0;
}
