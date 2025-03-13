//
// Created by Belal on 13-Mar-25.
//

#ifndef ALLSTUDENTSSCREEN_H
#define ALLSTUDENTSSCREEN_H

#include <iomanip>
#include <iostream>
#include <set>

#include "../Screen.h"
#include "../../Core/Student.h"
using namespace std;
class AllStudentsScreen : public Screen {
// 111111 <-> Belal Mohamed Mohamed Ahmed <-> 3041020120323 <-> belalmo@22 <-> Computer Science <-> 0.000000 <-> NULL

private:

    static void PrintHeader() {
        cout<<endl;
        cout<<left<<setw(10)<<"ID"
        <<" | "
        << setw(30) <<"Name" <<" | "
        <<setw(13)<<"National ID"<<" | "
        <<setw(15)<<"Password"<<" | "
        <<setw(15)<<"Faculty"<<" | "
        <<setw(4)<<"GPA"<<" | "
        <<setw(6)<<"Degree"<<endl;
        std::cout << std::string(85, '_') << std::endl;

    }

    static void PrintStudent(const Student & student ) {

        cout<<left<<setw(10)<<student.getID()
       <<" | "
       << setw(30) <<student.getFullName()<<" | "
       <<setw(13)<<student.getNationalID()<<" | "
       <<setw(15)<<student.getPassword()<<" | "
       <<setw(15)<<student.getFacultyName()<<" | "
       <<setw(4)<< student.getGPA()<<" | "
       <<setw(6)<<student.getDegree()<<endl;

    }

    static void PrintStudents(const vector<Student> & students ) {
        PrintHeader();
        for(Student  student : students ) {
            PrintStudent(student);
        }
        std::cout << std::string(85, '_') << std::endl;

    }

public:
    static void Show() {
        vector<Student> students = Student::getAllStudents();
        PrintStudents(students);
    }
};
#endif //ALLSTUDENTSSCREEN_H
