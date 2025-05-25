// 2.36. Csak olvasható fájl
// 2.36.2. Írja meg a tuti törlés programot! A program először törli a csak 
// olvasható tulajdonságot és utána DOS parancs segítségével törli a fájlt. 
// 2.36.2.


#include <iostream>
#include <string>
#include <cstdlib>  // system()

int main() {
    std::string fileName;

    std::cout << "File name: ";
    std::cin >> fileName;

    // Töröljük az írásvédelmet (chmod +w)
    std::string chmodCmd = "chmod +w \"" + fileName + "\"";
    int chmodResult = system(chmodCmd.c_str());

    if (chmodResult != 0) {
        std::cerr << "Error: failed to set write permission (chmod).\n";
        return 1;
    } else {
        std::cout << "Write permission added (chmod +w).\n";
    }

    // Töröljük a fájlt
    std::string rmCmd = "rm \"" + fileName + "\"";
    int rmResult = system(rmCmd.c_str());

    if (rmResult == 0) {
        std::cout << "File deleted successfully using rm.\n";
    } else {
        std::cerr << "Failed to delete file using rm.\n";
        return 2;
    }

    return 0;
}
