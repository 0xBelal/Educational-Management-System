//
// Created by Belal on 25-Feb-25.
//

#ifndef ADMINMAINSCREEN_H
#define ADMINMAINSCREEN_H

#include <iostream>
#include "../Screen.h"
#include "E:/Computer Science/Projects/Educational Management System/lib/clsInputValidate.h"
#include "AddNewSubAdminScreen.h"
using namespace  std;
enum eAdminScreens {eAddNewAdmin = 1, eExit = 2};
class AdminMainScreen : public  Screen {
private:

public:

    static void  Show() {
        system("cls");
        Screen::DrawScreen("Admin Main Screen");
        cout<<"\n";
        cout<<"1. Add New Faculty Admin"<<endl;
        cout<<"2. Exit"<<endl;

        switch (short ANS = clsInputValidate::ReadShortNumberBetween(1,2)) {
            case eAddNewAdmin:
                //  cout<<"Add new admin screen will be here....\n";
                    AddNewSubAdminScreen::Show();
                    Show();
                break;
            case eExit:
                return;
        }
    }
};
#endif //ADMINMAINSCREEN_H
