//
// Created by Belal on 05-Mar-25.
//

#ifndef REGISTERETIONSCREEN_H
#define REGISTERETIONSCREEN_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "../Screen.h"
#include "../../Core/Course.h"


class RegisteretionScreen : public Screen{

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
              << " | " << std::setw(20) ;

            if(course.getPrerequisitesCourses().size() > 0) {

                for(string x : course.getPrerequisitesCourses()) {
                    cout<< x<<" ";
                }
            }
            cout<< std::endl;
    }
    static void PrintAllCourses() {
        vector<Course> vAllCourses = Course::GetAllCourses();

        cout <<"\n\n";
        PrintHeader();
        for(Course &x : vAllCourses) PrintCourse(x);
    }
public:

    static void Show() {
        Screen::DrawScreen("Registeretion Screen");
        PrintAllCourses();
        system("pause>0");
    }
};



#endif //REGISTERETIONSCREEN_H
