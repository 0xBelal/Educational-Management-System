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
        Screen::DrawScreen("\t  Add New Student Screen");

       Student student;
        cout<<Space<<" Full Name   : ";
        student.setFullName(clsInputValidate::ReadString());
        cout<<Space <<" National ID : ";
        student.setNationalID(clsInputValidate::ReadString());
        cout<<Space<<" Password    : ";
        student.setPassword(clsInputValidate::ReadPassword());
        cout<<Space<<" Faculty     : ";
        student.setFacultyName(clsInputValidate::ReadString());
       // cout<<"GPA         : ";
        student.setGPA(0);
        //cout<<"Degree      : ";
        student.setDegree("NULL");
        if(student.addNewStudent()) cout<<"\n\n"<<Space<<"Add successfully....\n";
        else cout<<"Error\n";

    }

};
#endif //ADDNEWSTUDENT_H
