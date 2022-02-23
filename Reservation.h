#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Date.h"
#include "Room.h"
#include "Student.h"

using namespace std;

class Reservation{
    public:
        //constructor
        Reservation(Student*, Room*, Date&);

        //getters
        Student getStudent();
        Room getRoom();
        Date getDate();

        //other functions
        bool lessThan(Reservation&);
        bool overlaps(string, Date&);
        void print();

    private:    
        //members
        Student* student;
        Room* room;
        Date date;

};

#endif