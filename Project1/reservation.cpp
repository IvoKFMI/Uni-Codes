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

