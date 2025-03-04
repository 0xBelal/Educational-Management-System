//
// Created by Belal on 02-Mar-25.
//

#ifndef STUDENTMAINSCREEN_H
#define STUDENTMAINSCREEN_H


#include <iostream>
#include "../Screen.h"
#include "E:/Computer Science/Projects/Educational Management System/lib/clsInputValidate.h"

using namespace  std;
enum eStudentScreens {Registeretion = 1, Exit = 2};
class StudentMainScreen : public  Screen {
private:

public:

    static void  Show() {
        system("cls");
        Screen::DrawScreen("Student Main Screen");
        cout<<"\n";
        cout<<"1. Registeretion "<<endl;
        cout<<"2. Exit"<<endl;

        switch (short ANS = clsInputValidate::ReadShortNumberBetween(1,2)) {
            case Registeretion:
                 cout<<"Registeretion screen will be here....\n";

                Show();
            break;
            case Exit:
                return;
        }
    }
};
#endif //STUDENTMAINSCREEN_H
