//*****************************************************************************************************
//
//		File:			    driver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #7
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    March 19, 2025
//
//
//		This is the driver program for a Priority Queue.
//
//		Other files required:
//                       1.   PriorityQueue.h
//
//*****************************************************************************************************

#include <iostream>
#include "PriorityQueue.h"
using namespace std;

//*****************************************************************************************************

int main()
{
    PriorityQueue <int> pq;
    int elements[] = {15, 30, 10, 20, 70, 90, 11, 12, 0, 100};
    int numElements = 10;
    int value;

    for (int i = 0; i < numElements; ++i)
    {
        pq.enqueue(elements[i]);
    }

    pq.print();

    while (pq.isEmpty() == false)
    {
        pq.dequeue(value);
        cout << "Dequeued: " << value << endl;
    }

    if (pq.isEmpty() == true)
    {
        cout << "Priority queue is Empty" << endl;
    }
    else
    {
        cout << "Priority queue is Not Empty" << endl;
    }

    pq.enqueue(5);
    cout << endl << "Enqueued 5" << endl;

    pq.makeEmpty();
    cout << "Called makeEmpty()" << endl;

    if (pq.isEmpty())
    {
        cout << "Priority queue is Empty" << endl;
    }
    else
    {
        cout << "Priority queue is Not Empty" << endl;
    }

    return 0;
}

//*****************************************************************************************************

/*

Priority Queue as array: [100, 90, 70, 15, 30, 10, 11, 12, 0, 20]
Dequeued: 100
Dequeued: 90
Dequeued: 70
Dequeued: 30
Dequeued: 20
Dequeued: 15
Dequeued: 12
Dequeued: 11
Dequeued: 10
Dequeued: 0
Priority queue is Empty

Enqueued 5
Called makeEmpty()
Priority queue is Empty

*/

