#ifndef ADMIN_H
#define ADMIN_H


#include <iostream>
#include <fstream>
#include <vector>       // Include vector header
#include <string>       // Include string header
#include "../Core/Person.h"

#include "../Global/Global.h"    // circular dependency

#include "../lib/clsString.h"  // Assuming clsString is here

using namespace std;


class Admin : public Person {

private:
    // LoadAdminData function to load admin data from a file
    Admin LoadAdminData(const string &FileName) {
        fstream file(FileName.c_str(), ios::in);
        vector<string> Info;
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Info = clsString::Split(line, Separator);
            }
            file.close();
        }
        Admin admin(Info[0], Info[1], Info[2], Info[3]);
        return admin;
    }



public:
    // Default constructor calling base class default constructor
    Admin() : Person() {}

    // Parameterized constructor calling base class constructor
   // 100 <-> Admin <-> 30410201203234 <-> Admin
    Admin(const string& ID, const string& FullName,  const string& NationalID, const string& Password)
        : Person(ID, FullName, Password,NationalID) {
       // this->setNationalID(NationalID);
    }

    // Method to check if user is admin
    bool isAdmin() {
        Admin CorrectAdmin = LoadAdminData(Admin_File);
        return getNationalID() == CorrectAdmin.getNationalID() && getPassword() == CorrectAdmin.getPassword();
    }
};

#endif //ADMIN_H
