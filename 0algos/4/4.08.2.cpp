// c++11
// 4.8.2. Unió helyett a két lista metszetét képezzük!  


#include <iostream>
#include <vector>

// A simple singly‐linked list node
struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

// Build a sorted linked list from a vector of ints
Node* buildList(const std::vector<int>& vals) {
    Node* head = nullptr;
    Node** tail = &head;
    for (int v : vals) {
        *tail = new Node(v);
        tail = &((*tail)->next);
    }
    return head;
}

// Print the list, one element per line
void printList(Node* head) {
    int idx = 1;
    for (Node* p = head; p; p = p->next, ++idx) {
        std::cout << idx << ". element: " << p->value << "\n";
    }
}

// Free all nodes in the list
void freeList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// Destructively intersect list1 with list2 (both sorted).
// Returns the new head of list1; list2 is left unchanged.
Node* intersect(Node* list1, Node* list2) {
    Node dummy(0);
    dummy.next = list1;
    Node* prev = &dummy;
    Node* p1 = list1;
    Node* p2 = list2;

    while (p1 && p2) {
        if (p1->value < p2->value) {
            // remove p1
            prev->next = p1->next;
            delete p1;
            p1 = prev->next;
        }
        else if (p1->value > p2->value) {
            // skip ahead in list2
            p2 = p2->next;
        }
        else {
            // match: keep p1
            prev = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    // any remaining p1 nodes are not in intersection: remove them
    while (p1) {
        prev->next = p1->next;
        delete p1;
        p1 = prev->next;
    }
    return dummy.next;
}

int main() {
    // Two sorted arrays
    int numbers1[] = {0, 1, 5, 7, 9, 13, 19, 96};
    int numbers2[] = {1, 4, 9, 15, 19, 25, 37, 45};
    std::vector<int> v1(std::begin(numbers1), std::end(numbers1));
    std::vector<int> v2(std::begin(numbers2), std::end(numbers2));

    // Build lists
    Node* list1 = buildList(v1);
    Node* list2 = buildList(v2);

    std::cout << "First list:\n";
    printList(list1);

    std::cout << "\nSecond list:\n";
    printList(list2);

    // Intersect list1 with list2
    list1 = intersect(list1, list2);

    std::cout << "\nFirst list after intersection:\n";
    printList(list1);

    // Clean up
    freeList(list1);
    freeList(list2);
    return 0;
}
