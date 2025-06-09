// 2.36.1. Írjon programot, amely beállítja egy fájl „csak olvasható” 
// tulajdonságát! Kérje be egy szöveges fájl nevét! Állítsa be a fájl 
// csak olvasható tulajdonságát, majd próbáljon meg a fájl végéhez fűzni 
// egy szöveget C-ből hívott DOS parancs segítségével (DOS parancs: echo 
// text >>fileName)! Futtassa a DOS parancsot C-ből: system(char*) 
// segítségével! Törölje a csak olvasható tulajdonságot és próbáljon 
// ismét a fájl végéhez fűzni egy szöveget! 
// 2.36.1.

#include <iostream>
#include <string>
#include <sys/stat.h>
#include <cstdlib>
#include <cerrno>

int main() {
    std::string filename;
    std::cout << "Enter text file name: ";
    std::cin >> filename;

    // 1) Kapcsoljuk csak olvashatóra (0444)
    if (chmod(filename.c_str(), S_IRUSR | S_IRGRP | S_IROTH) != 0) {
        std::perror("chmod to read-only failed");
        return 1;
    }
    std::cout << "File set to read-only.\n";

    // 2) Próbáljunk meg fűzni: echo "Read-only append" >> filename
    {
        std::string cmd = "echo \"Read-only append\" >> " + filename;
        int ret = std::system(cmd.c_str());
        std::cout << "Attempt to append in read-only mode returned: " << ret << "\n";
    }

    // 3) Visszaállítjuk read-write (0644)
    if (chmod(filename.c_str(), S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) != 0) {
        std::perror("chmod to read-write failed");
        return 1;
    }
    std::cout << "File set to read-write.\n";

    // 4) Újra próbáljuk a fűzést
    {
        std::string cmd = "echo \"Writable append\" >> " + filename;
        int ret = std::system(cmd.c_str());
        std::cout << "Attempt to append in read-write mode returned: " << ret << "\n";
    }

    return 0;
}
