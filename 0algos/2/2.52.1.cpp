// 2.52. Halmazok különbsége
// 2.52.1. Írjon programot, amely két halmaz különbségét generálja! 
// Mindkét halmaz egész számokat tartalmaz. A program olvassa be az input 
// fájlt! Kérjen be egy számot a billentyűzetről, és döntse el, hogy a 
// szám eleme-e az első halmaznak, a második halmaznak, az A\B vagy a B\A 
// halmaznak! Írassa ki a képernyőre az előbbi négy halmazt! Végül írassa 
// ki, hogy az első halmaz részhalmaza-e a másodiknak, illetve fordítva! 
// Használjon dinamikus tömböket! Az input fájl formátuma: Első sor: az 
// első halmaz mérete Második sor: az első halmaz elemei Harmadik sor: a 
// második halmaz mérete Negyedik sor: a második halmaz elemei A számok 
// egy-egy szóköz karakterrel vannak elválasztva. Példa bemenet: 3 80 54 41 5 
// 41 21 54 76 80 Kimenet: Type a number: 76 76 is not element of A 76 is element 
// of B 76 is not element of A \ B 76 is element of B \ A A = {80, 54, 41} B = 
// {41, 21, 54, 76, 80} Set difference A\B = {} Set difference B\A = {21, 76} B is 
// not subset of A A is subset of B 
// 2.52.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void ReadSet(std::ifstream& in, std::vector<int>& set) {
    int size;
    in >> size;
    set.resize(size);
    for (int i = 0; i < size; ++i) {
        in >> set[i];
    }
}

void PrintSet(const std::string& name, const std::vector<int>& set) {
    std::cout << name << " = {";
    for (size_t i = 0; i < set.size(); ++i) {
        std::cout << set[i];
        if (i != set.size() - 1) std::cout << ", ";
    }
    std::cout << "}\n";
}

bool Element(int e, const std::vector<int>& set) {
    return std::find(set.begin(), set.end(), e) != set.end();
}

std::vector<int> SetDifference(const std::vector<int>& A, const std::vector<int>& B) {
    std::vector<int> result;
    for (int a : A) {
        if (!Element(a, B)) {
            result.push_back(a);
        }
    }
    return result;
}

bool IsSubset(const std::vector<int>& A, const std::vector<int>& B) {
    for (int a : A) {
        if (!Element(a, B)) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    std::ifstream file(argc > 1 ? argv[1] : "sets.txt");
    if (!file) {
        std::cerr << "Error opening input file.\n";
        return 1;
    }

    std::vector<int> A, B;
    ReadSet(file, A);
    ReadSet(file, B);
    file.close();

    std::vector<int> AminusB = SetDifference(A, B);
    std::vector<int> BminusA = SetDifference(B, A);

    int num;
    std::cout << "Type a number: ";
    std::cin >> num;

    std::cout << num << (Element(num, A) ? " is" : " is not") << " element of A\n";
    std::cout << num << (Element(num, B) ? " is" : " is not") << " element of B\n";
    std::cout << num << (Element(num, AminusB) ? " is" : " is not") << " element of A \\ B\n";
    std::cout << num << (Element(num, BminusA) ? " is" : " is not") << " element of B \\ A\n";

    PrintSet("A", A);
    PrintSet("B", B);
    PrintSet("Set difference A\\B", AminusB);
    PrintSet("Set difference B\\A", BminusA);

    std::cout << (IsSubset(B, A) ? "B is subset of A\n" : "B is not subset of A\n");
    std::cout << (IsSubset(A, B) ? "A is subset of B\n" : "A is not subset of B\n");

    return 0;
}
