//
// Created by Belal on 25-Feb-25.
//

#ifndef PERSON_H
#define PERSON_H


#include <string>
#include "../Global/Global.h"
class Person {
private:
    string ID;
    string FullName;
    string Password;
    string NationalID;
    string type;

public:
    // Default constructor - Needs definition
    Person() : ID(""), FullName(""), Password(""), NationalID("") {}

    // Parameterized constructor
    Person(string ID, string FullName, string Password,const string& NID)
        : ID(ID), FullName(FullName), Password(Password),NationalID(NID) {}

    string getFullName() const { return FullName; }
    string getNationalID() const { return NationalID; }
    string getID() const { return ID; }
    string getPassword() const { return Password; }
    string getType() const { return type; }

    void setFullName(string FullName) { this->FullName = FullName; }
    void setPassword(string Password) { this->Password = Password; }
    void setNationalID(string NationalID) { this->NationalID = NationalID; }
    void setID(string ID) { this->ID = ID; }
    void setType(string t) { this->type = t; }

     string userInfoRecord(const string &type) {

           return getID() + Separator  + getNationalID() +  Separator + getPassword()
            +  Separator + type;
    }
    static vector<Person> getAllUsers() {
        fstream file;
        file.open(AllUsers.c_str(), ios::in);
        vector<Person> persons;
        string line = "";
        if (file.is_open()) {
            Person person;
            while( getline(file,line) ) {
                vector<string> vRecord = clsString::Split(line,Separator);

                person.setID(vRecord[0]);
                person.setNationalID(vRecord[1]);
                person.setPassword(vRecord[2]);
                person.setType(vRecord[3]);

                persons.push_back(person);
            }
            file.close();
        }
        return persons;
    }
};



#endif //PERSON_H
