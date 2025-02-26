//
// Created by Belal on 26-Feb-25.
//

#ifndef SADMINMAINSCREEN_H
#define SADMINMAINSCREEN_H

#include <iostream>
#include "../Screen.h"
#include "E:/Computer Science/Projects/Educational Management System/lib/clsInputValidate.h"
#include "AddNewStudentScreen.h"
using namespace  std;
enum ensAdminScreens {eAddNewStudent = 1, esExit = 2};
class sAdminMainScreen : public  Screen {
private:

public:

    static void  Show() {
        system("cls");
        Screen::DrawScreen("sub-Admin Main Screen");
        cout<<"\n";
        cout<<"1. Add New Student"<<endl;
        cout<<"2. Exit"<<endl;

        switch (short ANS = clsInputValidate::ReadShortNumberBetween(1,2)) {
            case ensAdminScreens::eAddNewStudent:
                //  cout<<"Add new admin screen will be here....\n";
                    AddNewStudentScreen::Show();
            break;
            case ensAdminScreens::esExit:
                return;
        }
    }
};

#endif //SADMINMAINSCREEN_H
