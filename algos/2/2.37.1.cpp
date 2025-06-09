// 2.37. Átnevezés
// 2.37.1. Feladat: Írjon programot fájlok átnevezésére! A régi és az új 
// fájlnév a program paraméterében legyen adott! Ha valamelyik paraméter 
// hiányzik, akkor írja ki a helyes használatot! Ha hiba történik átnevezés 
// közben, akkor írja ki a megfelelő hibaüzenetet a hibakód alapján! 
// 2.37.1.

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cerrno>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage:\n  " << argv[0] << " <oldName> <newName>\n";
        return 1;
    }

    const char* oldName = argv[1];
    const char* newName = argv[2];

    if (std::rename(oldName, newName) != 0) {
        switch (errno) {
            case EEXIST:
                std::cerr << "Error: '" << newName << "' already exists!\n";
                break;
            case ENOENT:
                std::cerr << "Error: '" << oldName << "' does not exist!\n";
                break;
            case EINVAL:
                std::cerr << "Error: Invalid characters in '" << newName << "'.\n";
                break;
            case EACCES:
                std::cerr << "Error: Permission denied.\n";
                break;
            default:
                std::cerr << "Unknown error (" << strerror(errno) << ").\n";
                break;
        }
        return 2;
    }

    std::cout << "Rename successful: '" << oldName << "' → '" << newName << "'\n";
    return 0;
}
