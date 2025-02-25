//
// Created by Belal on 25-Feb-25.
//

#ifndef SUBADMIN_H
#define SUBADMIN_H

#include <iostream>
#include "../Global/Global.h"
#include "Admin.h"

using namespace std;

class SubAdmin: public Admin {

    private:
    string FacultyName;

    static vector<SubAdmin> _LoadAdminData(const string &FileName) {
        fstream file(FileName.c_str(), ios::in);
        vector<string> Info;
        vector<SubAdmin> vSubAdmins;
       // SubAdmin SAdmin;
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Info = clsString::Split(line, Separator);
                SubAdmin SAdmin (Info[0], Info[1], Info[2], Info[3], Info[4]);
                vSubAdmins.push_back(SAdmin);
            }
            file.close();
        }

        return vSubAdmins;
    }

    string ConvertAdminObjectToRecord() {
       return (getID() + Separator + getFullName() + Separator + getNationalID() + Separator + getPassword() + Separator +getFacultyName());
    }


public:

    SubAdmin(){}
    SubAdmin(const string &ID ,const string &FullName ,const string &NID,const string &Password , const string &FacultyName):
    Admin(ID,FullName,NID,Password) {
        this->FacultyName = FacultyName;
    }
    string getFacultyName()const{ return this->FacultyName; }
    void setFacultyName(const string &FacultyName){ this->FacultyName = FacultyName; }

    static vector<SubAdmin> GetAllSubAdmins() {
        return _LoadAdminData(AllAdmin_File);
    }

    bool AddNewAdmin() {

        fstream file(AllAdmin_File, ios::app | ios::out);
        if (file.is_open()) {
            file << this->ConvertAdminObjectToRecord()<<endl;
        } else {
            return false;
        }
        file.close();

        return true;
    }

};
#endif //SUBADMIN_H
