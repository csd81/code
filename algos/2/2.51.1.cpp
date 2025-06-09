// 2.51. Halmazok uniója
// 2.51.1. Írjon programot, amely két halmaz unióját generálja! Mindkét 
// halmaz egész számokat tartalmaz! A program olvassa be az input fájlt. 
// Kérjen be egy számot a billentyűzetről, és döntse el, hogy a szám 
// eleme-e az első halmaznak, a második halmaznak, illetve ezek uniójának! 
// Írassa ki a képernyőre az előbbi három halmazt! Végül írassa ki, hogy 
// az első halmaz részhalmaza-e a másodiknak, illetve fordítva! Használjon 
// dinamikus tömböket! Az input fájl formátuma: Első sor: az első halmaz 
// mérete Második sor: az első halmaz elemei Harmadik sor: a második halmaz 
// mérete Negyedik sor: a második halmaz elemei A számok egy-egy space 
// karakterrel vannak elválasztva. Példa bemenet: 3 80 54 41 5 41 21 54 76 80 
// Kimenet: Type a number: 76 76 is not element of A 76 is element of B 76 is 
// element of union of A and B A = {80, 54, 41} B = {41, 21, 54, 76, 80} Union of 
// A and B = {41, 21, 54, 76, 80} B is not subset of A A is subset of B 
// 2.51.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

void readSet(std::ifstream& file, std::vector<int>& set) {
    int size, value;
    file >> size;
    for (int i = 0; i < size; ++i) {
        file >> value;
        set.push_back(value);
    }
}

void printSet(const std::string& name, const std::vector<int>& set) {
    std::cout << name << " = {";
    for (size_t i = 0; i < set.size(); ++i) {
        std::cout << set[i];
        if (i != set.size() - 1) std::cout << ", ";
    }
    std::cout << "}\n";
}

bool contains(int value, const std::vector<int>& set) {
    return std::find(set.begin(), set.end(), value) != set.end();
}

std::vector<int> unionSet(const std::vector<int>& A, const std::vector<int>& B) {
    std::vector<int> result = A;
    for (int val : B) {
        if (!contains(val, result)) {
            result.push_back(val);
        }
    }
    return result;
}

bool isSubset(const std::vector<int>& sub, const std::vector<int>& full) {
    for (int val : sub) {
        if (!contains(val, full)) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    std::string filename = (argc > 1) ? argv[1] : "sets.txt";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return 1;
    }

    std::vector<int> A, B;
    readSet(file, A);
    readSet(file, B);
    file.close();

    std::vector<int> U = unionSet(A, B);

    int number;
    std::cout << "Type a number: ";
    std::cin >> number;

    std::cout << number << (contains(number, A) ? " is" : " is not") << " element of A\n";
    std::cout << number << (contains(number, B) ? " is" : " is not") << " element of B\n";
    std::cout << number << (contains(number, U) ? " is" : " is not") << " element of union of A and B\n";

    printSet("A", A);
    printSet("B", B);
    printSet("Union of A and B", U);

    std::cout << (isSubset(B, A) ? "B is" : "B is not") << " subset of A\n";
    std::cout << (isSubset(A, B) ? "A is" : "A is not") << " subset of B\n";

    return 0;
}
