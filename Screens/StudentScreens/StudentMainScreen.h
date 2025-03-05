//
// Created by Belal on 02-Mar-25.
//

#ifndef STUDENTMAINSCREEN_H
#define STUDENTMAINSCREEN_H


#include <iostream>
#include "../Screen.h"
#include "E:/Computer Science/Projects/Educational Management System/lib/clsInputValidate.h"
#include "E:\Computer Science\Projects\Educational Management System\Screens\StudentScreens\GetStudentIDScreen.h"
#include "RegisteretionScreen.h"
using namespace  std;
enum eStudentScreens {Registeretion = 1, GetID = 2, Exit = 3};
class StudentMainScreen : public  Screen {
private:

public:

    static void  Show() {
        system("cls");
        Screen::DrawScreen("Student Main Screen");
        cout<<"\n";
        cout<<"1. Registeretion "<<endl;
        cout<<"2. Get ID By National ID"<<endl;
        cout<<"3. Exit"<<endl;

        switch (short ANS = clsInputValidate::ReadShortNumberBetween(1,3)) {
            case Registeretion:
                //cout<<"Registeretion screen will be here....\n";
                    RegisteretionScreen::Show();
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
