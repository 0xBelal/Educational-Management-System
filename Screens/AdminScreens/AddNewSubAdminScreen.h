//
// Created by Belal on 25-Feb-25.
//

#ifndef ADDNEWSUBADMINSCREEN_H
#define ADDNEWSUBADMINSCREEN_H

#include <iostream>
#include "../Screen.h"
#include "../../Core/SubAdmin.h"
#include "../../lib/clsInputValidate.h"

using namespace std;
class AddNewSubAdminScreen : public Screen {
private:


public:

    static void Show() {
        system("cls");
        Screen::DrawScreen("Add New Sub Admin Screen");

        SubAdmin sAdmin;
        cout<<"Full Name   : ";
        sAdmin.setFullName(clsInputValidate::ReadString());
        cout<<"National ID : ";
        sAdmin.setNationalID(clsInputValidate::ReadString());
        cout<<"Password    : ";
        sAdmin.setPassword(clsInputValidate::ReadPassword());
        cout<<"Faculty     : ";
        sAdmin.setFacultyName(clsInputValidate::ReadString());

        if(sAdmin.AddNewAdmin()) cout<<"\nAdd successfully....\n";


    }

};
#endif //ADDNEWSUBADMINSCREEN_H
