//
// Created by Belal on 25-Feb-25.
//

#ifndef GLOBAL_H
#define GLOBAL_H

#include <fstream>
#include <iostream>


using namespace std;

const string Separator = " <-> ";
const string Admin_File = "E:\\Computer Science\\Projects\\Educational Management System\\DataSource\\Admin.txt";
const string ComputerScience = "E:\\Computer Science\\Projects\\Educational Management System\\DataSource\\ComputerScience\\";
const string AllAdmin_File = "E:\\Computer Science\\Projects\\Educational Management System\\DataSource\\AllAdmin.txt";


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

const string StudentCourses = "E:\\Computer Science\\Projects\\Educational Management System\\DataSource\\Students\\Details\\Courses";
const string StudentInfo    = "E:\\Computer Science\\Projects\\Educational Management System\\DataSource\\Students\\S";
const string AllStudent     = "E:\\Computer Science\\Projects\\Educational Management System\\DataSource\\Students\\All.txt";

#endif // GLOBAL_H
