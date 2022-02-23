#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student{

    public:
        //constructors
        Student();
        Student(string, string);
        Student(Student&);

        //getters
        string getName();
        string getNumber();

        //setters
        void setName(string);
        void setNumber(string);

        //other methods
        bool lessThan(Student&);
        void print();

    //members
    private:
        string name;
        string number;
};

#endif