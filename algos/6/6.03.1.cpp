// 6.3.1. Tároljon adatokat egerekről bináris keresőfában ár szerint rendezve! A tárolandó adatok: ár - int, gyártó - statikus sztring, infra - bitmező, madzag hossz vagy infra hatótáv - lebegőpontos. Ne használjon szülő mutatót! Tárolja a fa gyökerét őrszemmel! Az őrszem kulcsmezőjének maximálisnak kell lennie! Valósítsa meg a következő függvényeket: csomópont megjelenítése, fa megjelenítése, fa felszabadítása, csomópont beszúrása! Teszteljük a programot! 


#include <iostream>
#include <string>
#include <limits>

// 6.3.1: Mouse info in a BST sorted by price, with sentinel root
struct Node {
    int price;
    std::string manufacturer;
    bool infra;
    float range;
    Node* less;
    Node* bigger;
    Node(int p, const std::string& m, bool i, float r)
      : price(p), manufacturer(m), infra(i), range(r), less(nullptr), bigger(nullptr) {}
};

// Print a single node
void printNode(const Node* n) {
    std::cout
      << "(price: " << n->price
      << ", manuf: " << n->manufacturer
      << ", infra: " << n->infra
      << ", range: " << n->range
      << ")\n";
}

// In-order traversal
void printTree(const Node* root) {
    if (!root) return;
    printTree(root->less);
    printNode(root);
    printTree(root->bigger);
}

// Delete entire tree
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->less);
    freeTree(root->bigger);
    delete root;
}

// Insert new node into BST with sentinel root
void insertNode(Node* sentinel, int price,
                const std::string& manuf,
                bool infra, float range) {
    Node* newNode = new Node(price, manuf, infra, range);
    Node* cur = sentinel;
    while (true) {
        if (price <= cur->price) {
            if (!cur->less) {
                cur->less = newNode;
                return;
            }
            cur = cur->less;
        } else {
            if (!cur->bigger) {
                cur->bigger = newNode;
                return;
            }
            cur = cur->bigger;
        }
    }
}

int main() {
    // Sentinel root has max price
    Node sentinel(std::numeric_limits<int>::max(), "", false, 0.0f);

    // Insert some mice
    insertNode(&sentinel, 25, "IBM",    false, 5.2f);
    insertNode(&sentinel, 63, "MS",     true,  2.1f);
    insertNode(&sentinel, 11, "Genius", true,  4.5f);
    insertNode(&sentinel, 22, "Taka",   false, 0.9f);

    std::cout << "Mouse catalog (in order by price):\n";
    printTree(sentinel.less);

    freeTree(sentinel.less);
    return 0;
}
