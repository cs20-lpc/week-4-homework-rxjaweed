// TODO:  Student class methods implementation here.

#include <iostream>
#include <stdexcept>

using namespace std;
#include "Student.hpp"


LinkedList::LinkedList() : head(nullptr), length(0) { }

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::AddStudent(const string& name, int ID, double GPA) 
{
    Node *newNode = new Node;

    newNode->ID = ID;
    newNode->name = name;
    newNode->GPA = GPA;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }

    else 
    {
        Node* nodePtr = head;
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
    ++length;
}

void LinkedList::Search(int ID) 
{
    Node* nodePtr = head;
    bool found = false;

    while (nodePtr !=nullptr)
    {
        if (nodePtr->ID == ID)
        {
            cout << "Student Found!" << endl;
            cout << "Student ID: " << nodePtr-> ID << endl;
            cout << "Student Name: " << nodePtr-> name << endl;
            cout << "Student GPA: " << nodePtr-> GPA << endl;
            found = true;
            break;
        }
        nodePtr = nodePtr->next;
        
    }
    if (!found)
    {
        cout << "Student not found" << endl;
    }

    
    
}

void LinkedList::DisplayAllStudents() const 
{
    Node* nodePtr = head;
    int count = 0;

    while (nodePtr != nullptr) 
    {
        cout << "Name: " << nodePtr->name << endl;
        cout << "ID: " << nodePtr->ID << endl;
        cout << "GPA: " << nodePtr->GPA << endl;
        cout << "---------------------------------" << endl;
        nodePtr = nodePtr->next;
    }
    
}


int LinkedList::NumberofStudents() const 
{
    return this->length;
}

/*template <typename T>
bool LinkedList<T>::isEmpty() const 
{
    return this->length == 0;
}*/


void LinkedList::DeleteStudent(int ID) 
{
    Node* nodePtr = head;
    Node* prev = nullptr;

    if (head == nullptr)
    {
        cout << "List is empty" << endl;
    }

    if (head-> ID == ID)
    {
        head = head->next;
        delete nodePtr;
        cout << "Student deleted" << endl;
    }


    while (nodePtr != nullptr && nodePtr->ID != ID) //searching for node in list
    {
            prev = nodePtr;
            nodePtr = nodePtr->next;
        
    }

    if (nodePtr != nullptr) //if found, unlink and delete
    {
        prev->next = nodePtr->next;
        delete nodePtr;
        cout << "Student deleted" << endl;
    }
    else{
        cout << "Student not found" << endl;
    }
    
}


void LinkedList::clear() 
{
    Node* nodePtr = head;
    while (nodePtr != nullptr)
    {
        Node* temp = nodePtr;
        nodePtr = nodePtr->next;
        delete temp;
    }
    head = nullptr;
    length = 0;
}

void LinkedList :: AddCourse(string course, int ID, string courseLoc)
{
    

    
    Node* nodePtr = head;
    //newNode->ID = ID;
    //newNode->course = course;
    //newNode->courseLoc = courseLoc;

    
    //newNode->next = nullptr;

    while (nodePtr != nullptr)
    {
        
        if (nodePtr->ID == ID)
        {
            nodePtr->course = course;
            nodePtr->courseLoc = courseLoc;
            return;
        }
        nodePtr = nodePtr->next;
    }

}


/*ostream& operator<<(ostream& outStream, const LinkedList& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}*/
