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
using namespace std;

// Enum for Screen Types
enum eScreens { eAdmin = 1, eFacultyAdmin, eStudent, eProfessor };

class LoginScreen : public Screen {
private:
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
public:
    // Static Method to Show Login Screen
    static void show() {
        system("cls");
        cout << "\n1. Admin   2. Faculty Admin   3. Student    4. Professor\n";
        switch (short ANS = clsInputValidate::ReadShortNumberBetween(1, 4)) {
            case eScreens::eAdmin:
               // Screen::DrawScreen("Admin Login");
                   AdminLoginScreen();
                   AdminMainScreen::Show();
            break;
            case eScreens::eFacultyAdmin:
                Screen::DrawScreen("Faculty Admin Login");
            break;
            case eScreens::eStudent:
                Screen::DrawScreen("Student Login");
            break;
            case eScreens::eProfessor:
                Screen::DrawScreen("Prof Login");
            break;
            default:
                cout << "Invalid Option. Please try again.\n";
            break;
        }
    }
};


#endif //LOGINSCREEN_H
