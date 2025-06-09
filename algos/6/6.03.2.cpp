// 6.3.2. Módosítsa úgy a programot, hogy az őrszemben a legkisebb kulcs értéket tároljuk! A billentyűzetről kérje be az új csomópont tulajdonságait! Az őrszem helyett mutatóval reprezentáljuk a fát! Használjon szülő mutatót is! 6.4. Családfa

#include <iostream>
#include <string>
#include <limits>

// 6.3.2: BST of mice, keyboard input, no sentinel, use parent pointer
struct Node {
    int price;
    std::string manufacturer;
    bool infra;
    float range;
    Node* less;
    Node* bigger;
    Node* parent;
    Node(int p, const std::string& m, bool i, float r)
      : price(p), manufacturer(m), infra(i), range(r),
        less(nullptr), bigger(nullptr), parent(nullptr)
    {}
};

// Insert into BST, setting parent pointers
void insertNode(Node*& root, Node* newNode) {
    if (!root) {
        root = newNode;
        return;
    }
    Node* cur = root;
    while (true) {
        if (newNode->price <= cur->price) {
            if (!cur->less) {
                cur->less = newNode;
                newNode->parent = cur;
                return;
            }
            cur = cur->less;
        } else {
            if (!cur->bigger) {
                cur->bigger = newNode;
                newNode->parent = cur;
                return;
            }
            cur = cur->bigger;
        }
    }
}

// In-order traversal
void printTree(const Node* root) {
    if (!root) return;
    printTree(root->less);
    std::cout
      << "(price:" << root->price
      << ", manuf:" << root->manufacturer
      << ", infra:" << root->infra
      << ", range:" << root->range << ")\n";
    printTree(root->bigger);
}

// Free tree
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->less);
    freeTree(root->bigger);
    delete root;
}

int main() {
    Node* root = nullptr;
    int n;
    std::cout << "How many mice to insert? ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int price;
        std::string manuf;
        bool infra;
        float range;
        std::cout << "Enter price, manufacturer, infra(0/1), range: ";
        std::cin >> price >> manuf >> infra >> range;
        Node* node = new Node(price, manuf, infra, range);
        insertNode(root, node);
    }

    std::cout << "\nBST in-order (sorted by price):\n";
    printTree(root);

    freeTree(root);
    return 0;
}
