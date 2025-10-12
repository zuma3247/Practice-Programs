//*****************************************************************************************************
//
//		File:			    qDriver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #7
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    October 31, 2024
//
//
//		This program creates a templated queue and tested using a simple driver program.
//
//		Other files required:
//                       1.   queue.h
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "queue.h"

//*****************************************************************************************************

int main ()
{
    Queue <int> myQ;
    int numVal,
        deQueVal,
        viewVal;

    cout << "Is the list empty? " << myQ.isEmpty() << endl;

    cout << endl << "Adding 10-50 to my Queue" << endl;

    for (int i = 1; i <= 5; i++)
        myQ.enqueue (i * 10);

    myQ.viewFront (viewVal);
    cout << endl << "Viewing front of the Queue: " << viewVal << endl;

    myQ.viewRear (viewVal);
    cout << "Viewing end of the Queue: " << viewVal << endl << endl;

    numVal = myQ.getNumValues();
    cout << "Number of values in the Queue: " << numVal << endl;

    cout << "Adding 60 to my Queue" << endl << endl;
    myQ.enqueue (60);

    cout << "Removing first 2 values of my Queue: " << endl;
    myQ.dequeue (deQueVal);
    cout << "Removed " << deQueVal << " from the queue." << endl;
    myQ.dequeue (deQueVal);
    cout << "Removed " << deQueVal << " from the queue." << endl;

    myQ.viewFront (viewVal);
    cout << endl << "Viewing front of the Queue: " << viewVal << endl;

    myQ.viewRear (viewVal);
    cout << "Viewing end of the Queue: " << viewVal << endl << endl;

    numVal = myQ.getNumValues();
    cout << "Number of values in the Queue: " << numVal << endl;

    cout << "Is the list full? " << myQ.isFull() << endl;

    return 0;
}

//*****************************************************************************************************

/*

Is the list empty? 1

Adding 10-50 to my Queue

Viewing front of the Queue: 10
Viewing end of the Queue: 50

Number of values in the Queue: 5
Adding 60 to my Queue

Removing first 2 values of my Queue:
Removed 10 from the queue.
Removed 20 from the queue.

Viewing front of the Queue: 30
Viewing end of the Queue: 60

Number of values in the Queue: 4
Is the list full? 0

 */