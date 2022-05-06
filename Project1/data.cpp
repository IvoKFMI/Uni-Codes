#include<iostream>
#include"data.h"
bool Data::isLeapYear() const
{
return year % 4 == 0;
}
Data::Data(int day, int month, int year)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}

int Data::getDay() const
{
    return day;
}

int Data::getMonth() const
{
    return month;
}

int Data::getYear() const
{
    return year;
}

void Data::setDay(int day)
{
    if (day > MAX_DAYS[month - 1])
	{
		day = 1;
	}
    this->day = day;
}

void Data::setMonth(int month)
{
    if(month > 12)
    {
        month = 1;
    }
    this->month = month;
}

void Data::setYear(int year)
{
    
    if(isLeapYear())
    {
        MAX_DAYS[1] = 29;
    }
    else
    {
        MAX_DAYS[1] = 28;
    }
    this->year = year;
}

Data& Data::operator==(const Data& other) const
{
return  day == other.day && month == other.month && year == other.year;
}
    

