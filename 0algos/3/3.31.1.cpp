// 3.31. Kikölcsönzött könyvek

// 3.31.1. A könyvtárak nyilvántartást vezetnek a kikölcsönzött 
// könyvekről. Ez tartalmazza a könyvek szerzőjét, címét, illetve a 
// kölcsönzés lejáratának idejét. Tételezzük fel, hogy az aktuális dátum 
// 2008. december 15. Írjon programot, amely beolvassa a kikölcsönzött 
// könyvek listáját egy fájlból, és kilistázza azoknak a könyveknek az 
// adatait, amelyek kölcsönzési ideje már lejárt! Használjon dinamikus 
// tömböket és struktúrákat az adatok tárolására! Az input fájl 
// formátuma: Első sor: A könyvek száma. A többi sor: Szerző Rövid_cím Év 
// Hónap Nap A szerző neve és a könyv címe is egy-egy szó csak. Az év, 
// hónap, nap a lejárat idejét jelölik. Példa bemenet: 3 Asimov Foundation 
// 2009 1 20 Herbert Dune 2008 12 1 Dancs Terror 2008 11 30 Kimenet: Title: 
// Herbert Author: Dune Expiraton: 2008 12 1 Title: Dancs Author: Terror 
// Expiraton: 2008 11 30 
// 3.31.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

constexpr int YEAR = 2008;
constexpr int MONTH = 12;
constexpr int DAY = 15;

struct Book {
    std::string author;
    std::string title;
    int year, month, day;
};

bool isExpired(int y, int m, int d) {
    if (y < YEAR) return true;
    if (y == YEAR && m < MONTH) return true;
    if (y == YEAR && m == MONTH && d < DAY) return true;
    return false;
}

std::vector<Book> readBooks(std::ifstream& file) {
    int count;
    file >> count;
    std::vector<Book> books(count);
    for (int i = 0; i < count; ++i) {
        file >> books[i].author >> books[i].title
             >> books[i].year >> books[i].month >> books[i].day;
    }
    return books;
}

void printExpiredBooks(const std::vector<Book>& books) {
    std::cout << "\nLejárt könyvek:\n\n";
    for (const auto& book : books) {
        if (isExpired(book.year, book.month, book.day)) {
            std::cout << "Title: " << book.author << '\n';
            std::cout << "Author: " << book.title << '\n';
            std::cout << "Expiration: " << book.year << " "
                      << book.month << " " << book.day << "\n\n";
        }
    }
}

int main(int argc, char* argv[]) {
    std::string filename = (argc > 1) ? argv[1] : "lib1.txt";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Hiba a fájl megnyitásakor: " << filename << "\n";
        return 1;
    }

    std::vector<Book> books = readBooks(file);
    file.close();

    printExpiredBooks(books);

    return 0;
}
