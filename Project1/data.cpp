#include<iostream>
#include"data.h"
bool Data::isLeapYear() const
{
return year % 4 == 0;
}

Data::Data()
{
    day = 1;
    month = 1;
    year = 1;
}

Data::Data(unsigned int day, unsigned int month, unsigned int year)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

const int Data::getDay() const
{
    return day;
}

const int Data::getMonth() const
{
    return month;
}

const int Data::getYear() const
{
    return year;
}

void Data::setDay(unsigned int day)
{
    if (day > MAX_DAYS[month - 1])
	{
		day = 1;
	}
    this->day = day;
}

void Data::setMonth(unsigned int month)
{
    if(month > 12)
    {
        month = 1;
    }
    this->month = month;
    setDay(this->day);
}

void Data::setYear(unsigned int year)
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
    setMonth(this->month);
}

bool Data::operator==(const Data& other) const
{
return  day == other.day && month == other.month && year == other.year;
}

bool Data::operator>=(const Data& other) const
{
if(year >= other.year)
return 1;
//if(year = other.year && month)
}

bool Data::operator<=(const Data& other) const
{
return day <= other.day && month <= other.month && year <= other.year;    
}

bool Data::operator>(const Data& other) const
{
return day > other.day && month > other.month && year > other.year;   
}

bool Data::operator<(const Data& other) const
{
return day < other.day && month < other.month && year < other.year;   
}




