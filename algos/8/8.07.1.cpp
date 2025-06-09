// 8.7.1. James nagyon feledékeny, ezért emlékeztetőket szokott írni magának. Egy emlékeztető egy dátumot tartalmaz (év, hónap, nap), egy időpontot (órát), és egy emlékeztető kulcsszót. Az emlékeztetők összekeveredtek, ezért programot kell írni azok rendezésére. Az emlékeztetőket fájlból olvassa be! Írja ki a képernyőre a rendezett emlékeztetősorozatot! Tárolja az emlékeztetőket struktúrában, illetve dinamikus tömbökben! Az input fájl formátuma: Első sor: az emlékeztetők száma. A további sorok az emlékeztetőket tárolják a következő formátumban: Év Hónap Nap Óra Kulcsszó Az év, hónap, nap és óra értékei pozitív egészek. A szó maximális hossza 20 karakter. A sorokban az adatok szóköz karakterekkel vannak elválasztva. Példa bemenet: 2 2008 11 20 12 Bank 2008 10 16 16 Dentist Kimenet: Year: 2008 Month: 10 Day: 16 Hour: 16 Dentist Year: 2008 Month: 11 Day: 20 Hour: 12 Bank 

 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Memo {
    int     year;
    int     month;
    int     day;
    int     hour;
    std::string keyword;
};

// Comparison: ascending by year, then month, day, hour
bool memoLess(const Memo& a, const Memo& b) {
    if (a.year   != b.year)   return a.year   < b.year;
    if (a.month  != b.month)  return a.month  < b.month;
    if (a.day    != b.day)    return a.day    < b.day;
    return a.hour  < b.hour;
}

int main(int argc, char* argv[]) {
    const char* filename = (argc > 1 ? argv[1] : "memo1.txt");
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error opening file: " << filename << "\n";
        return 1;
    }

    int n;
    infile >> n;
    std::vector<Memo> memos;
    memos.reserve(n);

    for (int i = 0; i < n; ++i) {
        Memo m;
        infile >> m.year
               >> m.month
               >> m.day
               >> m.hour
               >> m.keyword;
        memos.push_back(std::move(m));
    }

    // sort ascending by date/time
    std::sort(memos.begin(), memos.end(), memoLess);

    // print sorted
    for (const auto& m : memos) {
        std::cout
            << "Year: "  << m.year
            << " Month: " << m.month
            << " Day: "   << m.day
            << " Hour: "  << m.hour
            << " "        << m.keyword
            << "\n";
    }

    return 0;
}
 