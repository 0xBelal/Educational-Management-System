//
// Created by Belal on 25-Feb-25.
//

#ifndef ADDNEWSUBADMINSCREEN_H
#define ADDNEWSUBADMINSCREEN_H

#include <iostream>
#include "../Screen.h"
#include "E:/Computer Science/Projects/Educational Management System/Core/SubAdmin.h"
#include "E:/Computer Science/Projects/Educational Management System/lib/clsInputValidate.h"

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

        sAdmin.AddNewAdmin();


    }

};
#endif //ADDNEWSUBADMINSCREEN_H
