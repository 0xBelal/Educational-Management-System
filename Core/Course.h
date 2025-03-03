//
// Created by Belal on 03-Mar-25.
//

#ifndef COURSE_H
#define COURSE_H



#include <iostream>
#include <vector>
#include "Student.h"
#include  "../Global/Global.h"
#include "../Global/Global.h"
using namespace std;

class Course {
private:

    string courseCode;
    string name;
    int creditHours;
    double studentMark;
    vector<string> PrerequisitesCourses;

    string ConvertCourseObjToRecord() {

        string line = (getCourseCode() + Separator + getName()+ Separator + to_string(getCreditHours()) +
            Separator + to_string(getStudentMark()) );

        line += ConvertPrerequisiteCourseObjToRecord();

        return line;
    }
    string ConvertPrerequisiteCourseObjToRecord() { // <-> CS100
        string pre="";
        for(string &x:PrerequisitesCourses) {
            pre += Separator + x;
        }
        return pre;
    }

public:

    Course(){}
    Course(const string &cCode,const string &cName,const  int &cHours, const double &sMark)
        : courseCode(cCode), name(cName), creditHours(cHours), studentMark(sMark) {

        setMark(studentMark);

    }

    void setMark(double m) {
        if (m >= 0 && m <= 100) {
            studentMark = m;
        } else {
            cout << "Invalid mark! Should be between 0 and " << 100 << endl;
        }
    }
    void setCourseCode(const string &cCourseCode) {  courseCode = cCourseCode; }
    void setName(const string &cName) {  name = cName; }
    void setCreditHours(const int &cHours) { creditHours = cHours; }
    void setStudentMark(const double &m) {
        if (m >= 0 && m <= 100) {
        studentMark = m;
        } else {
            cout << "Invalid mark! Should be between 0 and " << 100 << endl;
        }
    }
    void setPrerequisiteCourse(const string &cCourse) {
        PrerequisitesCourses.push_back(cCourse);
    }

    string getCourseCode() const {  return courseCode; }
    string getName() const {  return name; }
    int getCreditHours() const {  return creditHours; }
    double getStudentMark() const {  return studentMark; }
    vector<string> getPrerequisitesCourses() const {  return PrerequisitesCourses;  }

    bool AddNewCourse() {

        fstream file_allCourses (AllCourses.c_str(),ios::app);
        fstream file_courseInfo ((CoursesInfo + getCourseCode()).c_str() , ios::out);

        if(file_allCourses.is_open()) {

            file_allCourses<<ConvertCourseObjToRecord()<<endl;
            file_allCourses.close();

            if(file_courseInfo.is_open()) {

                file_courseInfo << getCourseCode()<<" " << Separator << " "<<getName()<<ConvertPrerequisiteCourseObjToRecord()<<endl;
                file_courseInfo.close();

            }
        }else return false;

        return true;
    }

    /*void displayCourseInfo() const {
        cout << "Course Code: " << courseCode << endl;
        cout << "Name: " << name << endl;
        cout << "Credit Hours: " << creditHours << endl;
        cout << "Max Mark: " << maxMark << endl;
        cout << "Current Mark: " << mark << endl;
        getPrerequisites(); // Show prerequisite courses
    }*/
};


#endif //COURSE_H
