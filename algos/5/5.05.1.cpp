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
}