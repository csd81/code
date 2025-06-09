// 3.42. Ellenőrző összeg
// 3.42.1. Írjon programot, amely képes ellenőrző összeg generálására egy 
// üzenethez, és ezen összeg alapján ellenőrizni tudja a bejövő 
// üzeneteket! Az ellenőrző összeg kiszámítása a következőképpen 
// történik: Adjuk össze az üzenet minden bájtját, ha az összeg nagyobb, 
// mint 255, akkor az összegnek csak a legkisebb bájtját tekintjük. Az így 
// kapott bájt kettes komplemense (255 - sum + 1) lesz az ellenőrző összeg. 
// Például az „ABCD” üzenet bájtjai: 0x41, 0x42, 0x43 and 0x44, így az 
// összeg = 0x41 + 0x42 + 0x43 + 0x44 = 0x10A. Ebből legkisebb bájt: 0xA, a 
// kettes komplemens pedig: 0xFF - 0xA + 0x1 = 0xF6. Az ellenőrzés menete: Az 
// üzenettel együtt az ellenőrző összeg is megérkezik egy fájlban. A 
// programnak össze kell adnia a beérkezett üzenet minden bájtját és az 
// ellenőrző összeget. Ha az eredmény utolsó bájtja 0, akkor a beérkezett 
// üzenet valószínűleg nem sérült. Egy fájl több üzenetet tartalmaz, az 
// ellenőrző összegükkel együtt. A program olvassa be ezeket, és 
// ellenőrizze őket! Írja ki a képernyőre az üzeneteket, az ellenőrző 
// összegeket, és azt, hogy az üzenetek hibásak vagy helyesek! Végül 
// számolja ki a „This is a simple checksum example.” üzenet ellenőrző 
// összegét! Az input fájl formátuma: Első sor: Az üzenetek száma A többi 
// sor felváltva tartalmaz üzeneteket és ellenőrző összegeket. Az üzenetek 
// soraiban több szó is szerepelhet. Az üzenet után következő sor az üzenet 
// ellenőrző összegét tartalmazza hexadecimális formában. Példa bemenet: 2 
// This is the first row of the message. C2 This is the second row ov the message. 
// 6E Kimenet: "This is the first row of the message." C2 ===> Correct! "This is 
// the second row ov the message." 6E ===> Faulty! Sum of "This is a simple 
// checksum example.": C6C The checksum: 94 

// 3.42.1.


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using ubyte = unsigned char;

ubyte getChecksum(const std::string& msg) {
    unsigned int sum = 0;
    for (char c : msg)
        sum += static_cast<ubyte>(c);

    std::cout << "\nSum of \"" << msg << "\": " << std::hex << std::uppercase << sum << '\n';

    ubyte reduced = static_cast<ubyte>(sum);  // Only the least significant byte
    ubyte checksum = 0xFF - reduced + 1;

    std::cout << "The checksum: " << std::hex << static_cast<int>(checksum) << std::dec << '\n';

    return checksum;
}

bool checkMessage(const std::string& msg, ubyte checksum) {
    unsigned int sum = checksum;
    for (char c : msg)
        sum += static_cast<ubyte>(c);

    return (static_cast<ubyte>(sum) == 0);
}

void readMessages(std::istream& in) {
    int count;
    in >> count;
    in.ignore(); // skip newline

    for (int i = 0; i < count; ++i) {
        std::string msg;
        std::getline(in, msg);

        std::string checksum_line;
        std::getline(in, checksum_line);
        unsigned int checksum;
        std::stringstream(checksum_line) >> std::hex >> checksum;

        std::cout << "\"" << msg << "\" " << std::uppercase << checksum << " ===> ";
        if (checkMessage(msg, static_cast<ubyte>(checksum))) {
            std::cout << "Correct!\n";
        } else {
            std::cout << "Faulty!\n";
        }
    }
}

int main(int argc, char* argv[]) {
    const std::string filename = (argc > 1) ? argv[1] : "message.txt";
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Hiba a fájl megnyitásakor: " << filename << '\n';
        return 1;
    }

    readMessages(file);
    file.close();

    getChecksum("This is a simple checksum example.");

    return 0;
}
