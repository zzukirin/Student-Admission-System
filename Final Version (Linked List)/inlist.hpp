#ifndef INLIST_H
#define INLIST_H
#include "Student.hpp"
#include "InternationalStudent.hpp"


class inlist : public InternationalStudent
{
    private:
        InternationalStudent* head;
        InternationalStudent* tail;

    public:
        //Constructors
        inlist(); //default

        //Deconstructor
        ~inlist();

        //Functions
        void insert(InternationalStudent& myStudent);
        void sort(InternationalStudent& myStudent);
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
        InternationalStudent* gethead();
        InternationalStudent* gettail();

};
#endif