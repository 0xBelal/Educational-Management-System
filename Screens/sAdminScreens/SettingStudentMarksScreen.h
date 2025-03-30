//
// Created by Belal on 13-Mar-25.
//

#ifndef SETTINGSTUDENTMARKSSCREEN_H
#define SETTINGSTUDENTMARKSSCREEN_H

#include <iostream>

#include "AllStudentsScreen.h"
#include "../Screen.h"
#include "../../Global/LoginUser.h"
#include "../../Screens/StudentScreens/RegistredCoursesScreen.h"
using namespace   std;

class SettingStudentMarksScreen: public Screen {

private:



public:

static void Show() {
        system("cls");
        Screen::DrawScreen("\tSetting Student Marks Screen");

        cout<<endl;
        cout<<"<All Students>\n";
        AllStudentsScreen::Show();

        cout<<endl;
        Student student;
    do {
        cout<<"Enter a student ID : ";
        student.setID(clsInputValidate::ReadString());
        student.getStudentByID();

        if(student.isEmpty()) {
            cout<<"Invalid ID!"<<endl;
        }else break;
    }while (true);
            system("cls");
            //LoginStudent = student;
            PrintStudentInfo(student);

             PrintRegistredCourses(student);

            cout<<"Enter Course Code : ";
            string code = clsInputValidate::ReadString();
            fstream courseFile;
            courseFile.open((StudentCourses+student.getID()+".txt").c_str(), ios::out);

            bool flag = false;

            fstream studentFile;
            studentFile.open((StudentInfo+student.getID()+".txt").c_str(),ios::app);

            if(courseFile.is_open() && studentFile.is_open()) {
                for(Course &course : student.getEnrolledCourses()) {

                    if(course.getCourseCode() != code) {
                        courseFile << course.ConvertToStudentCourseObjToRecord()<<endl;
                    }else {
                        flag =true;
                        cout<<"Student Mark [0 to 100] : ";
                        course.setStudentMark(clsInputValidate::ReadIntNumberBetween(0,100));

                        studentFile << course.ConvertToStudentCourseObjToRecord()<<endl;


                    }

                }
                studentFile.close();
                courseFile.close();
            }

            if (flag) {
                cout<<"\nCourse Mark setting successufully....\n";

                student.calculateGPA();
                student.updateStudentInfoFile();
                student.updateAllStudentsInfoFile();


            }else cout<<"Error,Invalid Course Code!"<<endl;

     system("pause>0");
    }



};
#endif //SETTINGSTUDENTMARKSSCREEN_H
