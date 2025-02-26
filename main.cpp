#include <iostream>
#include "Screens/LoginScreen.h"
#include "Global/Global.h"
using namespace std;

const int ss=0;
int main()
{
    while (true) {
        LoginScreen::show();
    }

    system("pause>0");
    return 0;
}

/*
Educational Management System

sub admin add new student to path file:  “..\\DataSource\\FacultyName\\Students\\Student_ID”
and file path  all {id , national id ,pass}
 Student { id , name, national id, faculty, GPA, }

 */