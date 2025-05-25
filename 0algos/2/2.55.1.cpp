// 2.55. Dátumellenőrzés
// 2.55.1. Írjon programot, amely beolvas egy dátumot egy fájlból, 
// szintaktikai és szemantikai ellenőrzést végez rajta és kiírja az 
// esetleges hibákat! Szintaktikai ellenőrzés: A dátum 3 számot tartalmaz, 
// mindegyik szám után egy pont szerepel. A számok csak számjegyet 
// tartalmazhatnak! Például a „2007.” megfelelő, de a következők nem: 
// „2A07.”, „2007”. Szemantikai ellenőrzés: Akkor hajtódik végre, ha a 
// szintaktikai ellenőrzés nem jelzett hibát. A hónap értéke 1 és 12 közt, 
// a napé 1 és 31 közt változhat. Ha az értékek valamelyike hibás, ezt a 
// program írja ki a képernyőre. Az input fájl formátuma: Év. Hónap. Nap. 
// Példa bemenet: 2007. 12. 31. Kimenet: 2007. 12. 31. 
// ******************************* I found 0 errors Példa bemenet: 2007 1u2. 31 
// Kimenet: 2007 1u2. 31 Error: A "." have to follow the number, not "7"! Error: 
// the Month cannot contain u character! Error: A "." have to follow the number, 
// not "1"! ******************************* I found 3 errors Példa bemenet: 2007. 
// 13. 0. Kimenet: 2007. 13. 0. Error: There are only 12 months! Error: There are 
// at most 31, at least 1 days in a month! ******************************* I found 
// 1 errors 
// 2.55.1.



#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>

#define DEFAULT_INPUTFILE "date.txt"
#define DOT '.'
#define MAX_LENGTH 10

struct TDate {
    std::string Year;
    std::string Month;
    std::string Day;
};

void InitDate(TDate& date) {
    date.Year.clear();
    date.Month.clear();
    date.Day.clear();
}

void ReadDate(std::ifstream& file, TDate& date) {
    file >> date.Year >> date.Month >> date.Day;
}

void PrintDate(const TDate& date) {
    std::cout << date.Year << " " << date.Month << " " << date.Day << "\n";
}

int CheckNumAndDots(const std::string& str, const std::string& label) {
    int errors = 0;
    int len = str.length();

    for (int i = 0; i < len - 1; ++i) {
        if (!std::isdigit(str[i])) {
            std::cout << "Error: the " << label << " cannot contain " << str[i] << " character!\n";
            ++errors;
        }
    }

    if (str[len - 1] != DOT) {
        std::cout << "Error: A \"" << DOT << "\" has to follow the number, not \"" << str[len - 1] << "\"!\n";
        ++errors;
    }

    return errors;
}

int CheckNums(const TDate& date) {
    int errors = 0;

    int month = std::atoi(date.Month.c_str());
    int day = std::atoi(date.Day.c_str());

    if (month < 1 || month > 12) {
        std::cout << "Error: There are only 12 months!\n";
        ++errors;
    }

    if (day < 1 || day > 31) {
        std::cout << "Error: There are at most 31, at least 1 days in a month!\n";
        ++errors;
    }

    return errors;
}

void CheckDate(const TDate& date) {
    int errors = 0;
    errors += CheckNumAndDots(date.Year, "Year");
    errors += CheckNumAndDots(date.Month, "Month");
    errors += CheckNumAndDots(date.Day, "Day");

    if (errors == 0) {
        errors += CheckNums(date);
    }

    std::cout << "*******************************\n";
    std::cout << "I found " << errors << " error(s)\n";
}

int main(int argc, char* argv[]) {
    TDate date;
    InitDate(date);

    std::ifstream file(argc > 1 ? argv[1] : DEFAULT_INPUTFILE);
    if (!file) {
        std::perror("Error opening file");
        return 1;
    }

    ReadDate(file, date);
    file.close();

    PrintDate(date);
    CheckDate(date);

    return 0;
}
