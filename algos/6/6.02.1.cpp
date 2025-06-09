
// 6.2.1. Hozzon létre struktúrát a bináris fa csomópontja számára! Ne használjon szülő mutatót, de legyen egy egész típusú adattag! Hozzon létre 8 struktúra változót és állítsa be úgy a mutatókat, hogy kialakítsa az alábbi adatszerkezetet! Valósítsa meg a preodrer, inorder és postorder fabejárásokat! 2 7 4 1 3 9 5 8 Ábra: Megvalósítandó szerkezet 6.3. Bináris keresőfa
 

#include <iostream>
using namespace std;

// 6.2.1: Binary tree node without parent pointer
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

// Pre-order traversal: visit node, then left subtree, then right subtree
void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

// In-order traversal: left subtree, node, right subtree
void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}

// Post-order traversal: left subtree, right subtree, node
void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
}

int main() {
    // Create 8 nodes
    Node a(1), b(2), c(3), d(4), e(5), f(7), g(8), h(9);
    Node* root = &b; // root holds value 2

    // Link pointers to form the tree:
    //        b(2)
    //       /    \
    //    f(7)    c(3)
    //   /   \
    // d(4)  h(9)
    // / \      \
    //a(1)e(5)  g(8)
    
    b.left  = &f;
    b.right = &c;

    f.left  = &d;
    f.right = &h;

    d.left  = &a;
    d.right = &e;

    h.right = &g;

    // Perform traversals
    cout << "Pre-order:   ";
    preOrder(root);
    cout << '\n';

    cout << "In-order:    ";
    inOrder(root);
    cout << '\n';

    cout << "Post-order:  ";
    postOrder(root);
    cout << '\n';

    return 0;
}
