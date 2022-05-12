#pragma once
#include<iostream>
#include"reservation.h"

class Room
{
private:
static const size_t DEFAULT_STARTING_SIZE = 3;
size_t size;
unsigned int numberofroom;
unsigned int numberofbeds;
bool availability;
Reservation* allReservations;
size_t numberOfReservations;
const char defaul_name[10] = "default";

void copyFrom(const Room& other);
void free();

public:
Room();
Room(const unsigned int numberofroom, const unsigned int numberofbeds, const bool availability, Reservation* allReservations);
Room(const Room& other);
Room& operator=(const Room& other);

const int getNumberOfRoom() const;
const int getNumberOfBeds() const;
const bool getAvailability() const;
const Reservation* getAllReservations() const;
const size_t getMAX_RESERVATIONS() const;

void setNumberOfRoom(unsigned int numberofroom);
void setNumberOfBeds(unsigned int numberofbeds);
void setAvailability(bool availability);

int addReservation(const Reservation& other);
~Room();
};