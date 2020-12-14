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
#include "dslist.hpp"
#include "inlist.hpp"
#include "mainlist.hpp"
using namespace std;

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

  //list creation for domestic students file
  dslist* list1 = new dslist();
  mainlist* alist = new mainlist();

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

    try {
        //myStudent object creations for each vector index
        DomesticStudent myDom(firstName, lastName, province, cgpa, researchScore, applicationid);
        list1->insert(myDom);
    }
    catch (std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught: " << ba.what();
    }

    applicationid++;
  }
  //Closes file after use
  domesticFile.close();
  ///////////////////////////////////////////////////////////////////////////////////////

  /////////////////////////// read/write international-stu.txt //////////////////////////
  //Read the international-stu.txt file and exit if failed
  string line1;
  applicationid = applicationid + 900;

  ifstream internationalFile("international-stu.txt");
  if(!internationalFile.is_open()) {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }
  //Read the first line of international-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(internationalFile, line1);
  cout << "File format (International): " << line1 << endl;

  //list creation for international students file
  inlist* list2 = new inlist();

  //vector creation of international student objects
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
    
    if (toefl_total >= 93 && reading >= 20 && listening >= 20 && speaking >= 20 && writing >= 20) { //true if toeflscore is >= 20 in any category and total >= 90
        //myStudent object creations for each vector index
        InternationalStudent myIn(firstName, lastName, country, cgpa, researchScore, applicationid);
        list2->insert(myIn); //copies variables into current student obj
        applicationid++;
    }
    else {} //false if doesn't meet requirements
    
    //international student error checking, checks if any fields are empty.
    if ((firstName.empty()) || (lastName.empty()) || (country.empty()) || (cgpa = 0) || (researchScore = 0) || (applicationid = 0) || (listening = 0) || (reading = 0) || (writing = 0))
    {
    cout << "Error: an input field is empty";
    exit(1);
    }
    //international student error checking, checks if an invalid country was inputed.
    if ((country != "Canada") && (country != "China") && (country != "India") && (country != "Iran") && (country != "Korea")) {
        if (country == "Idian") {
            //output warning message
            cout << "Error: India was misspelled. Correcting error\n";
            country = "India";
        }
        else {
        //output error because province isnt valid
        cout << "Error: An invalid country was inputed";
        exit(1);
        }
     }
  }
  internationalFile.close();
  ///////////////////////////////////////////////////////////////////////////////////////

  // MENU:
  bool menu = true;
  cout << "\n\n\n|**********************************************************************************|\n";
  cout << "\n               Welcome to the SFU graduate student admission system!\n";
  cout << "\n               Created and copyrighted © by:\n                     Jim Pimentel          Rajnesh Joshi\n                     Ritchie Kumar         Fatima Agheli\n";
  cout << "\n               In accordance of:\n                     ENSC 251 - Final Project\n";
  cout << "\n|**********************************************************************************|\n\n\n   Loading. . .\n\n";
  
  while (menu == true) {
    int choice; 
    cout << "\nWhich type of list would you like to view?\n 1 : Domestic Students\n 2 : International Students\n 0 : EXIT PROGRAM!!\n";
    cin >> choice;

    if (choice == 1) {
      bool loop = true;
      int option;

      while(loop == true) 
      {
        cout << "\n   Loading Domestic Students menu. . .\n";
        cout << "\n  ~ Domestic Students Menu ~\n 1 : Print out domestic-stu.txt\n 2 : Search by AppID/CGPA/Research Score\n 3 : Search by First and Last name\n 4 : Add new student\n 5 : Delete student\n 6 : Delete head/tail\n 0 : Go back to main menu\n";
        cin >> option;
        
        if(option == 1) { ///print out entire domestic students file
            list1->print();
        }
        else if(option == 2) { //searchdomestic by appid or cgpa or research score
            bool loop2 = true;
            int option2;
            
            while (loop2 == true) {
                cout << "\nSort by?\n 1 : Application ID [20200000->2020xxxx]\n 2 : CGPA [0.0->4.0]\n 3 : Research Score [0->100]\n 0 : Go back to previous menu\n";
                cin >> option2;
                if (option2 == 1) {
                    list1->searchID();
                }
                else if (option2 == 2) {
                    list1->searchCGPA();
                }
                else if (option2 == 3) {
                    list1->searchRes();
                }
                else if (option2 == 0) {
                    cout << endl;
                    loop2 = false;
                }
                else {
                    cout << "This is not a menu option.\n\n";
                }
            }
        }
        else if(option == 3) { //search domestic by first and last name
            list1->searchName();
        }
        else if (option == 4) { //add new student
            list1->add();
        }
        else if (option == 5) { //delete existing student
            list1->del();
        }
        else if (option == 6) { //delete head/tail nodes
            list1->delht();
        }
        else if(option == 0) { //Go back to main menu
          cout << endl;
          loop = false;
        }
        else { //return a warning and to the main menu of the program
          cout << "This is not a menu option.\n";
        }
      }
    }
    else if (choice == 2 ) {
        bool loop = true;
        int option;

        while (loop == true)
        {
            cout << "\n   Loading International Students menu. . .\n";
            cout << "\n  ~ International Students Menu ~\n 1 : Print out international-stu.txt\n 2 : Search by AppID/CGPA/Research Score\n 3 : Search by First and Last name\n 4 : Add new student\n 5 : Delete student\n 6 : Delete head/tail\n 0 : Go back to main menu\n";
            cin >> option;

            if (option == 1) { ///print out entire domestic students file
                list2->print();
            }
            else if (option == 2) { //searchdomestic by appid or cgpa or research score
                bool loop2 = true;
                int option2;

                while (loop2 == true) {
                    cout << "\nSort by?\n 1 : Application ID [20201000->2020xxxx]\n 2 : CGPA [0.0->4.0]\n 3 : Research Score [0->100]\n 0 : Go back to previous menu\n";
                    cin >> option2;
                    if (option2 == 1) {
                        list2->searchID();
                    }
                    else if (option2 == 2) {
                        list2->searchCGPA();
                    }
                    else if (option2 == 3) {
                        list2->searchRes();
                    }
                    else if (option2 == 0) {
                        cout << endl;
                        loop2 = false;
                    }
                    else {
                        cout << "This is not a menu option.\n\n";
                    }
                }
            }
            else if (option == 3) { //search domestic by first and last name
                list2->searchName();
            }
            else if (option == 4) { //add new student
                list2->add();
            }
            else if (option == 5) { //delete existing student
                list2->del();
            }
            else if (option == 6) { //delete head/tail nodes
                list2->delht();
            }
            else if (option == 0) { //Go back to main menu
                cout << endl;
                loop = false;
            }
            else { //return a warning and to the main menu of the program
                cout << "This is not a menu option.\n";
            }
        }
    }/*
    else if (choice == 3) {
        alist->merge();
        alist->print();
    }*/
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