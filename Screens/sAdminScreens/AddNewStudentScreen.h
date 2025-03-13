//
// Created by Belal on 26-Feb-25.
//

#ifndef ADDNEWSTUDENT_H
#define ADDNEWSTUDENT_H


#include <iostream>
#include "../Screen.h"
#include "../../Core/Student.h"
#include "../../lib/clsInputValidate.h"

using namespace std;
class AddNewStudentScreen : public Screen {
private:


public:

    static void Show() {
        system("cls");
        Screen::DrawScreen("Add New Student Screen");

       Student student;
        cout<<"Full Name   : ";
        student.setFullName(clsInputValidate::ReadString());
        cout<<"National ID : ";
        student.setNationalID(clsInputValidate::ReadString());
        cout<<"Password    : ";
        student.setPassword(clsInputValidate::ReadPassword());
        cout<<"Faculty     : ";
        student.setFacultyName(clsInputValidate::ReadString());
        cout<<"GPA         : ";
        student.setGPA(clsInputValidate::ReadFloatNumber());
        cout<<"Degree      : ";
        student.setDegree(clsInputValidate::ReadString());
        if(student.AddNewStudent()) cout<<"\nAdd successfully....\n";
        else cout<<"Error\n";

    }

};
#endif //ADDNEWSTUDENT_H
