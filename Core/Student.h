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
    vector<Student> LoadStudents() {
        vector<Student> students;
        vector<string> Record;
        ifstream file;
        file.open(AllStudent.c_str(),ios::in);
        if(file.is_open()) {
            string line;
           while(getline(file,line)) {

               Record = clsString::Split(line,Separator);
                //1009 <-> Belal Mohamed Mohamed <-> 30410201203234 <-> belalmo@22 <-> CS <-> 0.000000 <-> NULL

               float gpa = (Record[6] == "NULL") ? 0.0f : stof(Record[6]);

               
               Student student(Record[0], Record[1], Record[2], Record[3], Record[4], Record[5], gpa);
               students.push_back(student);
           }

        }
         return students;
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

    vector<Student> getAllStudents() {
           return LoadStudents();
    }
    bool isStudent() {
           vector<Student> students = getAllStudents();

            for(Student &student : students) {
                if(student.getNationalID() == getNationalID() && student.getPassword() == getPassword()) return true;
            }
        return false;
    }
    bool AddNewStudent(){

        setID(to_string(GenerateID()));
        fstream file((StudentInfo+getID()+".txt").c_str(),ios::out | ios::app);
        fstream Courses((StudentCourses+getID()+".txt").c_str(),ios::out | ios::app);
        fstream All_Student((AllStudent).c_str(),ios::out | ios::app);
        if(All_Student.is_open()) {
            All_Student<<ConvertStudentObjToRecord()<<endl;
            All_Student.close();
        }
        if (file.is_open()) {
            file<<ConvertStudentObjToRecord()<<endl;
            file.close();

        } else return false;

        
        return true;
    }
};



#endif //STUDENT_H
