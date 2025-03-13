//
// Created by Belal on 25-Feb-25.
//

#ifndef GLOBAL_H
#define GLOBAL_H

#include <fstream>
#include <iostream>
#include <filesystem>



using namespace std;
namespace fs = std::filesystem;



int GenerateID() {
    fstream oFile("E:\\Computer Science\\Projects\\Educational Management System\\Global\\ID.txt", ios::in | ios::out);
    string line;
    int ID = 0;  // Initialize to prevent uninitialized variable issues
    if (oFile.is_open()) {
        while (getline(oFile, line)) {
            ID = stoi(line);
        }
        oFile.close();
    }

    oFile.open("E:\\Computer Science\\Projects\\Educational Management System\\Global\\ID.txt", ios::out);
    if (oFile.is_open()) {
        oFile << to_string(ID + 1);
        oFile.close();
    }

    return ID;
}

const string Separator = " <-> ";
const string Admin_File = R"(..\DataSource\Admin.txt)";
//const string ComputerScience = "E:\\Computer Science\\Projects\\Educational Management System\\DataSource\\ComputerScience\\";
const string AllAdmin_File = R"(..\DataSource\AllAdmin.txt)";

const string StudentCourses = R"(..\DataSource\Students\Details\StudentsInfo\Courses_)";
const string StudentInfo    = R"(..\DataSource\Students\Details\StudentsInfo\Student_)";
const string AllStudent     =  R"(..\DataSource\Students\All.txt)";
const string AllCourses     = R"(..\DataSource\Students\Details\Courses\AllCourses)";
const string CoursesInfo    = R"(..\DataSource\Students\Details\Courses\)";
//const string AllStudent_File = R"(..\DataSource\Students\All.txt)";

#endif // GLOBAL_H
