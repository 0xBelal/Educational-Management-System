//
// Created by Belal on 26-Feb-25.
//

#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include "Person.h"
#include "../Global/Global.h"
#include <fstream>

using namespace  std;


class Student : public Person{

private :
    string FacultyName;
    string Degree;
    float GPA;

    string ConvertStudentObjToRecord() {
        return (getID() + Separator + getFullName() + Separator + getNationalID() + Separator + getPassword() +
            Separator +getFacultyName() + Separator +to_string( getGPA()) + Separator + getDegree());
    }

    void Assigin(Student& student) {
        this->setID(student.getID());
        this->setFullName(student.getFullName());
        this->setNationalID(student.getNationalID());
        this->setPassword(student.getPassword());
        this->setFacultyName(student.getFacultyName());
        this->setGPA(student.getGPA());
        this->setDegree(student.getDegree());

    }
public:
    Student(){}
    Student(const string &ID ,const string &FullName ,const string &NID,const string &Password ,
        const string &FacultyName,const string &Degree,const float &GPA):
    Person(ID, FullName,  Password,NID) {       //     Person(string ID, string FullName, string Password,const string& NID)

        setGPA(GPA);
        setDegree(Degree);

    }
    void setDegree(const string &degree) {Degree = degree;}
    void setGPA(const float &gpa) { GPA = gpa; }
    void setFacultyName(const string &Name){ FacultyName = Name;}

    string getDegree(){return Degree;}
    float getGPA(){return GPA;}
    string getFacultyName(){return FacultyName;}

    bool AddNewStudent(){

        setID(to_string(GenerateID()));
        fstream file(GenerateStudentPath(getFacultyName(),getID()),ios::out | ios::app);
        if (file.is_open()) {
            file<<ConvertStudentObjToRecord()<<endl;
            file.close();

        } else return false;

        
        return true;
    }
};



#endif //STUDENT_H
