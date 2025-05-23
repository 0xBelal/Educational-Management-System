//
// Created by Belal on 26-Feb-25.
//

#ifndef SADMINMAINSCREEN_H
#define SADMINMAINSCREEN_H

#include <iostream>

#include "AddNewCourseScreen.h"
#include "../Screen.h"
#include "../../lib/clsInputValidate.h"
#include "AddNewStudentScreen.h"
#include "AddNewCourseScreen.h"
#include "StudentsScreen.h"
using namespace  std;
enum ensAdminScreens {eAddNewStudent = 1, eStudents=3,eAddNewCourse = 2 ,esExit = 4};
class sAdminMainScreen : public  Screen {
private:



public:

    static void  Show() {
        system("cls");
        Screen::DrawScreen("\t sub-Admin Main Screen");
        cout<<"\n";
        cout<< Space << "   [1] Add New Student"<<endl;
        cout<< Space << "   [2] Add New Course"<<endl;
        cout<<Space << "   [3] Manage Students"<<endl;
        cout<<Space << "   [4] Logout"
              <<endl;
        cout<<"\n\t\t\t========================================\n";
        cout<<"\t\t\tenter your choice [1 to 4] : " ;
        switch (short ANS = clsInputValidate::ReadShortNumberBetween(1,4)) {
            case ensAdminScreens::eAddNewStudent:
                //  cout<<"Add new admin screen will be here....\n";
                    AddNewStudentScreen::Show();
                    Show();
            break;
            case ensAdminScreens::eAddNewCourse:
                AddNewCourseScreen::Show();
                Show();
            break;
            case eStudents:
                StudentsScreen::Show();
                Show();
                break;
            case ensAdminScreens::esExit:
                return;
        }
    }
};

#endif //SADMINMAINSCREEN_H
