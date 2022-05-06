#include<iostream>
#include"room.h"
Room::Room()
{
    numberofroom = 0;
    numberofbeds = 0;
    availability = false;
}

Room::Room(unsigned int numberofroom, unsigned int numberofbeds, bool availability)
{
    setNumberOfRoom(numberofroom);
    setNumberOfBeds(numberofbeds);
    setAvailability(availability);
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