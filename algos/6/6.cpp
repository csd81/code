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

// 6.4.1. Az input fájl egy családfáról tartalmaz információkat. Minden emberhez egy darab őst rendel. Írjon programot, amely beolvassa a családfát a fájlból, a billentyűzetről pedig bekér egy nevet! Ezután a program írja ki a képernyőre a megadott személy gyerekeinek a nevét és életkorát (az aktuális év 1436), vagy az évet, amikor meghaltak! Ha a megadott embernek nincs gyereke, vagy nem létezik, akkor a program ennek megfelelő üzenetet írjon ki a képernyőre! Használjon dinamikus tömböket! Az input formátuma: NameString Number1 Number2 Number3 ahol NameString: A személy neve, egy szó szóköz nélkül. Number1: A személy születési éve Number2: A személy halálának éve (ha ez a szám -1, a személy él) Number3: A személy gyerekeinek száma Az input faszerkezet szerűen tárolja a személyeket. Ha valakinek két gyereke van, akkor először az első gyermek sorát írjuk le, aztán felsoroljuk az első gyermek leszármazottját és csak utána jön a második gyerekhez tartozó sor. A bemeneti fájl tabulálása nem kötelező. Példa: Fosco 1264 1360 3 Dora 1302 1406 0 Drogo 1308 1380 1 Frodo 1368 -1 0 Dudo 1311 1409 1 Daisy 1350 -1 0 Fosco 1264-ben született, és 1360-ban halt meg. 3 gyermeke volt, Dora, Drogo és Dudo. Drogo fia volt Frodo, aki 1368-ban született, és még életben van. Dora 104 évet élt. Kimenet: (A „Fosco” nevet gépeltük be) Name: Fosco Children of Fosco: ********************************* Dora, lived for 104 years Drogo, lived for 72 years Dudo, lived for 98 years 6.5. Matematikai kifejezések kiértékelése


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

static const int CURRENT_YEAR = 1436;

struct Person {
    std::string name;
    int born;
    int died;    // -1 if still alive
    std::vector<Person> children;
};

// Read one person (and their subtree) from stream
void readPerson(std::istream& in, Person& p) {
    int numChildren;
    in >> p.name >> p.born >> p.died >> numChildren;
    p.children.resize(numChildren);
    for (int i = 0; i < numChildren; ++i) {
        readPerson(in, p.children[i]);
    }
}

// Search for person by name in subtree; return pointer or nullptr
Person* findPerson(Person& root, const std::string& target) {
    if (root.name == target) return &root;
    for (auto& c : root.children) {
        Person* res = findPerson(c, target);
        if (res) return res;
    }
    return nullptr;
}

int main(int argc, char* argv[]) {
    std::ifstream fin;
    if (argc > 1) {
        fin.open(argv[1]);
        if (!fin) {
            std::cerr << "Cannot open file " << argv[1] << "\n";
            return 1;
        }
    }
    std::istream& in = (fin.is_open() ? fin : std::cin);

    Person root;
    readPerson(in, root);

    std::cout << "Enter name: ";
    std::string query;
    std::cin >> query;

    Person* person = findPerson(root, query);
    if (!person) {
        std::cout << "No person named " << query << " found.\n";
        return 0;
    }

    if (person->children.empty()) {
        std::cout << query << " has no children.\n";
        return 0;
    }

    std::cout << "Children of " << query << ":\n";
    for (auto& c : person->children) {
        if (c.died != -1) {
            int age = c.died - c.born;
            std::cout << c.name << ", lived for " << age << " years\n";
        } else {
            int age = CURRENT_YEAR - c.born;
            std::cout << c.name << ", " << age << " years old\n";
        }
    }

    return 0;
}//  6.5.1. Írjon programot, amely kiértékel egy egyszerű matematikai kifejezést! A kifejezések lebegőpontos számokat, illetve négy matematikai operátort tartalmazhatnak: összeadás (+), kivonás (-), szorzás (*), osztás (/). A kifejezés nem tartalmaz zárójeleket. A kifejezést fájlból olvassa be! A program a beolvasott matematikai kifejezést és annak eredményét írja ki a képernyőre! Figyeljen az operátorok kiértékelési sorrendjére! Például 1 + 2 * 3 = 7 és nem 9. Az input fájl formátuma: Első sor: Az operandusok száma. Második sor: A matematikai kifejezés. A számok és operátorok egy-egy szóköz karakterrel vannak elválasztva. Példa bemenet: 6 2 + 3 * 54 - 64 / 10 + 60 Kimenet: 2 + 3 * 54 - 64 / 10 + 60 = 217.6 


// c++11
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

// Evaluate tokens in two passes: first * and /, then + and -
double evalExpression(std::vector<std::string>& tokens) {
    // 1) * and /
    for (size_t i = 1; i < tokens.size() - 1; ) {
        if (tokens[i] == "*" || tokens[i] == "/") {
            double lhs = std::stod(tokens[i-1]);
            double rhs = std::stod(tokens[i+1]);
            double res = (tokens[i] == "*") ? (lhs * rhs) : (lhs / rhs);
            tokens[i-1] = std::to_string(res);
            tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
            // stay at same i (now points to next operator)
        } else {
            i += 2; // skip over the next number to the following operator
        }
    }
    // 2) + and -
    for (size_t i = 1; i < tokens.size() - 1; ) {
        if (tokens[i] == "+" || tokens[i] == "-") {
            double lhs = std::stod(tokens[i-1]);
            double rhs = std::stod(tokens[i+1]);
            double res = (tokens[i] == "+") ? (lhs + rhs) : (lhs - rhs);
            tokens[i-1] = std::to_string(res);
            tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
        } else {
            i += 2;
        }
    }
    // now tokens.size() == 1
    return std::stod(tokens[0]);
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ifstream fin;
    if (argc > 1) {
        fin.open(argv[1]);
        if (!fin) {
            std::cerr << "Cannot open file " << argv[1] << "\n";
            return 1;
        }
    }
    std::istream& in = (fin.is_open() ? fin : std::cin);

    int n;
    if (!(in >> n)) {
        std::cerr << "Failed to read the operand count\n";
        return 1;
    }
    std::vector<std::string> tokens;
    tokens.reserve(n * 2 - 1);

    // read the rest of the line: expression tokens
    std::string tok;
    for (int i = 0; i < 2*n-1; ++i) {
        in >> tok;
        tokens.push_back(tok);
    }

    // print original expression
    for (size_t i = 0; i < tokens.size(); ++i) {
        std::cout << tokens[i] << (i+1<tokens.size() ? ' ' : '\0');
    }

    // copy tokens for evaluation
    auto evalTokens = tokens;
    double result = evalExpression(evalTokens);

    // trim trailing zeros
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(6) << result;
    std::string s = oss.str();
    // remove trailing zeros and possibly the dot
    s.erase(s.find_last_not_of('0') + 1, std::string::npos);
    if (!s.empty() && s.back() == '.') s.pop_back();

    std::cout << " = " << s << "\n";
    return 0;
}

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

