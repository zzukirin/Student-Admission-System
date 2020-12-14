#include "inlist.hpp"
#include "ToeflScore.hpp"
#include <cmath>

inlist::inlist() {
	head = NULL;
	tail = NULL;
}

inlist::~inlist() {}

InternationalStudent* inlist::gethead() {
	return head;
}

InternationalStudent* inlist::gettail() {
	return tail;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Functions ///////////////////////////////////////

//insert students into linked list
void inlist::insert(InternationalStudent& stu) {
	try { //try catch statement for new allocated memory
		InternationalStudent* temp = new InternationalStudent(stu);
		if (head == NULL) { //0 nodes
			head = temp;
			tail = temp;
			temp->next = NULL;
		}
		else {
			//sets temp to next, sets new tail to be the temp next
			tail->next = temp;
			tail = tail->next;

			tail->next = NULL; //sets very last tail to NULL
		}
	}
	catch (std::bad_alloc& ba) {
		std::cerr << "bad_alloc caught: " << ba.what();
	}
}

//overall sort? (WIP - researchscore sort for now)
void inlist::sort(InternationalStudent& stu) {
	InternationalStudent* temp = head;
	InternationalStudent* temp2 = new InternationalStudent;
	InternationalStudent* temp3 = new InternationalStudent;
	while (temp->next != NULL) {
		if (temp->get_researchscore() > temp->next->get_researchscore()) {
			temp2 = temp;
			temp = temp->next;
			temp3 = temp;
			temp = temp2;
			head = temp3;
			head->next = temp;
		}
		else {
			break;
		}
	}
}

//print entire linked list
void inlist::print() {
	int count = 0;
	InternationalStudent* temp = head;
	while (temp != NULL) {
		//cout << "\ntemp address: " << temp << endl << "next address: " << temp->next; //address checking (TESTS)
		cout << endl << "[Student #" << count + 1 << "]" << endl << *temp << endl;
		temp = temp->next;
		count++;
	}
	cout << "\n  **There are currently " << count << " entries in the list.\n";
}

//search student app ID
void inlist::searchID() {
	//counter
	int count = 0;
	InternationalStudent* temp = head;
	while (temp != NULL) {
		++count;
		temp = temp->next;
	}

	unsigned int id;
	cout << "\nEnter the Application ID of the student you would like to search for...\nID#: ";
	cin >> id;

	temp = head;
	while (temp != NULL) {
		if (id == temp->get_applicationid()) {
			cout << endl << *temp << endl;
			temp = temp->next;
		}
		else if (id == temp->get_applicationid() && temp->get_firstname().empty()) { //need to fix
			cout << "\n< That student has previously been deleted! >\n";
			break;
		}
		else if (id < 20201000 || id > 20201000 + count - 1 || id > 20210000) {
			cout << "\n< That Application ID does not exist! >\n";
			break;
		}
		else {
			temp = temp->next;
		}
	}
}

//search student CGPA
void inlist::searchCGPA() {
	//counter
	int count = 0;
	InternationalStudent* temp = head;
	while (temp != NULL) {
		++count;
		temp = temp->next;
	}

	float num, a;
	int none = 0;
	cout << "\nEnter the CGPA. Students with the specified CGPA will be printed out...\nCGPA: ";
	cin >> num;

	temp = head;
	while (temp != NULL) {
		a = round(temp->get_cgpa() * 10) / 100; //rounds to one decimal
		if (round(num * 10) / 100 == a) {
			cout << endl << *temp << endl;
			temp = temp->next;
		}
		else if (num < 0 || num > 4.33) {
			cout << "\n< The CGPA ranges only from 0.0 to 4.33! >\n";
			break;
		}
		else {
			temp = temp->next;
			none++;
		}
	}
	if (none == count) {
		cout << "\n< No student currently has the specified CGPA! >\n";
	}
}

//search student research score
void inlist::searchRes() {
	//counter
	int count = 0;
	InternationalStudent* temp = head;
	while (temp != NULL) {
		++count;
		temp = temp->next;
	}

	int res;
	int none = 0;
	cout << "\nEnter the Research Score. Students with the specified Research Score will be printed out...\nScore: ";
	cin >> res;

	temp = head;
	while (temp != NULL) {
		if (res == temp->get_researchscore()) {
			cout << endl << *temp << endl;
			temp = temp->next;
		}
		else if (res < 0 || res > 100) {
			cout << "\n< The Research Score can only range from 0 to 100! >\n";
			break;
		}
		else {
			temp = temp->next;
			none++;
		}
	}
	if (none == count) {
		cout << "\n< No student currently has the specified Research Score! >\n";
	}
}

//convert string to lower (for case insensitive comparison)
string inlist::lowstring(string a) {
	for (int i = 0; i < a.length(); i++) {
		a[i] = tolower(a[i]);
	}
	return a;
}

//search student first+last name
void inlist::searchName() {
	string fname, lname;
	int exist = 0;
	cout << "\nEnter the First and Last name of the student you would like to search for...\nFirst: ";
	cin >> fname;
	cout << "Last: ";
	cin >> lname;
	fname = lowstring(fname);
	lname = lowstring(lname);

	InternationalStudent* temp = head;
	while (temp != NULL) {
		if (fname == lowstring(temp->get_firstname()) && lname == lowstring(temp->get_lastname())) {
			cout << endl << *temp << endl;
			temp = temp->next;
			exist++;
		}
		else {
			temp = temp->next;
		}
	}
	if (exist == 0) {
		cout << "\n< That student is not in the system! >\n";
	}
}

//add student
void inlist::add() {
	cout << "\n|********************************************************|\n";
	cout << "\n	Welcome to the student creation portal!\n";
	cout << "\n You will need to supply the following information\n to add a student to the list:\n";
	cout << "	-> First and Last name\n	-> Country\n	-> CGPA (SFU grading scale)\n	-> Research Score (0-100)\n";
	cout << "\n Type 'cancel' at any word input (or -1 at number input)\n to return to the domestic students menu.";
	cout << "\n|********************************************************|\n";

	string cancel = "cancel";
	string fname, lname, country;
	float cgpa;
	int res, to;
	bool loop = true;
	while (loop == true) {
		bool l2 = true;
		while (l2 == true) {
			cout << "\nName...\nFirst: ";
			cin >> fname;
			cout << "Last: ";
			cin >> lname;
			if (lowstring(fname) == cancel || lowstring(lname) == cancel) {
				break;
			}
			string c;
			cout << "\n< Are you okay with this name? (Y/N) >\n";
			cin >> c;
			if (c == "Y" || c == "y") {
				l2 = false;
			}
		}
		bool l3 = true;
		while (l3 == true) {
			cout << "\nCountry: ";
			cin >> country;
			if (lowstring(country) == cancel) {
				break;
			}
			bool test = true;
			while (test == true) {
				if (lowstring(country) == "canada" || lowstring(country) == "china" || lowstring(country) == "india" || lowstring(country) == "iran" || lowstring(country) == "korea") {
					test = false;
				}
				else {
					cout << "\n< That country is invalid. Please retry. >\n\nCountry: ";
					cin >> country;
				}
			}
			string c;
			cout << "\n< Are you okay with this country? (Y/N) >\n";
			cin >> c;
			if (c == "Y" || c == "y") {
				l3 = false;
			}
		}
		bool l4 = true;
		while (l4 == true) {
			cout << "\nCGPA: ";
			cin >> cgpa;
			if (cgpa == -1) {
				break;
			}
			bool test = true;
			while (test == true) {
				if (cgpa >= 0 && cgpa <= 4.33) {
					test = false;
				}
				else {
					cout << "\n< That CGPA is invalid. Please retry. >\n\nCGPA: ";
					cin >> cgpa;
				}
			}
			string c;
			cout << "\n< Are you okay with this CGPA? (Y/N) >\n";
			cin >> c;
			if (c == "Y" || c == "y") {
				l4 = false;
			}
		}
		bool l5 = true;
		while (l5 == true) {
			cout << "\nResearch Score: ";
			cin >> res;
			if (res == -1) {
				break;
			}
			bool test = true;
			while (test == true) {
				if (res >= 0 && res <= 100) {
					test = false;
				}
				else {
					cout << "\n< That score is invalid. Please retry. >\n\nResearch Score: ";
					cin >> res;
				}
			}
			string c;
			cout << "\n< Are you okay with this score? (Y/N) >\n";
			cin >> c;
			if (c == "Y" || c == "y") {
				l5 = false;
			}
		}
		bool l6 = true;
		while (l6 == true) {
			cout << "\nResearch Score: ";
			cin >> to;
			if (to == -1) {
				break;
			}
			bool test = true;
			while (test == true) {
				if (to >= 93 && to < 200) {
					test = false;
				}
				else {
					cout << "\n< That Toefl score does not meet minimum requirements. Please retry. >\n\nToeflScore: ";
					cin >> to;
				}
			}
			string c;
			cout << "\n< Are you okay with this Toefl score? (Y/N) >\n";
			cin >> c;
			if (c == "Y" || c == "y") {
				l6 = false;
			}
		}
		cout << "\nYour student is as follows:\n";
		cout << fname << " " << lname << " from " << country << ", CGPA: " << setprecision(2) << cgpa << ", ResearchScore: " << res << "\nApplication ID: " << tail->get_applicationid() + 1 << endl;
		string c;
		cout << "\n< Add to list? (Y/N) >\n";
		cin >> c;
		if (c == "Y" || c == "y") {
			InternationalStudent myDom(fname, lname, country, cgpa, res, tail->get_applicationid() + 1);
			insert(myDom);
			loop = false;
		}
		else {
			cout << "\n	Cancelling student creation...\n";
			loop = false;
		}
	}
}

//delete
void inlist::del() {
	string fdel, ldel;
	int exist = 0;
	cout << "\nEnter the First and Last name of the student you would like to delete...\nFirst: ";
	cin >> fdel;
	cout << "Last: ";
	cin >> ldel;
	fdel = lowstring(fdel);
	ldel = lowstring(ldel);

	InternationalStudent* temp = head;
	while (temp != NULL) {
		if (fdel == lowstring(temp->get_firstname()) && ldel == lowstring(temp->get_lastname())) {
			bool loop = true;
			while (loop == true) {
				string c;
				cout << "\nThis is the student you are trying to delete:\n" << *temp << endl;
				cout << "\n-> Are you sure you would like to delete? (Y/N)\n";
				cin >> c;
				if (c == "y" || c == "Y") {
					cout << "\n Deleting. . .\n";
					if (temp == head) {
						head = temp->next;
						loop = false;
					}
					else {
						//deletion logic:
						//first create a del obj to copy temp into and delete later
						//assign del->next to the temp->next
						//copy temp data into del data too
						//then assign temp to the head and traverse list
						//when temp pointer gets to node before del node, set temp->next to node after del obj
						InternationalStudent* del = new InternationalStudent;
						del->next = temp->next;
						del = temp;
						temp = head;
						while (temp != NULL) {
							if (temp->next == del) {
								temp->next = del->next;
								break;
							}
							else {
								temp = temp->next;
							}
						}
						loop = false;
					}
				}
				else if (c == "n" || c == "N") {
					loop = false;
				}
				else {
					cout << "\nThat is not a choice.";
				}
			}
			temp = temp->next;
			exist++;
		}
		else {
			temp = temp->next;
		}
	}
	if (exist == 0) {
		cout << "\n< That student is not in the system! >\n";
	}
}

//delete both head+tail only
void inlist::delht() {
	bool loop = true;
	while (loop == true) {
		string c;
		cout << "\nThese are the students you are trying to delete...\n\nHead: \n" << *head << endl << "\nTail: \n" << *tail << endl;
		cout << "\n-> Are you sure you would like to delete? (Y/N)\n";
		cin >> c;
		if (c == "y" || c == "Y") {
			cout << "\n Deleting. . .\n";
			//delete tail
			InternationalStudent* delt = head;
			while (delt != NULL) {
				if (delt->next == tail) {
					tail = delt;
					tail->next = NULL;
				}
				else {
					delt = delt->next;
				}
			}
			//delete head
			InternationalStudent* temp = head->next;
			head = temp;
			loop = false;
		}
		else if (c == "n" || c == "N") {
			loop = false;
		}
		else {
			cout << "\nThat is not a choice.";
		}
	}
}