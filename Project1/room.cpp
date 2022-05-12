#include<iostream>
#include"room.h"
#include<cstring>
Room::Room()
{
    numberofroom = 0;
    numberofbeds = 0;
    size = DEFAULT_STARTING_SIZE;
    availability = false;
    allReservations = new Reservation[size];
}
Room::Room(const unsigned int numberofroom, const unsigned int numberofbeds, const bool availability, Reservation* allReservations)
{
    setNumberOfRoom(numberofroom);
    setNumberOfBeds(numberofbeds);
    setAvailability(availability);
    //setAllReservations(allReservations);
}

const int Room::getNumberOfRoom() const
{
    return numberofroom;
}

const int Room::getNumberOfBeds() const
{
    return numberofbeds;
}

const bool Room::getAvailability() const
{
    return availability;
}

const Reservation* Room::getAllReservations() const
{
    return allReservations;
}

const size_t Room::getMAX_RESERVATIONS() const
{
    return MAX_RESERVATIONS;
}

void Room::setNumberOfRoom(unsigned int numberofroom)
{
    this->numberofroom = numberofroom;
}

void Room::setNumberOfBeds(unsigned int numberofbeds)
{
    this->numberofbeds = numberofbeds;
}

void Room::setAvailability(bool availability)
{
    this->availability = availability;
}

void Room::copyFrom(const Room& other)
{
this->numberofroom = numberofroom;
this->numberofbeds = numberofbeds;
this->availability = availability;
this->numberOfReservations = numberOfReservations;
this->MAX_RESERVATIONS = MAX_RESERVATIONS;
allReservations = new Reservation[numberOfReservations];
}

void Room::free()
{
    delete[] allReservations;
}

Room& Room::operator=(const Room& other)
{
    if(this != &other)
    {
     free();
     copyFrom(other);   
    }
    return *this;
}

Room::Room(const Room& other)
{
    copyFrom(other);
}

int Room::addReservation(const Reservation& other)
{
    //allReservations[numberOfReservations] = other.allReservations[numberOfReservations + 1];
    //numberOfReservations++;
    if(numberOfReservations >= size ){
        resize();
    }

    allReservations[numberOfReservations] = other;
    numberOfReservations++;
    

}
/*resize(){
    size=size*2
    reservation* buffre = new reservation(size)

    fro(){
        buff[i] = res[i]
    }

    delte []res

    res = buff
    buff = nullptr;



}*/