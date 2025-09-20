#include <iostream>
#include <string>
#include "Student.hpp"
//#include "Course.hpp"
// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.
//program is crashing when GPA is a decimal, even though I have it as a double


using namespace std;


int main()
{
    LinkedList list; 
    int option; 


    do
    {
        cout << "Welcome to the Linked List program. Please select an option from the following. Enter -1 to quit the program:" << endl;

        cout << "1) Add a student" << endl; //needs to enter ID, GPA, list of courses enrolled, and name
        cout << "2) Dispay all Students" << endl; //display name and ID
        cout << "3) Search for a student" << endl; //needs to enter ID
        cout << "4) Delete Student" << endl;
        cout << "5) Number of Students in the List" << endl; //display literally the number of students in list
        cout << "6) Add Course to student" << endl; //search by ID and add the course to this list

        cin >> option;

        if (option == 1) //add student
        {
            string name;
            double GPA;
            int ID;

            
            cout << "Enter the name of the student:" << endl;
            cin.ignore();
            getline(cin,name);

            cout << "Enter the ID of the student:" << endl;
            cin >> ID;

            cout << "Enter the GPA of the student:" << endl;
            cin >> GPA;

            list.AddStudent(name, ID, GPA);
            cout << "The Student has been added to the list" << endl;
        
        }

        if (option == 2) //display
        {

            list.DisplayAllStudents();
        }

        if (option == 3) //search for a student
        {
            int ID;
            cout << "Please enter the ID of the student you wish to find: " << endl;
            cin >> ID;

            list.Search(ID);
        }

        if (option == 4) //Delete student
        {
            int ID;
            cout << "Please enter the student ID: " << endl;
            cin >> ID;

            list.DeleteStudent(ID);
        }

        if (option == 5) //Display # of Students in list
        {
            cout << "The list currently has " << list.NumberofStudents() << endl;
        }

        if (option == 6) // Add course to a student
        {
            int ID;
            string course;
            string courseLoc;

            cout << "Enter student ID for course being added: " << endl;
            cin >> ID;
            cin.ignore(); // clear leftover newline from ID input

            cout << "Enter name of the course: " << endl;
            getline(cin, course);

            cout << "Enter course location: " << endl;
            getline(cin, courseLoc);

            list.AddCourse(course, ID, courseLoc);
        }

    } while (option != -1);
    
        cout << "Thank you for using the Program" << endl;
    
    

    
}
