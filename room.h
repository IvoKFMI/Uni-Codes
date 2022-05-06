#include<iostream>

class Room
{
private:
unsigned int numberofroom;
unsigned int numberofbeds;
bool availability;
public:
Room();
Room(const unsigned int numberofroom, const unsigned int numberofbeds, const bool availability);

const int getNumberOfRoom() const;
const int getNumberOfBeds() const;
const bool getAvailability() const;

void setNumberOfRoom(unsigned int numberofroom);
void setNumberOfBeds(unsigned int numberofbeds);
void setAvailability(bool availability);
};