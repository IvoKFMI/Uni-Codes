#include<iostream>

class Time
{
private:
int seconds;
int minutes;
int hours;
int timeInSeconds() const;
public:
Time();
Time(int seconds, int minutes, int hours);

int getSeconds() const;
int getMinutes() const;
int getHours() const;

void setSeconds(int seconds);
void setMinutes(int minutes);
void setHours(int hours);

int compare(const Time& other) const;
int difference(const Time& other) const;

};