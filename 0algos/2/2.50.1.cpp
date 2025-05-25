// 2.50. Halmazok metszete
// 2.50.1. Írjon programot, amely két halmaz metszetét generálja! Mindkét 
// halmaz egész számokat tartalmaz. A program olvassa be az input fájlt! 
// Kérjen be egy számot a billentyűzetről, és döntse el, hogy a szám 
// eleme-e az első halmaznak, a második halmaznak, illetve ezek metszetének! 
// Írassa ki a képernyőre az előbbi három halmazt! Végül írassa ki, hogy 
// az első halmaz részhalmaza-e a másodiknak, illetve fordítva! Használjon 
// dinamikus tömböket! Az input fájl formátuma: Első sor: az első halmaz 
// mérete Második sor: az első halmaz elemei Harmadik sor: a második halmaz 
// mérete Negyedik sor: a második halmaz elemei A számok egy-egy szóköz 
// karakterrel vannak elválasztva. Példa bemenet: 3 80 54 41 5 41 21 54 76 80 
// Kimenet: Type a number: 76 76 is not element of A 76 is element of B 76 is not 
// element of intersection of A and B A = {80, 54, 41} B = {41, 21, 54, 76, 80} 
// Intersection of A and B = {41, 54, 80} B is not subset of A A is subset of B 
// 2.50.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void readSet(std::ifstream& file, std::vector<int>& set) {
    int size;
    file >> size;
    set.resize(size);
    for (int i = 0; i < size; ++i) {
        file >> set[i];
    }
}

void printSet(const std::string& name, const std::vector<int>& set) {
    std::cout << name << " = {";
    for (size_t i = 0; i < set.size(); ++i) {
        std::cout << set[i];
        if (i != set.size() - 1)
            std::cout << ", ";
    }
    std::cout << "}\n";
}

bool elementOf(int num, const std::vector<int>& set) {
    return std::find(set.begin(), set.end(), num) != set.end();
}

std::vector<int> intersection(const std::vector<int>& A, const std::vector<int>& B) {
    std::vector<int> result;
    for (int val : A) {
        if (elementOf(val, B) && !elementOf(val, result))
            result.push_back(val);
    }
    return result;
}

bool isSubset(const std::vector<int>& A, const std::vector<int>& B) {
    for (int val : A) {
        if (!elementOf(val, B))
            return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    std::string inputFile = (argc > 1) ? argv[1] : "sets.txt";
    std::ifstream file(inputFile);

    if (!file) {
        std::cerr << "Error: could not open file: " << inputFile << "\n";
        return 1;
    }

    std::vector<int> A, B;
    readSet(file, A);
    readSet(file, B);
    file.close();

    std::vector<int> I = intersection(A, B);

    int num;
    std::cout << "Type a number: ";
    std::cin >> num;

    std::cout << num << (elementOf(num, A) ? " is" : " is not") << " element of A\n";
    std::cout << num << (elementOf(num, B) ? " is" : " is not") << " element of B\n";
    std::cout << num << (elementOf(num, I) ? " is" : " is not") << " element of intersection of A and B\n";

    printSet("A", A);
    printSet("B", B);
    printSet("Intersection of A and B", I);

    std::cout << (isSubset(B, A) ? "B is" : "B is not") << " subset of A\n";
    std::cout << (isSubset(A, B) ? "A is" : "A is not") << " subset of B\n";

    return 0;
}
