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
#include "../../Global/LoginUser.h"

class RegistrationScreen : public Screen {
private:
    static void PrintHeader() {
        std::cout << std::left << std::setw(11) << "Course Code"
                  << " | " << std::setw(26) << "Course Name"
                  << " | " << std::setw(10) << "Credit Hour"
                  << " | " << std::setw(10) << "Max Mark"
                  << " | " << std::setw(30) << "Prerequisites"
                  << std::endl;
        std::cout << std::string(81, '_') << std::endl;
    }

    static void PrintCourse(const Course &course) {
        std::cout << std::left << std::setw(11) << course.getCourseCode()
                  << " | " << std::setw(26) << course.getName()
                  << " | " << std::setw(10) << course.getCreditHours()
                  << " | " << std::setw(10)  << course.getMaxMark()
                  << " | ";

        std::vector<std::string> prerequisites = course.getPrerequisitesCourses();
        if (!prerequisites.empty()) {
            for (size_t i = 0; i < prerequisites.size(); i++) {
                std::cout << prerequisites[i];
                if (i != prerequisites.size() - 1) std::cout << " ";
            }
        }

        std::cout << std::endl;
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
        string code;
        cout<<"\nEnter a code : ";  cin>>code;

        if(LoginStudent.registerCourse(code)) cout<<"successfully registration...."<<endl;
        else cout<<"error in registration....."<<endl;

        system("pause>0");
    }
};

#endif // REGISTRATIONSCREEN_H
