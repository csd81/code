#include "date.h"



int Date::getYear() const
{
    return year;
}

void Date::setYear(int newYear)
{
    year = newYear;
}

int Date::getMonth() const
{
    return month;
}

void Date::setMonth(int newMonth)
{
    month = newMonth;
}

int Date::getDay() const
{
    return day;
}

void Date::setDay(int newDay)
{
    day = newDay;
}

Date Date::getCurrentDate()
{
    return currentDate;
}

void Date::setCurrentDate(const Date &newCurrentDate)
{
    currentDate = newCurrentDate;
}

Date::Date(int y, int m, int d) : year(y),
    month(m),
    day(d)
{
}


Date Date::currentDate;
