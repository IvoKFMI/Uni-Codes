#include<iostream>
#include"data.h"

class Reservation
{
private:
Data begin;
Data end;
char* note;
char* name;

void copyFrom(const Reservation& other);
void free();

public:
Reservation();
Reservation(const Data& begin, const Data& end, const char* note, const char* name);
Reservation(const Reservation& other);
Reservation& operator=(const Reservation& other);

const Data getBegin() const;
const Data getEnd() const;
const char* getNote() const;
const char* getName() const;

void setBegin(Data& begin);
void setEnd(Data& end);
void setNote(const char* note);
void setName(const char* name);
~Reservation();
};