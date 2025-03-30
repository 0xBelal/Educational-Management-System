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
        Screen::DrawScreen("\tAdd New Sub Admin Screen");

        SubAdmin sAdmin;
        cout<<Space <<" Full Name   : ";
        sAdmin.setFullName(clsInputValidate::ReadString());
        cout<<Space<<" National ID : ";
        sAdmin.setNationalID(clsInputValidate::ReadString());
        cout<<Space<<" Password    : ";
        sAdmin.setPassword(clsInputValidate::ReadPassword());
        cout<<Space <<" Faculty     : ";
        sAdmin.setFacultyName(clsInputValidate::ReadString());

        if(sAdmin.AddNewAdmin()) cout<<"\n"<<Space<<"admin added successfully....\n";

        system("Pause>0");
    }

};
#endif //ADDNEWSUBADMINSCREEN_H
