//
// Created by Belal on 13-Mar-25.
//

#ifndef SETTINGSTUDENTMARKSSCREEN_H
#define SETTINGSTUDENTMARKSSCREEN_H

#include <iostream>

#include "AllStudentsScreen.h"
#include "../Screen.h"
using namespace   std;

class SettingStudentMarksScreen: public Screen {

private:



public:

static void Show() {
    system("cls");
    Screen::DrawScreen("Setting Student Marks Screen");

    cout<<endl;
    cout<<"<All Students>\n";
    AllStudentsScreen::Show();
}



};
#endif //SETTINGSTUDENTMARKSSCREEN_H
