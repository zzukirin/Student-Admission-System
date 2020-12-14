#ifndef MAINLIST_H
#define MAINLIST_H
#include "Student.hpp"
#include "DomesticStudent.hpp"
#include "InternationalStudent.hpp"
#include "dslist.hpp"
#include "inlist.hpp"

class mainlist
{
    private:
        Student* head;
        Student* tail;

    public:
        //Constructors
        mainlist(); //default

        //Deconstructor
        ~mainlist();

        //Functions
        void merge();
        void print(); //print entire list


        //Getters
        Student* gethead();
        Student* gettail();



};
#endif
