// c++11
// 5.1.1. Készítsen egy verem osztályt, amely statikus, 5 nagyságú egész tömbben tárol értékeket! valósítsa meg a következő metódusokat: init, push, pop, isFull, isEmpty! Ötlet: egyértelműen definiálja, hogy a verem mutató az első szabad elemre vagy az utolsó használt elemre mutat-e! 

#include <iostream>

class IntStack {
    static const int CAPACITY = 5;
    int elems[CAPACITY];
    int elemnum;  // index of next free slot (0…CAPACITY)

public:
    // Initialize to empty
    void init() {
        elemnum = 0;
    }

    // Returns true if no space left
    bool isFull() const {
        return elemnum == CAPACITY;
    }

    // Returns true if nothing to pop
    bool isEmpty() const {
        return elemnum == 0;
    }

    // Pushes n onto stack; returns false if full
    bool push(int n) {
        if (isFull()) return false;
        elems[elemnum++] = n;
        return true;
    }

    // Pops top into n; returns false if empty
    bool pop(int &n) {
        if (isEmpty()) return false;
        n = elems[--elemnum];
        return true;
    }
};

int main() {
    IntStack s;
    s.init();

    char choice;
    int value;

    do {
        std::cout << "\nMenu:\n"
                  << "  1) Push\n"
                  << "  2) Pop\n"
                  << "  3) Is Full?\n"
                  << "  4) Is Empty?\n"
                  << "  5) Exit\n"
                  << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cout << "Value to push: ";
                std::cin >> value;
                if (s.push(value))
                    std::cout << "Pushed " << value << "\n";
                else
                    std::cout << "Stack is full!\n";
                break;

            case '2':
                if (s.pop(value))
                    std::cout << "Popped " << value << "\n";
                else
                    std::cout << "Stack is empty!\n";
                break;

            case '3':
                std::cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n");
                break;

            case '4':
                std::cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;

            case '5':
                std::cout << "Exiting.\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != '5');

    return 0;
}

// c++11
// 5.1.2. Valósítsa meg a vermet dinamikus tömbbel! Ha betelt a tömb, foglaljon le egy nagyobbat 5.2. Verem

#include <iostream>

class DynamicIntStack {
    int *store;
    int elemnum;    // next free index
    int capacity;

    // Double the capacity
    void increaseCapacity() {
        int newCap = capacity * 2;
        int *temp = new int[newCap];
        for (int i = 0; i < elemnum; ++i) {
            temp[i] = store[i];
        }
        delete[] store;
        store = temp;
        capacity = newCap;
        std::cout << "[Resized to capacity " << capacity << "]\n";
    }

public:
    DynamicIntStack() : elemnum(0), capacity(1) {
        store = new int[capacity];
    }
    ~DynamicIntStack() {
        delete[] store;
    }

    bool isEmpty() const {
        return elemnum == 0;
    }
    bool isFull() const {
        return elemnum == capacity;
    }

    void push(int v) {
        if (isFull()) {
            increaseCapacity();
        }
        store[elemnum++] = v;
    }

    bool pop(int &out) {
        if (isEmpty()) return false;
        out = store[--elemnum];
        return true;
    }
};

int main() {
    DynamicIntStack stack;
    char choice;
    int value;

    do {
        std::cout << "\nMenu:\n"
                  << " 1) Push\n"
                  << " 2) Pop\n"
                  << " 3) Is Empty?\n"
                  << " 4) Exit\n"
                  << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
            case '1':
                std::cout << "Value to push: ";
                std::cin >> value;
                stack.push(value);
                std::cout << "Pushed " << value << "\n";
                break;
            case '2':
                if (stack.pop(value))
                    std::cout << "Popped " << value << "\n";
                else
                    std::cout << "Stack is empty!\n";
                break;
            case '3':
                std::cout << (stack.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case '4':
                std::cout << "Exiting.\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != '4');

    return 0;
}
// c++11
// 5.2.1. Írjon programot, amely számokat olvas be a billentyűzetről addig, amíg a beolvasott szám nem 0!
// Tárolja a számokat egy veremben, amit láncolt listával valósítson meg.
// A 0 gépelése után a program olvassa ki a számokat a veremből, és írja a képernyőre! 
// Valósítsa meg a push és pop függvényeket, valamint a lista felszabadítását!
// Példa: Type a number: 1 Type a number: 5 Type a number: 7 Type a number: 0 7 5 1 5.3. Sor

#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int v, Node* n) : value(v), next(n) {}
};

class Stack {
    Node* head;
    int count;
public:
    Stack() : head(nullptr), count(0) {}
    ~Stack() { clear(); }

    void push(int v) {
        head = new Node(v, head);
        ++count;
    }

    bool pop(int& out) {
        if (!head) return false;
        Node* tmp = head;
        out = head->value;
        head = head->next;
        delete tmp;
        --count;
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void clear() {
        int _;
        while (pop(_)) {}
    }

    int size() const {
        return count;
    }
};

int main() {
    Stack s;
    int num;

    do {
        std::cout << "Type a number: ";
        std::cin >> num;
        if (num != 0) {
            s.push(num);
        }
    } while (num != 0);

    std::cout << "\nPopped values in LIFO order:\n";
    while (!s.isEmpty()) {
        s.pop(num);
        std::cout << num << "\n";
    }

    return 0;
}

// c++11
// 5.3.1. Írjon programot, amely számokat olvas be a billentyűzetről addig, amíg a beolvasott szám nem 0! Tárolja ezeket egy sorban, amit láncolt listával valósíts meg! A 0 gépelése után a program olvassa ki a számokat a sorból, és írja a képernyőre! Valósítsa meg a push és pop függvényeket, valamint a lista felszabadítását! Példa: Type a number: 10 Type a number: 43 Type a number: 2 Type a number: 5 Type a number: 0 2 5 5.4. Fordított lengyelforma


#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

class Queue {
    Node* head;
    Node* tail;
    int count;

public:
    Queue() : head(nullptr), tail(nullptr), count(0) {}
    ~Queue() { clear(); }

    // Push to the back
    void push(int v) {
        Node* n = new Node(v);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        ++count;
    }

    // Pop from the front; returns false if empty
    bool pop(int &out) {
        if (!head) return false;
        Node* n = head;
        out = n->value;
        head = head->next;
        if (!head) tail = nullptr;
        delete n;
        --count;
        return true;
    }

    bool isEmpty() const { return count == 0; }
    int size() const { return count; }

    void clear() {
        int tmp;
        while (pop(tmp)) {}
    }
};

int main() {
    Queue q;
    int num;

    // Read until 0
    do {
        std::cout << "Type a number: ";
        std::cin >> num;
        if (num != 0) q.push(num);
    } while (num != 0);

    std::cout << "\nDequeued values:\n";
    while (!q.isEmpty()) {
        q.pop(num);
        std::cout << num << "\n";
    }

    return 0;
}

// c++11
// 5.4.1. Egy matematikai kifejezést felírhatunk úgynevezett fordított lengyelformában is.
// Például a 3 + 4 kifejezés ebben az alakban így néz ki: 3 4 +.
// Fordított lengyelformában nincs szükség zárójelekre, és a műveletek precedenciájára sem kell ügyelni,
// mert azt már figyelembe vettük akkor, amikor meghatároztuk ezt a formát.
// A fordított lengyelformában lévő kifejezés egy verem segítségével értékelhető ki.
// Balról jobbra olvassuk a kifejezést, ha szám következik, akkor azt berakjuk a verembe, ha műveleti jel, akkor kiveszünk a veremből 2 elemet, elvégezzük rajtuk a műveletet, majd az eredményt visszahelyezzük a verembe. A (2 + 5) * 3 - 9 / (2 + 1) kifejezés fordított lengyelformában: 2 5 + 3 * 9 2 1 + / -. Az algoritmus az alábbi táblázatban lévő lépéseket hajtja végre a kifejezés kiértékeléséhez. Írjon programot, amely beolvas egy matematikai kifejezést fordított lengyel formában, majd az ismertetett módszer szerint megoldja azt! Lépés 0 1 2 Verem tartalma Kifejezés 2 2 5 2 5 + 3 * 9 2 1 + / 5 + 3 * 9 2 1 + / + 3 * 9 2 1 + / - 3 7 3 * 9 2 1 + / - 4 7 3 * 9 2 1 + / - 5 9 2 1 + / - 6 7 8 21 9 21 9 2 21 9 2 1 2 1 + / 1 + / + / - 9 21 9 3 / - 21 3 - Művelet Verembe(2) Verembe(5) a = Veremből b = Veremből Verembe (b + a) Verembe(3) a = Veremből b = Veremből Verembe(b*a) Verembe(9) Verembe(2) Verembe(1) a = Veremből b = Veremből Verembe(b+a) a = Veremből b = Veremből Verembe(b/a) a = Veremből b = Veremből Verembe(b-a) 5.5. Várólista
 
#include <iostream>
#include <sstream>
#include <string>

// Node for linked-list stack
struct Node {
    int value;
    Node* next;
    Node(int v, Node* n) : value(v), next(n) {}
};

class Stack {
    Node* head;
public:
    Stack() : head(nullptr) {}
    ~Stack() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void push(int v) {
        head = new Node(v, head);
    }
    bool pop(int &out) {
        if (!head) return false;
        out = head->value;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }
    bool empty() const { return head == nullptr; }
};

int main() {
    std::cout << "Enter RPN expression (tokens separated by spaces):\n";
    std::string line;
    if (!std::getline(std::cin, line)) return 0;

    std::istringstream iss(line);
    std::string token;
    Stack st;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int a, b;
            if (!st.pop(a) || !st.pop(b)) {
                std::cerr << "Error: not enough operands\n";
                return 1;
            }
            int res;
            if (token == "+") res = b + a;
            else if (token == "-") res = b - a;
            else if (token == "*") res = b * a;
            else { // "/"
                if (a == 0) {
                    std::cerr << "Error: division by zero\n";
                    return 1;
                }
                res = b / a;
            }
            st.push(res);
        } else {
            // assume integer literal
            try {
                int v = std::stoi(token);
                st.push(v);
            } catch (...) {
                std::cerr << "Invalid token: " << token << "\n";
                return 1;
            }
        }
    }

    int result;
    if (!st.pop(result) || !st.empty()) {
        std::cerr << "Error: invalid RPN expression\n";
        return 1;
    }

    std::cout << "Result: " << result << "\n";
    return 0;
}

// 5.5.1. Egy fővárosi hivatalban az ügyfeleknek rendszerint várakozni kell. Minden újonnan érkező személy kap egy azonosítót és az embereket ezen azonosítók alapján szólítják. A kiszolgálás érkezési sorrendben történik. Írjon programot, amely segít a hivatal személyzetének a következő kiszolgálandó ügyfél azonosítójának megállapításában! Valósítsa meg a sor adatszerkezetet, ahol a beszúrás művelet létrehoz egy új azonosítót, kiírja a képernyőre és hozzáadja a sorhoz! A kivesz művelet kiveszi a sorból egy elemet és az azonosítót kiírja a képernyőre. Menü segítségével lehessen választani a beszúrás és a kivesz műveletek között! 
// 5.5.2. Előfordulhat, hogy egyszerre több embert tudnak kiszolgálni. Bővítse ki a programot az N_kivesz művelettel, amely N darab elemet vesz ki a sorból és kiírja a megfelelő azonosítókat! 5.6. Nyomtatók A fővárosi Könyvkötészeti- és Borászati Főiskola Szőlőtermesztési Tanszékén egy hálózati nyomtatót használ mindenki. Minden nyomtatási feladat bekerül egy nyomtatási sorba. A tanszéken az emberek nem egyenrangúak, a fontossági sorrendet az egyes személyeknek a szervezeti hierarchián belüli pozíciója szabja meg. A következő fokozatokat különböztetjük meg: tanszékvezető, professzorok, docensek, adjunktusok és tanársegédek. Például, ha a nyomtatási sor elején van 2 feladat docensektől, majd utána 3 tanársegédektől, akkor, ha egy adjunktus elindít egy nyomtatást, akkor az a docensek feladatai után, a tanársegédeké előtt jelenik meg a sorban. Az azonos hierarchia szinten lévő emberek nyomtatása érkezési sorrend alapján történik

// 5.5.1.-5.5.2.

#include <iostream>
#include <random>
#include <unordered_set>

// Simple linked-list queue for ints
class ServiceQueue {
    struct Node {
        int id;
        Node* next;
        Node(int i): id(i), next(nullptr) {}
    } *head, *tail;
public:
    ServiceQueue(): head(nullptr), tail(nullptr) {}
    ~ServiceQueue() { clear(); }

    // Enqueue
    void push(int id) {
        Node* n = new Node(id);
        if (!tail) head = tail = n;
        else {
            tail->next = n;
            tail = n;
        }
    }

    // Dequeue; return false if empty
    bool pop(int &out) {
        if (!head) return false;
        Node* n = head;
        out = n->id;
        head = head->next;
        if (!head) tail = nullptr;
        delete n;
        return true;
    }

    bool isEmpty() const { return head == nullptr; }

    void clear() {
        int tmp;
        while (pop(tmp));
    }
};

int main() {
    ServiceQueue queue;
    std::unordered_set<int> existing;

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 1000);

    char choice;
    do {
        std::cout << "\nMenu:\n"
                  << "  1) Insert (new customer)\n"
                  << "  2) Remove (next customer)\n"
                  << "  3) Remove N customers\n"
                  << "  4) Exit\n"
                  << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
            case '1': {
                // generate unique ID
                int id;
                do {
                    id = dist(rng);
                } while (existing.count(id));
                existing.insert(id);
                queue.push(id);
                std::cout << "New ID: " << id << "\n";
                break;
            }
            case '2': {
                int id;
                if (queue.pop(id)) {
                    existing.erase(id);
                    std::cout << "Next ID: " << id << "\n";
                } else {
                    std::cout << "Queue is empty!\n";
                }
                break;
            }
            case '3': {
                int n;
                std::cout << "How many to remove? ";
                std::cin >> n;
                for (int i = 0; i < n; ++i) {
                    int id;
                    if (queue.pop(id)) {
                        existing.erase(id);
                        std::cout << "Removed #" << (i+1)
                                  << ": ID=" << id << "\n";
                    } else {
                        std::cout << "Queue empty after " << i << " removals.\n";
                        break;
                    }
                }
                break;
            }
            case '4':
                std::cout << "Exiting.\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != '4');

    return 0;
}// 5.6.1. Írjon programot, amely kezeli a nyomtatási sort a fenti precedenciáknak megfelelően! Valósítsd meg Beszúrás és Következő műveleteket! Beszúrásnál a dokumentum azonosítóját és a személy rangját kell megadni. Minden nyomtatás elindítása után 45% valószínűséggel rögtön elkészül egy nyomtatás. 
// 5.6.2. Bővítse ki a programot úgy, hogy minden nyomtatás előtt egy személyhez tartozó kódot kell megadni! Csak akkor lehet nyomtatni, ha a kód helyes. A kódból következik a személy rangja is. Minden nyomtatás elindítása után jelenítse meg a nyomtatási sort! 5.7. Pascal háromszög
// 5.6.1.-5.6.2.

#include <iostream>
#include <string>
#include <random>
#include <memory>

enum class Rank { PROFESSOR=0, DOCENT, ADJUNKTUS, ASSISTANT };

struct Job {
    int id;
    Rank rank;
    std::shared_ptr<Job> next;
    Job(int i, Rank r) : id(i), rank(r), next(nullptr) {}
};

class PrintQueue {
    std::shared_ptr<Job> head;
public:
    void insert(int id, Rank r) {
        auto job = std::make_shared<Job>(id, r);
        if (!head || static_cast<int>(r) < static_cast<int>(head->rank)) {
            job->next = head;
            head = job;
            return;
        }
        auto cur = head;
        while (cur->next && static_cast<int>(cur->next->rank) <= static_cast<int>(r)) {
            cur = cur->next;
        }
        job->next = cur->next;
        cur->next = job;
    }

    bool pop(int &outId) {
        if (!head) return false;
        outId = head->id;
        head = head->next;
        return true;
    }

    bool empty() const { return !head; }

    void display() const {
        std::cout << "\nCurrent queue:\n";
        if (!head) {
            std::cout << "  [empty]\n";
            return;
        }
        auto cur = head;
        while (cur) {
            static const char* names[] = {"PROFESSOR","DOCENT","ADJUNKTUS","ASSISTANT"};
            std::cout << "  ID=" << cur->id
                      << " (" << names[static_cast<int>(cur->rank)] << ")\n";
            cur = cur->next;
        }
    }
};

int main(){
    PrintQueue q;
    std::mt19937_64 rng(std::random_device{}());
    std::uniform_real_distribution<> dist(0.0,1.0);

    char cmd;
    do {
        std::cout << "\nMenu:\n"
                  << "  i : Insert new print job\n"
                  << "  n : Print next job\n"
                  << "  q : Quit\n"
                  << "Choice: ";
        std::cin >> cmd;

        if (cmd == 'i') {
            int id;
            std::string code;
            std::cout << "  Enter document ID: ";
            std::cin >> id;
            std::cout << "  Enter personal code (initial P/D/A/T): ";
            std::cin >> code;
            Rank r;
            switch (code[0]) {
                case 'P': r = Rank::PROFESSOR; break;
                case 'D': r = Rank::DOCENT;    break;
                case 'A': r = Rank::ADJUNKTUS; break;
                case 'T': r = Rank::ASSISTANT; break;
                default:
                    std::cout << "Invalid code, treating as ASSISTANT.\n";
                    r = Rank::ASSISTANT;
            }
            q.insert(id, r);
            // 45% immediate print chance
            if (!q.empty() && dist(rng) < 0.45) {
                int nextId;
                q.pop(nextId);
                std::cout << ">> Printed immediately ID=" << nextId << "\n";
            }
            q.display();
        }
        else if (cmd == 'n') {
            std::cout << "Press personal code to confirm: ";
            std::string code;
            std::cin >> code;
            Rank attempt;
            switch (code[0]) {
                case 'P': attempt = Rank::PROFESSOR; break;
                case 'D': attempt = Rank::DOCENT;    break;
                case 'A': attempt = Rank::ADJUNKTUS; break;
                case 'T': attempt = Rank::ASSISTANT; break;
                default:
                    std::cout << "Invalid code. Cannot print.\n";
                    continue;
            }
            int nextId;
            if (q.pop(nextId)) {
                std::cout << ">> Printed ID=" << nextId << "\n";
            } else {
                std::cout << "Queue empty; nothing to print.\n";
            }
            q.display();
        }
    } while (cmd != 'q');

    std::cout << "Exiting.\n";
    return 0;
}


// c++11
/* //  5.7.1. Állítsuk elő a Pascal háromszöget a k-dik sorig, sor adatszerkezetet használva! Ötlet:ha az i-dik sora megvan a Pascal háromszögnek, akkor abból megkapjuk a i+1-edik sort a következő képen. Vegyük ki az utolsó elemet a sorból és tároljuk el, adjuk hozzá az új utolsó elemet, majd rakjuk be a sor elejére. Az előző műveleteket összesen (i-1)-szer hajtsuk végre, ezután rakjuk be a sor elejére az „1” elemet. Példa: (1 3 3 1);
utolsó elem ki -> (1 3 3);
összeadás, lista elejére fűzés -> (4 1 3 3);
utolsó elem ki -> (4 1 3);
összeadás, lista elejére fűzés -> (6 4 1 3);
utolsó elem ki -> (6 4 1);
összeadás, lista elejére fűzés -> (4 6 4 1);
’1’-es elem befűzése a lista elejére -> (1 4 6 4 1).  
*/

// c++11
#include <iostream>
#include <deque>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);

    int k;
    std::cout << "Enter number of rows (k): ";
    std::cin >> k;
    if (k < 0) return 0;

    // We'll generate rows 0 through k of Pascal's triangle.
    // We store each row in a deque<int>.
    std::deque<int> row{1};

    for (int i = 0; i <= k; ++i) {
        // Print leading spaces for a nice triangle shape
        int spaces = k - i;
        for (int s = 0; s < spaces; ++s) 
            std::cout << "   ";

        // Print the current row
        for (int v : row) 
            std::cout << std::setw(4) << v;
        std::cout << "\n";

        // Build the next row from the current one
        std::deque<int> next;
        next.push_back(1);
        for (size_t j = 1; j < row.size(); ++j) {
            next.push_back(row[j-1] + row[j]);
        }
        next.push_back(1);
        row.swap(next);
    }

    return 0;
}

