//*****************************************************************************************************
//
//		File:			    studentList.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #11
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    December 3, 2024
//
//
//		This program creates a templated ordered Doubly Linked List
//		using overloaded operators.
//
//		Other files required:
//                       1.   node.h
//                       2.   DLList.h
//                       3.   Student.h
//                       3.   studentFile.txt
//
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

#include "Student.h"
#include "DLList.h"

//*****************************************************************************************************

char getChoice              ();
void process                (DLList <Student> & studentList);
void buildList              (DLList <Student> & studentList);
void displayStudents        (DLList <Student> & studentList);
void displayStudentsRev     (DLList <Student> & studentList);

void countStudents          (DLList <Student> & studentList);
void addNewStudent          (DLList <Student> & studentList);
void removeStudent          (DLList <Student> & studentList);
void findStudent            (DLList <Student> & studentList);

//*****************************************************************************************************

int main()
{
    DLList <Student> studentList;
    buildList (studentList);
    process (studentList);

    return 0;
}

//*****************************************************************************************************

void buildList (DLList <Student> & studentList)
{
    Student student;
    ifstream studentData;

    studentData.open ("studentFile.txt");

    while (studentData >> student.id)
    {
        studentData.ignore();
        studentData.getline (student.name, 50);
        studentData.getline (student.citystate, 50);
        studentData >> student.phone
                    >> student.gender
                    >> student.year
                    >> student.credits
                    >> student.gpa
                    >> student.major;

        studentList.insert (student);
    }

    studentData.close();
}

//*****************************************************************************************************

void process (DLList <Student> & studentList)
{
    char choice;

    do
    {
        choice = getChoice();

        switch (choice)
        {
            case 'A':
                addNewStudent (studentList);
                break;

            case 'F':
                findStudent (studentList);
                break;

            case 'R':
                removeStudent (studentList);
                break;

            case 'C':
                countStudents (studentList);
                break;

            case 'D':
                displayStudents (studentList);
                break;

            case 'V':
                displayStudentsRev (studentList);
                break;

            case 'Q':
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
    while (choice != 'Q');
}

//*****************************************************************************************************

char getChoice()
{
    char choice;
    bool valid;

    cout << "======== MENU ========\n"
         << "A:  Add a new Student\n"
         << "F:  Find a Student Record\n"
         << "R:  Remove a Student\n"
         << "C:  Count Students\n"
         << "D:  Display Students (Forward)\n"
         << "V:  Display Students (Reverse)\n"
         << "Q:  Quit\n"
         << "Enter your choice: ";

    do
    {
        cin >> choice;
        choice = toupper (choice);

        switch (choice)
        {
            case 'A':
            case 'F':
            case 'R':
            case 'C':
            case 'D':
            case 'V':
            case 'Q':
                valid = true;
                break;

            default:
                valid = false;
                cout << "\aInvalid choice\n"
                     << "Please try again: ";
                break;
        }
    } while (!valid);

    return choice;
}

//*****************************************************************************************************

void displayStudents (DLList <Student> & studentList)
{
    cout << endl << "Displaying Student List:" << endl;

    studentList.display();

    cout << endl;
}

//*****************************************************************************************************

void displayStudentsRev (DLList <Student> & studentList)
{
    cout << endl << "REVERSE STUDENT LIST" << endl;

    for (int i = 0; i < 50; i++)
        cout << "=";

    cout << endl << left << setw(10) << "ID" << setw(25) << "NAME"
         << setw(10) << "MAJOR" << "GPA" << endl;

    for (int i = 0; i < 50; i++)
        cout << "=";

    cout << endl;
    studentList.displayReverse();
    cout << endl;
}

//*****************************************************************************************************

void countStudents (DLList <Student> & studentList)
{
    cout << "Number of students: " << studentList.getNumValues() << endl << endl;
}

//*****************************************************************************************************

void addNewStudent (DLList <Student> & studentList)
{
    Student student;

    cout << "Enter student details:\n";
    cout << "ID: ";
    cin >> student.id;
    cin.ignore();

    cout << "Name: ";
    cin.getline(student.name, 50);
    cout << "City/State: ";
    cin.getline(student.citystate, 50);

    cout << "Phone: ";
    cin >> student.phone;
    cout << "Gender: ";
    cin >> student.gender;
    cout << "Year: ";
    cin >> student.year;

    cout << "Credits: ";
    cin >> student.credits;
    cout << "GPA: ";
    cin >> student.gpa;
    cout << "Major: ";
    cin >> student.major;

    if (studentList.insert(student))
        cout << "Student added successfully!" << endl << endl;
    else
        cout << "Student add error!" << endl;
}

//*****************************************************************************************************

void removeStudent (DLList <Student> & studentList)
{
    Student temp;

    cout << "Enter the ID of the student to remove: ";
    cin >> temp.id;

    if (studentList.remove(temp))
        cout << "Student removed successfully!" << endl << endl;
    else
        cout << "Student not found!" << endl;
}

//*****************************************************************************************************

void findStudent (DLList <Student> & studentList)
{
    Student temp;

    cout << "Enter the ID of the student to find: ";
    cin >> temp.id;

    if (studentList.retrieve(temp))
        cout << temp << endl;
    else
        cout << "Student not found!" << endl;
}

//*****************************************************************************************************

/*
======== MENU ========
A:  Add a new Student
F:  Find a Student Record
R:  Remove a Student
C:  Count Students
D:  Display Students (Forward)
V:  Display Students (Reverse)
Q:  Quit
Enter your choice: v

REVERSE STUDENT LIST
==================================================
ID        NAME                     MAJOR     GPA
==================================================
       PSYC      1.85
           GREE      3.25
      PHIL      3.1
          GEOG      3.37
   MUSC      2.87
          ART       3.74
            SPEE      3.4
        EDUC      3.83
       EDUC      0.99
          MATH      2.99
          LATI      2.87
   CHEM      3.85
       HIST      1.95
      HIST      1.77
           MUSI      2.78
         MATH      3.83
        GEOG      2.29
       PSYC      2.48
          CPSC      2.95
     CPSC      2.99
        ENGL      1.95
     EDUC      1.75
       BIOL      3.1
          CPSC      3.83
      BIOL      2.66
           CPSC      3.25
         ENGR      3.1
           HIST      2.29
            ECON      2.75
        SOCI      1.95
     SOCI      3.25
        RELI      2.98
          PHIL      2.99
              FOOD      3.98
    PE        2.78
         CPSC      1.98
 HIST      3.74
    ART       2.2
      ENGR      2.78
 MUSC      2.75
        PE        1.98
              GNED      0.21
        EDUC      1.99
       RELI      2.99
        MATH      2.75
     GERM      3.05
        CPSC      2.78
        ENGR      3.15
  EDUC      2.7
    MATH      3.25
     ENGR      2.79
       POLS      2.95
     POLS      3.15
 PSYC      2.99
           ENGR      2.75
 NURS      3.15
   CPSC      4
           MATH      4
       SOCI      1.95
      CPSC      1.88
    MATH      1.95

======== MENU ========
A:  Add a new Student
F:  Find a Student Record
R:  Remove a Student
C:  Count Students
D:  Display Students (Forward)
V:  Display Students (Reverse)
Q:  Quit
Enter your choice: q
Exiting the program.
 */