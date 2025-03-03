//
// Created by Belal on 03-Mar-25.
//

#ifndef ADDNEWCOURSESCREEN_H
#define ADDNEWCOURSESCREEN_H

#include <iostream>
#include <string>
#include "E:\Computer Science\Projects\Educational Management System\Screens\Screen.h"
#include "E:\\Computer Science\\Projects\\Educational Management System\\Core\\Course.h"
#include "E:\Computer Science\Projects\Educational Management System\lib\clsInputValidate.h"
using namespace std;

class AddNewCourseScreen : public Screen {

private:


     static void AddNewCourse() {
        Course course;
        cout<<"Course Code   : ";
        course.setCourseCode(clsInputValidate::ReadString());
        cout<<"Course Name   : ";
        course.setName(clsInputValidate::ReadString());
        cout<<"Credits Hours : ";
        course.setCreditHours(clsInputValidate::ReadIntNumberBetween(0,3));
        cout<<"Are there Prerequisites ? y/n ? ";
        char ANS; ANS = clsInputValidate::ReadYes_Or_No_Q();

        switch (ANS) {
            case 'Y':
                int NoOfCourses;
                cout<<"The number of courses required : "; NoOfCourses = clsInputValidate::ReadIntNumberBetween(1,10);

            for(int i=0;i<NoOfCourses;i++) {

                cout<<i+1<<") Course Code : ";
                course.setPrerequisiteCourse(clsInputValidate::ReadString());

            }

            break;

        }

        if(course.AddNewCourse()) {
            cout<<"Course Added Successfully....";
        }else {
            cout<<"Course Added Failed....";
        }

    }
    public:
    static void Show() {
        system("cls");
        Screen::DrawScreen("Add New Course Screen");

        AddNewCourse();
        system("pause>0");
    }
};
#endif //ADDNEWCOURSESCREEN_H
