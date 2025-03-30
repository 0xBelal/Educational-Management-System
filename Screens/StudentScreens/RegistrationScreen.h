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
        std::cout << std::string(83, '_') << std::endl;
        std::cout << std::left << std::setw(11) << "Course Code"
                  << " | " << std::setw(26) << "Course Name"
                  << " | " << std::setw(10) << "Credit Hour"
                  << " | " << std::setw(10) << "Max Mark"
                  << " | " << std::setw(30) << "Prerequisites"
                  << std::endl;
        std::cout << std::string(83, '_') << std::endl;
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
        std::vector<Course> vEnrolledCourses = LoginStudent.getStudentCourses();
        std::vector<Course> vCompleteCourses = LoginStudent.getCompletedCourses();

        std::cout << "\n\n";
        PrintHeader();
        for (Course &x : vAllCourses) {
            auto it = find(vEnrolledCourses.begin(),vEnrolledCourses.end(),x);
            auto it2 = find(vCompleteCourses.begin(),vCompleteCourses.end(),x);
            if(it == vEnrolledCourses.end() && it2 == vCompleteCourses.end())
                PrintCourse(x);
        }
        std::cout << std::string(83, '_') << std::endl;
    }

public:
    static void Show() {
        Screen::DrawScreen("\t   Registration Screen");
        PrintAllCourses();
        string code;


        cout<<"\nEnter Course Code to Register: ";  cin>>code;
        if(!Course::isCourse(code)) {
            cout<<"Invalid course code ... ";
           // return ;
        }else {
            std::vector<Course> vEnrolledCourses = LoginStudent.getEnrolledCourses();

            if(find(vEnrolledCourses.begin(),vEnrolledCourses.end(),code) == vEnrolledCourses.end()) {
                if(LoginStudent.registerCourse(code)) cout<<"Course "<< code <<" registered successfully!"<<endl;
                else cout<<"You must register for the prerequisite courses before enrolling in this course";
            }
            else cout<<"error in registration....."<<endl;
        }
        system("pause>0");
    }
};

#endif // REGISTRATIONSCREEN_H
