//
// Created by Belal on 03-Mar-25.
//

#ifndef ADDNEWCOURSESCREEN_H
#define ADDNEWCOURSESCREEN_H

#include <iostream>
#include <string>
#include "..\..\Screens\Screen.h"
#include "..\..\Core\Course.h"
#include "..\..\lib\clsInputValidate.h"
using namespace std;

class AddNewCourseScreen : public Screen {

private:


     static void AddNewCourse() {
        Course course;
        cout<<Space<<"Course Code   : ";
        course.setCourseCode(clsInputValidate::ReadString());
        cout<<Space<<"Course Name   : ";
        course.setName(clsInputValidate::ReadString());
        cout<<Space<<"Credits Hours : ";
        course.setCreditHours(clsInputValidate::ReadIntNumberBetween(0,3));
        cout<<Space<<"Are there Prerequisites ? y/n ? ";
        char ANS; ANS = clsInputValidate::ReadYes_Or_No_Q();

        switch (ANS) {
            case 'Y':
                int NoOfCourses;
                cout<<Space<<"The number of courses required : "; NoOfCourses = clsInputValidate::ReadIntNumberBetween(1,10);

            for(int i=0;i<NoOfCourses;i++) {

                cout<<Space<<i+1<<") Course Code : ";
                course.addPrerequisiteCourse(clsInputValidate::ReadString());

            }

            break;

        }

        if(course.addNewCourse()) {
            cout<<"\n"<<Space<<"Course Added Successfully....";
        }else {
            cout<<"\n"<<Space<<"Course Added Failed....";
        }

    }
    public:
    static void Show() {
        system("cls");
        Screen::DrawScreen("\t  Add New Course Screen");

        AddNewCourse();
        system("pause>0");
    }
};
#endif //ADDNEWCOURSESCREEN_H
