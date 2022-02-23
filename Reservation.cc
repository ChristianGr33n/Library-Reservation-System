using namespace std;

#include "Reservation.h"

Reservation::Reservation(Student* student, Room* room, Date& date){
    this->student = student;
    this->room = room;
    this->date.setDate(date);
}

Student Reservation::getStudent(){
    return *student;
}

Room Reservation::getRoom(){
    return *room;
}

Date Reservation::getDate(){
    return date;
}

bool Reservation::lessThan(Reservation& res){
    return this->date.lessThan(res.date);
}

//takes in a string for the room name and a Date
//returns wether the room with the given name already has a reservation or not
bool Reservation::overlaps(string r, Date& d){
    if (r==this->room->getName()){
        if(this->date.overlaps(d)) return true;
        else return false;
    }
    else return false;
}

void Reservation::print(){
    cout<<"------Reservation information------"<<endl;
    this->student->print();
    this->room->print();
    this->date.print();
    cout<<endl;
}



