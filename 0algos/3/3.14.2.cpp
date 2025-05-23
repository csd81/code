// 3.14.2. Módosítsa úgy a programot, hogy a második sztring minden 
// előfordulását kiveszi az elsőből! 
// 3.14.2.



#include <iostream>
#include <string>

void substractAll(std::string& from, const std::string& what) {
    size_t pos;
    while ((pos = from.find(what)) != std::string::npos) {
        from.erase(pos, what.length());
    }
}

int main() {
    std::string from, what;

    std::cout << "Substract from = ";
    std::cin >> from;

    std::cout << "Substract what = ";
    std::cin >> what;

    substractAll(from, what);

    std::cout << "\nThe reduced word is: " << from << "\n";

    return 0;
}
