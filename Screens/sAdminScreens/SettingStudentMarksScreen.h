//
// Created by Belal on 13-Mar-25.
//

#ifndef SETTINGSTUDENTMARKSSCREEN_H
#define SETTINGSTUDENTMARKSSCREEN_H

#include <iostream>

#include "AllStudentsScreen.h"
#include "../Screen.h"
#include "../../Global/LoginUser.h"
#include "../../Screens/StudentScreens/RegistredCoursesScreen.h"
using namespace   std;

class SettingStudentMarksScreen: public Screen {

private:

    static void PrintStudentInfo(const Student & student ) {


        cout<<"Student Information:"<<endl;
        std::cout << std::string(50, '_') << std::endl;
        cout<<"ID   : "<<student.getID()<<"   National ID : "<<student.getNationalID()<<endl;
        cout<<"Name : "<<student.getFullName()<<endl;
        cout<<"Faculty : "<< student.getFacultyName()<<" , GPA : "<< student.getGPA()<<endl;
        cout<<"Degree  : "<< student.getDegree()<<endl;
        std::cout << std::string(50, '_') << std::endl;

    }

public:

static void Show() {
        system("cls");
        Screen::DrawScreen("Setting Student Marks Screen");

        cout<<endl;
        cout<<"<All Students>\n";
        AllStudentsScreen::Show();

        cout<<endl;
        Student student;
    do {
        cout<<"Enter a student ID : ";
        student.setID(clsInputValidate::ReadString());
        student.getStudentByID();

        if(student.isEmpty()) {
            cout<<"Invalid ID!"<<endl;
        }else break;
    }while (true);
            system("cls");
            //LoginStudent = student;
            PrintStudentInfo(student);
           // RegistredCoursesScreen::Show();

     system("pause>0");
    }



};
#endif //SETTINGSTUDENTMARKSSCREEN_H
