#include "mainlist.hpp"
#include <cmath>

mainlist::mainlist() {
	head = NULL;
	tail = NULL;
}

mainlist::~mainlist() {}

Student* mainlist::gethead() {
	return head;
}

Student* mainlist::gettail() {
	return tail;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Functions ///////////////////////////////////////

//merge students into linked list
void mainlist::merge() {
	Student* temp = new Student();

	dslist* dtemp = new dslist();
	cout << dtemp->gethead() << endl;
	Student* head = dtemp->gethead();
	Student* tail = dtemp->gethead();
	temp->next = NULL;

	temp = head;
	while (temp != NULL) {
		//sets temp to next, sets new tail to be the temp next
		tail->next = temp;
		tail = tail->next;

		tail->next = NULL; //sets very last tail to NULL
	}
}

//print entire linked list
void mainlist::print() {
	int count = 0;
	Student* temp = head;
	while (temp != NULL) {
		//cout << "\ntemp address: " << temp << endl << "next address: " << temp->next; //address checking (TESTS)
		cout << endl << "[Student #" << count + 1 << "]" << endl << temp << endl;
		temp = temp->next;
		count++;
	}
	cout << "\n  **There are currently " << count << " entries in the list.\n\n\n";
}