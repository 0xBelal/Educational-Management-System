//
// Created by Belal on 25-Feb-25.
//

#ifndef GLOBAL_H
#define GLOBAL_H

#include<iostream>
#include "../Core/Admin.h"
#include <fstream>
using namespace std;

#include <bits/stdc++.h>
#include "../Core/Admin.h"
using namespace std;
// ID <-> Full Name <-> National ID <-> Password
const string Separator = " <-> ";
const string Admin_File = "E:\\Computer Science\\Projects\\Educational Management System\\DataSource\\Admin.txt";
const string ComputerScience = "E:\\Computer Science\\Projects\\Educational Management Sys\\DataSource\\ComputerScience\\";
const string AllAdmin_File = "E:\\Computer Science\\Projects\\Educational Management System\\DataSource\\AllAdmin.txt";

int GenerateID() {
      fstream file("E:\\Computer Science\\Projects\\Educational Management System\\Global\\ID.txt",ios::in | ios::out);
        string line;
        int ID;
        if(file.is_open()) {
            while(getline(file,line)) {
                ID = stoi(line);
                cout<<to_string(ID+1);
            }
            file.close();
        }
    return ID;
}
#endif //GLOBAL_H
