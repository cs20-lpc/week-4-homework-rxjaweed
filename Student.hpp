// TO DO:  Student class definition  here.
#ifndef STUDENT_HPP
#define STUDENT_HPP

//#include "Student.tpp"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class LinkedList {
    protected:
        
        // represents an element in the linked list
        struct Node 
        {
            string name;
            Node* next;
            double GPA;
            int ID;
            string course;
            string courseLoc;
            
            

            /*Node(const string& n = "", int id = 0, int gpa = 0, Node* next = nullptr)
                : name(n), ID (id), GPA(gpa), next (next) { }*/
        };

        // a pointer to the front of the list
        Node* head;
        int length;

    public:
        // default constructor
        LinkedList();

        // destructor
        virtual ~LinkedList();

        // add the argument to the end of the list
        virtual void AddStudent(const string&, int, double);

        // remove all elements in the list, resetting to the initial state
        virtual void Search(int);

        // return the element at the given position (argument)
        virtual void DisplayAllStudents() const;

        // return the current length of the list
        virtual int NumberofStudents() const;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        virtual void DeleteStudent(int) ;

        // remove all elements in the list, resetting to the initial state virtual void clear() override;
        virtual void clear();

        //this function will allow a course to be added to a student's profile, basically adding something to the node. You need to know ID to add
        virtual void AddCourse(string, int, string);

        // overloaded stream insertion operator to make printing easier
        template <typename U>
        friend ostream& operator<<(ostream&, const LinkedList&);
};

#include "Student.tpp"
#endif
