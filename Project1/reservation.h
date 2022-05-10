#include<iostream>
#include<cstring>
#include"data.h"

class Reservation
{
private:
Data begin;
Data end;
char* note;
char* name;
const char defaul_name[ 10 ] = "default";

void copyFrom(const Reservation& other);
void free();

bool isValidTerm(const Data& begin, const Data& end);

public:
Reservation();
Reservation(const Data& begin, const Data& end, const char* note, const char* name);
Reservation(const Reservation& other);
Reservation& operator=(const Reservation& other);

const Data& getBegin() const;
const Data& getEnd() const;
const char* getNote() const;
const char* getName() const;

void setBegin(const Data& begin);
void setEnd(const Data& end);
void setNote(const char* note);
void setName(const char* name);
~Reservation();
/* 
bool function  която взима параметър reservation  и връща дали двата се застъпват
*/
bool overlapReservation(const Reservation& other);//Проверява дали две резервации не се препокриват
};