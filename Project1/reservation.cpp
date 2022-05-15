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

const Data& Reservation::getBegin() const
{
    return begin;
}

const Data& Reservation::getEnd() const
{
    return end;
}

const char* Reservation::getNote() const
{
    return note;
}

const char* Reservation::getName() const
{
    return name;
}

void Reservation::setBegin(const Data& begin)
{
    this->begin =  begin;
}

void Reservation::setEnd(const Data& end)
{
    this->end = end;
}

void Reservation::setNote(const char* note)
{
    if(note == nullptr || this->note == note)
    {
      note = defaul_name;
    }
    delete[] this->note;
    unsigned int noteLenght = strlen(note);
    this->note = new char[noteLenght + 1];
    strcpy(this->note, note);
}

void Reservation::setName(const char* name)
{
    if(name == nullptr || this->name == name) 
    {
        name = defaul_name;
    }
    delete[] this->name;
    unsigned int nameLenght = strlen(name);
    this->name = new char[nameLenght + 1];
    strcpy(this->name, name);
}

Reservation::~Reservation()
{
  free();
}

bool isValidTerm(const Data& begin, const Data& end)//проверка за валидени начало и край на резервация
{
    if(begin < end)
    {
        return 1;
    }
    return 0;
}

bool Reservation::overlapReservation(const Reservation& other)
{
    while(isValidTerm(begin, end))
    {
        if(end < other.begin || begin > other.end)
    
            return 1;
    
    }
}
