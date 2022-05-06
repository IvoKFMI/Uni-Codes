#include<iostream>

class Data
{
private:
int day;
int month;
int year;
int MAX_DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeapYear() const;
public:
//Data();
Data(int day, int month, int year);

int getDay() const;
int getMonth() const;
int getYear() const;

void setDay(int day);
void setMonth(int month);
void setYear(int year);

Data& operator=(const Data& other);
Data& operator>(const Data& other);

};
