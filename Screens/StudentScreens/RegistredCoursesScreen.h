//
// Created by Belal on 13-Mar-25.
//

#ifndef REGISTREDCOURSES_H
#define REGISTREDCOURSES_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "../Screen.h"
#include "../../Core/Course.h"
#include "../../Global/LoginUser.h"

class RegistredCoursesScreen: public Screen {

private:

    static void PrintHeader() {
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


    static void PrintRegistredCourses() {
        std::vector<Course> vEnrolledCourses = LoginStudent.getEnrolledCourses();
// CS102 <-> Programming 2 <-> 3 <-> 0.000000 <-> CS101

        std::cout << "\n\n";
        PrintHeader();
        int TotalHoures = 0, TotalCourses = 0;
        for (Course &x : vEnrolledCourses) {
                TotalCourses++;
                TotalHoures+=x.getCreditHours();
                PrintCourse(x);
        }

        std::cout << std::string(70, '_') << std::endl;
        cout<<"Total Courses: "<<TotalCourses<<"             Total Hours: "<<TotalHoures<<endl;
        std::cout << std::string(70, '_') << std::endl;


    }

public:
    static void Show() {
        system("cls");
        Screen::DrawScreen("Registred Courses Screen");

        PrintRegistredCourses();

        system("pause>0");
    }
};
#endif //REGISTREDCOURSES_H