// c++11
// 5.8.1. Egy rádióadó periodikusan ismétli ugyanazt az adást, minden adás végén egy speciális jelet ad (#). Az adássorozat egy szekvenciális karakter tömbben van, döntsük el egy sor adatszerkezetet használva, hogy volt-e hiba valamelyik adásban! Hiba az adásban: nem mindig ugyanazt a jelsorozatot adta le az adó. 5.9. Zárójelezés

// c++11
#include <iostream>
#include <string>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Example input; you can replace these with std::getline/std::cin if desired.
    std::string signal = "abcdefg#abcdefg#abfdgcdefg#abdfcdefg#abcdfdefg#abcdefg#adfcvbcdefg#abcde fg#abcdefg#aega";
    std::string pattern = "abcdefg";

    // Split signal on '#' into a queue of messages
    std::queue<std::string> q;
    std::string current;
    for (char c : signal) {
        if (c == '#') {
            if (!current.empty()) {
                q.push(current);
                current.clear();
            }
        } else {
            current += c;
        }
    }
    // In case there's no trailing '#'
    if (!current.empty()) {
        q.push(current);
    }

    // Process the queue: check each segment against the pattern
    int idx = 1;
    while (!q.empty()) {
        const std::string& msg = q.front();
        bool ok = (msg == pattern);
        std::cout << idx << ". \"" << msg << "\" -> "
                  << (ok ? "OK" : "Wrong") << "\n";
        q.pop();
        ++idx;
    }

    return 0;
}
// c++11
// 5.9.1. Kérjünk be egy kifejezést, ami több nyitó és zárójelet tartalmaz!
// Verem segítségével írjuk ki az összetartozó zárójelpárok indexeit,
// és közben döntsük el, hogy helyes-e a zárójelezés!  


#include <iostream>
#include <string>
#include <stack>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string expr;
    std::cout << "Enter expression with parentheses: ";
    std::getline(std::cin, expr);

    std::stack<int> st;
    bool error = false;

    for (int i = 0; i < static_cast<int>(expr.size()); ++i) {
        char c = expr[i];
        if (c == '(') {
            st.push(i);
        } else if (c == ')') {
            if (st.empty()) {
                std::cout << "Error: unmatched ')' at index " << i << "\n";
                error = true;
                break;
            }
            int openIdx = st.top();
            st.pop();
            std::cout << "Matched parentheses: '(' at index "
                      << openIdx << " with ')' at index " << i << "\n";
        }
    }

    if (!error) {
        if (!st.empty()) {
            while (!st.empty()) {
                std::cout << "Error: unmatched '(' at index " << st.top() << "\n";
                st.pop();
            }
        } else {
            std::cout << "All parentheses matched correctly.\n";
        }
    }

    return 0;
}