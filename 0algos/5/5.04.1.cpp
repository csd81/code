
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

