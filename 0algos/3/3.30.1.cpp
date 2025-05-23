// 3.30. Könyvtári rendszer
// 3.30.1. A könyvtárakban a könyvek az Egyetemes Tizedes Osztályozás (ETO, 
// angolul UDC) szerint vannak osztályozva. Minden könyvnek van egy ETO száma, 
// amit a könyv témája határoz meg. Az ETO szám első számjegye a fő 
// témát határozza meg: 0. Általános művek, bibliográfia, könyvtárügy. 
// 1. Filozófia, pszichológia, logika, etika. 2. Vallás, egyházak, teológia. 
// 3. Társadalomtudományok, közigazgatás, jog, oktatás. 4. Nem használt 5. 
// Matematika, természettudományok, fizika, kémia. 6. Alkalmazott tudományok, 
// műszaki tudományok, orvostudományok. 7. Művészetek, játék, sport, 
// szórakozás. 8. Nyelvészet, irodalom 9. Régészet, földrajz, életrajz, 
// történelem Például egy 543-as ETO számú könyvről tudjuk, hogy 
// matematikával, vagy természettudományokkal foglalkozik. A többi számjegy a 
// program szempontjából nem fontos. A „lib1.txt” fájlban könyvek adatai 
// szerepelnek. A fájl tartalmazza a szerző nevét, a könyv címét, a kiadási 
// évet és a könyv ETO számát. Írjon programot, amely beolvassa ezt a 
// fájlt, listázza az egyes könyveket, végül összesítést ad, hogy hány 
// könyv található a könyvtárban egy-egy a témában! Használjon dinamikus 
// tömböket és struktúrákat az adatok tárolására! Az input fájl 
// formátuma: Első sor: A könyvek száma. A többi sor formátuma: Szerző 
// Rövid_Cím Kiadási év ETO (szóköz karakterekkel elválasztva). A szerző 
// neve és a könyv címe maximum 20 karakterből áll, mindkettő egy-egy szó 
// csak. Az ETO szám 3 karakterből áll. Példa bemenet: 
// 3
// Asimov Foundation 1980 820
// Herbert Dune 1990 820
// Dancs Terror 2001 512

// Kimenet: 
// Author: Asimov
// Title: Foundation
// Year of edition: 1980
// UDC: 820 Language, Linguistics, Literature

// Author: Herbert
// Title: Dune
// Year of edition: 1990
// UDC: 820 Language, Linguistics, Literature

// Author: Dancs
// Title: Terror
// Year of edition: 2001
// UDC: 512 Mathematics and natural sciences

// **************************************

// Generalities: 0 books
// Philosophy, Psychology: 0 books
// Religion, Theology: 0 books
// Social sciences: 0 books
// vacant: 0 books
// Mathematics and natural sciences: 1 books
// Applied sciences, Medicine, Technology: 0 books
// Arts, Recreation, Entertainment, Sport: 0 books
// Language, Linguistics, Literature: 2 books
// Geography, Biography, History: 0 books

// 3.30.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <array>

const std::string DEFAULT_INPUTFILE = "lib1.txt";
const int MAX_UDC_CLASSES = 10;

const std::array<std::string, MAX_UDC_CLASSES> UDC_CLASSES = {
    "Generalities",
    "Philosophy, Psychology",
    "Religion, Theology",
    "Social sciences",
    "vacant",
    "Mathematics and natural sciences",
    "Applied sciences, Medicine, Technology",
    "Arts, Recreation, Entertainment, Sport",
    "Language, Linguistics, Literature",
    "Geography, Biography, History"
};

struct Book {
    std::string author;
    std::string title;
    int year;
    std::string udc;
};

std::vector<Book> readBooks(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    int n;
    in >> n;
    std::vector<Book> books(n);

    for (int i = 0; i < n; ++i) {
        in >> books[i].author >> books[i].title >> books[i].year >> books[i].udc;
    }

    return books;
}

void printBooksAndStats(const std::vector<Book>& books) {
    std::array<int, MAX_UDC_CLASSES> counts = {0};

    for (const auto& book : books) {
        int mainClass = book.udc[0] - '0';
        std::cout << "Author: " << book.author << "\n"
                  << "Title: " << book.title << "\n"
                  << "Year of edition: " << book.year << "\n"
                  << "UDC: " << book.udc << " " << UDC_CLASSES[mainClass] << "\n\n";

        if (mainClass >= 0 && mainClass < MAX_UDC_CLASSES) {
            counts[mainClass]++;
        }
    }

    std::cout << "**************************************\n\n";
    for (int i = 0; i < MAX_UDC_CLASSES; ++i) {
        std::cout << UDC_CLASSES[i] << ": " << counts[i] << " books\n";
    }
}

int main(int argc, char* argv[]) {
    try {
        std::string filename = (argc > 1) ? argv[1] : DEFAULT_INPUTFILE;
        auto books = readBooks(filename);
        printBooksAndStats(books);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
