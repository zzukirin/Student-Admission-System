#include "InternationalStudent.hpp"

//Constructors
InternationalStudent::InternationalStudent(string firstname, string lastname, string country, float cgpa, int researchscore, unsigned int applicationid) {
  // Precondition: Inputs student properties.
  // Postcondition: Sets properties for respective vector object.
  set_firstname(firstname);
  set_lastname(lastname);
  set_country(country);
  set_cgpa(cgpa);
  set_researchscore(researchscore);
  set_applicationid(applicationid);
}

//Default Constructor
InternationalStudent::InternationalStudent() {}

//Destructor
InternationalStudent::~InternationalStudent() {}

//Overload operator << definition
ostream& operator<<(ostream& out, InternationalStudent& myStudent) {
  out << myStudent.get_firstname() << " " << myStudent.get_lastname() << " from " << myStudent.get_country() << ", CGPA: " << setprecision(2) << myStudent.get_cgpa() << ", ResearchScore: " << myStudent.get_researchscore() << "\nApplication ID: " << myStudent.get_applicationid() << "\n";
  return out;
}

//Setters
void InternationalStudent::set_country(string country) {
  this->country = country;
}

//Getters
string InternationalStudent::get_country() {
  return country;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Functions ///////////////////////////////////////

// compareCountry() function: compares two countries
// return values: strings equal = 0, 1st string < 2nd string = -1, else 1
int InternationalStudent::compareCountry(string c1, string c2) {
  // Precondition: Two string input values.
  // c1: first student country, c2: second student country
  // Postcondition: Compared the letters alphabetically until it finds 
  // two different letters in the same position of the two country names.
  int output = 0;
  for(int i = 0; i < c1.length(); i++) {
    if((c1[i]) == (c2[i])) {
      continue;
    }
    else if((c1[i]) > (c2[i])) {
      output = 1;
      break;
    }
    else if((c1[i]) < (c2[i])) {
      output = -1;
      break;
    }
  }
  return output;
}
