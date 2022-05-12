#pragma once
#include<iostream>

class Data
{
private:
unsigned int day;
unsigned int month;
unsigned int year;
int MAX_DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeapYear() const;
public:
Data();
Data(unsigned int day, unsigned int month, unsigned int year);

const int getDay() const;
const int getMonth() const;
const int getYear() const;

void setDay(unsigned int day);
void setMonth(unsigned int month);
void setYear(unsigned int year);

bool operator==(const Data& other) const;
bool operator>=(const Data& other) const;
bool operator<=(const Data& other) const;
bool operator>(const Data& other) const;
bool operator<(const Data& other) const;
};
