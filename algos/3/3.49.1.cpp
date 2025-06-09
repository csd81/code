/* c++11

3.49.1. Nemo kapitány alámerül a Nautilus tengeralattjáróval, 
hogy megvizsgálja a tenger élővilágát. 
Merülés közben a segédei minden tízedik méternél megszámolják, 
hogy mennyi halat látnak, hogy ezt felhasználhassák későbbi 
kutatásaikhoz. 
A számlálások eredményét egy vektorban tárolják el, ahol az i. komponens 
a 10*i méter mélyen végzett számlálás eredményét tárolja. 
Sajnos még nem áll rendelkezésre nagy memória kapacitású számítógép, 
az eredményeket lyukkártyára írják. Megfigyelték, hogy nagyon gyakran nem 
látnak egy halat sem, 
ezért úgy gondolták, oly módon tárolják az eredményeket, hogy ezt a 
tényt kihasználják 
és a ritka vektorok tárolási módszeréhez folyamodtak, így helyet 
takarítottak meg, 
és az adatok feldolgozása is gyorsabb. Írjon programot, amely egy ilyen 
ritka vektorokat kezel! 
A ritka vektorok olyan vektorok, amelyek nagyon kevés nem 0 komponenst 
tartalmaznak. 
Ezeket célszerű úgy tárolni, hogy csak a nem 0 elemeket tároljuk, azon 
vektoron belüli indexével. 
Ennek egyik módja, ha a (szám, index) párokat láncolt listában tároljuk. 
A vektor dimenziója nincs korlátozva. Valósítsa meg a következő 
műveleteket: 
· Beállít(index, érték): A vektor adott indexű elemét az adott értékre 
állítja be.  
  Ha az érték 0, akkor az elem nem tárolódik. 
· Érték(index): A művelet visszaadja az adott indexű elem értékét. 
· Töröl: A művelet nulláza a teljes vektor tartalmát. 
· NemNullák: A művelet visszaadja, hogy mennyi nem 0 elem van a vektorban. 
· Legutolsó: A művelet visszaadja, hogy hányas indexen található a 
legutolsó nem 0 elem. 
· Megjelenít: A művelet kiírja a képernyőre a teljes vektort egészen a 
„Legutolsó” által meghatározott elemig.
 A 0-kat is meg kell jeleníteni. 

3.49.2. Előfordulhat, hogy az előző vektoron belül az elemek nem jó 
sorrendben követik egymást. 
éldául lehet, hogy előbb található meg az 5-ös indexű elem a listában, 
mint a 3-as. 
Implementálja a „Rendez” műveletet, amely az indexeknek megfelelően 
növekvő sorrendbe rendezi 
a listán belüli elemeket! 

3.49.3. Bővítse ki az előző programot az összeadás és a szorzás 
műveletekkel! 
Az összeadás két ritka vektort ad össze. Ügyeljen arra, hogy a 0 elemeket 
ne tárolja el! 
A szorzás 2 ritka vektort szoroz össze skalárisan.  

3.49.1-3.49.3. */



#include <iostream>
#include <memory>

class SparseVector {
    struct Node {
        double value;
        int index;
        std::unique_ptr<Node> next;
        Node(double val, int idx) : value(val), index(idx), next(nullptr) {}
    };

    std::unique_ptr<Node> head;

    // Segédfüggvény: mély másolás egy láncolt listáról
    static std::unique_ptr<Node> clone(const std::unique_ptr<Node>& src) {
        if (!src) return nullptr;
        std::unique_ptr<Node> res(new Node(src->value, src->index));
        res->next = clone(src->next);
        return res;
    }

public:
    SparseVector() = default;
    ~SparseVector() = default;

    // Másoló konstruktor (deep copy)
    SparseVector(const SparseVector& other) : head(clone(other.head)) {}

    // Másoló értékadó operátor (deep copy)
    SparseVector& operator=(const SparseVector& other) {
        if (this != &other) {
            head = clone(other.head);
        }
        return *this;
    }

