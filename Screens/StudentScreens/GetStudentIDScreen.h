//
// Created by Belal on 05-Mar-25.
//

#ifndef GETSTUDENTIDSCREEN_H
#define GETSTUDENTIDSCREEN_H
#include <iostream>
#include <string>

#include "../Screen.h"
#include "../../Core/Student.h"
#include "../Screen.h"
#include "../../lib/clsInputValidate.h"
using namespace std;
class GetStudentIDScreen : public Screen {
private:


    /*static void PrintStudentInfo(Student &student)  {
        cout<<"\n______________Student Info______________\n";
        cout<<"Student ID : "<<student.getID()<<" , Password : "<<student.getPassword()<<endl;
        cout<<"Name : "<<student.getFullName()<<endl;
        cout<<"National ID : "<<student.getNationalID()<<endl;
        cout<<"Faculty : "<<student.getFacultyName()<< " , GPA : "<<student.getGPA()<<endl;
        cout<<"Degree : "<<student.getDegree()<<endl;
        cout<<"________________________________________\n";

    }*/

public:

    static void Show() {
        system("cls");
        Screen::DrawScreen("\t  Get Student ID Screen");
       // cout<<"\n________________________________________\n";
        cout<<"\n"<<Space<<"Student National ID : ";
        Student student; student.setNationalID(clsInputValidate::ReadString());
        if((student = student.getIDByNationalID()).isEmpty()) cout<<"\n"<<Space<<"Invalid national id....."<<endl;
        else {system("cls"); PrintStudentInfo(student);}

        // cout<<"\n\n________________________________________\n";

        system("pause>0");
    }

};
#endif //GETSTUDENTIDSCREEN_H
