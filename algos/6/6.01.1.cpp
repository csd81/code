// 6.1.1. Hozzon létre struktúrát a bináris fa csomópontja számára! Használjon szülő mutatót és egy egész típusú adattagot! Hozzon létre 8 struktúra változót és állítsa be úgy a mutatókat, hogy kialakítsa az alábbi adatszerkezetet! Írjon menüt, amelynek a segítségével a fán mozoghat balra, jobbra, visszafele és kiléphet! Írja ki mindig az aktuális elem egész adattagját és hogy vannak-e gyerekei! Ha olyan irányba történne a mozgás, ahol nincs csomópont, akkor nem változik az aktuális mutató. 2 9 7 8 Ábra: Megvalósítandó szerkezet

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int v)
      : data(v), left(nullptr), right(nullptr), parent(nullptr)
    {}
};

void printNode(Node* cur) {
    cout << "Current node: " << cur->data
         << "   [can go: "
         << "L=" << (cur->left   ? "yes" : "no") << "  "
         << "R=" << (cur->right  ? "yes" : "no") << "  "
         << "Up="<<(cur->parent ? "yes" : "no") << "]\n";
}

int main() {
    // 1) Create 8 nodes with the given integer values
    Node a(2),  b(11), c(23), d(13),
         e(9),  f(7),  g(66), h(8);

    // 2) Link them up to form the tree:
    //
    //            a(2)
    //           /    \
    //       b(11)    c(23)
    //       /   \       \
    //   d(13)  e(9)     f(7)
    //     \             /
    //     g(66)       h(8)
    //
    a.left  = &b;
    a.right = &c;
    b.parent = &a;
    c.parent = &a;

    b.left  = &d;
    b.right = &e;
    d.parent = &b;
    e.parent = &b;

    d.right = &g;
    g.parent = &d;

    c.right = &f;
    f.parent = &c;

    f.left = &h;
    h.parent = &f;

    // 3) Start at the root
    Node* cur = &a;
    int choice;
    do {
        printNode(cur);
        cout << "\nMove: (1) Left   (2) Right   (3) Up   (4) Quit\n> ";
        cin >> choice;
        switch (choice) {
            case 1:
                if (cur->left)  cur = cur->left;
                break;
            case 2:
                if (cur->right) cur = cur->right;
                break;
            case 3:
                if (cur->parent) cur = cur->parent;
                break;
            case 4:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
