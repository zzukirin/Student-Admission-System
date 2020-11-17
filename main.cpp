#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <string>
#include <vector>
#include "Student.hpp"
#include "DomesticStudent.hpp"
#include "ToeflScore.hpp"
#include "InternationalStudent.hpp"
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Function Declaration /////////////////////////////////

//View All Domestic Students
void ViewAllDom(vector<DomesticStudent> &list) {
  for(int i = 0; i < list.size(); i++) {
    cout << "------------------ Domestic Student #" << i + 1 << " -----------------\n";
    cout << list[i] << endl;
  }
}

//View All Domestic Students (REVERSE)
void ViewAllDomR(vector<DomesticStudent> &list) {
  for(int i = list.size() - 1; i >= 0; i--) {
    cout << "------------------ Domestic Student #" << list.size() - i << " -----------------\n";
    cout << list[i] << endl;
  }
}

//View All International Students
void ViewAllInt(vector<InternationalStudent> &list, vector<ToeflScore> &scores) {
  for(int i = 0; i < list.size(); i++) {
    cout << "--------------- International Student #" << i + 1 << " ---------------\n";
    cout << list[i] << scores[i] << endl;
  }
}

//View All International Students (REVERSE)
void ViewAllIntR(vector<InternationalStudent> &list, vector<ToeflScore> &scores) {
  for(int i = list.size() - 1; i >= 0; i--) {
    cout << "--------------- International Student #" << list.size() - i << " ---------------\n";
    cout << list[i] << scores[i] << endl;
  }
}

//View Only ToeflScore International Students (REVERSE)
void ViewToeflIntR(vector<InternationalStudent> &list, vector<ToeflScore> &scores) {
  for(int i = list.size() - 1; i >= 0; i--) {
    if(scores[i].ToeflCondition()) {
      cout << "--------------- International Student #" << list.size() - i << " ---------------\n";
      cout << list[i] << scores[i] << endl;
    }
  }       
}

//BUBBLE SORT ALGORITHM:
//Saving (Domestic):
void SaveDom(int i, int j, vector<DomesticStudent> &list) {
  DomesticStudent temp = list[i];
  list[i] = list[j];
  list[j] = temp;
}

//Saving (International):
void SaveInt(int i, int j, vector<InternationalStudent> &list, vector<ToeflScore> &scores) {
  InternationalStudent temp = list[i];
  list[i] = list[j];
  list[j] = temp;

  ToeflScore tempScore = scores[i];
  scores[i] = scores[j];
  scores[j] = tempScore;
}

//Sorting (Domestic):
void SortDom(int option, vector<DomesticStudent> &list) {
  int output, output2, output3;
  for(int i = 0; i < list.size(); i++) {
    for(int j = i + 1; j < list.size(); j++) {
      //decides which comparison to sort:
      if(option == 2) {
        output = compareFirstName(list[i], list[j]);
        if(output == 1) {
          SaveDom(i, j, list);
        }
      }
      else if(option == 3) {
        output = compareLastName(list[i], list[j]);
        if(output == 1) {
          SaveDom(i, j, list);
        }
      }
      else if(option == 4) {
        output = compareCGPA(list[i], list[j]);
        if(output == 1) {
          SaveDom(i, j, list);
        }
      }
      else if(option == 5) {
        output = compareResearchScore(list[i], list[j]);
        if(output == 1) {
          SaveDom(i, j, list);
        }
      }
      else if(option == 6) {
        output = compareResearchScore(list[i], list[j]);
        if(output == 1) {
          SaveDom(i, j, list);
        }
        else if(output == 0) {
          output2 = compareCGPA(list[i], list[j]);
          if(output2 == 1) {
            SaveDom(i, j, list);
          }
          else if(output2 == 0) {
            DomesticStudent cp;
            output3 = cp.compareProvince(list[i].get_province(), list[j].get_province());
            if(output3 == -1) {
              SaveDom(i, j, list);
            }
          }
        }
      }
    } 
  }
}

