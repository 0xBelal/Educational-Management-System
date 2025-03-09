//
// Created by Belal on 26-Feb-25.
//

#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include "Person.h"
#include "../Global/Global.h"
#include <fstream>
#include "../Core/Course.h"
#include <vector>
#include <string>
#include <set>

using namespace  std;


class Student : public Person{

private :
    string FacultyName;
    string Degree;
    float GPA;
    bool Empty = true;
    vector<Course> enrolledCourses;

    string ConvertStudentObjToRecord() {
        return (getID() + Separator + getFullName() + Separator + getNationalID() + Separator + getPassword() +
            Separator +getFacultyName() + Separator +to_string( getGPA()) + Separator + getDegree());
    }

    void Assigin(Student& student) {
        this->setID(student.getID());
        this->setFullName(student.getFullName());
        this->setNationalID(student.getNationalID());
        this->setPassword(student.getPassword());
        this->setFacultyName(student.getFacultyName());
        this->setGPA(student.getGPA());
        this->setDegree(student.getDegree());

    }
    vector<Student> LoadStudents() {
        vector<Student> students;
        vector<string> Record;
        ifstream file;
        file.open(AllStudent.c_str(),ios::in);
        if(file.is_open()) {
            string line;
            Student student;
           while(getline(file,line)) {

               Record = clsString::Split(line,Separator);
                //1009 <-> Belal Mohamed Mohamed <-> 30410201203234 <-> belalmo@22 <-> CS <-> 0.000000 <-> NULL

               float gpa = (Record[6] == "NULL") ? 0.0f : stof(Record[6]);

               
               student.setID(Record[0]);
               student.setFullName(Record[1]);
               student.setNationalID( Record[2]);
               student.setPassword( Record[3]);
               student.setFacultyName( Record[4]);
               student.setDegree( Record[6]);
               student.setGPA( gpa);
               students.push_back(student);

               Record.clear();

           }

        }
         return students;
    }
    vector<Course> LoadStudentCourses() {
        vector<Course> courses;
        vector<string> vCourse;
        fstream file;
        file.open((StudentCourses+getID()).c_str(),ios::in);
        if(file.is_open()) {
            string line;
            while(getline(file,line)) {
                // CS102 <-> Programming 2 <-> 3 <-> 100 <-> CS101

                Course course;
                vCourse = clsString::Split(line,Separator);
                course.setCourseCode(vCourse[0]);
                course.setName(vCourse[1]);
                course.setCreditHours(stoi(vCourse[2]));
                course.setStudentMark(stod(vCourse[3]));
                for(int i=4;i<vCourse.size();i++) {
                    course.addPrerequisiteCourse(vCourse[i]);
                }

                courses.push_back(course);
            }
            file.close();
        }
        return courses;
    }
public:
    Student() : Empty(true) {}
    Student(const string &ID ,const string &FullName ,const string &NID,const string &Password ,
        const string &FacultyName,const string &Degree,const float &GPA):
    Person(ID, FullName,  Password,NID) {       //     Person(string ID, string FullName, string Password,const string& NID)

        setGPA(GPA);
        setDegree(Degree);

    }
    void setDegree(const string &degree) {Degree = degree;}
    void setGPA(const float &gpa) { GPA = gpa; }
    void setFacultyName(const string &Name){ FacultyName = Name;}


    string getDegree(){return Degree;}
    float getGPA(){return GPA;}
    string getFacultyName(){return FacultyName;}

    bool isEmpty(){return Empty;}
    vector<Student> getAllStudents() {
           return LoadStudents();
    }
    bool isStudent() {
           vector<Student> students = getAllStudents();

            for(Student &student : students) {
                if(student.getNationalID() == getNationalID() && student.getPassword() == getPassword()) return true;
            }
        return false;
    }
    Student getIDByNationalID()  {


        vector<Student> students = getAllStudents();

        for(Student & s : students) {
            if(getNationalID() == s.getNationalID()) {
                s.Empty = false;

                return s;
            }
        }
        return Student();
    }
    bool AddNewStudent(){

        setID(to_string(GenerateID()));
        fstream file((StudentInfo+getID()+".txt").c_str(),ios::out | ios::app);
        fstream Courses((StudentCourses+getID()+".txt").c_str(),ios::out | ios::app);
        fstream All_Student((AllStudent).c_str(),ios::out | ios::app);
        if(All_Student.is_open()) {
            All_Student<<ConvertStudentObjToRecord()<<endl;
            All_Student.close();
        }
        if (file.is_open()) {
            file<<ConvertStudentObjToRecord()<<endl;
            file.close();

        } else return false;

        
        return true;
    }

    vector<Course> getEnrolledCourses() {
        return enrolledCourses;
    }

    bool registerCourse(const string& code) {
        Course course = Course::getCourseByCode(code);

        vector<Course> enrolledCourses = LoadStudentCourses();

        unordered_set<string> enrolledSet;
        for (const Course& s : enrolledCourses) {
            enrolledSet.insert(s.getCourseCode());
        }

        for (const string& subj : course.getPrerequisitesCourses()) {
            if (enrolledSet.find(subj) == enrolledSet.end()) {
               return false;
            }
        }

        // addCourseToStudent(code);

        return true;
    }
};



#endif //STUDENT_H
