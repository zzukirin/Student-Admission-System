#ifndef INTERNATIONALSTUDENT_H //International header
#define INTERNATIONALSTUDENT_H
#include "Student.hpp"

class InternationalStudent: public Student
{
  private:
    //Declarations
    string country;

  public:
    //Constructors
    InternationalStudent(); //default
    InternationalStudent(string firstname, string lastname, string country, float cgpa, int researchscore, unsigned int applicationid);

    //Destructors
    ~InternationalStudent();

    //Overloaded Operator
    friend ostream& operator<<(ostream& out, InternationalStudent& myStudent);

    //Functions
    int compareCountry(string c1, string c2);

    //Setters
    void set_country(string country);

    //Getters
    string get_country();
};
#endif
