//
// Created by Belal on 05-Mar-25.
//

#ifndef REGISTRATIONSCREEN_H
#define REGISTRATIONSCREEN_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "../Screen.h"
#include "../../Core/Course.h"

class RegistrationScreen : public Screen {
private:
    static void PrintHeader() {
        std::cout << std::setw(10) << "cCode"
                  << " | " << std::setw(15) << "Course Name"
                  << " | " << std::setw(10) << "Credit H"
                  << " | " << std::setw(10) << "Max Mark"
                  << " | " << std::setw(20) << "Prerequisites"
                  << std::endl;
    }

    static void PrintCourse(const Course &course) {
        std::cout << std::setw(10) << course.getCourseCode()
                  << " | " << std::setw(15) << course.getName()
                  << " | " << std::setw(10) << course.getCreditHours()
                  << " | " << std::setw(10) << course.getMaxMark()
                  << " | ";

        std::string prerequisites;
        for (const std::string &x : course.getPrerequisitesCourses()) {
            prerequisites += x + " ";
        }

        std::cout << std::setw(20) << prerequisites << std::endl;
    }

    static void PrintAllCourses() {
        std::vector<Course> vAllCourses = Course::GetAllCourses();

        std::cout << "\n\n";
        PrintHeader();
        for (Course &x : vAllCourses) {
            PrintCourse(x);
        }
    }

public:
    static void Show() {
        Screen::DrawScreen("Registration Screen");
        PrintAllCourses();
        system("pause>0");
    }
};

#endif // REGISTRATIONSCREEN_H