    // Beállít: értéket ad egy indexhez (ha 0, akkor törli)
    void set(int idx, double val) {
        Node* prev = nullptr;
        Node* curr = head.get();

        while (curr && curr->index < idx) {
            prev = curr;
            curr = curr->next.get();
        }
        if (curr && curr->index == idx) {
            if (val == 0.0) {
                if (prev)
                    prev->next = std::move(curr->next);
                else
                    head = std::move(curr->next);
            } else {
                curr->value = val;
            }
            return;
        }
        if (val == 0.0) return;

        std::unique_ptr<Node> newNode(new Node(val, idx));
        if (prev) {
            newNode->next = std::move(prev->next);
            prev->next = std::move(newNode);
        } else {
            newNode->next = std::move(head);
            head = std::move(newNode);
        }
    }

    // Lekérdezés
    double get(int idx) const {
        Node* curr = head.get();
        while (curr && curr->index < idx)
            curr = curr->next.get();
        if (curr && curr->index == idx)
            return curr->value;
        return 0.0;
    }

    // Töröl mindent
    void clear() {
        head.reset();
    }

    // Nem nulla elemek száma
    int nonZeros() const {
        int count = 0;
        Node* curr = head.get();
        while (curr) {
            ++count;
            curr = curr->next.get();
        }
        return count;
    }

    // Legutolsó nem nulla index (ha nincs, -1)
    int lastIndex() const {
        int idx = -1;
        Node* curr = head.get();
        while (curr) {
            if (curr->index > idx) idx = curr->index;
            curr = curr->next.get();
        }
        return idx;
    }

    // Megjelenít (nullákkal együtt, egészen a legutolsóig)
    void print() const {
        int max = lastIndex();
        if (max == -1) {
            std::cout << "ures" << std::endl;
            return;
        }
        for (int i = 0; i <= max; ++i) {
            std::cout << get(i);
            if (i < max) std::cout << ", ";
        }
        std::cout << std::endl;
    }

    // Rendezés index szerint (Bubble-sort szerűen, pointerek helyett 
értékcserével)
    void sort() {
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node* curr = head.get();
            while (curr->next) {
                if (curr->index > curr->next->index) {
                    std::swap(curr->index, curr->next->index);
                    std::swap(curr->value, curr->next->value);
                    swapped = true;
                }
                curr = curr->next.get();
            }
        } while (swapped);
    }

    // Összeadás
    SparseVector operator+(const SparseVector& other) const {
        SparseVector result = *this;
        Node* curr = other.head.get();
        while (curr) {
            result.set(curr->index, result.get(curr->index) + curr->value);
            curr = curr->next.get();
        }
        return result;
    }

    // Skaláris szorzat (dot product)
    double dot(const SparseVector& other) const {
        double sum = 0.0;
        Node* curr = head.get();
        while (curr) {
            double v = other.get(curr->index);
            sum += curr->value * v;
            curr = curr->next.get();
        }
        return sum;
    }
};

int menu() {
    std::cout << "\n1. Beallit (index, ertek)\n"
              << "2. Ertek lekerdezese\n"
              << "3. Mindet torol\n"
              << "4. Nem nullak szama\n"
              << "5. Legutolso index\n"
              << "6. Megjelenit\n"
              << "7. Rendez\n"
              << "8. Osszead masik vektorral\n"
              << "9. Skalaris szorzas masik vektorral\n"
              << "10. Kilepes\n"
              << "Valasztas: ";
    int ch;
    std::cin >> ch;
    return ch;
}

int main() {
    SparseVector v;
    SparseVector v2;
    v2.set(2, 5.0);
    v2.set(6, 1.0);
    v2.set(10, 7.0);

    int menuval;
    do {
        menuval = menu();
        if (menuval == 1) {
            int idx; double val;
            std::cout << "Index: "; std::cin >> idx;
            std::cout << "Ertek: "; std::cin >> val;
            v.set(idx, val);
        } else if (menuval == 2) {
            int idx;
            std::cout << "Index: "; std::cin >> idx;
            std::cout << "Ertek: " << v.get(idx) << "\n";
        } else if (menuval == 3) {
            v.clear();
        } else if (menuval == 4) {
            std::cout << "Nem nullak szama: " << v.nonZeros() << "\n";
        } else if (menuval == 5) {
            std::cout << "Legutolso index: " << v.lastIndex() << "\n";
        } else if (menuval == 6) {
            v.print();
        } else if (menuval == 7) {
            v.sort();
        } else if (menuval == 8) {
            v = v + v2;
        } else if (menuval == 9) {
            std::cout << "Skalaris szorzat: " << v.dot(v2) << "\n";
        }
    } while (menuval != 10);

    return 0;
}
