//
// Created by Belal on 13-Mar-25.
//

#ifndef STUDENTSSCREEN_H
#define STUDENTSSCREEN_H

#include <iostream>
#include <string>

#include "SettingStudentMarksScreen.h"
#include "../Screen.h"
#include "../../lib/clsInputValidate.h"

using namespace std;

class StudentsScreen:public Screen {

private:

    enum ScreenOptions {eSettignMarks = 1, eStudentReport = 2,eExist=3};

    static void ReadScreenOptions() {


        cout<<"1. Setting Student Marks"<<endl;
        cout<<"2. Student Report"<<endl;
        cout<<"3. Exist"<<endl;

        int ANS = clsInputValidate::ReadIntNumberBetween(1,3);

        switch (ANS) {
            case StudentsScreen::eSettignMarks:
             //   cout<<"Student Marks Set Successfully"<<endl;
                 SettingStudentMarksScreen::Show();
            break;
            case StudentsScreen::eStudentReport:
                cout<<"Student Report Set Successfully"<<endl;
            break;
            case StudentsScreen::eExist:
                return;
            default:
                cout<<"Invalid Input"<<endl;
            break;
        }
    }
public:
    static void Show() {
        system("cls");
        Screen::DrawScreen("Students Manage Screen");

        cout<<"\n\n";

        ReadScreenOptions();
        system("pause>0");
    }


};
#endif //STUDENTSSCREEN_H
