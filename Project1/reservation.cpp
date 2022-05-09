#include<iostream>
#include<cstring>
#include"reservation.h"
void Reservation::copyFrom(const Reservation& other)
{
    this->begin = other.begin;
    this->end = other.end;  
    note = new char[strlen(other.note)+ 1];
    strcpy(note, other.note);
    name = new char[strlen(other.name)+ 1];
    strcpy(name, other.name);
}

void Reservation::free()
{
    delete[] note;
    delete[] name;
}

Reservation::Reservation()
{
    note = nullptr;
    name = nullptr;
}

Reservation::Reservation(const Data& begin, const Data& end, const char* note, const char* name)
{
    setNote(note);
    setName(name);
    setBegin(begin);
    setEnd(end);
}

Reservation::Reservation(const Reservation& other)
{
    copyFrom(other);
}

Reservation& Reservation::operator=(const Reservation& other)
{
    if(this != &other)
    {
     free();
     copyFrom(other);   
    }
    return *this;
}

