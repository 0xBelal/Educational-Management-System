#include <iostream>
#include "Screens/LoginScreen.h"
#include "Global/Global.h"
#include <fstream>
#include "Screens/Start.h"
using namespace std;

int main()
{

    while (true) {
        start::startProgram();
    }


    system("pause>0");
    return 0;
}

/*
Educational Management System

sub admin add new student to path file:  “..\\DataSource\\FacultyName\\Students\\Student_ID”
and file path  all {id , national id ,pass}
 Student { id , name, national id, faculty, GPA, }


Course code , Name , credit hours, mark

 */