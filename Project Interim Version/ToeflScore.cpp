#include "ToeflScore.hpp"

//Constructors
ToeflScore::ToeflScore(int reading, int listening, int speaking, int writing, int toefl_total) {
  set_reading(reading);
  set_listening(listening);
  set_speaking(speaking);
  set_writing(writing);
  set_toefl_total(toefl_total);
}

//Default Constructor
ToeflScore::ToeflScore() {/* Do nothing */}

//Destructor
ToeflScore::~ToeflScore() {}

//Overload operator << definition
ostream& operator<<(ostream& out, ToeflScore& myScores) {
  out << "ToeflScore: " << myScores.get_toefl_total() << "\nReading: " << myScores.get_reading() << ", Listening: " << myScores.get_listening() << ", Speaking: " << myScores.get_speaking() << ", Writing: " << myScores.get_writing() << "\n\n";
  return out;
}

//Setters
void ToeflScore::set_reading(int reading) {
  this->reading=reading;
}
void ToeflScore::set_listening(int listening) {
  this->listening=listening;
}
void ToeflScore::set_speaking(int speaking) {
  this->speaking=speaking;
}
void ToeflScore::set_writing(int writing) {
  this->writing=writing;
}
void ToeflScore::set_toefl_total(int toefl_total) {
  this->toefl_total=toefl_total;
}

//Getters
int ToeflScore::get_reading() {
  return reading;
}
int ToeflScore::get_listening() {
  return listening;
}
int ToeflScore::get_speaking() {
  return speaking;
}
int ToeflScore::get_writing() {
  return writing;
}
int ToeflScore::get_toefl_total() {
  return toefl_total;
}

//////////////////////////// low ToeflScore negation from list ////////////////////////////
bool ToeflScore::ToeflCondition() {
  //Precondition: The toefl total, reading, listening, speaking, and writing should all be integer values
  //Postcondition: If the score is larger than/equal to 20 for any seperate section or larger than/equal to 93 then the score meets requirements and returns true
  //Otherwise the score does not meet the requirements
  //The return false
  if(get_toefl_total() >= 93 && get_reading() >= 20 && get_listening() >= 20 && get_speaking() >= 20 && get_writing() >= 20) {
    return true; //true if toeflscore is >= 20 in any category and total >= 90
  }
  else {
    return false; //false if doesn't meet requirements
  }
}
///////////////////////////////////////////////////////////////////////////////////////////
