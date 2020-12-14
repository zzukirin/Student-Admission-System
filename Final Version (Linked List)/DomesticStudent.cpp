#include "DomesticStudent.hpp"

//Constructors
DomesticStudent::DomesticStudent(string firstname, string lastname, string province, float cgpa, int researchscore, int applicationid) {
  // Precondition: Inputs student properties.
  // Postcondition: Sets properties for respective vector object.
  set_firstname(firstname);
  set_lastname(lastname);
  set_cgpa(cgpa);
  set_researchscore(researchscore);
  set_province(province);
  set_applicationid(applicationid);
}

//Default Constructor
DomesticStudent::DomesticStudent() {
    next = NULL;
}

//Deconstrcutor
DomesticStudent::~DomesticStudent() {}

//Overload operator << definition
ostream& operator<<(ostream& out, DomesticStudent& myStudent) {
  out << myStudent.get_firstname() << " " << myStudent.get_lastname() << " from " << myStudent.get_province() << ", CGPA: " << setprecision(2) << myStudent.get_cgpa() << ", ResearchScore: " << myStudent.get_researchscore() << "\nApplication ID: " << myStudent.get_applicationid();
  return out;
}

//Setters
void DomesticStudent::set_province(string province) {
  this->province = province;
}

//Getters
string DomesticStudent::get_province() {
  return province;
}

DomesticStudent* DomesticStudent::getnext() {
    return next;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Functions ///////////////////////////////////////

// compareProvince() function: compares two provinces
// return values: strings equal = 0, 1st string < 2nd string = -1, else 1
int DomesticStudent::compareProvince(string p1, string p2) {
  // Precondition: Two string input values.
  // p1: first student province, p2: second student province
  // Postcondition: Compared the letters alphabetically until it finds 
  // two different letters in the same position of the two province names.
  int output = 0;
  for(int i = 0; i < p1.length(); i++) {
    if((p1[i]) == (p2[i])) {
      continue;
    }
    else if((p1[i]) > (p2[i])) {
      output = 1;
      break;
    }
    else if((p1[i]) < (p2[i])) {
      output = -1;
      break;
    }
  }
  return output;
}