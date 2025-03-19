//
// Created by Belal on 15-Mar-25.
//

#ifndef STUDENTREPORTSCREEN_H
#define STUDENTREPORTSCREEN_H

#include <iostream>

#include "../Screen.h"
#include "../../Core/Student.h"
#include "../../Global/LoginUser.h"
#include "../../lib/clsInputValidate.h"
using namespace  std;

class StudentReportScreen : public Screen {

private:

    static void PrintHeader() {
        std::cout << std::string(70, '_') << std::endl;

        std::cout << std::left << std::setw(11) << "Course Code"
                  << " | " << std::setw(26) << "Course Name"
                  << " | " << std::setw(10) << "Credit Hour"
                  << " | " << std::setw(10) << "Student Mark"

                  << std::endl;

        std::cout << std::string(70, '_') << std::endl;
    }

    static void PrintCourse(const Course &course) {
        std::cout << std::left << std::setw(11) << course.getCourseCode()
                  << " | " << std::setw(26) << course.getName()
                  << " | " << std::setw(10) << course.getCreditHours()
                  << " | " << std::setw(10)  << course.getStudentMark();

        /*std::vector<std::string> prerequisites = course.getPrerequisitesCourses();
        if (!prerequisites.empty()) {
            for (size_t i = 0; i < prerequisites.size(); i++) {
                std::cout << prerequisites[i];
                if (i != prerequisites.size() - 1) std::cout << " ";
            }
        }*/

        std::cout << std::endl;
    }


    static void PrintCourses(Student &student) {
        std::vector<Course> vCourses = student.getCompletedCourses();

        PrintHeader();
        int TotalHoures = 0, TotalCourses = 0;
        for (Course &x : vCourses) {
            TotalCourses++;
            TotalHoures+=x.getCreditHours();
            PrintCourse(x);
        }

        std::cout << std::string(70, '_') << std::endl;
        /*cout<<"Total Courses: "<<TotalCourses<<"                  Total Hours: "<<TotalHoures<<endl;
        std::cout << std::string(70, '_') << std::endl;*/


    }


public:
int x;
    static void Show() {
        system("cls");
        Screen::DrawScreen("\t  Student Report Screen");
        AllStudentsScreen::Show();
        Student student;
        do {
            cout<<"Enter student id : "; student.setID(clsInputValidate::ReadString());
            if(!student.getStudentByID().isEmpty()) {
                break;
            }
            cout<<"Invalid id"<<std::endl;
        } while (true);

        PrintStudentInfo(student);
        PrintCourses(student);

        system("pause>0");
        return;
    }

    static void Show(Student student) {
        system("cls");
        Screen::DrawScreen("\t Student Report Screen");

        PrintStudentInfo(student);
        PrintCourses(student);

        system("pause>0");
    }

};
#endif //STUDENTREPORTSCREEN_H
