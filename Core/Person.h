//
// Created by Belal on 25-Feb-25.
//

#ifndef PERSON_H
#define PERSON_H


#include <string>
class Person {
private:
    string ID;
    string FullName;
    string Password;
    string NationalID;

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

    void setFullName(string FullName) { this->FullName = FullName; }
    void setPassword(string Password) { this->Password = Password; }
    void setNationalID(string NationalID) { this->NationalID = NationalID; }
    void setID(string ID) { this->ID = ID; }
};



#endif //PERSON_H
