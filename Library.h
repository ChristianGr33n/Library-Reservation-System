#ifndef LIBRARY_H
#define LIBRARY_H

//the following should be set to 100 (if <100 then I was testing and forgot...)
#define STUDENT_MAX 100
#define ROOM_MAX 100
#define RESERVATION_MAX 100

#include <iostream>
#include <string>

#include "Student.h"
#include "Room.h"
#include "Reservation.h"

using namespace std;

class Library{
    public:
        //constructor
        Library();
        
        //destructor
        ~Library();

        //other functions
        bool addStudent(string , string);
        bool addRoom(string, int=1, int=0, bool=false);
        bool getStudent(string, Student**);
        bool getRoom(string, Room**);
        bool isFree(string, Date&);
        bool makeReservation(string, string, Date&);

        //bonus functions
        void update(Date&);
        void printReservations();



    private:
        Student** students;
        Room* rooms[ROOM_MAX];
        Reservation** reservations;
        int studentQuantity;
        int roomQuantity;
        int reservationQuantity;
};

#endif