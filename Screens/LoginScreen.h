//
// Created by Belal on 25-Feb-25.
//

#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H



#include <iostream>
#include "Screen.h"
#include "../lib/clsInputValidate.h"
#include "../Core/Admin.h"
#include "../Screens/AdminScreens/AdminMainScreen.h"
#include "../Core/SubAdmin.h"
#include "../Screens/sAdminScreens/sAdminMainScreen.h"
#include "../Core/Student.h"
#include "../Core/Person.h"
#include "../Global/LoginUser.h"
#include "../Screens/StudentScreens/StudentMainScreen.h"
using namespace std;

// Enum for Screen Types
enum eScreens { eAdmin = 1 , eFacultyAdmin = 2, eStudent=3, eProfessor=4,eInvalid = 5};

class LoginScreen : public Screen {
private:

    static eScreens Login(const Person &p) {

        vector<Person> vPersons = Person::getAllUsers();

        for(Person temp : vPersons) {
            if(temp.getNationalID() == p.getNationalID() && p.getPassword() == temp.getPassword()) {

                if(temp.getType() == "student") {
                    LoginStudent.setID(temp.getID());
                    LoginStudent.getStudentByID();
                    return eStudent;
                }
                else if(temp.getType() == "professor") return eProfessor;
                else if(temp.getType() == "admin") return eAdmin;
                else if(temp.getType() == "subAdmin") return eFacultyAdmin;
            }
        }

        return eScreens::eInvalid;
    }

    static void AdminLoginScreen() {
        system("cls");
        Screen::DrawScreen("Admin Login");
        Admin admin;
        cout<<"National ID : ";
        admin.setNationalID(clsInputValidate::ReadString());
        cout<<"Password    : ";
        admin.setPassword(clsInputValidate::ReadString());
        if(!admin.isAdmin()) {
            cout<<"Admin login failed...\n";
            system("pause>0");
            AdminLoginScreen();
        }
    }



    static void sAdminLoginScreen() {
        system("cls");
        Screen::DrawScreen("sub-Admin Login");
        SubAdmin sAdmin;
        cout<<"National ID : ";
        sAdmin.setNationalID(clsInputValidate::ReadString());
        cout<<"Password    : ";
        sAdmin.setPassword(clsInputValidate::ReadString());
        if(!sAdmin.isSubAdmin()) {
            cout<<"sub-Admin login failed...\n";
            system("pause>0");
            sAdminLoginScreen();
        }

    }

    static void StudentLoginScreen() {
        system("cls");
        Screen::DrawScreen("Student Login");

        cout<<"National ID : ";
        LoginStudent.setNationalID(clsInputValidate::ReadString());
        cout<<"Password    : ";
        LoginStudent.setPassword(clsInputValidate::ReadPassword());
        if(!LoginStudent.isStudent()) {
            cout<<"Student login failed...\n";
            system("pause>0");
            StudentLoginScreen();
        }
        

    }


public:
    // Static Method to Show Login Screen
    static void show() {
        system("cls");
        //cout << "\n1. Admin   2. Faculty Admin   3. Student    4. Professor\n";

        Screen::DrawScreen("\t    Login Screen");
        Person p;

            cout<<endl<<Space<<"National ID : ";
            p.setNationalID(clsInputValidate::ReadString());
            cout<<Space<<"Password    : ";
            p.setPassword(clsInputValidate::ReadPassword());

            switch (Login(p)) {
                case eScreens::eAdmin:
                    // Screen::DrawScreen("Admin Login");
                     //   AdminLoginScreen();
                AdminMainScreen::Show();

                break;
                case eScreens::eFacultyAdmin:
                    //  Screen::DrawScreen("Faculty Admin Login");
                     //   sAdminLoginScreen();
                sAdminMainScreen::Show();
                break;
                case eScreens::eStudent:
                    // Screen::DrawScreen("Student Login");
                     //   StudentLoginScreen();
                StudentMainScreen::Show();
                break;
                case eScreens::eProfessor:
                    Screen::DrawScreen("Prof Login");
                break;
                case eScreens::eInvalid:
                    cout<<Space<<"faild login....\n";
                    system("pause>0");
                    show();
                    break;
                default:
                    cout << "Invalid Option. Please try again.\n";
                break;
            }

    }
};


#endif //LOGINSCREEN_H
