//
// Created by Belal on 25-Feb-25.
//

#ifndef ADMINMAINSCREEN_H
#define ADMINMAINSCREEN_H

#include <iostream>
#include "../Screen.h"
#include "../../lib/clsInputValidate.h"
#include "AddNewSubAdminScreen.h"
#include "deleteAdmin.h"
#include "showAllSubAdmins.h"
using namespace  std;
enum eAdminScreens {eAddNewAdmin = 1, eDeleteAdmin=2,AllAdmin=3,eExit = 4};
class AdminMainScreen : public  Screen {
private:

public:

    static void  Show() {
        system("cls");
        Screen::DrawScreen("\t Admin Main Screen");
        cout<<"\n";
        cout<<Space<<"   [1] Add new admin"<<endl;
        cout<<Space<<"   [2] Delete admin"<<endl;
        cout<<Space<<"   [3] All admin "<<endl;
        cout<<Space<<"   [4] Logout"<<endl;
        cout<<"\n\t\t\t========================================\n";
        cout<<Space<<"enter your choice [1 to 4] : ";
        switch (short ANS = clsInputValidate::ReadShortNumberBetween(1,4)) {
            case eAddNewAdmin:
                //  cout<<"Add new admin screen will be here....\n";
                    AddNewSubAdminScreen::Show();
                    Show();
                break;
            case AllAdmin:
                showAllSubAdmins::show();
            break;
            case eDeleteAdmin:
                deleteAdmin::show();
            break;
            case eExit:
                return;
        }
    }
};
#endif //ADMINMAINSCREEN_H
