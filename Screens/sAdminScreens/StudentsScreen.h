//
// Created by Belal on 13-Mar-25.
//

#ifndef STUDENTSSCREEN_H
#define STUDENTSSCREEN_H

#include <iostream>
#include <string>

#include "SettingStudentMarksScreen.h"
#include "StudentReportScreen.h"
#include "../Screen.h"
#include "../../lib/clsInputValidate.h"

using namespace std;

class StudentsScreen:public Screen {

private:

    enum ScreenOptions {eSettignMarks = 1, eStudentReport = 2,eExist=3};

    static int ReadScreenOptions() {


        cout<<Space << "   [1] Setting Student Marks"<<endl;
        cout<<Space << "   [2] Student Report"<<endl;
        cout<<Space << "   [3] Exist"<<endl;
        cout<<"\n\t\t\t========================================\n";
        cout<<"\t\t\tenter your choice [1 to 3] : " ;
        return clsInputValidate::ReadIntNumberBetween(1,3);
    }
public:
    static void Show() {
        system("cls");
        Screen::DrawScreen("\t  Students Manage Screen");

        cout<<"\n\n";


        switch (ReadScreenOptions()) {
            case StudentsScreen::eSettignMarks:
                //   cout<<"Student Marks Set Successfully"<<endl;
                    SettingStudentMarksScreen::Show();
            break;
            case StudentsScreen::eStudentReport:
              //  cout<<"Student Report Set Successfully"<<endl;
                  StudentReportScreen::Show();
            break;
            case StudentsScreen::eExist:
                return;
            default:
                cout<<"Invalid Input"<<endl;
            break;
        }
        Show();
        system("pause>0");
    }


};
#endif //STUDENTSSCREEN_H
