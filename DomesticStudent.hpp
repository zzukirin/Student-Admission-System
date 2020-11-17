#ifndef DOMESTICSTUDENT_H //Domestic header
#define DOMESTICSTUDENT_H
#include "Student.hpp"

class DomesticStudent: public Student
{
  private:
    //Declarations
    string province;

  public:
    //Constructor
    DomesticStudent(); //default
    DomesticStudent(string firstname, string lastname, string province, float cgpa, int researchscore, int applicationid);

    //Destructor 
    ~DomesticStudent();

    //Overloaded Operator to display object information
    friend ostream& operator<<(ostream& out, DomesticStudent& newDomesticStudent);

    //Functions
    int compareProvince(string p1, string p2);

    //Setters
    void set_province(string province);

    //Getters
    string get_province();
};
#endif