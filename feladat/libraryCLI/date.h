#ifndef DATE_H
#define DATE_H
#include <string>


namespace utils {
struct Date {

    int day, month, year;
    Date(int d, int m, int y);

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
    std::string toString() const;
};
}

#endif // DATE_H
