using namespace std;

#include "library.h"

Library::Library(){
    students = new Student*[STUDENT_MAX];
    reservations = new Reservation*[RESERVATION_MAX];
    studentQuantity = 0;
    roomQuantity = 0;
    reservationQuantity = 0;
}

//destructor for deleting appropriate arrays and their elements
Library::~Library(){
    //deleting array pointers
    for(int i=0; i<studentQuantity;++i){
        delete students[i];
    }
    for(int i=0; i<roomQuantity;++i){
        delete rooms[i];
    }
    for(int i=0; i<reservationQuantity;++i){
        delete reservations[i];
    }
    
    //deleting dynamically allocated arrays
    delete [] students; 
    delete [] reservations;
}

//input: a string name and number for creating a Student object
//output: adds a new Student with the given parameters to the students array
//return: true if added to the array, false otherwise
bool Library::addStudent(string name, string number){
    //checking the case that the array is full
    if(studentQuantity == STUDENT_MAX) return false;
    
    Student* stu = new Student(name, number);
    //BONUS: adding the student pointer defined by lessThan ordering
    for(int i=0; i<studentQuantity; ++i){
        //checks to see if the new student is smaller than the student at position i
        if(stu->lessThan(*students[i])){
            //if so, starting from the back of the array, shift all students greater than the new student by one to the right
            for(int j=0; j< studentQuantity-i; ++j){
                students[studentQuantity-j] = students[studentQuantity-j-1];
            }
            //set the newly emptied slot to the new student and adjust the student count
            students[i] = stu;
            ++studentQuantity;
            return true;
        }
    }
    //if the new student is greater than all students, add it to the end
    students[studentQuantity] = stu;
    ++studentQuantity;
    return true;
}

//input: a string name, integers capcity and computers and a boolean whiteboard
//       for creating a Room object
//output: adds a new Room with the given parameters to the rooms array
//return: true if added to the array, false otherwise
bool Library::addRoom(string name, int capacity, int computers, bool whiteboard){
    //checking the case that the array is full
    if(roomQuantity == ROOM_MAX) return false;
    
    Room* room = new Room(name, capacity, computers, whiteboard);
    //BONUS: adding the room pointer defined by lessThan ordering
    for(int i=0; i<roomQuantity; ++i){
        //checks to see if the new room is smaller than the room at position i
        if(room->lessThan(*rooms[i])){
            //if so, starting from the back of the array, shift all rooms greater than the new room by one to the right
            for(int j=0; j< roomQuantity-i; ++j){
                rooms[roomQuantity-j] = rooms[roomQuantity-j-1];
            }
            //set the newly emptied slot to the new room and adjust the room count
            rooms[i] = room;
            ++roomQuantity;
            return true;
        }
    }
    //if the new room is greater than all rooms, add it to the end
    rooms[roomQuantity] = room;
    ++roomQuantity;
    return true;
}

//input: string for the student's name and a Student double pointer
//output: sets the student double pointer to the student from the array if it exists
//return: true if there is a student with the given string as name and false otherwise
bool Library::getStudent(string name, Student** student){
    for(int i=0; i<studentQuantity; ++i){
        if (name == students[i]->getName()){
            *student = students[i];
            return true;
        }
    }
    return false;
}

//input: a string for the room name and a Room double pointer
//output: sets the room double pointer to the room from the array if it exists
//return: true if there is a room with the string given and false otherwise
bool Library::getRoom(string roomName, Room** room){
    for(int i=0; i<roomQuantity; ++i){
        if (roomName == rooms[i]->getName()){
            *room = rooms[i];
            return true;
        }
    }
    return false;
}

//input: a string for the room name and a date
//returns if the room with the room name is free on the given date
bool Library::isFree(string room, Date& date){
    bool exists = false;

    //checking the rooms exists
    for(int i=0; i<roomQuantity; ++i){
        if(rooms[i]->getName() == room) exists = true;
    }

    //checking if there is a revervation with that room that overlaps
    for(int i=0; i<reservationQuantity; ++i){
        if(reservations[i]->getRoom().getName() == room){
            if(reservations[i]->overlaps(room, date)) return false;
        }
    }
    
    //if the room exists with no overlaps, return true. Otherwise return false
    if(exists) return true;
    else return false;
}

bool Library::makeReservation(string student, string room, Date& date){
    //setting variables
    Student stu;
    Student* stuPtr = &stu;
    Student** stuPtr2 = &stuPtr;
    Room roo("x", 0, 0, false);
    Room* rooPtr = &roo;
    Room** rooPtr2 = &rooPtr;

    //checking if the reservations array is full
    if(reservationQuantity == RESERVATION_MAX) return false;

    //checking if the room is free
    if(!isFree(room, date)) return false;

    //checking if the room exists
    if(!getRoom(room, rooPtr2)) return false;
    
    //checking if the student exists
    if(!getStudent(student, stuPtr2)) return false;

    Reservation* res = new Reservation(*stuPtr2, *rooPtr2, date);

    //BONUS: adding the reservation pointer defined by lessThan ordering
    for(int i=0; i<reservationQuantity; ++i){
        //checks to see if the new reservation is smaller than the reservation at position i
        if(res->lessThan(*reservations[i])){
            //if so, starting from the back of the array, shift all reservation greater than the new reservation by one to the right
            for(int j=0; j< reservationQuantity-i; ++j){
                reservations[reservationQuantity-j] = reservations[reservationQuantity-j-1];
            }
            //set the newly emptied slot to the new reservation and adjust the reservation count
            reservations[i] = res;
            ++reservationQuantity;
            return true;
        }
    }
    //if the new reservation is greater than all reservations, add it to the end
    reservations[reservationQuantity] = res;
    ++reservationQuantity;
    return true;
}

//BONUS: removes all reservations on or before the date given as parameter
//note: the assignment says to remove any reservation before or on the date given in the parameter
//      Which I assume here that means any date that starts on the same hour, day, month, and year (duration not mattering) 
void Library::update(Date& d){
    int remove=0;
    //removing every reservation that has a date prior or equal to the date given
    for(int i=0; i<reservationQuantity; ++i){

        if(reservations[i]->getDate().lessThan(d) || (reservations[i]->getDate().getYear() == d.getYear() && reservations[i]->getDate().getMonth() == d.getMonth()
        && reservations[i]->getDate().getDay() == d.getDay() && reservations[i]->getDate().getHour() == d.getHour())){
            delete reservations[i];
            ++remove;
        }
        else{
            //shifting remaining revervations to the left
            reservationQuantity -=remove;
            for(int j=0; j<reservationQuantity; ++j){
                reservations[j] = reservations[j+i];
                //if there was a reservation at j+i, we have to delete it now
                if(reservationQuantity+remove == j+i) delete reservations[j+i];
            }
            return;
        }
    }
    //in the case that all is deleted from the array, we will update the count here
    reservationQuantity -=remove;
}

//BONUS: printReservations function that outputs the information of all rerservations
void Library::printReservations(){
    for(int i=0; i<reservationQuantity; ++i){
        reservations[i]->print();
    }
}

