#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room{
    public:
        //constructors
        Room(string, int, int, bool);
        Room(Room&);

        //getters
        string getName();
        int getCapacity();
        int getComputers();
        bool hasWhiteboard();

        //setters
        void setName(string);
        void setCapacity(int);
        void setComputers(int);
        void setWhiteboard(bool);

        //other functions
        bool meetsCriteria(int=0, int=0, bool=false);
        bool lessThan(Room&);
        void print();



    private:
        string name;
        int capacity;
        int computers;
        bool whiteboard;

};

#endif