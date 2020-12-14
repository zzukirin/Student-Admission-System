#ifndef STUDENT_H //Student Header
#define STUDENT_H
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

class Student
{
  private:
    //Declarations
    string firstname;
    string lastname;
    float cgpa;
    int researchscore;
    unsigned int applicationid;
    Student* next;

  public:
    //Constructors
    Student(); //default


    //Destructors
    ~Student();

    //Friend Functions
    friend int compareFirstName(Student *a, Student *b);
    friend int compareLastName(Student &a, Student &b);
    friend int compareCGPA(Student &a, Student &b);
    friend int compareResearchScore(Student* a, Student* b);

    //Friends
    friend class mainlist;

    //Mutators
    void set_firstname(string firstname);
    void set_lastname(string lastname);
    void set_cgpa(float cgpa);
    void set_researchscore(int researchscore);
    void set_applicationid(unsigned int applicationid);

    //Accessors
    string get_firstname();
    string get_lastname();
    float get_cgpa();
    int get_researchscore();
    int get_applicationid();
};
#endif