//
// Created by Belal on 25-Feb-25.
//

#ifndef SUBADMIN_H
#define SUBADMIN_H

#include <iostream>
#include <vector>
#include "../Core/Admin.h"
#include "../Global/Global.h"
#include "Admin.h"
#include "Course.h"
#include "Student.h"

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
    void Assigin(SubAdmin &SAdmin) {
        setID(SAdmin.getID());
        setFullName(SAdmin.getFullName());
        setNationalID(SAdmin.getNationalID());
        setPassword(SAdmin.getPassword());
        SAdmin.setFacultyName(SAdmin.getFacultyName());

    }
    bool isSubAdmin() {
        vector<SubAdmin> AllAdmin = GetAllSubAdmins();

        for(SubAdmin &sAdmin : AllAdmin) {
            if(getNationalID() == sAdmin.getNationalID() && getPassword() == sAdmin.getPassword()){
                this->Assigin(sAdmin);
                return true;
            }

            return false;
        }
    }
    bool AddNewAdmin(){

            fstream file(AllAdmin_File, ios::app | ios::out);
            fstream AllUsers_file(AllUsers.c_str(),ios::out | ios::app);

            if (file.is_open()) {
                this->setID(to_string(GenerateID()));
                file << this->ConvertAdminObjectToRecord()<<endl;
            } else {
                return false;
            }
            file.close();

        if(AllUsers_file.is_open()) {
            AllUsers_file <<this->UserInfoRecord("subAdmin")<<endl;
            AllUsers_file.close();
        }else return false;
            return true;
    }

    bool setStudentCourseMark(const Student &student) {

    }
};
#endif //SUBADMIN_H
