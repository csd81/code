// 6.6.1. Írjon programot, amely egy tömb elemeiből készít bináris keresőfát, ezután határozza meg, hány csúcsa, illetve hány levele van a fának! A bináris keresőfa olyan adatszerkezet, amelyben minden elemnek két mutatója van, egy jobb, illetve egy bal. A fába elsőként belerakott elem a gyökér, ezután minden elemet a következőképp helyezünk el. Kiindulunk a gyökér elemtől. Ha a beszúrni kívánt elem kisebb, mint az aktuális, akkor balra megyünk tovább a fában, ha nagyobb, akkor jobbra. Egészen addig haladunk így a fában, amíg egy üres helyet találunk, ide beszúrjuk az kívánt elemet. 
// 6.6.2. Írjon függvényeket a következő funkciók megvalósítására; fa magassága (a gyökérlevél távolságok között a legnagyobb), maximális érték meghatározása, gyökérhez legközelebb eső szint meghatározása, amin már van levele a fának! Levél: olyan csúcs a fában, aminek nincsen se bal, se jobb gyereke. 
// 6.6.3. Írjon programot, amely eldönti két fáról, hogy azonos alakúak-e! 7. Gráf feladatok 7.1. Tűzoltók


// C++11
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 6.6.1: Insert into BST
void insert(Node*& root, int v) {
    if (!root) {
        root = new Node(v);
    } else if (v < root->val) {
        insert(root->left, v);
    } else if (v > root->val) {
        insert(root->right, v);
    }
    // duplicates ignored
}

// In-order listing
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->val << ' ';
    inorder(root->right);
}

// Count total nodes
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaves (nodes with no children)
int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// 6.6.2: Maximum depth (height)
int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

// Maximum key in BST = rightmost node
int maxKey(Node* root) {
    if (!root) throw std::runtime_error("Empty tree");
    while (root->right) root = root->right;
    return root->val;
}

// Minimum depth to a leaf
int minDepth(Node* root) {
    if (!root) return 0;
    // If one child is null, we must go down the other
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    // both children exist
    return 1 + std::min(minDepth(root->left), minDepth(root->right));
}

// 6.6.3: Check if two trees have the same shape
bool sameShape(Node* a, Node* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return sameShape(a->left, b->left) && sameShape(a->right, b->right);
}

int main() {
    // Example arrays
    std::vector<int> tree1 = {7, 9, 13, 15, 45, 2, 1, 5, 94};
    std::vector<int> tree2 = {7, 9, 13, 15, 45, 2, 1, 5, 94};

    Node* root1 = nullptr;
    Node* root2 = nullptr;

    for (int v : tree1) insert(root1, v);
    for (int v : tree2) insert(root2, v);

    std::cout << "First tree (in-order): ";
    inorder(root1);
    std::cout << "\nSecond tree (in-order): ";
    inorder(root2);
    std::cout << "\n\n";

    std::cout << "First tree nodes: " << countNodes(root1) << "\n";
    std::cout << "First tree leaves: " << countLeaves(root1) << "\n";
    std::cout << "First tree max depth: " << maxDepth(root1) << "\n";
    std::cout << "First tree max key: " << maxKey(root1) << "\n";
    std::cout << "First tree min depth: " << minDepth(root1) << "\n";

    std::cout << (sameShape(root1, root2)
                 ? "The trees have the same shape.\n"
                 : "The trees do NOT have the same shape.\n");

    // Cleanup omitted for brevity
    return 0;
}

