cmake_minimum_required(VERSION 3.29)
project(Educational_Management_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(Educational_Management_System main.cpp
        Core/Person.h
        Core/Admin.h
        Screens/Screen.h
        Screens/LoginScreen.h
        lib/clsInputValidate.h
        lib/clsDate.h
        lib/clsString.h
        Global/Global.h
        Screens/AdminScreens/AdminMainScreen.h
        Core/SubAdmin.h
        Screens/AdminScreens/AddNewSubAdminScreen.h
        Core/Student.h
        Screens/sAdminScreens/sAdminMainScreen.h
        Screens/sAdminScreens/AddNewStudentScreen.h
        Screens/StudentScreens/StudentMainScreen.h
        Core/Course.h
        Screens/sAdminScreens/AddNewCourseScreen.h
        Screens/StudentScreens/GetStudentIDScreen.h
        Screens/StudentScreens/RegistrationScreen.h
        Global/LoginUser.h)
