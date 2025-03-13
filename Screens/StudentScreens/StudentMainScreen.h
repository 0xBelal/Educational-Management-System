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
using namespace  std;
enum eStudentScreens {Registeretion = 1, RegistredCourses =2 ,GetID = 3, Exit = 4};
class StudentMainScreen : public  Screen {
private:

public:

    static void  Show() {
        system("cls");
        Screen::DrawScreen("Student Main Screen");
        cout<<"\n";
        cout<<"1. Registeretion "<<endl;
        cout<<"2. Registred Courses"<<endl;
        cout<<"3. Get ID By National ID"<<endl;
        cout<<"4. Exit"<<endl;

        switch (short ANS = clsInputValidate::ReadShortNumberBetween(1,4)) {
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
            case Exit:
                return;
        }
    }
};
#endif //STUDENTMAINSCREEN_H
