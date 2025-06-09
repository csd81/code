
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
}