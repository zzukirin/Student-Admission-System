#ifndef DSLIST_H
#define DSLIST_H
#include "Student.hpp"
#include "DomesticStudent.hpp"


class dslist : public DomesticStudent
{
    private:
        DomesticStudent* head;
        DomesticStudent* tail;

    public:
        //Constructors
        dslist(); //default

        //Deconstructor
        ~dslist();

        //Functions
        void insert(DomesticStudent& myStudent);
        void sort(DomesticStudent& myStudent);
        void print(); //print entire list
        void searchID(); //search appid
        void searchCGPA(); //search CGPA
        void searchRes(); //search research score
        string lowstring(string a); //compare strings
        void searchName(); //search names
        void add(); //add new student
        void del(); //delete student
        void delht(); //delete head/tail

        //Getters
        DomesticStudent *gethead();
        DomesticStudent* gettail();

};
#endif