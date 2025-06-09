// 2.55.2. Írja át az előző programot úgy, hogy csak szemantikai ellenőrzés 
// legyen, de abból szigorúbb! Az év 1000 és 3000 közti érték lehet. A 
// hónap 1 és 12 közti érték lehet. A nap értéke 1 és 31 között lehet 
// januárban, márciusban, májusban, júliusban, augusztusban, októberben és 
// decemberben. A nap értéke 1 és 30 közti értéket vehet fel áprilisban, 
// júniusban, szeptemberben és novemberben. Ha az év szökőév, februárban a 
// nap értéke 1 és 29 közt lehet, ha nem, akkor 1 és 28 között. Szökőév 
// minden 4-gyel osztható év, de a 100-zal oszthatóak nem. A 400-zal osztható 
// évek mindig szökőévek. Például 1992, 1996, 2000, 1600 szökőév, de 
// 1800, 1900 nem az. A program elsőként az évet és a hónapot ellenőrizze, 
// majd ha ezek megfelelőek, akkor a napot is! Írja ki a képernyőre a 
// felfedezett hibákat! 
// 2.55.2.


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define DEFAULT_INPUTFILE "date.txt"
#define YEAR_MIN 1000
#define YEAR_MAX 3000
#define MONTH_MAX 12
#define DAY_MAX 31

const std::string Months_Strings[12] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

enum Months { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

struct TDate {
    int Year;
    int Month;
    int Day;
};

bool LeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int CheckYear(int y) {
    int errors = 0;
    if (y < YEAR_MIN) {
        std::cout << "Error: " << y << " is too low for the year!\n";
        errors++;
    }
    if (y > YEAR_MAX) {
        std::cout << "Error: " << y << " is too high for the year!\n";
        errors++;
    }
    return errors;
}

int CheckMonth(int m) {
    int errors = 0;
    if (m < 1) {
        std::cout << "Error: " << m << " is too low for the month!\n";
        errors++;
    }
    if (m > MONTH_MAX) {
        std::cout << "Error: " << m << " is too high for the month!\n";
        errors++;
    }
    return errors;
}

int CheckDay(const TDate& date) {
    int errors = 0;
    switch (date.Month) {
        case jan: case mar: case may: case jul: case aug: case oct: case dec:
            if (date.Day < 1 || date.Day > 31) {
                std::cout << "Error: In " << Months_Strings[date.Month - 1] << " there are 31 days!\n";
                errors++;
            }
            break;
        case apr: case jun: case sep: case nov:
            if (date.Day < 1 || date.Day > 30) {
                std::cout << "Error: In " << Months_Strings[date.Month - 1] << " there are 30 days!\n";
                errors++;
            }
            break;
        case feb:
            if (LeapYear(date.Year)) {
                if (date.Day < 1 || date.Day > 29) {
                    std::cout << "Error: In " << date.Year << " " << Months_Strings[date.Month - 1] << " there are 29 days!\n";
                    errors++;
                }
            } else {
                if (date.Day < 1 || date.Day > 28) {
                    std::cout << "Error: In " << date.Year << " " << Months_Strings[date.Month - 1] << " there are 28 days!\n";
                    errors++;
                }
            }
            break;
        default:
            std::cout << "Invalid month!\n";
            errors++;
    }
    return errors;
}

void ReadDate(std::ifstream& file, TDate& date) {
    char dot;
    file >> date.Year >> dot >> date.Month >> dot >> date.Day;
}

void PrintDate(const TDate& date) {
    std::cout << "Year: " << date.Year << "\n";
    if (date.Month >= 1 && date.Month <= 12)
        std::cout << "Month: " << Months_Strings[date.Month - 1] << "\n";
    else
        std::cout << "Month: Invalid\n";
    std::cout << "Day: " << date.Day << "\n";
}

void CheckDate(const TDate& date) {
    int errors = 0;
    errors += CheckYear(date.Year);
    errors += CheckMonth(date.Month);
    if (errors == 0) {
        errors += CheckDay(date);
    }
    std::cout << "*******************************\n";
    std::cout << "I found " << errors << " error(s)\n";
}

int main(int argc, char* argv[]) {
    std::ifstream file(argc > 1 ? argv[1] : DEFAULT_INPUTFILE);
    if (!file) {
        std::perror("Error opening file");
        return 1;
    }

    TDate date;
    ReadDate(file, date);
    file.close();

    PrintDate(date);
    CheckDate(date);

    return 0;
}
