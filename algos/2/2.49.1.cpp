// 2.49. Telefonszámla
// 2.49.1. Írjon programot egy telefontársaság számára, ami az egyes 
// előfizetők telefonszámláit szeretné kiszámolni! Az előfizetők adatai az 
// „in.txt” nevű fájlban tárolja! A program készítsen felsorolást minden 
// előfizető számára, amelynek tartalmaznia kell a teljes beszélgetési 
// időt, és a fizetendő összeget! Ezután a program számolja ki, melyik 
// előfizető telefonált összesen a legtöbb ideig, ez milyen hosszú idő, 
// kinek kell a legtöbbet fizetni, és mennyit! Használjon dinamikus tömböket! 
// Feltételezzük, hogy a bemeneti fájl az előírásoknak megfelelő. Az input 
// formátuma: Első sor: az előfizetők száma Második sor: két tízes 
// számrendszerbeli szám, a csúcsidőben való telefonálás tarifája, és a 
// csúcsidőn kívüli telefonálás tarifája. A többi sor az előfizetők 
// adatait tárolja: az előfizető neve (keresztnév, vezetéknév), majd két 
// tízes számrendszerbeli szám: mennyi időt telefonált az illető 
// csúcsidőben, illetve csúcsidőn kívül. Mind a keresztnév, mind a 
// vezetéknév maximum 10 karakterből áll. Példa bemenet: 2 3 1 csúcsidőn 
// kívül Bela Kovacs 731 123 123 percet csúcsidőn kívül Mihaly Toth 300 35 
// Kimenet: Bela Kovacs: Mihaly Toth: 2316 Ft 935 Ft 854 minute 335 minute Highest 
// fee: 2316 Ft Bela Kovacs Longest speaking: 854 Ft Bela Kovacs
// 2.49.1.
 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

struct Subscriber {
    std::string firstName;
    std::string lastName;
    int inRushMinutes;
    int outRushMinutes;
    int totalMinutes;
    int fee;
};

void readSubscribers(std::ifstream& file, int count, std::vector<Subscriber>& subs) {
    for (int i = 0; i < count; ++i) {
        Subscriber s;
        file >> s.firstName >> s.lastName >> s.inRushMinutes >> s.outRushMinutes;
        subs.push_back(s);
    }
}

void calculateFeesAndPrint(const std::vector<Subscriber>& subs, int rushTariff, int offTariff) {
    int maxFee = 0;
    int maxMinutes = 0;

    std::vector<const Subscriber*> maxFeeSubs;
    std::vector<const Subscriber*> maxMinSubs;

    for (const auto& s : subs) {
        int total = s.inRushMinutes + s.outRushMinutes;
        int fee = s.inRushMinutes * rushTariff + s.outRushMinutes * offTariff;

        std::cout << std::setw(20) << s.firstName + " " + s.lastName << ": "
                  << std::setw(6) << fee << " Ft, "
                  << std::setw(4) << total << " minute\n";

        if (fee > maxFee) {
            maxFee = fee;
            maxFeeSubs.clear();
            maxFeeSubs.push_back(&s);
        } else if (fee == maxFee) {
            maxFeeSubs.push_back(&s);
        }

        if (total > maxMinutes) {
            maxMinutes = total;
            maxMinSubs.clear();
            maxMinSubs.push_back(&s);
        } else if (total == maxMinutes) {
            maxMinSubs.push_back(&s);
        }
    }

    std::cout << "\nHighest fee: " << maxFee << " Ft\n";
    for (const auto* s : maxFeeSubs)
        std::cout << "\t" << s->firstName << " " << s->lastName << "\n";

    std::cout << "\nLongest speaking: " << maxMinutes << " minute\n";
    for (const auto* s : maxMinSubs)
        std::cout << "\t" << s->firstName << " " << s->lastName << "\n";
}

int main() {
    std::ifstream file("in.txt");
    if (!file) {
        std::cerr << "Failed to open file 'in.txt'\n";
        return 1;
    }

    int count, rushTariff, offTariff;
    file >> count >> rushTariff >> offTariff;

    std::vector<Subscriber> subscribers;
    readSubscribers(file, count, subscribers);
    file.close();

    calculateFeesAndPrint(subscribers, rushTariff, offTariff);

    return 0;
}
