//
// Created by Belal on 24-Mar-25.
//

#ifndef DELETEADMIN_H
#define DELETEADMIN_H
#include "showAllSubAdmins.h"
#include "../Screen.h"
#include "../../Core/SubAdmin.h"
#include "../../lib/clsInputValidate.h"


class deleteAdmin : public  Screen {

private:


public:

    static void show() {
        system("cls");
        Screen::DrawScreen("\t  Delete Admin Screen");
        showAllSubAdmins::PrintAdmins(SubAdmin::GetAllSubAdmins());
        SubAdmin adminToDelete;
        do {
            cout<<"enter admin id to delete : ";
            adminToDelete = SubAdmin::findByID(clsInputValidate::ReadString());
        }while( adminToDelete.getID() == "" );

       if( adminToDelete.deleteAdmin()) cout<<"\nAdmin deleted....."<<endl;
        else cout<<"\nError"<<endl;

        system("pause>0");
    }
};
#endif //DELETEADMIN_H
