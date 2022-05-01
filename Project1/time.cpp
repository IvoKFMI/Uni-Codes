#include<iostream>
#include"time.h"

int Time::timeInSeconds() const
{
    return 3600*hours + 60*minutes + seconds;
}

Time::Time() : Time(0, 0, 0)
{}

Time::Time(int seconds, int minutes, int hours)
{
    setSeconds(seconds);
    setMinutes(minutes);
    setHours(hours);
}

int Time::getSeconds() const
{
    return seconds;
}

int Time::getMinutes() const
{
   return minutes;
}

int Time::getHours() const
{
    return hours;
}

void Time::setSeconds(int seconds)
{
    if(seconds > 59)
    {
        seconds = 0;
    }
    this->seconds = seconds;
}

void Time::setMinutes(int minutes)
{
    if(minutes > 59)
    {
        minutes = 0;
    }
    this->minutes = minutes;
}

void Time::setHours(int hours)
{
    if(hours > 23)
    {
        hours = 0;
    }
    this->hours = hours;
}

int Time::compare(const Time& other) const
{
    int firtsTime = timeInSeconds();
    int secondTime = other.timeInSeconds();
}

