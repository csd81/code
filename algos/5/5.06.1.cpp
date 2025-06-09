// 5.6.1. Írjon programot, amely kezeli a nyomtatási sort a fenti precedenciáknak megfelelően! Valósítsd meg Beszúrás és Következő műveleteket! Beszúrásnál a dokumentum azonosítóját és a személy rangját kell megadni. Minden nyomtatás elindítása után 45% valószínűséggel rögtön elkészül egy nyomtatás. 
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

