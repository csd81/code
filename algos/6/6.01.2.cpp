
// 6.1.2. Az egész adattag mellet még legyen sztring és lebegőpontos szám típusú adattag is! A menüben legyen lehetőség az egyes adattagok megváltoztatására! 6.2. Fabejárások
 

// C++11
#include <iostream>
#include <string>

struct Node {
    int dataInt;
    float dataFloat;
    std::string dataString;
    Node* left;
    Node* right;
    Node* parent;
    Node(int i, float f, const std::string& s)
      : dataInt(i), dataFloat(f), dataString(s),
        left(nullptr), right(nullptr), parent(nullptr)
    {}
};

void printNode(Node* cur) {
    std::cout << "Current node:\n"
              << "  int:    " << cur->dataInt   << "\n"
              << "  float:  " << cur->dataFloat << "\n"
              << "  string: " << cur->dataString<< "\n"
              << "Can move: "
              << "L=" << (cur->left   ? "yes" : "no") << "  "
              << "R=" << (cur->right  ? "yes" : "no") << "  "
              << "Up="<< (cur->parent ? "yes" : "no") << "\n";
}

void editNode(Node* cur) {
    std::cout << "Edit this node:\n";
    std::cout << "  New int:    ";  std::cin >> cur->dataInt;
    std::cout << "  New float:  ";  std::cin >> cur->dataFloat;
    std::cout << "  New string: ";  std::cin >> cur->dataString;
}

int main(){
    // 1) Create nodes
    Node a(2,  0.2f, ""); 
    Node b(11, 0.11f,"");
    Node c(23, 0.23f,"");
    Node d(13, 0.13f,"");
    Node e(9,  0.9f, ""); 
    Node f(7,  0.7f, "");
    Node g(66, 0.66f,"");
    Node h(8,  0.8f, "");

    // 2) Link them (no parent pointer in struct, so we set manually):
    //            a
    //           / \
    //          b   c
    //         / \   \
    //        d   e   f
    //         \       \
    //          g       h
    a.left   = &b; b.parent = &a;
    a.right  = &c; c.parent = &a;
    b.left   = &d; d.parent = &b;
    b.right  = &e; e.parent = &b;
    d.right  = &g; g.parent = &d;
    c.right  = &f; f.parent = &c;
    f.right  = &h; h.parent = &f;

    Node* cur = &a;
    int choice;
    do {
        printNode(cur);
        std::cout << "\nMenu:\n"
                  << " 1 - Move Left\n"
                  << " 2 - Move Right\n"
                  << " 3 - Move Up (Parent)\n"
                  << " 4 - Edit this node\n"
                  << " 5 - Quit\n"
                  << "Enter choice: ";
        std::cin >> choice;
        switch(choice) {
            case 1:
                if (cur->left) cur = cur->left;
                break;
            case 2:
                if (cur->right) cur = cur->right;
                break;
            case 3:
                if (cur->parent) cur = cur->parent;
                break;
            case 4:
                editNode(cur);
                break;
            case 5:
                std::cout << "Exiting.\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
        std::cout << "\n";
    } while(choice != 5);

    return 0;
}
