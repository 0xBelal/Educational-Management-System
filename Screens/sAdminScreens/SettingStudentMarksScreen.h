//
// Created by Belal on 13-Mar-25.
//

#ifndef SETTINGSTUDENTMARKSSCREEN_H
#define SETTINGSTUDENTMARKSSCREEN_H

#include <iostream>

#include "AllStudentsScreen.h"
#include "../Screen.h"
using namespace   std;

class SettingStudentMarksScreen: public Screen {

private:

    static void PrintStudentInfo(const Student & student ) {


        cout<<"Student Information:"<<endl;
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

            PrintStudentInfo(student);


     //system("pause>0");
    }



};
#endif //SETTINGSTUDENTMARKSSCREEN_H
