
#include "Room.h"


//constructors
Room::Room(string name, int capacity, int computers, bool whiteboard){
    this->name = name;
    this->capacity = capacity;
    this->computers = computers;
    this->whiteboard = whiteboard;
}

Room::Room(Room& r){
    this->name = r.name;
    this->capacity = r.capacity;
    this->computers = r.computers;
    this->whiteboard = r.whiteboard;
}

//getters
string Room::getName(){
    return name;
}

int Room::getCapacity(){
    return capacity;
}

int Room::getComputers(){
    return computers;
}

bool Room::hasWhiteboard(){
    return whiteboard;
}

//setters
void Room::setName(string name){
    this->name = name;
}

void Room::setCapacity(int capacity){
    this->capacity = capacity;
}

void Room::setComputers(int computers){
    this->computers = computers;
}

void Room::setWhiteboard(bool whiteboard){
    this->whiteboard = whiteboard;
}

//other functions
bool Room::meetsCriteria(int capacity, int computers, bool whiteboard){
    if(this->capacity >= capacity && this->computers >= computers){
        //if they want a whiteboard, and this room has a whiteboard
        if (whiteboard == true && this->whiteboard == true) return true;
        //they don't need a whiteboard
        else if (whiteboard == false) return true;
        //they want a whiteboard but the room does not have one
        else return false;
    }
    else return false;
}

bool Room::lessThan(Room& r){
    return this->name < r.name;
}

void Room::print(){
    cout<<"name:  "<<name<<endl;
    cout<<"capacity:  "<<capacity<<endl;
    cout<<"computers:  "<<computers<<endl;
    cout<<"has a whiteboard?:  "<<whiteboard<<endl;
}
