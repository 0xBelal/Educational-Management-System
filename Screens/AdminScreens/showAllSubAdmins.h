//
// Created by Belal on 24-Mar-25.
//

#ifndef SHOWALLSUBADMINS_H
#define SHOWALLSUBADMINS_H
#include "../Screen.h"
#include "../../Core/SubAdmin.h"

class showAllSubAdmins:public  Screen {

private:

    //111119 <-> Mohamed Ahmed <-> 12345678910123 <-> admin <-> Computer Science

    static void PrintHeader() {
        cout<<endl;
        std::cout << std::string(75+22, '_') << std::endl;
        cout<<left<<setw(10)<<"ID"
        <<" | "
        << setw(30) <<"Name" <<" | "
        <<setw(14)<<"National ID"<<" | "
        <<setw(15)<<"Password"<<" | "
        <<setw(16)<<"Faculty"<<endl;
        std::cout << std::string(75+22, '_') << std::endl;

    }

    static void PrintAdmin(const SubAdmin & admin ) {

        cout<<left<<setw(10)<<admin.getID()
       <<" | "
       << setw(30) <<admin.getFullName()<<" | "
       <<setw(14)<<admin.getNationalID()<<" | "
       <<setw(15)<<admin.getPassword()<<" | "
       <<setw(16)<<admin.getFacultyName()<<endl;

    }



public:

    static void PrintAdmins(const vector<SubAdmin> & allAdmins ) {
        PrintHeader();
        for(SubAdmin  admin : allAdmins ) {
            PrintAdmin(admin);
        }
        std::cout << std::string(75+22, '_') << std::endl;

    }


    static void show() {
        Screen::DrawScreen("\t    All sub-Admins");
        PrintAdmins(SubAdmin::GetAllSubAdmins());

        system("pause>0");
    }

};
#endif //SHOWALLSUBADMINS_H
