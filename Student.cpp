#include "Student.hpp"

//Default Constructor
Student::Student() {}

//Destructor
Student::~Student() {}

//Setters
void Student::set_firstname(string firstname) {
  this->firstname = firstname;
}
void Student::set_lastname(string lastname) {
  this->lastname = lastname;
}
void Student::set_cgpa(float cgpa) {
  this->cgpa = cgpa;
}
void Student::set_researchscore(int researchscore) {
  this->researchscore = researchscore;
}
void Student::set_applicationid(int applicationid) {
  this->applicationid = applicationid;
}

//Getters
string Student::get_firstname() {
  return firstname;
} 
string Student::get_lastname() {
  return lastname;
}
float Student::get_cgpa() {
  return cgpa;
}
int Student::get_researchscore() {
  return researchscore;
}
int Student::get_applicationid() {
  return applicationid;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Functions ///////////////////////////////////////
// return 0 if both strings are equal, -1 if first string is less than the second, else 1

// Compare first name function //
int compareFirstName(Student &a, Student &b) 
{
  //Precondition: Two different student objects are inputted
  //Postcondition: Comapared the two first names until it found a different letter for both in the same position
  //If the letter for student_a is alphabetically after the letter for student_b return a positive 1 otherwise it will return a negative 1
  int output = 0;
  
  string one = a.get_firstname();
  string two = b.get_firstname();

  for(int i = 0; i < one.length(); i++) {
    one[i] = tolower(one[i]);
  }
  for(int i = 0; i < two.length(); i++) {
    two[i]  = tolower(two[i]);
  }

  //For loop that checks and compares two names until if finds a different letter in the same position for both names
  for(int i = 0; i < a.get_firstname().length(); i++) {
    if(one[i] == two[i])
    {
      continue;
    }
    else if(one[i] > two[i]) 
    {
      output = 1;
      break;
    }
    else if(one[i] < two[i]) {
      output = -1;
      break;
    }
    if(i == one.length() - 1 && two.length() > one.length()) {
      output = -1;
    }
    else if(i == one.length() - 1 && two.length() < one.length()){
      output = 1;
    }

  }
  return output;
}

// Compare last name function //
int compareLastName(Student &a, Student &b) {
  //Precondition: Two different string values are inputed
  //lastnameone is the first last name and lastnametwo is the second last name
  //Postcondition: Comapared the two last names until it found a different letter for both in the same position
  //If the letter for lastnameone is alphabetically after the letter for lastnametwo return a positive 1 otherwise it will return a negative 1
  int output = 0;
  
  string one = a.get_lastname();
  string two = b.get_lastname();

  for(int i = 0; i < one.length(); i++) {
    one[i] = tolower(one[i]);
  }
  for(int i = 0; i < two.length(); i++) {
    two[i]  = tolower(two[i]);
  }

  //For loop that checks and compares two names until it finds a different letter in the same positon for both names
  for(int i = 0; i < a.get_lastname().length(); i++) {
    if(one[i] == two[i])
    {
      continue;
    }
    else if(one[i] > two[i]) 
    {
      output = 1;
      break;
    }
    else if(one[i] < two[i]) {
      output = -1;
      break;
    }
    if(i == one.length() - 1 && two.length() > one.length()) {
      output = -1;
    }
    else if(i == one.length() - 1 && two.length() < one.length()){
      output = 1;
    }

  }
  return output;
}

// Compare CGPA function //
int compareCGPA(Student &a, Student &b) 
{
  //Precondition: Two different float values are inputed
  //cgpaOne is the first CGPA and cgpaTwo is the second CGPA
  //Postcondition: Comapared the two CGPA values
  //If cgpaOne is numerically greater than cgpaTwo return a postive 1 otherwise it will return a negative 1
  if(a.get_cgpa() > b.get_cgpa()) {
    return 1;
  }
  else if(a.get_cgpa() < b.get_cgpa()) {
    return -1;
  }
  else {
    return 0;
  }
}

// Compare research score function //
int compareResearchScore(Student &a, Student &b) 
{
  //Precondition: Two different int values are inputed
  //one is the first research score and two is the second research score
  //Postcondition: Comapared the two research score values
  //If one is numerically greater two return a positive 1 otherwise it will return a negative 1
  if(a.get_researchscore() > b.get_researchscore()) {
    return 1;
  }
  else if(a.get_researchscore() < b.get_researchscore()) {
    return -1;
  }
  else {
    return 0;
  }
}