//Sorting (International):
void SortInt(int option, vector<InternationalStudent> &list, vector<ToeflScore> &scores) {
  int output, output2, output3;
  for(int i = 0; i < list.size(); i++) {
    for(int j = i + 1; j < list.size(); j++) {
      //decides which comparison to sort:
      if(option == 2) {
        output = compareFirstName(list[i], list[j]);
        if(output == 1) {
          SaveInt(i, j, list, scores);
        }
      }
      else if(option == 3) {
        output = compareLastName(list[i], list[j]);
        if(output == 1) {
          SaveInt(i, j, list, scores);
        }
      }
      else if(option == 4) {
        output = compareCGPA(list[i], list[j]);
        if(output == 1) {
          SaveInt(i, j, list, scores);
        }
      }
      else if(option == 5) {
        output = compareResearchScore(list[i], list[j]);
        if(output == 1) {
          SaveInt(i, j, list, scores);
        }
      }
      else if(option == 6) {
        output = compareResearchScore(list[i], list[j]);
        if(output == 1) {
          SaveInt(i, j, list, scores);
        }
        else if(output == 0) {
          output2 = compareCGPA(list[i], list[j]);
          if(output2 == 1) {
            SaveInt(i, j, list, scores);
          }
          else if(output2 == 0) {
            InternationalStudent cc;
            output3 = cc.compareCountry(list[i].get_country(), list[j].get_country());
            if(output3 == -1) {
              SaveInt(i, j, list, scores);
            }
          }
        }
      }
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// main() ////////////////////////////////////////

int main()
{
  unsigned int applicationid = 20200000; //unique applicationid for each student
  
  ///////////////////////////// read/write domestic-stu.txt /////////////////////////////
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) 
  {
    //Gives user a warning if the file they would like to use is not opened
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }
  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(domesticFile, line);
  cout << "File format (Domestic): " << line << endl;

  //vector creation for domestic students file
  vector<DomesticStudent> myDomesticList;
  vector<DomesticStudent> DomesticStudentVector;

  while(getline(domesticFile, line))
  {
    istringstream ss(line);

    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    getline(ss, firstName, ','); //get firstName separated by comma
    getline(ss, lastName, ','); //get lastName separated by comma
    getline(ss, province, ','); //get province separated by comma
    getline(ss, s_cgpa, ','); //get cpga separated by comma
    cgpa = atof(s_cgpa.c_str()); //convert string to float
    getline(ss, s_researchScore, ','); //get researchScore separated by comma
    researchScore = atoi(s_researchScore.c_str()); //convert it to int

    //myStudent object creations for each vector index
    DomesticStudent myStudent(firstName, lastName, province, cgpa, researchScore, applicationid);
    myDomesticList.push_back(myStudent); //copies variables into current student obj

    applicationid++;
  }
  //Closes file after use
  domesticFile.close();
  ///////////////////////////////////////////////////////////////////////////////////////

  /////////////////////////// read/write international-stu.txt //////////////////////////
  //Read the international-stu.txt file and exit if failed
  string line1;
  ifstream internationalFile("international-stu.txt");
  if(!internationalFile.is_open()) {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }
  //Read the first line of international-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(internationalFile, line1);
  cout << "File format (International): " << line1 << endl;

  //vector creation of international student objects
  vector<InternationalStudent> myInternationalList;
  vector<ToeflScore> myScoreList;

  while(getline(internationalFile, line)) {
    istringstream ss(line);

    string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
    float cgpa;
    int researchScore, reading, listening, speaking, writing, toefl_total;

    getline(ss, firstName, ','); //get firstName separated by comma
    getline(ss, lastName, ','); //get lastName separated by comma
    getline(ss, country, ','); //get province separated by comma
    getline(ss, s_cgpa, ','); //get cpga separated by comma 
    cgpa = atof(s_cgpa.c_str()); //convert cgpa string to float
    getline(ss, s_researchScore, ','); //get researchScore separated by comma
    researchScore = atoi(s_researchScore.c_str()); //convert researchScore to int
    getline(ss, s_reading, ','); //get reading separated by comma
    reading = atoi(s_reading.c_str()); //convert reading to int
    getline(ss, s_listening, ','); //get listening separated by comma
    listening = atoi(s_listening.c_str()); //convert listening to int
    getline(ss, s_speaking, ','); //get speaking separated by comma
    speaking = atoi(s_speaking.c_str()); //convert speaking to int
    getline(ss, s_writing, ','); //get writing separated by comma
    writing = atoi(s_writing.c_str()); //convert writing to int
    toefl_total = reading + listening + speaking + writing; //Add up ToeflScores to get total
        
    //myStudent object creations for each vector index
    InternationalStudent myStudent(firstName, lastName, country, cgpa, researchScore, applicationid);
    myInternationalList.push_back(myStudent); //copies variables into current student obj

    //myScores object creations for each vector index
    ToeflScore myScores(reading, listening, speaking, writing, toefl_total);
    myScoreList.push_back(myScores); //copies variables into current scores obj

    applicationid++;
  }
  internationalFile.close();
  ///////////////////////////////////////////////////////////////////////////////////////

  // MENU:
  bool menu = true;
  cout << "\n\nWelcome to the SFU graduate student admission system! Please select an option below:\n";
  
  while (menu == true) {
    int choice; 
    cout << "\nWhich type of list would you like to view?\n1 : Domestic Students\n2 : International Students\n0 : EXIT PROGRAM!!\n";
    cin >> choice;

    if (choice == 1) {
      bool loop = true;
      int option;

      while(loop == true) 
      {
        cout << "\n====================================================================\n\n";
        cout << "1 : Print out domestic-stu.txt\n2 : Sort by First Names\n3 : Sort by Last Names\n4 : Sort by CGPA\n5 : Sort by ResearchScore\n6 : Overall sort\n0 : Go back to main menu\n";
        cin >> option;
        cout << "\n====================================================================\n\n";

        if(option == 1) { ///print out entire domestic students file
          ViewAllDom(myDomesticList);
        }
        else if(option == 2) { //sort domestic by first names (A-Z)
          SortDom(option, myDomesticList);
          ViewAllDom(myDomesticList);
        }
        else if(option == 3) { //sort domestic by last names (A-Z)
          SortDom(option, myDomesticList);
          ViewAllDom(myDomesticList);
        }
        else if(option == 4) { //sort domestic students by CGPA (high-to-low)
          SortDom(option, myDomesticList);
          ViewAllDomR(myDomesticList);
        }
        else if(option == 5) { //sort domestic students by ResearchScore (high-to-low)
          SortDom(option, myDomesticList);
          ViewAllDomR(myDomesticList);
        }
        else if(option == 6) { //overall sort the domestic student text file
          SortDom(option, myDomesticList);
          ViewAllDomR(myDomesticList);   
        }  
        else if(option == 0) { //Go back to main menu
          cout << endl;
          loop = false;
        }
        else { //return a warning and to the main menu of the program
          cout << "This is not a menu option\n";
        }
      }
    }
    else if (choice == 2 ) {
      bool loop = true;
      int option;

      while(loop == true) 
      {
        cout << "\n====================================================================\n\n";
        cout << "1 : Print out international-stu.txt\n2 : Sort by First Names\n3 : Sort by Last Names\n4 : Sort by CGPA\n5 : Sort by ResearchScore\n6 : Overall sort\n0 : Go back to main menu\n";
        cin >> option;
        cout << "\n====================================================================\n\n";

        if(option == 1) { ///print out entire international students file
          ViewAllInt(myInternationalList, myScoreList);
        }
        else if(option == 2) { //sort international by first names (A-Z)
          SortInt(option, myInternationalList, myScoreList);
          ViewAllInt(myInternationalList, myScoreList);
        }
        else if(option == 3) { //sort international by last names (A-Z)
          SortInt(option, myInternationalList, myScoreList);
          ViewAllInt(myInternationalList, myScoreList);
        }
        else if(option == 4) { //sort international students by CGPA (high-to-low)
          SortInt(option, myInternationalList, myScoreList);
          ViewAllIntR(myInternationalList, myScoreList);
        }
        else if(option == 5) { //sort international students by ResearchScore (high-to-low)
          SortInt(option, myInternationalList, myScoreList);
          ViewAllIntR(myInternationalList, myScoreList);
        }
        else if(option == 6) { //overall sort the international student text file
          SortInt(option, myInternationalList, myScoreList);
          ViewToeflIntR(myInternationalList, myScoreList);   
        }  
        else if(option == 0) { //Go back to main menu
          cout << endl;
          loop = false;
        }
        else { //return a warning and to the main menu of the program
          cout << "This is not a menu option\n";
        }
      }
    }
    else if (choice == 0)
    {
      cout<<"\nBuh-bye\n";
      exit(1);
    }
    else {
      cout<< "\nOkay Sathish/Xingyu, there's only three numbers you can type!\nPlease re-input...\n";
    }
  }
}


//Can be used to view individual students.
/*
/////////////////////////////////////////////////////////////////////////
    else if(option == 8) { //TESTING PURPOSES
      int x = -1;
      cout << "Input the desired domestic student info you would like to get: ";
      cin >> x;
      x -= 1;
      cout << myInternationalList[x];
    }
    else if(option == 9) { //TESTING PURPOSES
    int x = -1;
    cout << "Input the desired international student info you would like to get: ";
    cin >> x;
    x -= 1;
    ToeflScore myScores;
      if(myScoreList[x].negateToefl(myScores) == false) {
        cout << "\nThis student did not meet the minimum ToeflScore.\n\n";
      }
      else if(myScoreList[x].negateToefl(myScores) == true) {
        cout << myInternationalList[x] << myScoreList[x];
      }
    }
    else if(option == 10) { //TESTING PURPOSES
    int x = -1;
    cout << "Input the desired student info you would like to get: ";
    cin >> x;
    x -= 1;
    cout << myInternationalList[x];
    }
/////////////////////////////////////////////////////////////////////////
*/