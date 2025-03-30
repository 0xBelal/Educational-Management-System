//
// Created by Belal on 19-Mar-25.
//

#ifndef START_H
#define START_H
#include <process.h>

#include "LoginScreen.h"
#include "../Global/Global.h"
#include "../lib/clsInputValidate.h"


class start {

    public:
    static void startProgram() {


        system("cls");

        cout<<"\t\t\t========================================\n";
        cout<<"\n"<<Space<<"   [1] Login\n";
        cout<<Space<<"   [2] get student id by national id\n";
        cout<<"\n\t\t\t========================================\n";

        cout<<Space<<"enter your choice [1 to 2] : ";
        switch (clsInputValidate::ReadIntNumberBetween(1,2)) {
            case 1:
                LoginScreen::show();
                break;
            case 2:
                GetStudentIDScreen::Show();
                break;
        }

    }
};
#endif //START_H
