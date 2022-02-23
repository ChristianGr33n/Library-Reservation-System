using namespace std;
#include "Student.h"

Student::Student(){
    name = "";
    number = "";
}

Student::Student(string name, string number){
    this->name = name;
    this->number = number; 
}

//copy constructor
Student::Student(Student& stu){
    this->name = stu.name;
    this->number = stu.number;
}

//getters
string Student::getName(){
    return name;
}

string Student::getNumber(){
    return number;
}

//setters
void Student::setName(string name){
    this->name = name;
}

void Student::setNumber(string number){
    this->number = number;
}

bool Student::lessThan(Student& s){
    return this->number < s.number;
}

void Student::print(){
    cout<<"name:  "<<name<<endl;
    cout<<"number:  "<<number<<endl;

}




