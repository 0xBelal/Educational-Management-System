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
            Separator +getFacultyName() + Separator +to_string( getGPA()) + Separator + getDegree()) + "\n";
    }


    string getLetterGrade(float grade) {
        if (grade >= 97) return "A+";
        else if (grade >= 93) return "A";
        else if (grade >= 90) return "A-";
        else if (grade >= 87) return "B+";
        else if (grade >= 83) return "B";
        else if (grade >= 80) return "B-";
        else if (grade >= 77) return "C+";
        else if (grade >= 73) return "C";
        else if (grade >= 70) return "C-";
        else if (grade >= 67) return "D+";
        else if (grade >= 63) return "D";
        else if (grade >= 60) return "D-";
        else return "F";
    }

    string calculateDegree() {
        vector<Course> courses = this->getCompletedCourses();
        float grads = 0;
        for(const Course & s : courses) {
            grads +=s.getStudentMark();
        }

        this->setDegree(getLetterGrade(grads/(float)courses.size()));
        return  getDegree();
    }


    static vector<Student> LoadStudents() {
        vector<Student> students;
        vector<string> Record;
        ifstream file;
        file.open((AllStudent).c_str(),ios::in);
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


            file.close();
        }
         return students;
    }

    vector<Course> LoadStudentCourses() {
        vector<Course> courses;
        vector<string> vCourse;
        fstream file;
        file.open((StudentCourses+getID()+".txt").c_str(),ios::in);
        if(file.is_open()) {
            string line;
            while(getline(file,line)) {
               // BS000 <-> Mathemathematics 0 <-> 0 <-> 0.000000

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
    void setGPA(const float &gpa) { this->GPA = gpa; }
    void setFacultyName(const string &Name){ FacultyName = Name;}
    void setEnrolledCourses(vector<Course> &vCourses){enrolledCourses =vCourses;}

    void assignStudent(Student& student) {
        this->setID(student.getID());
        this->setFullName(student.getFullName());
        this->setNationalID(student.getNationalID());
        this->setPassword(student.getPassword());
        this->setFacultyName(student.getFacultyName());
        this->setGPA(student.getGPA());
        this->setDegree(student.getDegree());
        this->Empty = student.Empty;
        this->enrolledCourses = getEnrolledCourses();
    }

    string getDegree() const { return Degree;}
    float getGPA() const {return GPA;}
    string getFacultyName()const {return FacultyName;}


    static vector<Student> getAllStudents() {
        return LoadStudents();
    }
     vector<Course> getStudentCourses() {
        return LoadStudentCourses();
    }
    vector<Course> getCompletedCourses() {

        vector<Course> courses;
        vector<string> vCourse;
        fstream file;
        file.open((StudentInfo+getID()+".txt").c_str(),ios::in);
        if(file.is_open()) {
            string line;
            int counter=0;
            while(getline(file,line)) {
               if(++counter == 1) continue;
                // BS000 <-> Mathemathematics 0 <-> 0 <-> 0.000000

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

    bool isEmpty(){return Empty;}

    void updateStudentInfoFile() {
        fstream file;
        vector<Course> vCourses = this->getCompletedCourses();
        file.open((StudentInfo+this->getID()+".txt").c_str(),ios::out);


        if(file.is_open()) {
            file<<this->ConvertStudentObjToRecord();
            // BS000 <-> Mathemathematics 0 <-> 0 <-> 100.000000

            for(Course &course :  vCourses) {
               file<<course.getCourseCode()<<Separator;
                file<<course.getName()<<Separator;
                file<<course.getCreditHours()<<Separator;
                file<<course.getStudentMark();
                file<<endl;
            }

            file.close();
        }
    }
    void updateAllStudentsInfoFile() {

        fstream file;
        vector<Student> vallStudents = getAllStudents();
        file.open((AllStudent).c_str(),ios::out);


        if(file.is_open()) {

            for(Student &s :  vallStudents) {
                if(s.getID() == this->getID()) file << this->ConvertStudentObjToRecord();
                else file<<s.ConvertStudentObjToRecord() ;
            }



            file.close();
        }

    }
    bool isStudent() {
           vector<Student> students = getAllStudents();

            for(Student &student : students) {
                if(student.getNationalID() == getNationalID() && student.getPassword() == getPassword()) {
                    /*this->setID(student.getID());
                    this->setFullName(student.getFullName());
                    //this->setNationalID(student.getNationalID());
                    this->setFacultyName(student.getFacultyName());
                    this->setDegree(student.getDegree());
                    this->setGPA(student.getGPA());
                   // this->setPassword(student.getPassword());*/

                    this->assignStudent(student);
                    return true;
                }
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

    static Student &getStudnetByID(string ID) {

        Student student;
        vector<string> vStudent;
        fstream file;
        file.open((StudentInfo+ID+".txt").c_str(),ios::in);
        if(file.is_open()) {
            string line;
            getline(file,line);

            vStudent = clsString::Split(line,Separator);
            // 111111 <-> Belal Mohamed Mohamed Ahmed <-> 30410201203234 <-> belalmo@22 <-> Computer Science <-> 0.000000 <-> NULL
            student.setID(vStudent[0]);
            student.setFullName(vStudent[1]);
            student.setNationalID(vStudent[2]);
            student.setPassword(vStudent[3]);
            student.setFacultyName(vStudent[4]);
            student.setGPA(stod(vStudent[5]));
            student.setDegree(vStudent[6]);
            student.Empty = false;
            file.close();
        }
        return student;
    }

    Student getStudentByID()  {


        vector<Student> students = getAllStudents();

        for(Student & s : students) {
            if(getID() == s.getID()) {
                s.Empty = false;
                this->assignStudent(s);
                return s;
            }
        }
        return Student();
    }
    bool addNewStudent(){

        setID(to_string(GenerateID()));
        fstream file((StudentInfo+getID()+".txt").c_str(),ios::out | ios::app);
        fstream Courses((StudentCourses+getID()+".txt").c_str(),ios::out | ios::app);
        fstream All_Student((AllStudent).c_str(),ios::out | ios::app);
        fstream AllUsers_file(AllUsers.c_str(),ios::out | ios::app);

        if(All_Student.is_open()) {
            All_Student<<ConvertStudentObjToRecord()<<endl;
            All_Student.close();
        }
        if (file.is_open()) {
            file<<ConvertStudentObjToRecord()<<endl;
            file.close();

        } else return false;

        if(AllUsers_file.is_open()) {
            AllUsers_file <<  this->userInfoRecord("student")<<endl;
            AllUsers_file.close();
        }else return false;
        
        return true;
    }

    vector<Course> getEnrolledCourses() {
        return  enrolledCourses;
    }

    bool registerCourse(const string& code) {

        Course course = Course::getCourseByCode(code);



        vector<Course> CompletedCourses = this->getCompletedCourses();

        unordered_set<string> enrolledSet;
        for (const Course& s : CompletedCourses) {
            enrolledSet.insert(s.getCourseCode());
        }

        for (const string& subj : course.getPrerequisitesCourses()) {

            if (enrolledSet.find(subj) == enrolledSet.end()) {
               return false;
            }
        }

        return addCourseToStudent(course);


    }
    bool addCourseToStudent(Course & addedCourse) {

        fstream courses_file((StudentCourses+getID()+".txt").c_str(), ios::app);
        if(courses_file.is_open()) {
            courses_file<<addedCourse.ConvertToStudentCourseObjToRecord()<<endl;
        }else return false;
        return true;
    }

    float calculateGPA() {

        calculateDegree();

        map<string, float> gradeMap = {
            {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7},
            {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
            {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7},
            {"D+", 1.3}, {"D", 1.0}, {"D-", 0.7}, {"F", 0.0}
        };

        float gpa = gradeMap.count(getDegree()) ? gradeMap[getDegree()] : -1.0;
        setGPA(gpa);

        return gpa;
    }


};





static void PrintHeader() {
    std::cout << std::left << std::setw(11) << "Course Code"
              << " | " << std::setw(26) << "Course Name"
              << " | " << std::setw(10) << "Credit Hour"
              << " | " << std::setw(10) << "Student Mark"

              << std::endl;
    std::cout << std::string(70, '_') << std::endl;
}

static void PrintCourse(const Course &course) {
    std::cout << std::left << std::setw(11) << course.getCourseCode()
              << " | " << std::setw(26) << course.getName()
              << " | " << std::setw(10) << course.getCreditHours()
              << " | " << std::setw(10)  << course.getStudentMark();

    /*std::vector<std::string> prerequisites = course.getPrerequisitesCourses();
    if (!prerequisites.empty()) {
        for (size_t i = 0; i < prerequisites.size(); i++) {
            std::cout << prerequisites[i];
            if (i != prerequisites.size() - 1) std::cout << " ";
        }
    }*/

    std::cout << std::endl;
}


static void PrintRegistredCourses(Student &student) {
    std::vector<Course> vEnrolledCourses = student.getStudentCourses();
    student.setEnrolledCourses(vEnrolledCourses);
    // CS102 <-> Programming 2 <-> 3 <-> 0.000000 <-> CS101

    std::cout << "\n\n";
    PrintHeader();
    int TotalHoures = 0, TotalCourses = 0;
    for (Course &x : vEnrolledCourses) {
        TotalCourses++;
        TotalHoures+=x.getCreditHours();
        PrintCourse(x);
    }

    std::cout << std::string(70, '_') << std::endl;
    cout<<"Total Courses: "<<TotalCourses<<"             Total Hours: "<<TotalHoures<<endl;
    std::cout << std::string(70, '_') << std::endl;


}

static void PrintStudentInfo(const Student & student ) {


    cout<<"\nStudent Information:"<<endl;
    cout<<"\nName : "<<student.getFullName()<<endl;
    cout<<"ID   : "<<student.getID()<<endl;
    cout<<"National ID : "<<student.getNationalID()<<"    ";
    cout<<"Faculty : "<< student.getFacultyName()<<endl;//" , GPA : "<< student.getGPA()<<endl;
    //cout<<"Degree  : "<< student.getDegree()<<endl;
    //std::cout << std::string(50, '_') << std::endl;

}

#endif //STUDENT_H
