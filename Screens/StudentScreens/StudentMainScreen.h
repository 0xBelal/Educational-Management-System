//
// Created by Belal on 02-Mar-25.
//

#ifndef STUDENTMAINSCREEN_H
#define STUDENTMAINSCREEN_H


#include <iostream>
#include "../Screen.h"
#include "../../lib/clsInputValidate.h"
#include "../../Screens/StudentScreens/GetStudentIDScreen.h"
#include "RegistrationScreen.h"
#include "RegistredCoursesScreen.h"
#include "../../Screens/sAdminScreens/StudentReportScreen.h"
using namespace  std;
enum eStudentScreens {Registeretion = 1, RegistredCourses =2 ,GetID = 3,StudentReport =4, Exit = 5};
class StudentMainScreen : public  Screen {
private:

public:

    static void  Show() {
        system("cls");
        Screen::DrawScreen("\t  Student Main Screen");
        cout<<"\n";
        cout<<Space<<"   [1] Registeretion "<<endl;
        cout<<Space<<"   [2] Registred Courses"<<endl;
        cout<<Space<<"   [3] Get ID By National ID"<<endl;
        cout<<Space<<"   [4] Student Report"<<endl;
        cout<<Space<<"   [5] Logout"<<endl;
        cout<<"\n\t\t\t========================================\n";
        cout<<"\t\t\tenter your choice [1 to 5] : " ;
        switch (short ANS = clsInputValidate::ReadShortNumberBetween(1,5)) {
            case Registeretion:
                //cout<<"Registeretion screen will be here....\n";
                    RegistrationScreen::Show();
                Show();
            break;
            case RegistredCourses:
                RegistredCoursesScreen::Show();
                 Show();
            break;
            case GetID:
               // cout<<"Get ID screen will be here....\n";
                   GetStudentIDScreen::Show();
                Show();
            break;
            case StudentReport:
                StudentReportScreen::Show(LoginStudent);
                Show();
            break;
            case Exit:
                return;
        }
    }
};
#endif //STUDENTMAINSCREEN_H
