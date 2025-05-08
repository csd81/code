#ifndef DATE_H
#define DATE_H

class Date
{

    int year;
    int month;
    int day;
public:
    static Date currentDate;

    Date(int y = 1970, int m = 1, int d = 1);
    bool isSameMonth(const Date& d) const;
    int getYear() const;
    void setYear(int newYear);
    int getMonth() const;
    void setMonth(int newMonth);
    int getDay() const;
    void setDay(int newDay);
    static Date getCurrentDate();
    static void setCurrentDate(const Date &newCurrentDate);

};

#endif // DATE_H
