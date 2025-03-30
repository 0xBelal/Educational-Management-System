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
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Info = clsString::Split(line, Separator);

                vSubAdmins.push_back(convertVectorToSubAdmin(Info));
            }
            file.close();
        }

        return vSubAdmins;
    }

    string ConvertAdminObjectToRecord() {
       return (getID() + Separator + getFullName() + Separator + getNationalID() + Separator + getPassword() + Separator +getFacultyName());
    }

    static SubAdmin convertVectorToSubAdmin(const vector<string> &vSubAdmins) {
        SubAdmin SAdmin;
        SAdmin.setID(vSubAdmins[0]);
        SAdmin.setFullName(vSubAdmins[1]);
        SAdmin.setNationalID(vSubAdmins[2]);
        SAdmin.setPassword(vSubAdmins[3]);
        SAdmin.setFacultyName(vSubAdmins[4]);
        return SAdmin;
    }
public:

    SubAdmin() {
        setID("");
    }
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
    static SubAdmin findByID(string ID) {
        vector<SubAdmin> AllAdmin = GetAllSubAdmins();
        for(SubAdmin &sAdmin : AllAdmin) {
            if(sAdmin.getID() == ID) return sAdmin;
        }
        return SubAdmin();
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
            AllUsers_file <<this->userInfoRecord("subAdmin")<<endl;
            AllUsers_file.close();
        }else return false;
            return true;
    }

    bool deleteAdmin() {
        vector<SubAdmin> allAdmins = _LoadAdminData(AllAdmin_File);
        fstream allAdminFile (AllAdmin_File, ios::out);
        if(allAdminFile.is_open()) {
            for(SubAdmin &sAdmin : allAdmins) {
                if(sAdmin.getID() != this->getID()) {
                    allAdminFile << sAdmin.ConvertAdminObjectToRecord()<<endl;
                }
            }

            allAdminFile.close();
            return true;
        }
        return false;
    }
    bool setStudentCourseMark(const Student &student) {

    }
};
#endif //SUBADMIN_H
