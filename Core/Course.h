#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <vector>
#include <fstream>
//#include "Student.h"
#include "../Global/Global.h"

using namespace std;

class Course {
private:
    string courseCode;
    string name;
    int creditHours;
    double studentMark;
    double maxMark;
    vector<string> PrerequisitesCourses;

    string ConvertCourseObjToRecord() {
        string line = (getCourseCode() + Separator + getName() + Separator + to_string(getCreditHours()) +
                       Separator + to_string(getMaxMark()));
        line += ConvertPrerequisiteCourseObjToRecord();
        return line;
    }

    string ConvertPrerequisiteCourseObjToRecord() {
        string pre = "";
        for (const string &x : PrerequisitesCourses) {
            pre += Separator + x;
        }
        return pre;
    }

    static vector<Course> LoadAllCourses()  {
        fstream courseFile(AllCourses.c_str(),ios::in);
        string line;
        vector<string> vCourse;
        vector<Course> vAllCourses;
        Course course;
        if (courseFile.is_open()) {

            while(getline(courseFile,line)) {
                // BS100 <-> Mathemathematics 1 <-> 3 <-> 100 <-> BS000

                vCourse = clsString::Split(line,Separator);
                course.setCourseCode(vCourse[0]);
                course.setName(vCourse[1]);
                course.setCreditHours(stoi(vCourse[2]));
                course.setMaxMark(stoi(vCourse[3]));
                for(int i=4;i<vCourse.size();i++) {
                    course.addPrerequisiteCourse(vCourse[i]);
                }
                vAllCourses.push_back(course);
            }
            courseFile.close();

        }else {
            cout<<"Course file not found"<<endl;
        }
        return vAllCourses;
    }

public:
    Course() : studentMark(0), maxMark(100) {}

    Course(const string &cCode, const string &cName, int cHours, double sMark, double mMark = 100)
        : courseCode(cCode), name(cName), creditHours(cHours), studentMark(0), maxMark(mMark) {
        setMark(sMark);
    }

    // Setter methods
    void setMark(double m) {
        if (m >= 0 && m <= maxMark) {
            studentMark = m;
        } else {
            cout << "Invalid mark! Should be between 0 and " << maxMark << endl;
        }
    }

    void setCourseCode(const string &cCourseCode) { courseCode = cCourseCode; }
    void setName(const string &cName) { name = cName; }
    void setCreditHours(int cHours) { creditHours = cHours; }
    void setStudentMark(double m) { setMark(m); } // Calls setMark for validation
    void setMaxMark(double m) { maxMark = m; } // Set max mark dynamically
    void addPrerequisiteCourse(const string &cCourse) { PrerequisitesCourses.push_back(cCourse); }

    // Getter methods
    string getCourseCode() const { return courseCode; }
    string getName() const { return name; }
    int getCreditHours() const { return creditHours; }
    double getStudentMark() const { return studentMark; }
    double getMaxMark() const { return maxMark; }
    const vector<string> &getPrerequisitesCourses() const { return PrerequisitesCourses; }

    bool AddNewCourse() {
        fstream file_allCourses(AllCourses.c_str(), ios::app);
        fstream file_courseInfo((CoursesInfo + getCourseCode()).c_str(), ios::out);

        if (!file_allCourses.is_open()) {
            cerr << "Error: Unable to open file " << AllCourses << endl;
            return false;
        }

        file_allCourses << ConvertCourseObjToRecord() << endl;
        file_allCourses.close();

        if (!file_courseInfo.is_open()) {
            cerr << "Error: Unable to open file " << CoursesInfo + getCourseCode() << endl;
            return false;
        }

        file_courseInfo << getCourseCode() << " " << Separator << " " << getName()
                        << ConvertPrerequisiteCourseObjToRecord() << endl;
        file_courseInfo.close();

        return true;
    }

    static vector<Course> GetAllCourses(){ return LoadAllCourses();}

    void displayCourseInfo() const {
        cout << "Course Code: " << courseCode << endl;
        cout << "Name: " << name << endl;
        cout << "Credit Hours: " << creditHours << endl;
        cout << "Max Mark: " << maxMark << endl;
        cout << "Current Mark: " << studentMark << endl;
        cout << "Prerequisite Courses: ";
        if (PrerequisitesCourses.empty()) {
            cout << "None";
        } else {
            for (const string &course : PrerequisitesCourses) {
                cout << course << " ";
            }
        }
        cout << endl;
    }
};

#endif // COURSE_H
