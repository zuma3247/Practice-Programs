//*****************************************************************************************************
//
//		File:			    LDriver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #5
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    October 3, 2024
//
//
//		This program creates and manipulates a linked list using various functions.
//
//		Other files required:
//                       1.   LList.h
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "LList.h"

//*****************************************************************************************************

int main ()
{
    double removeVal,
           retrieveVal,
           first,
           last;
    int numVal;
    LList <double> dubList;

    cout << "Is the list empty? 1=Yes 0=No" << endl
         << dubList.isEmpty() << endl << endl;

    dubList.insert (7.8);
    cout << "Inserting 7.8 to an empty list:" << endl;
    dubList.display();
    cout << endl;

    dubList.insert (13.9);
    cout << "Inserting 13.9 in front of the current front:" << endl;
    dubList.display();
    cout << endl;

    dubList.insert (9.9);
    cout << "Inserting 9.9 in the middle of the list:" << endl;
    dubList.display();
    cout << endl;

    dubList.insert (17);
    cout << "Inserting 17 at the end of the list:" << endl;
    dubList.display();
    cout << endl << endl;

    cout << "Is the list full?  1=Yes 0=No" << endl
         << dubList.isFull() << endl;
    cout << endl;

    dubList.viewFront (first);
    cout << "Viewing front: " << first << endl;

    dubList.viewRear (last);
    cout << "Viewing last: " << last << endl;

    numVal = dubList.getNumValues();
    cout << "Num of values: " << numVal << endl << endl ;

    retrieveVal = 7.8;
    dubList.retrieve (retrieveVal);
    cout << "Retrieving the front: " << retrieveVal << endl;
    dubList.display();
    cout << endl;

    retrieveVal = 13.9;
    dubList.retrieve (retrieveVal);
    cout << "Retrieving the middle: " << retrieveVal << endl;
    dubList.display();
    cout << endl;

    retrieveVal = 17;
    dubList.retrieve (retrieveVal);
    cout << "Retrieving the last: " << retrieveVal << endl;
    dubList.display();
    cout << endl;

    retrieveVal = 5;
    dubList.retrieve (retrieveVal);
    cout << "Retrieving non-existent front: " << retrieveVal << endl;
    dubList.display();
    cout << endl;

    retrieveVal = 11;
    dubList.retrieve (retrieveVal);
    cout << "Retrieving non-existent middle: " << retrieveVal << endl;
    dubList.display();
    cout << endl;

    retrieveVal = 40.6;
    dubList.retrieve (retrieveVal);
    cout << "Retrieving non-existent larger than last: " << retrieveVal
         << endl;
    dubList.display();
    cout << endl << endl;

    removeVal = 7.8;
    dubList.remove (removeVal);
    cout << "Removing the front (7.8):" << endl;
    dubList.display();
    cout << endl;

    removeVal = 13.9;
    dubList.remove (removeVal);
    cout << "Removing the middle (13.9):" << endl;
    dubList.display();
    cout << endl;

    removeVal = 17;
    dubList.remove (removeVal);
    cout << "Removing the last (17):" << endl;
    dubList.display();
    cout << endl;

    removeVal = 5;
    dubList.remove (removeVal);
    cout << "Removing non-existent front (5):" << endl;
    dubList.display();
    cout << endl;

    removeVal = 11;
    dubList.remove (removeVal);
    cout << "Removing non-existent middle (11):" << endl;
    dubList.display();
    cout << endl;

    removeVal = 40.6;
    dubList.remove (removeVal);
    cout << "Removing non-existent larger than last (40.6):" << endl;
    dubList.display();
    cout << endl;

    return 0;
}

//*****************************************************************************************************

/*

Is the list empty? 1=Yes 0=No
1

Inserting 7.8 to an empty list:
7.8
Inserting 13.9 in front of the current front:
7.8 	13.9
Inserting 9.9 in the middle of the list:
7.8 	9.9 	13.9
Inserting 17 at the end of the list:
7.8 	9.9 	13.9 	17

Is the list full?  1=Yes 0=No
0

Viewing front: 7.8
Viewing last: 17
Num of values: 4

Retrieving the front: 7.8
7.8 	9.9 	13.9 	17
Retrieving the middle: 13.9
7.8 	9.9 	13.9 	17
Retrieving the last: 17
7.8 	9.9 	13.9 	17
Retrieving non-existent front: 5
7.8 	9.9 	13.9 	17
Retrieving non-existent middle: 11
7.8 	9.9 	13.9 	17
Retrieving non-existent larger than last: 40.6
7.8 	9.9 	13.9 	17

Removing the front (7.8):
9.9 	13.9 	17
Removing the middle (13.9):
9.9 	17
Removing the last (17):
9.9
Removing non-existent front (5):
9.9
Removing non-existent middle (11):
9.9
Removing non-existent larger than last (40.6):
9.9

 */